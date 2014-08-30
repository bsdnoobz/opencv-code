OpenCV - Qt Integration
=======================

This sample demonstrate how to display `cv::Mat` using `QLabel` widget. Tested on Mac OS X and Qt 5.3.0. 

![Screenshot](http://i.imgur.com/k1et0FY.png)

Within the `python/` directory, you will see the same code written in Python.

Compiling
---------

To compile the code, change the working directory and type:

    qmake
    make

If everything is ok, it will produce an executable: `ImageViewer` (Linux), `ImageViewer.exe` (Windows), or `ImageViewer.app` (Mac). Run the executable and you will see the GUI like the screenshot above.
