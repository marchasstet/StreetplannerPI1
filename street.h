#ifndef STREET_H
#define STREET_H

#include "city.h"
#include <QGraphicsScene>
class Street
{
public:
    Street(City*, City*);
    virtual void draw(QGraphicsScene& scene) const;
    virtual void drawRed(QGraphicsScene& scene) const;
    bool verbundeneStaedte(QList<City*>&cityListe)const;
    int getLength() const;
    City* getOppositeCity(const City* city) const;
    bool connectsCity(const City* city) const;
    City* getCity2();
    City* getCity1();
private:
    City* city1;
    City* city2;

};

#endif // STREET_H
