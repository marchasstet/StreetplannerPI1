#include "smalltown.h"


#include <QGraphicsView>
#include <QGraphicsView>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QGraphicsTextItem>
SmallTown::SmallTown(QString name,int x,int y):City(name,x,y) {

}
/**
 * @brief Draws the SmallTown on the QGraphicsScene.
 *
 * This method draws a representation of the SmallTown as an ellipse with a red border
 * and solid red fill on the provided QGraphicsScene. It also adds the town's name as text
 * above the ellipse.
 *
 * @param scene The QGraphicsScene where the SmallTown will be drawn.
 */
void SmallTown::draw(QGraphicsScene& scene)  {

    scene.addEllipse(x, y, 8,8, QPen(Qt::red), QBrush(Qt::red, Qt::SolidPattern));
    QGraphicsTextItem* stadtName=new QGraphicsTextItem ;
    // stadtName->setDefaultTextColor(Qt::red);
    stadtName->setPos(x+3,y-6);
    stadtName->setPlainText(name);
    scene.addItem(stadtName);
    qDebug()<<"Draw SmallCity works";

}
