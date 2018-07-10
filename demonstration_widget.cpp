#include "demonstration_widget.h"
#include "ui_demonstration_widget.h"



Demonstration_Widget::Demonstration_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Demonstration_Widget)
{
    ui->setupUi(this);

    step1 = 0;
    step2 = 0;
    step3 = 0;

    widthscale = 1;
    heightscale = 1;
    label_w_scale = 1;
    label_h_scale = 1;


    init_Widght_width = this->width();
    init_Widght_height = this->height();

    pos_x = 971;
    pos_y = 125;
//    QPalette palette;
//    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/pic/map2.png")));
//    this->setPalette(palette);
//    this->resize( QPixmap(":/pic/map2.png").size() );
//    this->setAutoFillBackground(true);

    //港口
    image_port.load(":/pic/port.png");
    image_port = image_port.scaled(50,50,Qt::IgnoreAspectRatio);
    port1 = new QLabel(this);
    port1->setPixmap( QPixmap(QPixmap::fromImage(image_port)) );
    port1->setScaledContents(true);
    port1->resize(image_port.width()/2,image_port.height()/2);
    port1->move(972,167);  //青岛港

    port2 = new QLabel(this);
    port2->setPixmap( QPixmap(QPixmap::fromImage(image_port)) );
    port2->setScaledContents(true);
    port2->resize(image_port.width()/2,image_port.height()/2);
    port2->move(1004,332); //上海港

    port3 = new QLabel(this);
    port3->setPixmap( QPixmap(QPixmap::fromImage(image_port)) );
    port3->setScaledContents(true);
    port3->resize(image_port.width()/2,image_port.height()/2);
    port3->move(1200,265); //福冈港

    //潜艇
    image_submarine.load(":/pic/submarine_to_right.png");
    //image_submarine = image_submarine.scaled(100, 62, Qt::IgnoreAspectRatio);
    pic_label = new QLabel(this);
    pic_label->setPixmap(QPixmap::fromImage(image_submarine));
    pic_label->setScaledContents(true);
    pic_label->resize(image_submarine.width()/13*label_w_scale, image_submarine.height()/13*label_h_scale);
    pic_label->move(pos_x,pos_y);

    pathselect = 0;//初始化为未选择路径
    //path1to2Init();

    animat_timer = new QTimer(this);
    connect(animat_timer, SIGNAL(timeout()), this, SLOT(move_label()));

    connect(ui->PB_start,SIGNAL(pressed()),this,SLOT(on_actionstart_triggered()));
    connect(ui->PB_stop,SIGNAL(pressed()),this,SLOT(on_actionstop_triggered()));
    connect(ui->PB_path,SIGNAL(pressed()),this,SLOT(on_actionpath_triggered()));

}

Demonstration_Widget::~Demonstration_Widget()
{
    delete ui;
}


//定时器溢出槽函数
void Demonstration_Widget::move_label()
{
  if(pathselect==0)
      return;
  if(pathselect==1)
      test_move();
      //path1to2();
      //Linear_inter_1to2();
  if(pathselect==2)
      path2to3();
  if(pathselect==3)
      path1to3();
}

void Demonstration_Widget::on_actionstart_triggered()
{
    animat_timer->start(50);
}

void Demonstration_Widget::on_actionstop_triggered()
{
    if(animat_timer->isActive())
        animat_timer->stop();
}

void Demonstration_Widget::mousePressEvent(QMouseEvent *event)
{
    int x = event->pos().x();
    int y = event->pos().y();
    qDebug() << "x:"<< x << " " << "y:" <<y;
}

