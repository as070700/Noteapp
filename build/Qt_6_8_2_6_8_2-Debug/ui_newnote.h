/********************************************************************************
** Form generated from reading UI file 'newnote.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWNOTE_H
#define UI_NEWNOTE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewNote
{
public:
    QLabel *label_newnote;
    QTextEdit *content_lineEdit_newnote;
    QLineEdit *title_lineEdit_newnote;
    QPushButton *saveButton_newnote;
    QPushButton *backButton_newnote;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *fomatting_newnote;
    QComboBox *fontSizeComboBox_newnote;
    QPushButton *colorButton_newnote;
    QPushButton *underlineButton_newnote;
    QPushButton *italicButton_newnote;
    QPushButton *boldButton_newnote;
    QCheckBox *passwordProtectionCheckBox_newnote;
    QLabel *errorLabel_newnote;

    void setupUi(QDialog *NewNote)
    {
        if (NewNote->objectName().isEmpty())
            NewNote->setObjectName("NewNote");
        NewNote->resize(800, 600);
        NewNote->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        label_newnote = new QLabel(NewNote);
        label_newnote->setObjectName("label_newnote");
        label_newnote->setGeometry(QRect(20, 10, 221, 31));
        content_lineEdit_newnote = new QTextEdit(NewNote);
        content_lineEdit_newnote->setObjectName("content_lineEdit_newnote");
        content_lineEdit_newnote->setGeometry(QRect(20, 120, 741, 371));
        content_lineEdit_newnote->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::IBeamCursor)));
        title_lineEdit_newnote = new QLineEdit(NewNote);
        title_lineEdit_newnote->setObjectName("title_lineEdit_newnote");
        title_lineEdit_newnote->setGeometry(QRect(20, 40, 741, 31));
        saveButton_newnote = new QPushButton(NewNote);
        saveButton_newnote->setObjectName("saveButton_newnote");
        saveButton_newnote->setGeometry(QRect(660, 530, 100, 32));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        saveButton_newnote->setIcon(icon);
        backButton_newnote = new QPushButton(NewNote);
        backButton_newnote->setObjectName("backButton_newnote");
        backButton_newnote->setGeometry(QRect(20, 530, 100, 32));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::GoHome));
        backButton_newnote->setIcon(icon1);
        horizontalLayoutWidget = new QWidget(NewNote);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 80, 741, 41));
        fomatting_newnote = new QHBoxLayout(horizontalLayoutWidget);
        fomatting_newnote->setObjectName("fomatting_newnote");
        fomatting_newnote->setContentsMargins(0, 0, 0, 0);
        fontSizeComboBox_newnote = new QComboBox(horizontalLayoutWidget);
        fontSizeComboBox_newnote->addItem(QString());
        fontSizeComboBox_newnote->addItem(QString());
        fontSizeComboBox_newnote->addItem(QString());
        fontSizeComboBox_newnote->addItem(QString());
        fontSizeComboBox_newnote->addItem(QString());
        fontSizeComboBox_newnote->addItem(QString());
        fontSizeComboBox_newnote->addItem(QString());
        fontSizeComboBox_newnote->setObjectName("fontSizeComboBox_newnote");

        fomatting_newnote->addWidget(fontSizeComboBox_newnote);

        colorButton_newnote = new QPushButton(horizontalLayoutWidget);
        colorButton_newnote->setObjectName("colorButton_newnote");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../Downloads/color-wheel.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        colorButton_newnote->setIcon(icon2);

        fomatting_newnote->addWidget(colorButton_newnote);

        underlineButton_newnote = new QPushButton(horizontalLayoutWidget);
        underlineButton_newnote->setObjectName("underlineButton_newnote");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::FormatTextUnderline));
        underlineButton_newnote->setIcon(icon3);

        fomatting_newnote->addWidget(underlineButton_newnote);

        italicButton_newnote = new QPushButton(horizontalLayoutWidget);
        italicButton_newnote->setObjectName("italicButton_newnote");
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::FormatTextItalic));
        italicButton_newnote->setIcon(icon4);

        fomatting_newnote->addWidget(italicButton_newnote);

        boldButton_newnote = new QPushButton(horizontalLayoutWidget);
        boldButton_newnote->setObjectName("boldButton_newnote");
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::FormatTextBold));
        boldButton_newnote->setIcon(icon5);

        fomatting_newnote->addWidget(boldButton_newnote);

        passwordProtectionCheckBox_newnote = new QCheckBox(NewNote);
        passwordProtectionCheckBox_newnote->setObjectName("passwordProtectionCheckBox_newnote");
        passwordProtectionCheckBox_newnote->setGeometry(QRect(586, 40, 171, 30));
        errorLabel_newnote = new QLabel(NewNote);
        errorLabel_newnote->setObjectName("errorLabel_newnote");
        errorLabel_newnote->setGeometry(QRect(400, 490, 361, 31));

        retranslateUi(NewNote);
        QObject::connect(saveButton_newnote, &QPushButton::clicked, NewNote, qOverload<>(&QDialog::accept));
        QObject::connect(backButton_newnote, &QPushButton::clicked, NewNote, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(NewNote);
    } // setupUi

    void retranslateUi(QDialog *NewNote)
    {
        NewNote->setWindowTitle(QCoreApplication::translate("NewNote", "Neue Notiz", nullptr));
        label_newnote->setText(QCoreApplication::translate("NewNote", "Neue Notiz erstellen:", nullptr));
        content_lineEdit_newnote->setPlaceholderText(QCoreApplication::translate("NewNote", "Neue Notiz...", nullptr));
        title_lineEdit_newnote->setPlaceholderText(QCoreApplication::translate("NewNote", "Titel", nullptr));
        saveButton_newnote->setText(QCoreApplication::translate("NewNote", "Speichern", nullptr));
        backButton_newnote->setText(QCoreApplication::translate("NewNote", "Zur\303\274ck", nullptr));
        fontSizeComboBox_newnote->setItemText(0, QCoreApplication::translate("NewNote", "8", nullptr));
        fontSizeComboBox_newnote->setItemText(1, QCoreApplication::translate("NewNote", "10", nullptr));
        fontSizeComboBox_newnote->setItemText(2, QCoreApplication::translate("NewNote", "12", nullptr));
        fontSizeComboBox_newnote->setItemText(3, QCoreApplication::translate("NewNote", "14", nullptr));
        fontSizeComboBox_newnote->setItemText(4, QCoreApplication::translate("NewNote", "16", nullptr));
        fontSizeComboBox_newnote->setItemText(5, QCoreApplication::translate("NewNote", "18", nullptr));
        fontSizeComboBox_newnote->setItemText(6, QCoreApplication::translate("NewNote", "20", nullptr));

        colorButton_newnote->setText(QString());
        underlineButton_newnote->setText(QString());
        italicButton_newnote->setText(QString());
        boldButton_newnote->setText(QString());
        passwordProtectionCheckBox_newnote->setText(QCoreApplication::translate("NewNote", "Notiz sch\303\274tzen?", nullptr));
        errorLabel_newnote->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NewNote: public Ui_NewNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWNOTE_H
