#ifndef QLABELBAR_H
#define QLABELBAR_H

#include <QLabel>
#include <QMouseEvent>
#include <QPoint>

class QLabelBar : public QLabel
{
    Q_OBJECT
public:
    explicit QLabelBar(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
signals:
    void released();
    void sendHoriDis(int dx);
    void sendVertiDis(int dy);

public slots:
private:
    QPoint first;

};

#endif // QLABELBAR_H
