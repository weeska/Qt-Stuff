#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QFileInfo>
#include <QLibraryInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->connect(ui->actionExit, SIGNAL(triggered()), SLOT(close()));

    this->connect(ui->actionEnglish, SIGNAL(triggered()), &m_languageMapper, SLOT(map()));
    this->connect(ui->actionDeutsch, SIGNAL(triggered()), &m_languageMapper, SLOT(map()));

    m_languageMapper.setMapping(ui->actionEnglish, QString("en_EN"));
    m_languageMapper.setMapping(ui->actionDeutsch, QString("de_DE"));

    this->connect(&m_languageMapper, SIGNAL(mapped(QString)), SLOT(onLanguageChange(QString)));
}

void MainWindow::onLanguageChange(const QString &languageString)
{
    const QString &translationFile = QString("translation_%0").arg(languageString);

    if(!m_translator.load(translationFile, ":/translations/"))
    {
        qDebug() << "Could not load translation " + languageString;
    }

    if(!qApp->installTranslator(&m_translator))
    {
        qDebug() << "Could not load translator!";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::changeEvent(QEvent *event)
{
    switch( event->type() )
    {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
        default:
            break;
    }
}
