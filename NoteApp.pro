TEMPLATE = app
TARGET = NoteApp
TEMPLATE = app

SOURCES += main.cpp \
           mainwindow.cpp \
           newnote.cpp \
           notebook.cpp

HEADERS += mainwindow.h \
           newnote.h \
           notebook.h \
           note.h

FORMS += mainwindow.ui \
            newnote.ui

QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Additional configurations can be added here as needed.
