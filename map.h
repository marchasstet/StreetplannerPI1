#ifndef MAP_H
#define MAP_H
#include <QGraphicsView>
#include <QGraphicsView>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QList>
#include"city.h"
#include "street.h"
#include "abstractmap.h"
class Map: public AbstractMap
{
public:
    Map();
virtual ~Map(void);
    void addCity(City*)  override;

    bool addStreet(Street*)   override;

    City* findCity(const QString cityName) const override;

    QVector<Street*> getStreetList(const City* city) const override;

   City* getOppositeCity(const Street* street, const City* city) const override;

    double getLength(const Street* street) const override;

    QList<City*> getCitiesWithStreets() const;
    QList<City*> getCities() const;
    void setHighlightedStreets(QList<Street*>);


void draw(QGraphicsScene &scene) const;
private:
QList <City*>cities;
QList <Street*> streets;
QList<Street*> highlightedStreets;
};

#endif // MAP_H
