#include "mainwindow.h"
#include <QApplication>
#include <QProcess>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow w;
    w.showMaximized();


    return app.exec();
}
