/*M///////////////////////////////////////////////////////////////////////////////////////
// Written by Qt 5.3
// Original by Shih-Jhong Yu, Revised by KKyang.
// Protected under LPGLv3 license.
//M*/

#ifndef QSMARTGRAPHICSVIEW_H
#define QSMARTGRAPHICSVIEW_H

#include <QApplication>
#include <QButtonGroup>
#include <QClipboard>
#include <QFileInfo>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QList>
#include <QMimeData>
#include <QPushButton>
#include <QStyleOption>
#include <QWheelEvent>
#include <QMessageBox>
#include <QVector>

#include <QDebug>

#include <vector>
#ifdef HAVE_OPENCV
#include "opencv2/opencv.hpp"
#endif
#ifdef QT_OPENGL_LIB
#include <QGL>
#endif


/*! QSmartGraphicsView main class. Provides user a more advance image viewing widget.*/
class QSmartGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit QSmartGraphicsView(QWidget *parent = 0);
    ~QSmartGraphicsView();
    void initialize(const int _img_num, const int width, const int height, int changeRow = 4); //!< Must initial before setting any image to QSmartGraphicsView.

    //Set images.
#ifdef HAVE_OPENCV
    void setImage(const cv::Mat &img); //!< Supports cv::Mat if OpenCV is used. Set a single image (cv::Mat) to QSmartGraphicsView.
    void setImage(const std::vector<cv::Mat> &imgs); //!< Supports cv::Mat if OpenCV is used. Set multiple images (cv::Mat) to QSmartGraphicsView.
#endif
    void setImagefromQImage(const QImage &qimg); //!< Set a single image (QImage) to QSmartGraphicsView.
    void setImagefromQImage(const std::vector<QImage> &qimgs); //!< Set a multiple images (QImage) to QSmartGraphicsView.

    bool isInitial() const{return _initial;} //!< Returns true if initialized before.
    int getImgNum(){return img_num;} //!< Returns the number of images set in QSmartGraphicsView.
protected:
    void wheelEvent(QWheelEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void sendItemMouXY(const double x, const double y); //!< Sends the mouse coordinate of the image when clicked the image.
    void sendMousePress(); //!< Sends signal if the mouse is pressed.
public slots:
    void updateImg();
private slots:
    void on_selectRegion_triggered();
    void on_saveAction_triggered(); //!< A right click menu function. Saves all the images on QSmartGraphicsView to system.
    void on_copyToClipboardAction_triggered(); //!< A right click menu function. Copy the selected image to the system clipboard.
private:
    QAction *saveAction, *copyToClipBoardAction; //!< Right click Actions on QSmartGraphicsView.
    QClipboard *clipboard; //!< Clipboard. Assigned to QApplication in constructor.
    QGraphicsScene *scene; //!< The container of the Pixmap items.
    QVector<QGraphicsPixmapItem*> pix_item_vec; //!< Holds the images set to QSmartGrahpicsView.

    QPoint mou_press; //!< Saves the mouse position when right click.
    int mou_x; //!< Records the last mouse x position in mouseMoveEvent.
    int mou_y; //!< Records the last mouse y position in mouseMoveEvent.

    bool _initial = false; //!< Set to true if initialized before.
    int img_num; //!< The number of images set in QSmartGraphicsView.
};

struct btnID{
    QPushButton* btn;
    QString ID;
};

class QSideButtonBar : public QWidget
{
    Q_OBJECT
public:
    QSideButtonBar(QWidget *parent = 0) : QWidget(parent){
        this->setStyleSheet("QSideButtonBar{border: 2px solid grey;}");
    }
    QSideButtonBar(int button_num, QWidget *parent = 0) : QWidget(parent){
        this->setStyleSheet("QSideButtonBar{border: 2px solid grey;}");
        btn.resize(button_num);
        for(int i = 0; i < btn.size(); i++)
        {
            btn[i].btn = new QPushButton(this);
            btn[i].btn->setCheckable(true);
            btn[i].btn->setGeometry(0, i * 31 + 0, 30, 30);
        }
    }

    ~QSideButtonBar()
    {
        btn.clear();
    }

    void addButton()
    {
        btnID newb;
        newb.ID = "";
        newb.btn = new QPushButton(this);
        btn.push_back(newb);
    }

    void renameButtonText(QString name, int btn_num)
    {
        if(btn_num >= 0 && btn_num < btn.size())
            btn[btn_num].btn->setText(name);
    }

    void renameButtonID(QString name, int btn_num)
    {
        if(btn_num >= 0 && btn_num < btn.size())
            btn[btn_num].ID = name;
    }

    int findButtonID(QString name)
    {
        int i = 0;
        for(i = 0; i < btn.size(); i++)
        {
            if(!btn[i].ID.compare(name))
                return i;
        }

        return -1;
    }

    QPushButton* returnButtonByName(QString name)
    {
        int i = 0;
        for(i = 0; i < btn.size(); i++)
        {
            if(!btn[i].ID.compare(name))
                return btn[i].btn;
        }

        return NULL;
    }

    std::vector<btnID> btn;
private:
    void paintEvent(QPaintEvent *)
    {
        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }
};



#endif // SMARTGRAPHICSVIEW_H
