#include <cstdio>
#include <ctime>
#include <limits>

#include <QCoreApplication>
#include <QCommandLineParser>
#include <QTextStream>

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

    QCommandLineOption randomNumberOption(QStringList() << "r" << "random", "Writes a random number to stdout.");
    parser.addOption(randomNumberOption);

    parser.addPositionalArgument("min", "Minimal random value.");
    parser.addPositionalArgument("max", "Maximal random value.");

    parser.process(argumments);

    if(parser.isSet(randomNumberOption))
    {
        srand(time(0));
        const QStringList &positionalArguments = parser.positionalArguments();

        const int min = (positionalArguments.size() > 0 ?
                             positionalArguments[0].toInt() : 0);
        const int max = (positionalArguments.size() > 1 ?
                             positionalArguments[1].toInt() : std::numeric_limits<int>::max());

        QTextStream ( stdout ) << rand() % (max - min + 1) + min;
    }

    return a.exec();
}
