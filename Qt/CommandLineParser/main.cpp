#include <QCoreApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName("CommandLineParser Example");
    QCoreApplication::setApplicationVersion("0.1");

    const QStringList &argumments = a.arguments();

    QCommandLineParser parser;
    parser.setApplicationDescription("An example on how to use the command line parser.");
    parser.addVersionOption();
    parser.addHelpOption();

    parser.process(argumments);

    return a.exec();
}
