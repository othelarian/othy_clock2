//#include "othyclock2.h"

//#include <QApplication>
#include <QtWidgets>

// colors definitions #########################
// ############################################

QColor fillcolor = QColor(252,224,35);
QColor bordercolor = QColor();
QColor afillcolor = QColor(255,240,50);
QColor abordercolor = QColor();
QColor ifillcolor;
QColor ibordercolor;

// declarations ###############################
// ############################################

void drawTiretHours(QGraphicsScene &scene);

// main function ##############################
// ############################################
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Othy Software");
    QCoreApplication::setApplicationName("Othy Clock 2");
    QCoreApplication::setApplicationName("1.0.0");

    QGraphicsScene scene;
    //
    // TODO : months
    // TODO : days
    // TODO : week days
    //
    drawTiretHours(scene);
    //
    //

    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setBackgroundBrush(QBrush(QColor(0,0,0)));
    view.setBaseSize(600,600);
    view.setMaximumSize(600,600);
    view.setWindowTitle("Othy Clock 2");
    view.show();

    //
    // TODO : timer
    //

    return a.exec();
}

// draw the tiret hours #######################
// ############################################
void drawTiretHours(QGraphicsScene &scene)
{
    //
    //scene.addRect(10,10,10,10,QPen(QColor(0,255,0),2));
    //
    scene.addPath();
    //
}
