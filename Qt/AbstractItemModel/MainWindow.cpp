#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QHeaderView>

#include "MultiplicationTableModel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableView->setModel(new MultiplicationTableModel(10, 10, this));

    QHeaderView *horizontalHeader = ui->tableView->horizontalHeader();
    if(horizontalHeader)
    {
        horizontalHeader->setSectionResizeMode(QHeaderView::Stretch);
    }

    QHeaderView *verticalHeader = ui->tableView->verticalHeader();
    if(verticalHeader)
    {
        verticalHeader->setSectionResizeMode(QHeaderView::Stretch);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
