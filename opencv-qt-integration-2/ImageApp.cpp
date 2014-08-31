#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QtWidgets>
#include "ImageApp.h"

ImageApp::ImageApp()
{
	originalImage = cv::imread("../assets/The_Chapter_House.jpg");
	if (originalImage.data) {
		cv::cvtColor(originalImage, originalImage, cv::COLOR_BGR2RGB);
	}
	setupUi();
	showImage(originalImage);
}

/**
 * Setup the widgets
 */
void ImageApp::setupUi()
{
	imageLabel = new QLabel();

	originalButton = new QPushButton("Original");	
	connect(originalButton, SIGNAL(clicked()), this, SLOT(showOriginalImage()));

	blurButton = new QPushButton("Gaussian Blur");
	connect(blurButton, SIGNAL(clicked()), this, SLOT(doGaussianBlur()));

	cannyButton = new QPushButton("Canny");
	connect(cannyButton, SIGNAL(clicked()), this, SLOT(doCanny()));

	quitButton = new QPushButton("Quit");
	connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

	buttonsLayout = new QVBoxLayout();
	buttonsLayout->addWidget(originalButton);
	buttonsLayout->addWidget(blurButton);
	buttonsLayout->addWidget(cannyButton);
	buttonsLayout->addStretch();
	buttonsLayout->addWidget(quitButton);

	mainLayout = new QHBoxLayout();
	mainLayout->addWidget(imageLabel);

	if (originalImage.data) {
		mainLayout->addLayout(buttonsLayout);
	}
	setLayout(mainLayout);
	setWindowTitle("Image Processing with Qt and OpenCV");
}

/**
 * Redraw original image
 */
void ImageApp::showOriginalImage()
{
	showImage(originalImage);
}

/**
 * Perform Canny edge detection on original image and display the result
 */
void ImageApp::doCanny()
{
	cv::Mat gray;
	cv::cvtColor(originalImage, gray, cv::COLOR_RGB2GRAY);
	cv::Canny(gray, processedImage, 150, 150);
	cv::cvtColor(processedImage, processedImage, cv::COLOR_GRAY2RGB);
	showImage(processedImage);
}

/**
 * Perform Gaussian blurring on original image and display the result
 */
void ImageApp::doGaussianBlur()
{
	cv::GaussianBlur(originalImage, processedImage, cv::Size(15, 15), 0, 0);
	showImage(processedImage);
}

/**
 * Draw OpenCV matrix using QLabel
 */
void ImageApp::showImage(cv::Mat img)
{
	if (img.data) {
		QImage _img(img.data, img.cols, img.rows, QImage::Format_RGB888);
		imageLabel->setPixmap(QPixmap::fromImage(_img));
	} else {
		imageLabel->setText("Cannot load the input image!");
	}
}
