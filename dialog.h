#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMouseEvent>
#include <QMessageBox>
#include <Windows.h>
#include <QClipboard>
namespace Ui {
	class Dialog;
}

class Dialog : public QDialog
{
	Q_OBJECT

public:
	explicit Dialog(QWidget* parent = nullptr);
	~Dialog();

protected:
	void init();
	void mousePressEvent(QMouseEvent* e);
	void mouseMoveEvent(QMouseEvent* e);
	void mouseReleaseEvent(QMouseEvent* e);
private:
	QPoint last;

private slots:

	void on_btnExit_clicked();

	void on_rBtnVersion_clicked();

	void on_rBtnNumber_clicked(bool checked);

	// 获取序列号
	void on_btnGetSerial_clicked();

	// 复制序列号
	void on_btnCopySerial_clicked();

	void on_cBtnRandom_clicked(bool checked);

private:
	Ui::Dialog* ui;
};

#endif // DIALOG_H
