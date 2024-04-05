######################################################################
# Automatically generated by qmake (3.0) ?? 3? 20 15:12:11 2018
######################################################################

QT += core gui widgets network multimedia x11extras

TEMPLATE = app
TARGET = gxde-redict
INCLUDEPATH += .
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget x11

LIBS += -lX11 -lXext -lXtst

# Input
HEADERS += dailypage.h \
           dictpage.h \
           eventmonitor.h \
           homepage.h \
           loadpage.h \
           mainwindow.h \
           transpage.h \
           trayicon.h \
           utils.h \
           youdaoapi.h \
           popup/popupcontent.h \
           popup/popupwindow.h \
           widgets/listdelegate.h \
           widgets/queryedit.h \
           widgets/scrollarea.h \
           widgets/textedit.h \
           widgets/toolbar.h

SOURCES += dailypage.cpp \
           dictpage.cpp \
           eventmonitor.cpp \
           homepage.cpp \
           loadpage.cpp \
           main.cpp \
           mainwindow.cpp \
           transpage.cpp \
           trayicon.cpp \
           utils.cpp \
           youdaoapi.cpp \
           popup/popupcontent.cpp \
           popup/popupwindow.cpp \
           widgets/listdelegate.cpp \
           widgets/queryedit.cpp \
           widgets/scrollarea.cpp \
           widgets/textedit.cpp \
           widgets/toolbar.cpp

RESOURCES += redict.qrc

isEmpty(BINDIR):BINDIR=/usr/bin
isEmpty(APPDIR):APPDIR=/usr/share/applications
isEmpty(DSRDIR):DSRDIR=/usr/share/redict

target.path = $$INSTROOT$$BINDIR
icon_files.path = /usr/share/icons/hicolor/scalable/apps/
icon_files.files = $$PWD/images/redict.svg

desktop.path = $$INSTROOT$$APPDIR
desktop.files = gxde-redict.desktop

INSTALLS += target desktop icon_files
