#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle("Multiplication Table");
    w.resize(400, 400);
    w.show();

    return a.exec();
}
