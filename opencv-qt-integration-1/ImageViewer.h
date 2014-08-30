#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <opencv2/core/core.hpp>
#include <QWidget>

class QLabel;
class QVBoxLayout;
class QPushButton;

class ImageViewer : public QWidget
{
public:
    ImageViewer();

private:
    cv::Mat img;
    QLabel *imageLabel;
    QVBoxLayout *mainLayout;
    QPushButton *quitButton;
};

#endif