//天津-》上海
void Demonstration_Widget::path1to2()
{
    if(step1==0)
    {
        if(pos_x>=1045)
            step1=1;

        pos_x+=2;
        image_submarine.load(":/pic/submarine_to_right.png");
        image_submarine = image_submarine.scaled(100, 62, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/2, image_submarine.height()/2);

        pic_label->move(pos_x,pos_y);
        //qDebug()<<"当前潜艇坐标："<< "x:" << pos_x << "y:"<< pos_y;
    }
    else if(step1==1)
    {
        if(pos_y>=332)
            step1=2;

        pos_y+=2;
        image_submarine.load(":/pic/submarine_to_down.png");
        image_submarine = image_submarine.scaled(62, 100, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/2, image_submarine.height()/2);
        pic_label->move(pos_x,pos_y);
    }
    else if(step1==2)
    {
        if(pos_x<=1024)
            step1=3;

        pos_x-=2;
        image_submarine.load(":/pic/submarine_to_left.png");
        image_submarine = image_submarine.scaled(100, 62, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/2, image_submarine.height()/2);

        pic_label->move(pos_x,pos_y);
    }
    //qDebug() << "当前潜艇坐标：" << "x:" << pos_x << "y:"<< pos_y;
}

//天津-》日本
void Demonstration_Widget::path1to3()
{
    if(step3==0)
    {
        if(pos_x>=1045)
            step3=1;

        pos_x+=2;
        image_submarine.load(":/pic/submarine_to_right.png");
        image_submarine = image_submarine.scaled(100, 62, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/2, image_submarine.height()/2);

        pic_label->move(pos_x,pos_y);
        //qDebug()<<"当前潜艇坐标："<< "x:" << pos_x << "y:"<< pos_y;
    }
    else if(step3==1)
    {
        if(pos_y>=295)
            step3=2;

        pos_y+=2;
        image_submarine.load(":/pic/submarine_to_down.png");
        image_submarine = image_submarine.scaled(62, 100, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/2, image_submarine.height()/2);
        pic_label->move(pos_x,pos_y);
    }
    else if(step3==2)
    {
        if(pos_x>=1130)
            step3=3;

        pos_x+=2;
        image_submarine.load(":/pic/submarine_to_right.png");
        image_submarine = image_submarine.scaled(100, 62, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/2, image_submarine.height()/2);

        pic_label->move(pos_x,pos_y);
    }
    else if(step3==3)
    {
        if(pos_y<=260)
            step3=4;

        pos_y-=2;
        image_submarine.load(":/pic/submarine_to_up.png");
        image_submarine = image_submarine.scaled(100, 62, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/2, image_submarine.height()/2);

        pic_label->move(pos_x,pos_y);
    }
    else if(step3==4)
    {
        if(pos_x<=1175)
            step3=5;

        pos_x+=2;
        image_submarine.load(":/pic/submarine_to_right.png");
        image_submarine = image_submarine.scaled(100, 62, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/2, image_submarine.height()/2);

        pic_label->move(pos_x,pos_y);
    }
}

//上海-》日本
void Demonstration_Widget::path2to3()
{
    if(step2==0)
    {
        if(pos_x>=1150)
            step2=1;

        pos_x+=2;
        image_submarine.load(":/pic/submarine_to_right.png");
        image_submarine = image_submarine.scaled(100, 62, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/2, image_submarine.height()/2);

        pic_label->move(pos_x,pos_y);
    }
    else if(step2==1)
    {
        if(pos_y<=260)
            step2=2;

        pos_y-=2;
        image_submarine.load(":/pic/submarine_to_up.png");
        image_submarine = image_submarine.scaled(62, 100, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/2, image_submarine.height()/2);

        pic_label->move(pos_x,pos_y);
    }
    else if(step2==2)
    {
        if(pos_x>=1150)
            step2=3;

        pos_x+=2;
        image_submarine.load(":/pic/submarine_to_right.png");
        image_submarine = image_submarine.scaled(100, 62, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/2, image_submarine.height()/2);

        pic_label->move(pos_x,pos_y);
    }
}

void Demonstration_Widget::on_actionpath_triggered()
{
    PathDialog *path_dialog = new PathDialog();
    connect(path_dialog, SIGNAL(pathSelected(int)), this, SLOT(pathset(int)) );
    path_dialog->setModal(true);
    path_dialog->show();
}

