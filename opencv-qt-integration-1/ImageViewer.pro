TEMPLATE = app
TARGET = ImageViewer
INCLUDEPATH += .
QT += widgets

# Input
HEADERS += ImageViewer.h
SOURCES += ImageViewer.cpp main.cpp
INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs
