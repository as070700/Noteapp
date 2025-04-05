/********************************************************************************
** Form generated from reading UI file 'detaileditnote.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILEDITNOTE_H
#define UI_DETAILEDITNOTE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_detaileditnote
{
public:
    QTextEdit *title_textEdit_detaileditnote;
    QTextEdit *content_textEdit_detaileditnote;
    QPushButton *saveButton_detaileditnote;
    QPushButton *backButton_detaileditnote;
    QLabel *label_t_detaileditnote;
    QLabel *label_c_detaileditnote;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *formatting_detaileditnote;
    QComboBox *fontSizeComboBox_detaileditnote;
    QPushButton *colorButton_detaileditnote;
    QPushButton *underlineButton_detaileditnote;
    QPushButton *italicButton_detaileditnote;
    QPushButton *boldButton_detaileditnote;
    QCheckBox *passwordProtectionCheckBox_detaileditnote;
    QLabel *errorLabel_detaileditnote;

    void setupUi(QDialog *detaileditnote)
    {
        if (detaileditnote->objectName().isEmpty())
            detaileditnote->setObjectName("detaileditnote");
        detaileditnote->resize(800, 600);
        detaileditnote->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        title_textEdit_detaileditnote = new QTextEdit(detaileditnote);
        title_textEdit_detaileditnote->setObjectName("title_textEdit_detaileditnote");
        title_textEdit_detaileditnote->setGeometry(QRect(30, 50, 731, 31));
        title_textEdit_detaileditnote->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::IBeamCursor)));
        content_textEdit_detaileditnote = new QTextEdit(detaileditnote);
        content_textEdit_detaileditnote->setObjectName("content_textEdit_detaileditnote");
        content_textEdit_detaileditnote->setGeometry(QRect(30, 160, 731, 351));
        content_textEdit_detaileditnote->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::IBeamCursor)));
        saveButton_detaileditnote = new QPushButton(detaileditnote);
        saveButton_detaileditnote->setObjectName("saveButton_detaileditnote");
        saveButton_detaileditnote->setGeometry(QRect(670, 550, 100, 32));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        saveButton_detaileditnote->setIcon(icon);
        saveButton_detaileditnote->setIconSize(QSize(20, 16));
        backButton_detaileditnote = new QPushButton(detaileditnote);
        backButton_detaileditnote->setObjectName("backButton_detaileditnote");
        backButton_detaileditnote->setGeometry(QRect(10, 550, 191, 32));
        backButton_detaileditnote->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::GoHome));
        backButton_detaileditnote->setIcon(icon1);
        label_t_detaileditnote = new QLabel(detaileditnote);
        label_t_detaileditnote->setObjectName("label_t_detaileditnote");
        label_t_detaileditnote->setGeometry(QRect(30, 30, 58, 16));
        label_c_detaileditnote = new QLabel(detaileditnote);
        label_c_detaileditnote->setObjectName("label_c_detaileditnote");
        label_c_detaileditnote->setGeometry(QRect(30, 100, 58, 16));
        horizontalLayoutWidget = new QWidget(detaileditnote);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(30, 120, 731, 38));
        formatting_detaileditnote = new QHBoxLayout(horizontalLayoutWidget);
        formatting_detaileditnote->setObjectName("formatting_detaileditnote");
        formatting_detaileditnote->setContentsMargins(0, 0, 0, 0);
        fontSizeComboBox_detaileditnote = new QComboBox(horizontalLayoutWidget);
        fontSizeComboBox_detaileditnote->addItem(QString());
        fontSizeComboBox_detaileditnote->addItem(QString());
        fontSizeComboBox_detaileditnote->addItem(QString());
        fontSizeComboBox_detaileditnote->addItem(QString());
        fontSizeComboBox_detaileditnote->addItem(QString());
        fontSizeComboBox_detaileditnote->addItem(QString());
        fontSizeComboBox_detaileditnote->addItem(QString());
        fontSizeComboBox_detaileditnote->setObjectName("fontSizeComboBox_detaileditnote");

        formatting_detaileditnote->addWidget(fontSizeComboBox_detaileditnote);

        colorButton_detaileditnote = new QPushButton(horizontalLayoutWidget);
        colorButton_detaileditnote->setObjectName("colorButton_detaileditnote");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../Downloads/color-wheel.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        colorButton_detaileditnote->setIcon(icon2);
        colorButton_detaileditnote->setIconSize(QSize(20, 16));

        formatting_detaileditnote->addWidget(colorButton_detaileditnote);

        underlineButton_detaileditnote = new QPushButton(horizontalLayoutWidget);
        underlineButton_detaileditnote->setObjectName("underlineButton_detaileditnote");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::FormatTextUnderline));
        underlineButton_detaileditnote->setIcon(icon3);
        underlineButton_detaileditnote->setIconSize(QSize(20, 16));

        formatting_detaileditnote->addWidget(underlineButton_detaileditnote);

        italicButton_detaileditnote = new QPushButton(horizontalLayoutWidget);
        italicButton_detaileditnote->setObjectName("italicButton_detaileditnote");
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::FormatTextItalic));
        italicButton_detaileditnote->setIcon(icon4);
        italicButton_detaileditnote->setIconSize(QSize(20, 16));

        formatting_detaileditnote->addWidget(italicButton_detaileditnote);

        boldButton_detaileditnote = new QPushButton(horizontalLayoutWidget);
        boldButton_detaileditnote->setObjectName("boldButton_detaileditnote");
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::FormatTextBold));
        boldButton_detaileditnote->setIcon(icon5);
        boldButton_detaileditnote->setIconSize(QSize(20, 16));

        formatting_detaileditnote->addWidget(boldButton_detaileditnote);

        passwordProtectionCheckBox_detaileditnote = new QCheckBox(detaileditnote);
        passwordProtectionCheckBox_detaileditnote->setObjectName("passwordProtectionCheckBox_detaileditnote");
        passwordProtectionCheckBox_detaileditnote->setGeometry(QRect(578, 50, 171, 30));
        errorLabel_detaileditnote = new QLabel(detaileditnote);
        errorLabel_detaileditnote->setObjectName("errorLabel_detaileditnote");
        errorLabel_detaileditnote->setGeometry(QRect(420, 510, 341, 31));

        retranslateUi(detaileditnote);
        QObject::connect(saveButton_detaileditnote, SIGNAL(clicked()), detaileditnote, SLOT(on_saveButton_detaileditnote_clicked()));
        QObject::connect(backButton_detaileditnote, SIGNAL(clicked()), detaileditnote, SLOT(on_backButton_detaileditnote_clicked()));

        QMetaObject::connectSlotsByName(detaileditnote);
    } // setupUi

    void retranslateUi(QDialog *detaileditnote)
    {
        detaileditnote->setWindowTitle(QCoreApplication::translate("detaileditnote", "Detail Edit Note", nullptr));
        saveButton_detaileditnote->setText(QCoreApplication::translate("detaileditnote", "Speichern", nullptr));
        backButton_detaileditnote->setText(QCoreApplication::translate("detaileditnote", "Zur\303\274ck zum Hauptmen\303\274", nullptr));
        label_t_detaileditnote->setText(QCoreApplication::translate("detaileditnote", "Titel:", nullptr));
        label_c_detaileditnote->setText(QCoreApplication::translate("detaileditnote", "Inhalt:", nullptr));
        fontSizeComboBox_detaileditnote->setItemText(0, QCoreApplication::translate("detaileditnote", "8", nullptr));
        fontSizeComboBox_detaileditnote->setItemText(1, QCoreApplication::translate("detaileditnote", "10", nullptr));
        fontSizeComboBox_detaileditnote->setItemText(2, QCoreApplication::translate("detaileditnote", "12", nullptr));
        fontSizeComboBox_detaileditnote->setItemText(3, QCoreApplication::translate("detaileditnote", "14", nullptr));
        fontSizeComboBox_detaileditnote->setItemText(4, QCoreApplication::translate("detaileditnote", "16", nullptr));
        fontSizeComboBox_detaileditnote->setItemText(5, QCoreApplication::translate("detaileditnote", "18", nullptr));
        fontSizeComboBox_detaileditnote->setItemText(6, QCoreApplication::translate("detaileditnote", "20", nullptr));

        colorButton_detaileditnote->setText(QString());
        underlineButton_detaileditnote->setText(QString());
        italicButton_detaileditnote->setText(QString());
        boldButton_detaileditnote->setText(QString());
#if QT_CONFIG(tooltip)
        passwordProtectionCheckBox_detaileditnote->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        passwordProtectionCheckBox_detaileditnote->setText(QCoreApplication::translate("detaileditnote", "Notiz sch\303\274tzen?", nullptr));
        errorLabel_detaileditnote->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class detaileditnote: public Ui_detaileditnote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILEDITNOTE_H
