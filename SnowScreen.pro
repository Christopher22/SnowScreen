lessThan(QT_MAJOR_VERSION, 5) : error("SnowSceen requires Qt 5")

QT       += core widgets gui svg
TARGET = SnowScreen
TEMPLATE = app
CONFIG += c11

SOURCES += main.cpp\
        screensaver.cpp \
    snowscreen.cpp \
    GUI/snowstorm.cpp \
    GUI/snowflake.cpp \
    Config/dialog.cpp \
    Config/slider.cpp

HEADERS  += screensaver.h \
    snowscreen.h \
    GUI/snowstorm.h \
    GUI/snowflake.h \
    Config/speedconfig.h \
    Config/dialog.h \
    Config/item.h \
    Config/slider.h \
    Config/snowflakesconfig.h \
    Config/sizeconfig.h \
    Config/randomconfig.h

RESOURCES += Data.qrc
win32:RC_ICONS += SnowScreen.ico
