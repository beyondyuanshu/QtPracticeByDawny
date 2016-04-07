#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ticker.h"

#include <QProgressDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QProgressDialog progress("Copying files...", "Abort Copy", 0, 3, this);
    progress.setWindowModality(Qt::WindowModal);
    progress.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
