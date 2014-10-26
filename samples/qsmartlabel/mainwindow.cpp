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
    //Get open file name
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"),0,"Image files (*.png *.bmp *.jpg);;PNG (*.png);;BMP (*.bmp);;JPG (*.jpg)");

    if(fileName.isEmpty()) //Check if the file name is returned.
        return;
    QImage image(fileName);
    if(!image.isNull())  //Check if the image is loaded.
    {
        //Set MainWindow geometry//
        QRect mainWindowGeometry = this->geometry();
        mainWindowGeometry.setWidth(image.width());
        mainWindowGeometry.setHeight(image.height()+54);
        this->setGeometry(mainWindowGeometry);
        //Set MainWindow geometry End//

        ui->label->setGeometry(0,0,image.width(), image.height());  //You can also use label->resize if you want

        ui->label->setPixmap(QPixmap::fromImage(image));  //Still use setPixmap to put Image.

        ui->statusBar->showMessage("Image: " + fileName + " opened!");
    }
}
