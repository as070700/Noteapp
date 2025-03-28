TEMPLATE = app
TARGET = NoteApp

SOURCES += main.cpp \
           deletenote.cpp \
           detaileditnote.cpp \
           detailshownote.cpp \
           editnote.cpp \
           mainwindow.cpp \
           newnote.cpp \
           notebook.cpp \
           searchnote.cpp \
           securityquestiondialog.cpp \
           setpassworddialog.cpp \
           shownote.cpp \
           getpassworddialog.cpp \
           utils.cpp

HEADERS += mainwindow.h \
           deletenote.h \
           detaileditnote.h \
           detailshownote.h \
           editnote.h \
           newnote.h \
           notebook.h \
           note.h \
           searchnote.h \
           securityquestiondialog.h \
           setpassworddialog.h \
           shownote.h \
           getpassworddialog.h \
           utils.h

FORMS += mainwindow.ui \
         deletenote.ui \
         detaileditnote.ui \
         detailshownote.ui \
         editnote.ui \
         newnote.ui \
         searchnote.ui \
         securityquestiondialog.ui \
         setpassworddialog.ui \
         shownote.ui \
         getpassworddialog.ui

QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
