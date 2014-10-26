#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_Image_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"),0,"Image files (*.png *.bmp *.jpg);;PNG (*.png);;BMP (*.bmp);;JPG (*.jpg)");
    if(fileName.isEmpty())
        return;
    QImage image(fileName);
    if(!image.isNull())
    {
        ui->graphicsView->initialize(1, image.width(), image.height());  //initial qgraphics view
        ui->graphicsView->setImagefromQImage(image);
        ui->statusBar->showMessage("Image: " + fileName + " opened!");
    }
}
