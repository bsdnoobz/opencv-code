TEMPLATE = app
TARGET = ImageApp
QT += core widgets
HEADERS += ImageApp.h
SOURCES += ImageApp.cpp main.cpp
INCLUDEPATH += . /usr/local/include
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs
