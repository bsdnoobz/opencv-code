OpenCV - Qt Integration
=======================

This code sample shows the basics to display OpenCV's matrix (`cv::Mat`) within a Qt GUI. The code simply load the `flughahn.jpg` image from the `assets/` directory and display it using the `QLabel` widget.

![Screenshot](http://i.imgur.com/k1et0FY.png)

Within the `python/` directory, you will see the same code written in Python.

Compiling
---------

Open `ImageViewer.pro` and modify the variables to match with your system. For example, you might need to modify the paths for the includes and libraries especially if you're on Windows.

    INCLUDEPATH += /usr/local/include
    LIBS += -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs

Change your working directory and compile the code by typing:

    qmake
    make

If everything is ok, it will produce an executable: `ImageViewer` (Linux), `ImageViewer.exe` (Windows), or `ImageViewer.app` (Mac). Run the executable and you will see the GUI like the screenshot above.

Known Issues
------------

The code using relative path to locate the input image:

    img = cv::imread("../assets/flughahn.jpg");

If the program cannot display the image and shows the "Cannot load the input image!" warning, try to use absolute path instead. For example:

    img = cv::imread("/full/path/to/flughahn.jpg");
