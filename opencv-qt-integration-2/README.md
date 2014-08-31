OpenCV - Qt Integration
=======================

This code sample shows you how to do basic image manipulation to an image and display the result using the `QLabel` widget. The code loads `The_Chapter_House.jpg` from the `assets/` directory and provides two buttons to perform some basic manipulation.

![screenshot](http://i.imgur.com/OPCiEw8.png)

To compile and run the code, you need to have Qt 5 installed on your computer. The code is successfully tested on the following environment:

 - Mac OS X Mavericks
 - Qt 5.3.0
 - OpenCV 3.0.0
 - Python 3.4.1

Compiling
---------

Open `ImageApp.pro` and modify the variables to match with your system. For example, you might need to modify the paths for the includes and libraries especially if you're on Windows.

    INCLUDEPATH += /usr/local/include
    LIBS += -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs

Change your working directory and compile the code by typing:

    qmake
    make

If everything is ok, it will produce an executable: `ImageApp` (Linux), `ImageApp.exe` (Windows), or `ImageApp.app` (Mac). Run the executable and you will see the GUI like the screenshot above.

Known Issues
------------

In `ImageApp.cpp`, the code using relative path to locate the input image:

    img = cv::imread("../assets/The_Chapter_House.jpg");

If the program cannot display the image and shows the "Cannot load the input image!" warning, try to use absolute path instead. For example:

    img = cv::imread("/full/path/to/The_Chapter_House.jpg");
