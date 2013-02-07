/*
straighten-img.cpp
Draw a line on an image and the image rotates so that the line is horizontal

Author:  Nash 
Website: http://opencv-code.com/tutorials/straighten-up-an-image/

Usage:
1. Click to set the start point.
2. Drag your mouse.
3. Click to set the end point.
4. The corrected image will be displayed.
5. Click the original image again to restart.
6. Press 'q' to quit.
*/

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cmath>
#include <iostream>

cv::Mat im0, im1;
std::vector<cv::Point> pt;

void straighten_image(std::vector<cv::Point> pt)
{
	double angle = std::atan((double)(pt[0].y - pt[1].y) / 
	                                 (pt[0].x - pt[1].x)) * 
	                                 (180 / CV_PI);

	cv::Point2f center(im0.cols/2., im0.rows/2.);
	cv::Mat dst, r = cv::getRotationMatrix2D(center, angle, 1.0);
	cv::warpAffine(im0, dst, r, im0.size());
	cv::imshow("dst", dst);
	cv::imwrite("src.jpg", im1);
	cv::imwrite("dst.jpg", dst);
}

void on_mouse(int event, int x, int y, int flags, void* param)
{
	if (event == CV_EVENT_LBUTTONDOWN)
	{
		switch (pt.size())
		{
			case 0:
				pt.push_back(cv::Point(x,y));
				break;
			case 1:
				pt.push_back(cv::Point(x,y));
				straighten_image(pt);
				break;
			case 2:
				im1 = im0.clone();
				pt.clear();
				break;
		}
	}
	else if (event == CV_EVENT_MOUSEMOVE && pt.size() == 1)
	{
		im1 = im0.clone();
		cv::line(im1, pt[0], cv::Point(x,y), CV_RGB(255,0,0), 2);
	}

	if (im1.data)
		cv::imshow("src", im1);
}

int main()
{
	im0 = cv::imread("lena.png");
	if (!im0.data)
	{
		std::cout << "Cannot load source image!" << std::endl;
		return -1;
	}

	cv::namedWindow("src", CV_WINDOW_AUTOSIZE);
	cv::setMouseCallback("src", on_mouse, 0);
	cv::imshow("src", im0);
	cv::waitKey();
	return 0;
}

