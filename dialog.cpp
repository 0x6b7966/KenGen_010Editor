#include "dialog.h"
#include "ui_dialog.h"
#include "sum_days_difference.h"
#include "serial_calc.h"

Dialog::Dialog(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::Dialog)
{
	ui->setupUi(this);
	init();
	connect(ui->rBtnVersion, SIGNAL(clicked()), this, SLOT(on_btnGetSerial_clicked()));
	connect(ui->rBtnNumber, SIGNAL(clicked()), this, SLOT(on_btnGetSerial_clicked()));
	on_btnGetSerial_clicked();
}

Dialog::~Dialog()
{
	delete ui;
}

void Dialog::init()
{
	this->setWindowFlags(Qt::FramelessWindowHint); // 去掉标题栏,去掉任务栏显示，窗口置顶
	ui->rBtnVersion->setChecked(true);
	QDateTime curDateTime = QDateTime::currentDateTime();
	ui->dateEdit->setDate(curDateTime.date());
	ui->cBtnRandom->setChecked(true);
	ui->editRegMen->setVisible(false);
	// 设置对话框icon
	setWindowIcon(QIcon(":/program/image/Editor.ico"));

}

void Dialog::on_btnExit_clicked()
{
	QApplication::quit();
}

void Dialog::mousePressEvent(QMouseEvent* e)
{
	last = e->globalPos();
}
void Dialog::mouseMoveEvent(QMouseEvent* e)
{
	int dx = e->globalX() - last.x();
	int dy = e->globalY() - last.y();
	last = e->globalPos();
	move(x() + dx, y() + dy);
}
void Dialog::mouseReleaseEvent(QMouseEvent* e)
{
	int dx = e->globalX() - last.x();
	int dy = e->globalY() - last.y();
	move(x() + dx, y() + dy);
}

void Dialog::on_rBtnVersion_clicked()
{
	ui->dateEdit->setEnabled(false);
	ui->editSerial->setText("");
}

void Dialog::on_rBtnNumber_clicked(bool checked)
{
	ui->dateEdit->setEnabled(checked);
	ui->editSerial->setText("");
}

/**
 * \brief 获取序列号
 */
void Dialog::on_btnGetSerial_clicked()
{
	int year, mounth, day;
	const char* szName;
	char serial[25] = { 0 };
	DWORD regmen = 0, number = 0;
	if (ui->cBtnRandom->checkState())
		regmen = GetRandNum();
	else
		regmen = ui->editRegMen->value();
	bool flag = ui->rBtnVersion->isChecked();
	if (!flag)
	{
		// 获取时间
		year = ui->dateEdit->date().year();
		mounth = ui->dateEdit->date().month();
		day = ui->dateEdit->date().day();
		number = GetSumDaysDifference(1970, 1, 1, year, mounth, day);
	}
	// 获取Name
	QString str = ui->editName->text().trimmed();
	if (!str.isEmpty())
	{
		std::string temp = str.toStdString();
		szName = temp.c_str();
		CalcReg(szName, number, regmen, flag, serial); // 计算序列号
	}
	else
	{
		QMessageBox::warning(this, tr("Warning"), tr("The user name cannot be empty!"));
	}
	str = QString(QLatin1String(serial));
	ui->editSerial->setText(str);
}

/**
 * \brief 复制序列号
 */
void Dialog::on_btnCopySerial_clicked()
{
	QString str = ui->editSerial->text();
	if (!str.isEmpty())
	{
		QClipboard* board = QApplication::clipboard();
		board->setText(str);
		QMessageBox::information(this, tr("information"), tr("Copy complete"), QMessageBox::Ok);
	}
}

/**
 * \brief 显示、隐藏人数输入框
 * \param checked
 */
void Dialog::on_cBtnRandom_clicked(bool checked)
{
	if (checked)
		ui->editRegMen->setVisible(false);
	else
		ui->editRegMen->setVisible(true);
}
