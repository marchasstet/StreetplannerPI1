#include "city.h"
#include <QGraphicsView>
#include <QGraphicsView>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QGraphicsTextItem>
    City::City(QString initName,int initX,int initY):name(initName),x(initX),y(initY) {

    }
    City::~City(void){

    }
    /**
 * @brief Zeichnet die City auf einer QGraphicsScene.
 *
 * Diese Methode erstellt eine grafische Darstellung der City auf der gegebenen QGraphicsScene.
 * Dabei wird ein roter Punkt (Ellipse) an den Koordinaten (x, y) mit einem Durchmesser von 4 Pixeln gezeichnet.
 * Der Name der Stadt wird als Text über dem Punkt positioniert und ebenfalls zur QGraphicsScene hinzugefügt.
 *
 * @param[in,out] scene Die QGraphicsScene, auf der die City gezeichnet wird.
 */
    void City::draw(QGraphicsScene& scene) {
        scene.addEllipse(x, y, 4, 4, QPen(Qt::red), QBrush(Qt::red, Qt::SolidPattern));
        QGraphicsTextItem* stadtName=new QGraphicsTextItem ;
       // stadtName->setDefaultTextColor(Qt::red);
        stadtName->setPos(x+3,y-6);
        stadtName->setPlainText(name);
        scene.addItem(stadtName);
        qDebug()<<"draw City works";
    }
    QString City::getName(){return name;}
    int City::getX(){return x;}
    int City::getY(){return y;}
