#ifndef IMAGEAPP_H
#define IMAGEAPP_H

#include <opencv2/core/core.hpp>
#include <QWidget>

class QLabel;
class QVBoxLayout;
class QHBoxLayout;
class QPushButton;

class ImageApp : public QWidget
{
	Q_OBJECT

public:
	ImageApp();

private slots:
	void showOriginalImage();
	void doCanny();
	void doGaussianBlur();

private:
	void setupUi();
	void showImage(cv::Mat);

	cv::Mat originalImage;
	cv::Mat processedImage;
	QLabel *imageLabel;
	QPushButton *originalButton;
	QPushButton *blurButton;
	QPushButton *cannyButton;
	QPushButton *quitButton;
	QVBoxLayout *buttonsLayout;
	QHBoxLayout *mainLayout;
};

#endif
