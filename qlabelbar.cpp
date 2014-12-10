#include "qlabelbar.h"
QLabelBar::QLabelBar(QWidget *parent) :
    QLabel(parent)
{
}

void QLabelBar::mousePressEvent(QMouseEvent *ev)
{
    first = ev->pos();
}

void QLabelBar::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons() == Qt::LeftButton)
    {
        emit sendHoriDis((int)(ev->pos().x() - first.x()));
        first = ev->pos();
    }
}

void QLabelBar::mouseReleaseEvent(QMouseEvent *ev)
{
    emit released();
}
