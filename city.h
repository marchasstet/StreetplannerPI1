#ifndef CITY_H
#define CITY_H
#include <QGraphicsView>
#include <QGraphicsView>
#include <QDebug>
#include <QString>
#include <QMessageBox>
class City
{
public:
    City(QString initName,int initxX, int initY);
    virtual ~City(void);
    virtual void draw(QGraphicsScene& scene);
    QString getName();
    int getX();
    int getY();
protected:
    int x;
    int y;
    QString name;
};

#endif // CITY_H
