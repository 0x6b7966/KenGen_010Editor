/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_3;
    QRadioButton *rBtnVersion;
    QDateEdit *dateEdit;
    QRadioButton *rBtnNumber;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *editName;
    QLineEdit *editSerial;
    QLabel *label;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnExit;
    QPushButton *btnGetSerial;
    QPushButton *btnCopySerial;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(520, 229);
        Dialog->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(Dialog);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        rBtnVersion = new QRadioButton(Dialog);
        rBtnVersion->setObjectName(QString::fromUtf8("rBtnVersion"));
        rBtnVersion->setMinimumSize(QSize(0, 0));
        rBtnVersion->setMaximumSize(QSize(300, 16777215));
        rBtnVersion->setAcceptDrops(true);

        gridLayout_3->addWidget(rBtnVersion, 0, 1, 1, 1);

        dateEdit = new QDateEdit(Dialog);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setEnabled(false);
        dateEdit->setMinimumDateTime(QDateTime(QDate(1970, 1, 1), QTime(0, 0, 0)));
        dateEdit->setCalendarPopup(true);

        gridLayout_3->addWidget(dateEdit, 0, 5, 1, 1);

        rBtnNumber = new QRadioButton(Dialog);
        rBtnNumber->setObjectName(QString::fromUtf8("rBtnNumber"));

        gridLayout_3->addWidget(rBtnNumber, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 6, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 1, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        editName = new QLineEdit(Dialog);
        editName->setObjectName(QString::fromUtf8("editName"));
        editName->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(editName, 1, 1, 1, 1);

        editSerial = new QLineEdit(Dialog);
        editSerial->setObjectName(QString::fromUtf8("editSerial"));
        editSerial->setMaximumSize(QSize(16777215, 16777215));
        editSerial->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(editSerial, 3, 1, 1, 1);

        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(500, 100));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Label/image/1.bmp")));

        gridLayout->addWidget(label, 0, 0, 1, 3);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        btnExit = new QPushButton(Dialog);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));

        gridLayout_4->addWidget(btnExit, 0, 5, 1, 1);

        btnGetSerial = new QPushButton(Dialog);
        btnGetSerial->setObjectName(QString::fromUtf8("btnGetSerial"));

        gridLayout_4->addWidget(btnGetSerial, 0, 1, 1, 1);

        btnCopySerial = new QPushButton(Dialog);
        btnCopySerial->setObjectName(QString::fromUtf8("btnCopySerial"));

        gridLayout_4->addWidget(btnCopySerial, 0, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 0, 6, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 0, 4, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 2, 1, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        rBtnVersion->setText(QApplication::translate("Dialog", "Version license", nullptr));
        dateEdit->setDisplayFormat(QApplication::translate("Dialog", "yyyy-M-d", nullptr));
        rBtnNumber->setText(QApplication::translate("Dialog", "Number license", nullptr));
        label_2->setText(QApplication::translate("Dialog", "Name:", nullptr));
        label_3->setText(QApplication::translate("Dialog", "Serial:", nullptr));
        editName->setText(QApplication::translate("Dialog", "test", nullptr));
        label->setText(QString());
        btnExit->setText(QApplication::translate("Dialog", "Exit", nullptr));
        btnGetSerial->setText(QApplication::translate("Dialog", "Get Serial", nullptr));
        btnCopySerial->setText(QApplication::translate("Dialog", "Copy Serial", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
