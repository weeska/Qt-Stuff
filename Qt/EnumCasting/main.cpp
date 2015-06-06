#include <QCoreApplication>

#include "Mail.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Mail m;
    m.setState(-1);
    m.setState(2);

    return a.exec();
}

