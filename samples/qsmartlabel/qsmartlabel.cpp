#include "qSmartLabel.h"
#include <QMouseEvent>
#include <QMessageBox>
#include <QFileDialog>
#include <QMenu>
QSmartLabel::QSmartLabel(QWidget *parent) :
    QLabel(parent)
{
    saveAction = new QAction("Save Image", this);
    connect(saveAction, SIGNAL(triggered()), this, SLOT(on_saveAction_triggered()));

    this->setPixmap(QPixmap(QSize(0,0)));
}

void QSmartLabel::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton){
        double c_x = this->width()/2;
        double c_y = this->height()/2;
        double img_width = this->pixmap()->width();
        double img_height = this->pixmap()->height();
        double send_x = ((ev->x()-c_x+0.0)/img_width);
        double send_y = ((ev->y()-c_y+0.0)/img_height);
        if(abs(send_x) > 0.5 || abs(send_y > 0.5))
            return;
        emit sendMouXY(send_x, send_y);
    }
}

void QSmartLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::RightButton){
        QMenu m(this);
        m.addAction(saveAction);
        m.exec(ev->globalPos());
    }
}

void QSmartLabel::on_saveAction_triggered()
{
    const QImage _img = this->pixmap()->toImage();
    QFileInfo file_name(QFileDialog::getSaveFileName(0, "Img",0,"PNG (*.png);;BMP (*.bmp);;JPG (*.jpg)"));
    if(file_name.fileName().isNull()) {
        return;
    }
    if(!_img.isNull())
    {
        _img.save(file_name.absoluteFilePath());
    }
    else{QMessageBox::information(0, 0, "Can Not Save Image!!");}
}


