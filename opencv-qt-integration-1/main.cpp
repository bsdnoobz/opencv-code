#include <QApplication>
#include "ImageViewer.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    ImageViewer viewer;
    viewer.show();
    app.exec();
}
