#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->graphicsView, SIGNAL(sendSelectedRegion(QImage)),this,SLOT(receiveSelectedRegion(QImage)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_Image_triggered()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this,tr("Open File"),0,"Image files (*.png *.bmp *.jpg);;PNG (*.png);;BMP (*.bmp);;JPG (*.jpg)");

    if(fileNames.isEmpty())
        return;

    int img_w = 0, img_h = 0;
    std::vector<QImage> images;
    for(int i = 0; i < fileNames.size(); i++)
    {
        QImage tmp(fileNames.at(i));
        if(!tmp.isNull())
        {
            if(tmp.width() > img_w){img_w = tmp.width();}
            if(tmp.height() > img_h){img_h = tmp.height();}
            images.push_back(tmp);
        }
    }

    if(!images.empty())
    {
        ui->graphicsView->initialize(images.size(), img_w, img_h);  //initial qgraphics view
        ui->graphicsView->setImagefromQImage(images);
        ui->statusBar->showMessage("Images opened!");
    }
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::receiveSelectedRegion(const QImage &img)
{
    ui->copy_screen->initialize(1, img.width(), img.height());
    ui->copy_screen->setImagefromQImage(img);
}
