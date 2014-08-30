#include <QtWidgets>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "ImageViewer.h"

ImageViewer::ImageViewer()
{
    img = cv::imread("../assets/flughahn.jpg");

    imageLabel = new QLabel();
    if (img.empty()) {
        imageLabel->setText("Cannot load the input image!");
    } else {
        cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
        QImage _img(img.data, img.cols, img.rows, QImage::Format_RGB888);
        imageLabel->setPixmap(QPixmap::fromImage(_img));
    }

    quitButton = new QPushButton("Quit");
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

    mainLayout = new QVBoxLayout();
    mainLayout->addWidget(imageLabel);
    mainLayout->addWidget(quitButton);

    setLayout(mainLayout);
    setWindowTitle("OpenCV - Qt Integration");
}
