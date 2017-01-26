#ifndef OTHYCLOCK2_H
#define OTHYCLOCK2_H

#include <QWidget>
#include <QTimer>
#include <QTime>

#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>


#include <QPainter>


//class QGraphicsScene;

class OthyClock2 : public QWidget
{
    Q_OBJECT

private:
    //
    QGraphicsScene *scene;
    //
    //
    // global colors
    //
    const QColor brownPen = QColor(204,85,34);
    //
    const QColor grayBrush = QColor(55,55,55);
    //
    const QColor yellowPen = QColor(255,240,50);
    const QColor yellowBrush = QColor(252,224,35);
    //
    // window size
    const int winWidth = 600;
    const int winHeight = 500;
    // background color
    const QColor background = grayBrush;
    // months
    //
    //
    // days
    //
    // week
    const QPen tiretWeekPen = QPen(brownPen,2);
    const QBrush tiretWeekBrush = QBrush(grayBrush);
    QPainterPath tiretWeekPath;
    const QPen arcWeekPen = QPen(QColor(119,86,10),2);
    const QBrush arcWeekBrush = QBrush(yellowBrush);
    QPainterPath arcWeekPath;
    const QPen antiarcWeekPen = QPen(grayBrush,2);
    const QBrush antiarcWeekBrush = QBrush(QColor(80,80,80));
    QPainterPath antiarcWeekPath;
    const QPen needleWeekPen = QPen(QColor(200,200,200),2);
    const QBrush needleWeekBrush = QBrush(QColor(255,255,255));
    QPainterPath needleWeekPath;
    // hours
    const QPen tiretHourPen = QPen(brownPen,2);
    const QBrush tiretHourBrush = QBrush(QColor(grayBrush));
    QPainterPath tiretHourPath;
    const QPen arcHourPen = QPen(yellowPen,2);
    const QBrush arcHourBrush = QBrush(yellowBrush);
    QPainterPath arcHourPath;
    const QPen needleHourPen = QPen(yellowPen,1);
    const QBrush needleHourBrush = QBrush(yellowBrush);
    QPainterPath needleHourPath;
    // minutes
    //
    const QPen tiretMinPen = QPen(brownPen,2);
    //
    //
    // seconds
    //
    const QPen tiretSecPen = QPen(brownPen,1);
    //
    const QPen needleSecPen = QPen(QColor(255,0,0),4);
    //

private:
    //
    //

public:
    OthyClock2(QWidget *parent = 0);
    ~OthyClock2();

protected:
    //void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};

#endif // OTHYCLOCK2_H
