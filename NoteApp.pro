TEMPLATE = app
TARGET = NoteApp
TEMPLATE = app

SOURCES += main.cpp \
           detaileditnote.cpp \
           detailshownote.cpp \
           editnote.cpp \
           mainwindow.cpp \
           newnote.cpp \
           notebook.cpp \
           shownote.cpp

HEADERS += mainwindow.h \
           detaileditnote.h \
           detailshownote.h \
           editnote.h \
           newnote.h \
           notebook.h \
           note.h \
           shownote.h

FORMS += mainwindow.ui \
            detaileditnote.ui \
            detailshownote.ui \
            editnote.ui \
            newnote.ui \
            shownote.ui

QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Additional configurations can be added here as needed.
