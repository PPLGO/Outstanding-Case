QT       += core gui
QT += multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cheater.cpp \
    checkmate.cpp \
    hint.cpp \
    main.cpp \
    menu.cpp \
    reverse.cpp \
    rule.cpp \
    widget.cpp

HEADERS += \
    cheater.h \
    checkmate.h \
    hint.h \
    menu.h \
    reverse.h \
    rule.h \
    widget.h

FORMS += \
    cheater.ui \
    checkmate.ui \
    hint.ui \
    menu.ui \
    reverse.ui \
    rule.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