void Demonstration_Widget::pathset(int path)
{   
    qDebug()<<"path:"<<path<<"is selected";
    pathselect = path;
    if( pathselect ==1 )
    {
        step1=0;
        pathselect = 1;
        pos_x = 971;
        pos_y = 125;
        pic_label->move(pos_x,pos_y);
        qDebug() << "当前路线：" << pathselect << endl;
        qDebug() << "路线1初始潜艇坐标：" << "x:" << pos_x << "y:"<< pos_y;
    }
    if( pathselect ==2 )
    {
        step2=0;
        pathselect = 2;
        pos_x = 1021;
        pos_y = 335;
        pic_label->move(pos_x,pos_y);
        qDebug() << "当前路线：" << pathselect << endl;
        qDebug() << "路线2初始潜艇坐标：" << "x:" << pos_x << "y:"<< pos_y;
    }
    if(pathselect ==3)
    {
        step3=0;
        pathselect = 3;
        pos_x = 971;
        pos_y = 125;
        pic_label->move(pos_x,pos_y);
        qDebug() << "当前路线：" << pathselect << endl;
        qDebug() << "路线2初始潜艇坐标：" << "x:" << pos_x << "y:"<< pos_y;
    }
}


void Demonstration_Widget::paintEvent(QPaintEvent *event)
{
    QPixmap pixmap = QPixmap(":/pic/map2.png").scaled(this->size());
    QPainter painter(this);
    painter.drawPixmap(pixmap.rect(), pixmap);

    widthscale = (double)pixmap.width() / QPixmap(":/pic/map2.png").width() ;
    heightscale = (double)pixmap.height() / QPixmap(":/pic/map2.png").height() ;

    //qDebug()<<"widthscale:"<<widthscale<<"   heightscale:" << heightscale;

    port1->move(972*widthscale,167*heightscale); //青岛港
    port2->move(1004*widthscale,332*heightscale); //上海港
    port3->move(1200*widthscale,265*heightscale); //福冈港
//    pic_label->resize(image_submarine.width()/10*label_w_scale, image_submarine.height()/10*label_h_scale);
    pic_label->move(pos_x*widthscale,pos_y*heightscale); //潜艇

//    cs = coordinate_convert(pos_x,pos_y);
//    qDebug()<<"当前潜艇经度："<< cs.longitude << "纬度"<< cs.latitude;
}

void Demonstration_Widget::resizeEvent(QResizeEvent *event)
{
    label_w_scale = ((double)this->width())/ init_Widght_width;
    label_h_scale = ((double)this->height())/ init_Widght_height;

    port1->resize( image_port.width()/2*label_w_scale, image_port.height()/2*label_h_scale );
    port2->resize( image_port.width()/2*label_w_scale, image_port.height()/2*label_h_scale );
    port3->resize( image_port.width()/2*label_w_scale, image_port.height()/2*label_h_scale );

    pic_label->resize(image_submarine.width()/13*label_w_scale, image_submarine.height()/13*label_h_scale);
}


