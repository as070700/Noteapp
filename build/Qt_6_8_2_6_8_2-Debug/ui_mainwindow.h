/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNewNote;
    QAction *setPasswordAction;
    QAction *resetPasswordAction;
    QWidget *centralwidget;
    QPushButton *addNoteButton;
    QPushButton *displayNotesButton;
    QPushButton *editNoteButton;
    QPushButton *deleteNoteButton;
    QPushButton *exitButton;
    QLabel *errorLabel_mainwindow;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSetting;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionNewNote = new QAction(MainWindow);
        actionNewNote->setObjectName("actionNewNote");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew));
        actionNewNote->setIcon(icon);
        setPasswordAction = new QAction(MainWindow);
        setPasswordAction->setObjectName("setPasswordAction");
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("dialog-password")));
        setPasswordAction->setIcon(icon1);
        resetPasswordAction = new QAction(MainWindow);
        resetPasswordAction->setObjectName("resetPasswordAction");
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("system-lock-screen")));
        resetPasswordAction->setIcon(icon2);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        addNoteButton = new QPushButton(centralwidget);
        addNoteButton->setObjectName("addNoteButton");
        addNoteButton->setGeometry(QRect(80, 90, 230, 90));
        QFont font;
        font.setPointSize(20);
        addNoteButton->setFont(font);
        addNoteButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        addNoteButton->setIcon(icon3);
        addNoteButton->setIconSize(QSize(35, 35));
        addNoteButton->setFlat(true);
        displayNotesButton = new QPushButton(centralwidget);
        displayNotesButton->setObjectName("displayNotesButton");
        displayNotesButton->setGeometry(QRect(80, 260, 230, 90));
        displayNotesButton->setFont(font);
        displayNotesButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::FormatJustifyFill));
        displayNotesButton->setIcon(icon4);
        displayNotesButton->setIconSize(QSize(35, 35));
        displayNotesButton->setFlat(true);
        editNoteButton = new QPushButton(centralwidget);
        editNoteButton->setObjectName("editNoteButton");
        editNoteButton->setGeometry(QRect(460, 80, 227, 90));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(editNoteButton->sizePolicy().hasHeightForWidth());
        editNoteButton->setSizePolicy(sizePolicy);
        editNoteButton->setBaseSize(QSize(0, 0));
        editNoteButton->setFont(font);
        editNoteButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        editNoteButton->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        editNoteButton->setToolTipDuration(-1);
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::MailMessageNew));
        editNoteButton->setIcon(icon5);
        editNoteButton->setIconSize(QSize(35, 35));
        editNoteButton->setFlat(true);
        deleteNoteButton = new QPushButton(centralwidget);
        deleteNoteButton->setObjectName("deleteNoteButton");
        deleteNoteButton->setGeometry(QRect(450, 270, 230, 90));
        deleteNoteButton->setFont(font);
        deleteNoteButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon6(QIcon::fromTheme(QString::fromUtf8("user-trash")));
        deleteNoteButton->setIcon(icon6);
        deleteNoteButton->setIconSize(QSize(35, 35));
        deleteNoteButton->setFlat(true);
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(630, 470, 130, 45));
        QFont font1;
        font1.setPointSize(16);
        exitButton->setFont(font1);
        exitButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon7(QIcon::fromTheme(QString::fromUtf8("system-log-out")));
        exitButton->setIcon(icon7);
        exitButton->setIconSize(QSize(25, 25));
        exitButton->setFlat(true);
        errorLabel_mainwindow = new QLabel(centralwidget);
        errorLabel_mainwindow->setObjectName("errorLabel_mainwindow");
        errorLabel_mainwindow->setGeometry(QRect(80, 435, 391, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 38));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuSetting = new QMenu(menubar);
        menuSetting->setObjectName("menuSetting");
        MainWindow->setMenuBar(menubar);
        QWidget::setTabOrder(addNoteButton, editNoteButton);
        QWidget::setTabOrder(editNoteButton, displayNotesButton);
        QWidget::setTabOrder(displayNotesButton, deleteNoteButton);
        QWidget::setTabOrder(deleteNoteButton, exitButton);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSetting->menuAction());
        menuFile->addAction(actionNewNote);
        menuSetting->addAction(setPasswordAction);
        menuSetting->addAction(resetPasswordAction);

        retranslateUi(MainWindow);
        QObject::connect(exitButton, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "NoteApp", nullptr));
        actionNewNote->setText(QCoreApplication::translate("MainWindow", "Neue Notiz", nullptr));
#if QT_CONFIG(shortcut)
        actionNewNote->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        setPasswordAction->setText(QCoreApplication::translate("MainWindow", "Passwort setzen", nullptr));
#if QT_CONFIG(shortcut)
        setPasswordAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        resetPasswordAction->setText(QCoreApplication::translate("MainWindow", "Passwort zur\303\274cksetzen", nullptr));
#if QT_CONFIG(shortcut)
        resetPasswordAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        addNoteButton->setText(QCoreApplication::translate("MainWindow", "   Notiz hinzuf\303\274gen", nullptr));
        displayNotesButton->setText(QCoreApplication::translate("MainWindow", "     Notizen anzeigen", nullptr));
        editNoteButton->setText(QCoreApplication::translate("MainWindow", "     Notiz bearbeiten", nullptr));
        deleteNoteButton->setText(QCoreApplication::translate("MainWindow", "     Notiz l\303\266schen", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", " Beenden", nullptr));
        errorLabel_mainwindow->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "Datei", nullptr));
        menuSetting->setTitle(QCoreApplication::translate("MainWindow", "Einstellung", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
