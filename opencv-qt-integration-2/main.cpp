#include <QApplication>
#include "ImageApp.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	ImageApp imageApp;
	imageApp.show();
	app.exec();
}
