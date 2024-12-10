#pragma once

#include "bigtown.h"
#include "city.h"

#include <QGraphicsView>
#include <QGraphicsView>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QGraphicsTextItem>
BigTown::BigTown(QString name,int x,int y):City(name,x,y) {

}
/**
 * @brief Zeichnet die BigTown auf einer QGraphicsScene.
 *
 * Diese Methode erstellt eine grafische Darstellung der BigTown auf der gegebenen QGraphicsScene.
 * Dabei wird ein roter Kreis (Ellipse) an den Koordinaten (x, y) mit einem Durchmesser von 6 Pixeln gezeichnet.
 * Der Name der Stadt wird als Text über der Ellipse positioniert und ebenfalls zur QGraphicsScene hinzugefügt.
 *
 * @param[in,out] scene Die QGraphicsScene, auf der die BigTown gezeichnet wird.
 */
void BigTown::draw(QGraphicsScene& scene)  {

    scene.addEllipse(x, y, 6, 6, QPen(Qt::red), QBrush(Qt::red, Qt::SolidPattern));
    QGraphicsTextItem* stadtName=new QGraphicsTextItem ;
    // stadtName->setDefaultTextColor(Qt::red);
    stadtName->setPos(x+3,y-6);
    stadtName->setPlainText(name);
    scene.addItem(stadtName);
    qDebug()<<"Draw Bigtwon works";

}
