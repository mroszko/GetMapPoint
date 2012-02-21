#include <QtGui/QApplication>
#include "MapPointsExtractor.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    MapPointsExtractor foo;
    foo.show();
    return app.exec();
}
