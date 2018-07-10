#include "demonstration_widget.h"
#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <QDebug>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    QPixmap pixmap(":/pic/submarine.jpg");
//    QSplashScreen screen(pixmap);
//    screen.show();
//    screen.showMessage("Loading...", Qt::AlignCenter, Qt::red);

#if 0
    QDateTime n=QDateTime::currentDateTime();
    QDateTime now;
    do{
        now=QDateTime::currentDateTime();
        app.processEvents(); //如果不加这一句无法正常工作
    } while (n.secsTo(now)<=1);//1为需要延时的秒数
#endif

    Demonstration_Widget w;
    w.show();

//    screen.finish(&w);

    return app.exec();
}
