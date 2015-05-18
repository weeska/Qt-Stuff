#include <QCoreApplication>
#include <QStorageInfo>
#include <QTextStream>
#include <cmath>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const double gbDiv = std::pow(1024, 3);

    const QList<QStorageInfo> &localMountedVolumes = QStorageInfo::mountedVolumes();

    foreach(const QStorageInfo &info, localMountedVolumes) {
        if(info.isReady() && !info.isReadOnly())
            QTextStream(stdout) << info.displayName() << ": "
                                << info.bytesFree()/gbDiv << " GiB/"
                                << info.bytesTotal()/gbDiv << "GiB\n";
    }

    return a.exec();
}
