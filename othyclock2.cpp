#include "othyclock2.h"

// path shapes #################################
// #############################################

void tiretWeekShape(QPainterPath &path)
{
    path.moveTo(-10,0);
    path.lineTo(-10,-10);
    path.lineTo(0,-14);
    path.lineTo(10,-10);
    path.lineTo(10,0);
    path.translate(0,-85);
}

void pointWeekShape(QPainterPath &path)
{
    path.lineTo(-8,0);
    path.lineTo(-8,-10);
    path.lineTo(0,-13);
    path.lineTo(8,-10);
    path.lineTo(8,0);
    path.lineTo(0,0);
}

void tiretHourShape(QPainterPath &path)
{
    path.lineTo(-10,-10);
    path.lineTo(-10,-15);
    path.lineTo(0,-20);
    path.lineTo(10,-15);
    path.lineTo(10,-10);
    path.lineTo(0,0);
    path.translate(0,-45);
}

void arcHourShape(QPainterPath &path)
{
    path.lineTo(-8,0);
    path.lineTo(-8,-3);
    path.lineTo(0,-7);
    path.lineTo(8,-3);
    path.lineTo(8,0);
    path.lineTo(0,0);
    path.translate(0,-55);
}

void needleHourShape(QPainterPath &path)
{
    path.lineTo(-10,-25);
    path.lineTo(-10,-32);
    path.lineTo(-5,-40);
    path.lineTo(5,-40);
    path.lineTo(10,-32);
    path.lineTo(10,-25);
    path.lineTo(0,0);
    path.translate(0,-29);
}

// constructor & destructor ####################
// #############################################
OthyClock2::OthyClock2(QWidget *parent)
    : QWidget(parent)
{
    // set the graphic scene
    //
    QVBoxLayout *layout = new QVBoxLayout();
    //
    scene = new QGraphicsScene(this);
    //
    scene->addText("test");
    //
    QGraphicsView *view = new QGraphicsView(scene);
    //
    setLayout(layout);
    //
    view->show();
    //
    // set the timer
    QTimer *timer = new QTimer(this);
    //connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    //timer->start();
    // title and size of the window
    setWindowTitle("Othy Clock 2");
    setMinimumSize(winWidth,winHeight);
    setMaximumSize(winWidth,winHeight);
    // shapes
    //
    // -- week
    tiretWeekShape(tiretWeekPath);
    pointWeekShape(arcWeekPath);
    arcWeekPath.translate(0,-81);
    pointWeekShape(antiarcWeekPath);
    antiarcWeekPath.translate(0,-75);
    pointWeekShape(needleWeekPath);
    needleWeekPath.translate(0,-83);
    // -- hours
    tiretHourShape(tiretHourPath);
    arcHourShape(arcHourPath);
    needleHourShape(needleHourPath);
    // -- minutes
    //
}

OthyClock2::~OthyClock2()
{
}

// initial paint ###############################
// #############################################


// paint event #################################
// #############################################
/*void OthyClock2::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    // get current date & time
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    // fill the background
    painter.fillRect(0,0,winWidth,winHeight,background);
    // center the clock
    painter.translate(winWidth/2,winHeight/2);
    // set the months ############
    //
    //
    //
    // set the month days ########
    //
    //
    //
    // set the week days #########
    painter.save();
    painter.rotate(180+16*4);
    for (int i = 0;i<7;i++)
    {
        painter.rotate(-16);
        painter.setPen(tiretWeekPen);
        painter.setBrush(tiretWeekBrush);
        painter.drawPath(tiretWeekPath);
        if (i+1 < date.dayOfWeek())
        {
            painter.setPen(arcWeekPen);
            painter.setBrush(arcWeekBrush);
            painter.drawPath(arcWeekPath);
        }
        else if (i+1 == date.dayOfWeek())
        {
            painter.setPen(needleWeekPen);
            painter.setBrush(needleWeekBrush);
            painter.drawPath(needleWeekPath);
        }
        else
        {
            painter.setPen(antiarcWeekPen);
            painter.setBrush(antiarcWeekBrush);
            painter.drawPath(antiarcWeekPath);
        }
    }
    painter.restore();
    // set the hours #############
    // -- tiret
    painter.setPen(tiretHourPen);
    painter.setBrush(tiretHourBrush);
    for (int i = 0;i<12;i++)
    {
        painter.save();
        painter.rotate(30*i);
        painter.drawPath(tiretHourPath);
        painter.restore();
    }
    // -- arc
    painter.setPen(arcHourPen);
    painter.setBrush(arcHourBrush);
    bool afternoon = (time.hour() > 11)? true : false;
    for (int i = 0;i<12;i++)
    {
        if ((afternoon && i>(time.hour()%12)) || (!afternoon && i<time.hour()%12))
        {
            painter.save();
            painter.rotate(30*i);
            painter.drawPath(arcHourPath);
            painter.restore();
        }
    }
    // -- needle
    int hour_rotation = 30*(time.hour()%12);
    painter.setPen(needleHourPen);
    painter.setBrush(needleHourBrush);
    painter.save();
    painter.rotate(hour_rotation);
    painter.drawPath(needleHourPath);
    painter.restore();
    // set the minutes ###########
    // -- tiret
    //painter.setPen(tiretMinPen);
    //for (int i = 0;i<12;i++)
    //{
    //    painter.save();
    //    painter.rotate(30*i);
    //    painter.drawLine(0,-50,0,-62);
    //    painter.restore();
    //}
    // -- anti arc
    //
    painter.rotate(hour_rotation);
    //
    painter.save();
    //
    //
    painter.translate(0,-130);
    painter.drawRect(-10,-10,20,20);
    //
    painter.restore();
    //
    painter.rotate(hour_rotation);
    // set the seconds ###########
    // -- tiret
    //painter.setPen(tiretSecPen);
    //painter.save();
    //for (int i = 0;i<60;i++)
    //{
    //    if (i > 0) painter.rotate(6);
    //    if (i%5 != 0) painter.drawLine(0,-50,0,-60);
    //}
    //painter.restore();
    // -- anti arc
    //
    //
    // -- arc
    //
    //
    // -- needle
    //painter.setPen(needleSecPen);
    //painter.save();
    //painter.rotate(6*time.second());
    //painter.drawLine(0,-20,0,-40);
    //painter.restore();
}*/
