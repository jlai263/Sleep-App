QT += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = ProjectTemplate
TEMPLATE = app

CONFIG += c++17

# List out all source files
SOURCES += \
    addhabitdialog.cpp \
    addsleepsessiondialog.cpp \
    habitmanager.cpp \
    main.cpp \
    mainwindow.cpp \
    habit.cpp \
    habitreminder.cpp \
    logentry.cpp \
    managehabitsdialog.cpp \
    reminder.cpp \
    sleepanalysisdialog.cpp \
    sleepanalyzer.cpp \
    sleeplog.cpp \
    smartalarm.cpp \
    smartalarmdialog.cpp \
    user.cpp

# List out all header files
HEADERS += \
    addhabitdialog.h \
    addsleepsessiondialog.h \
    habitmanager.h \
    mainwindow.h \
    habit.h \
    habitreminder.h \
    logentry.h \
    managehabitsdialog.h \
    reminder.h \
    sleepanalysisdialog.h \
    sleepanalyzer.h \
    sleeplog.h \
    smartalarm.h \
    smartalarmdialog.h \
    user.h

# List out all .ui files
FORMS += \
    addhabitdialog.ui \
    addsleepsessiondialog.ui \
    mainwindow.ui \
    managehabitsdialog.ui \
    sleepanalysisdialog.ui \
    smartalarmdialog.ui
