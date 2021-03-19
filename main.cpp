#include "mainwindow.h"
#include "leftmap.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LeftMap map;

    map.show();
    map.connectDB();
    return a.exec();

}
