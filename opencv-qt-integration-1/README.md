OpenCV - Qt Integration
=======================

This sample demonstrate how to display OpenCV's `cv::Mat` within a Qt GUI. Tested with Qt 5.3.0 on Mac OS X. 

![Screenshot](http://i.imgur.com/k1et0FY.png)

Within the `python/` directory, you will see the same code written in Python.

Compiling
---------

Open `ImageViewer.pro` and modify the variables to match with your system. For example, you might need to modify the paths for includes and libraries especially if you're on Windows.

    INCLUDEPATH += /usr/local/include
    LIBS += -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs

Change your working directory and compile the code by typing:

    qmake
    make

If everything is ok, it will produce an executable: `ImageViewer` (Linux), `ImageViewer.exe` (Windows), or `ImageViewer.app` (Mac). Run the executable and you will see the GUI like the screenshot above.
