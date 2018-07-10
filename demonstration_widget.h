#ifndef DEMONSTRATION_WIDGET_H
#define DEMONSTRATION_WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QImage>
#include <QLabel>
#include <QTimer>
#include <QList>
#include <QPoint>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QDebug>
#include <QPainter>
#include "sub_GUI/pathdialog.h"
#include "sub_GUI/automodedialog.h"
#include "sub_GUI/manualdialog.h"
#include "sub_GUI/datashowdialog.h"

namespace Ui {
class Demonstration_Widget;
}

#define Left_longitude 77.07
#define Right_longitude 141.42
#define Top_latitude 45.82
#define Bottom_latitude 4.18

#define Fix_re 20  //潜艇图标固定缩小比例  该值越大则显示的图标越小

struct coordinate_s{
    double longitude;
    double latitude;
};

class Demonstration_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Demonstration_Widget(QWidget *parent = 0);
    ~Demonstration_Widget();

private:
    Ui::Demonstration_Widget *ui;
    QImage image_submarine;
    QImage image_port;

    QTimer *animat_timer;
    int pos_x; //潜艇x坐标
    int pos_y; //潜艇y坐标

    //选择的路线 0:未选择 1：青岛港-》上海港 2：上海-》日本
    int pathselect;

    QLabel *port1; //青岛港
    QLabel *port2; //上海港
    QLabel *port3; //福冈港
    QLabel *pic_label; //潜艇

    coordinate_s coordinate_convert(int x,int y);//将坐标值转换为经纬度值
    coordinate_s cs; //保存经纬度值的结构体

    QAction* firstfaultaction;
    QAction* secondfaultaction;

    int step1;
    int step2;
    int step3;

    double widthscale;
    double heightscale;
    double label_w_scale;
    double label_h_scale;

    int init_Widght_width; //初始的窗口宽度
    int init_Widght_height; //初始的窗口高度

    void path1to2(); //天津-》上海
    void path2to3(); //上海-》日本
    void path1to3(); //天津-》日本

    //label移动到（end_x，end_y）
    bool label_moveto(int end_x,int end_y);

protected:
    void mousePressEvent(QMouseEvent *event);

    void paintEvent(QPaintEvent *event);

    void resizeEvent(QResizeEvent *event);


private slots:
    void move_label();
    void on_actionstart_triggered();
    void on_actionstop_triggered();
    void on_actionpath_triggered();
    void pathset(int path);

};

#endif // DEMONSTRATION_WIDGET_H