//使用线性插值来移动
void Demonstration_Widget::Linear_inter_1to2()
{
    if(step1==0)
    {
        if(pos_x>=1045)
            step1=1;

        pos_x+=2;
        image_submarine.load(":/pic/submarine_to_right.png");
        image_submarine = image_submarine.scaled(100, 62, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/2, image_submarine.height()/2);

        pic_label->move(pos_x,pos_y);
        //qDebug()<<"当前潜艇坐标："<< "x:" << pos_x << "y:"<< pos_y;
    }
    else if(step1==1)
    {
        if(pos_y>=186)
            step1=2;

        pos_y+=2;
        image_submarine.load(":/pic/submarine_to_down.png");
        image_submarine = image_submarine.scaled(62, 100, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/2, image_submarine.height()/2);
        pic_label->move(pos_x,pos_y);
    }
    else if(step1==2)
    {
//        int DX = abs(1024-pos_x);
//        int DY = abs(332-pos_y);

        qDebug()<<"当前潜艇坐标："<< "x:" << pos_x << "y:"<< pos_y;

        if(pos_x<1024 && pos_y>=332)
            step1=3;

        if(pos_x>1024 && pos_y<332)
        {
            pos_x-=1;
            pos_y+=1;
            image_submarine.load(":/pic/submarine_to_LD.png");
            image_submarine = image_submarine.scaled(100, 100, Qt::IgnoreAspectRatio);
            pic_label->setPixmap(QPixmap::fromImage(image_submarine));
            pic_label->resize(image_submarine.width()/2, image_submarine.height()/2);
            pic_label->move(pos_x,pos_y);
        }
        else if(pos_x<=1024 && pos_y<332)
        {
            pos_y+=2;
            image_submarine.load(":/pic/submarine_to_down.png");
            image_submarine = image_submarine.scaled(62, 100, Qt::IgnoreAspectRatio);
            pic_label->setPixmap(QPixmap::fromImage(image_submarine));
            pic_label->resize(image_submarine.width()/2, image_submarine.height()/2);
            pic_label->move(pos_x,pos_y);

        }
        else if( pos_x>=1024 && pos_y>=332 )
        {
            pos_x -= 2;
            image_submarine.load(":/pic/submarine_to_left.png");
            image_submarine = image_submarine.scaled(100, 62, Qt::IgnoreAspectRatio);
            pic_label->setPixmap(QPixmap::fromImage(image_submarine));
            pic_label->resize(image_submarine.width()/2, image_submarine.height()/2);

            pic_label->move(pos_x,pos_y);
        }

        //线性插值
//        if(DX>DY)
//        {
//            pos_x-=1;
//            image_submarine.load(":/pic/submarine_to_LD.png");
//            image_submarine = image_submarine.scaled(100, 62, Qt::IgnoreAspectRatio);
//            pic_label->setPixmap(QPixmap::fromImage(image_submarine));
//            pic_label->resize(image_submarine.width()/2, image_submarine.height()/2);
//        }
//        else
//        {
//            pos_y+=1;
//            image_submarine.load(":/pic/submarine_to_LD.png");
//            image_submarine = image_submarine.scaled(62, 100, Qt::IgnoreAspectRatio);
//            pic_label->setPixmap(QPixmap::fromImage(image_submarine));
//            pic_label->resize(image_submarine.width()/2, image_submarine.height()/2);

//            pic_label->move(pos_x,pos_y);
//        }
    }
}

//将坐标值转换为经纬度值
coordinate_s Demonstration_Widget::coordinate_convert(int x, int y)
{
    this->width();
    double dx = ((double)Right_longitude - Left_longitude)/QPixmap(":/pic/map2.png").width();
    double dy = ((double)Top_latitude - Bottom_latitude)/QPixmap(":/pic/map2.png").height();

    qDebug()<<"dx="<<dx<<"dy="<<dy<<endl;

    coordinate_s temp_s;
    temp_s.longitude = (double)Left_longitude +  x * dx;
    temp_s.latitude = (double)Top_latitude - y * dy;

    return temp_s;
}

