#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSignalMapper>
#include <qtranslator.h>

namespace Ui {
class MainWindow;
}

class MainWindow
    : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *event);

private slots:
    void onLanguageChange(const QString &languageString);

private:
    Ui::MainWindow *ui;
    QSignalMapper m_languageMapper;
    QTranslator m_translator;

};

#endif // MAINWINDOW_H
