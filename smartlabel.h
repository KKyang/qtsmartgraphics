/*M///////////////////////////////////////////////////////////////////////////////////////
// Written by Qt 5.3
// Original by Shih-Jhong Yu, Revised by KKyang.
// Protected under LPGLv3 license.
//M*/

#ifndef SMARTLABEL_H
#define SMARTLABEL_H

#include <QDateTime>
#include <QDebug>
#include <QImage>
#include <QFileInfo>
#include <QLabel>



class smartLabel : public QLabel
{
    Q_OBJECT
public:
    explicit smartLabel(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
signals:
    void sendMouXY(double x, double y); // 0~1, 0~1
public slots:
private slots:
    void on_saveAction_triggered();
private:

    QAction *saveAction;
};

#endif // SMARTLABEL_H