//label移动到（end_x，end_y）
void Demonstration_Widget::label_moveto(int end_x, int end_y)
{
    if(pos_x==end_x && pos_y==end_y)
        return;

    //向右斜下方移动
    if( pos_x<end_x &&  pos_y<end_y)
    {
        image_submarine.load(":/pic/submarine_to_RD.png");
        //image_submarine = image_submarine.scaled(50, 50, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/13 *label_w_scale, image_submarine.height()/13*label_h_scale);

        if(pos_x==end_x && pos_y==end_y)
            return;

        //采用线性插值
        int DX = abs(end_x-pos_x);
        int DY = abs(end_y-pos_y);

        if(DX>DY)
             pos_x+=1;
        else
              pos_y+=1;

        pic_label->move(pos_x,pos_y);

    }


    //向右斜上方移动
    if( pos_x<end_x &&  pos_y>end_y)
    {
        image_submarine.load(":/pic/submarine_to_RU.png");
        //image_submarine = image_submarine.scaled(50, 50, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/13 *label_w_scale, image_submarine.height()/13*label_h_scale);

        if(pos_x==end_x && pos_y==end_y)
            return;

         //采用线性插值
         int DX = abs(end_x-pos_x);
         int DY = abs(end_y-pos_y);

         if(DX>DY)
              pos_x+=1;
         else
              pos_y-=1;

         pic_label->move(pos_x,pos_y);
    }

    //向左斜上方移动
    if( pos_x>end_x &&  pos_y>end_y)
    {
        image_submarine.load(":/pic/submarine_to_LU.png");
        //image_submarine = image_submarine.scaled(50, 50, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/13 *label_w_scale, image_submarine.height()/13*label_h_scale);

        if(pos_x==end_x && pos_y==end_y)
            return;

         //采用线性插值
         int DX = abs(end_x-pos_x);
         int DY = abs(end_y-pos_y);

         if(DX>DY)
              pos_x-=1;
         else
              pos_y-=1;

         pic_label->move(pos_x,pos_y);

    }

    //向左斜下方移动
    if( pos_x>end_x &&  pos_y<end_y)
    {
        image_submarine.load(":/pic/submarine_to_LD.png");
        //image_submarine = image_submarine.scaled(50, 50, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/13 *label_w_scale, image_submarine.height()/13*label_h_scale);

        if(pos_x==end_x && pos_y==end_y)
            return;

         //采用线性插值
         int DX = abs(end_x-pos_x);
         int DY = abs(end_y-pos_y);

         if(DX>DY)
              pos_x-=1;
         else
              pos_y+=1;

         pic_label->move(pos_x,pos_y);

    }

    //向上方移动
    if( pos_x==end_x &&  pos_y>end_y)
    {
        image_submarine.load(":/pic/submarine_to_up.png");
        //image_submarine = image_submarine.scaled(43, 69, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/13 *label_w_scale, image_submarine.height()/13*label_h_scale);

        if(pos_y==end_y)
            return;

         pos_y--;
         pic_label->move(pos_x,pos_y);
    }

    //向下方移动
    if( pos_x==end_x &&  pos_y<end_y)
    {
        image_submarine.load(":/pic/submarine_to_down.png");
        //image_submarine = image_submarine.scaled(43, 69, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/13 *label_w_scale, image_submarine.height()/13*label_h_scale);

        if(pos_y==end_y)
            return;

         pos_y++;
         pic_label->move(pos_x,pos_y);

    }

    //向左移动
    if( pos_x>end_x &&  pos_y==end_y)
    {
        image_submarine.load(":/pic/submarine_to_left.png");
        //image_submarine = image_submarine.scaled(55, 34, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/13 *label_w_scale, image_submarine.height()/13*label_h_scale);

        if(pos_x==end_x)
            return;

         pos_x--;
         pic_label->move(pos_x,pos_y);

    }

    //向右移动
    if( pos_x<end_x &&  pos_y==end_y)
    {
        image_submarine.load(":/pic/submarine_to_right.png");
        //image_submarine = image_submarine.scaled(55, 34, Qt::IgnoreAspectRatio);
        pic_label->setPixmap(QPixmap::fromImage(image_submarine));
        pic_label->resize(image_submarine.width()/13 *label_w_scale, image_submarine.height()/13*label_h_scale);

        if(pos_x==end_x)
            return;

         pos_x++;
         pic_label->move(pos_x,pos_y);
    }
}


void Demonstration_Widget::test_move()
{
    label_moveto(0,0);
}
