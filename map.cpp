#include "map.h"
#include <QGraphicsView>
#include <QGraphicsView>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QList>
#include "street.h"
Map::Map(): cities(QList<City*>())  {

}
/**
 * @brief Fügt eine Stadt zur Liste der Städte hinzu.
 *
 * Diese Methode fügt eine übergebene Stadt zur Liste der Städte (`cities`) der Karte hinzu.
 * Nachdem die Stadt hinzugefügt wurde, wird eine Debug-Nachricht ausgegeben, die bestätigt,
 * dass die Stadt erfolgreich zur Liste hinzugefügt wurde.
 *
 * @param city Ein Zeiger auf die Stadt, die hinzugefügt werden soll.
 *
 * @note Diese Methode geht davon aus, dass `city` gültig ist und nicht nullptr ist.
 * Die Methode aktualisiert die interne Liste der Städte (`cities`) und gibt eine Debug-Nachricht
 * aus, die den Namen der hinzugefügten Stadt enthält.
 */
void Map::addCity(City* city){
    cities.append(city);

   QString str1= city->getName();

    qDebug()<<QString("City %1 added to List").arg(str1);

}
/**
 * @brief Zeichnet alle Straßen und Städte auf der übergebenen QGraphicsScene.
 *
 * Diese Methode löscht zunächst alle vorhandenen Objekte auf der gegebenen QGraphicsScene
 * und zeichnet dann alle Straßen und Städte, die in der Map enthalten sind.
 * Zusätzlich werden alle markierten Straßen in roter Farbe gezeichnet, falls vorhanden.
 *
 * @param scene Eine Referenz auf die QGraphicsScene, auf der die Objekte gezeichnet werden sollen.
 *
 * @note Diese Methode geht davon aus, dass die QGraphicsScene `scene` gültig ist und dass die
 * Objekte in der `streets`, `highlightedStreets` und `cities` Listen gültige Objekte sind.
 * Vor dem Zeichnen werden alle vorhandenen Objekte auf der Szene gelöscht.
 */
void Map::draw(QGraphicsScene &scene) const{
    scene.clear();

    // Draw all streets

    for(auto is = streets.begin(); is != streets.end(); is++)
    {
        (*is)->draw(scene);
    }
    for (auto street : this->highlightedStreets) {//djkistra makierte straße
        street->drawRed(scene);
    }

    // Draw all cities

    for(auto ic = cities.begin(); ic != cities.end(); ic++)
    {
        (*ic)->draw(scene);
    }
}
/**
 * @brief Fügt eine Straße zur Liste der Straßen hinzu, wenn sie gültige Städte verbindet.
 *
 * Diese Methode versucht, eine übergebene Straße zur Liste der Straßen (`streets`) der Karte hinzuzufügen,
 * vorausgesetzt, dass die Straße gültige Städte verbindet, die bereits auf der Karte vorhanden sind.
 * Wenn die Straße erfolgreich hinzugefügt wird, wird eine Debug-Nachricht ausgegeben, die dies bestätigt.
 * Andernfalls wird eine Fehlermeldung ausgegeben, dass die Straße keine gültigen Städte verbindet.
 *
 * @param strasse Ein Zeiger auf die Straße, die hinzugefügt werden soll.
 * @return true, wenn die Straße erfolgreich hinzugefügt wurde, sonst false.
 *
 * @note Diese Methode geht davon aus, dass `strasse` gültig ist und nicht nullptr ist.
 * Sie überprüft, ob die Straße gültige Städte verbindet, die bereits auf der Karte vorhanden sind,
 * indem sie die Methode `verbundeneStaedte()` der Straße verwendet.
 * Die Methode gibt true zurück, wenn die Straße erfolgreich hinzugefügt wurde, andernfalls false.
 */
bool Map::addStreet(Street* strasse)  {
    if (strasse->verbundeneStaedte(cities)) {
        streets.append(strasse);
        qDebug()<<"strasse erlogreich hinzugefüegt";
        return true;
    } else {
        qDebug() << "Die Straße verbindet keine Städte, die auf der Map sind.";
        return false;
    }
}
/**
 * @brief Gibt eine Liste von Städten zurück, die durch Straßen verbunden sind.
 *
 * Diese Methode durchsucht alle Städte auf der Karte und prüft, ob jede Stadt durch
 * mindestens eine der vorhandenen Straßen verbunden ist. Wenn eine Stadt durch eine Straße
 * verbunden ist, wird sie zur Liste `citiesWithStreets` hinzugefügt.
 *
 * @return Eine QList<City*> mit den Städten, die durch Straßen verbunden sind.
 *
 * @note Diese Methode geht davon aus, dass die Liste der Städte (`cities`) und die Liste der Straßen (`streets`)
 *       gültige Werte enthalten und nicht leer sind.
 *       Sie verwendet die Methode `connectsCity()` der Straße, um zu überprüfen, ob eine Straße die Stadt verbindet.
 */
QList<City*> Map::getCitiesWithStreets() const {
    QList<City*> citiesWithStreets;

    for (auto city : cities) {
        for (auto street : streets) {
            if (street->connectsCity(city)) {
                citiesWithStreets.append(city);
                break;
            }
        }
    }
    return citiesWithStreets;
}
QList<City*> Map::getCities() const{
    return cities;
}
/**
 * @brief Sucht eine Stadt in der Karte anhand des Stadtnamens.
 *
 * Diese Methode durchläuft alle Städte auf der Karte und vergleicht den Namen
 * jeder Stadt mit dem übergebenen `cityName`. Wenn eine Übereinstimmung gefunden wird,
 * wird ein Zeiger auf die entsprechende Stadt zurückgegeben.
 *
 * @param cityName Der Name der Stadt, die gesucht wird.
 * @return Ein Zeiger auf die Stadt, falls sie gefunden wird, ansonsten NULL.
 */
City* Map::findCity(const QString cityName) const {

    for(auto ic = cities.begin(); ic != cities.end(); ic++)
    {
        // Found it ?
        if( (*ic)->getName() == cityName )
        {
            return (*ic);
        }
    }
    return NULL; // not found
}
/**
 * @brief Gibt eine Liste von Straßen zurück, die mit der angegebenen Stadt verbunden sind.
 *
 * Diese Methode durchläuft alle Straßen auf der Karte und überprüft, ob jede Straße
 * mit der angegebenen Stadt (`city`) verbunden ist. Wenn eine Straße die Stadt verbindet,
 * wird sie zur Liste `returnList` hinzugefügt.
 *
 * @param city Ein Zeiger auf die Stadt, für die die Liste der verbundenen Straßen zurückgegeben werden soll.
 * @return Ein QVector<Street*> mit den Straßen, die mit der angegebenen Stadt verbunden sind.
 *
 * @note Diese Methode geht davon aus, dass die Liste der Straßen (`streets`) gültige Werte enthält und nicht leer ist.
 *       Sie verwendet die Methode `connectsCity()` der Straße, um zu überprüfen, ob eine Straße die Stadt verbindet.
 */
QVector<Street*> Map::getStreetList(const City* city) const {
    // Alias für List =)
    QVector<Street*> returnList;

    for (auto street : streets) {
        if (street->connectsCity(city)) returnList.append(street);
    }
    return returnList;
}
/**
 * @brief Gibt die gegenüberliegende Stadt einer gegebenen Straße zurück.
 *
 * Diese Methode ruft die Methode `getOppositeCity()` der übergebenen Straße (`street`) auf,
 * um die gegenüberliegende Stadt zur angegebenen Stadt (`city`) zu erhalten.
 *
 * @param street Ein Zeiger auf die Straße, für die die gegenüberliegende Stadt gefunden werden soll.
 * @param city Ein Zeiger auf die Stadt, deren gegenüberliegende Stadt gesucht wird.
 * @return Ein Zeiger auf die gegenüberliegende Stadt, oder nullptr, wenn die Straße nicht mit der angegebenen Stadt verbunden ist.
 *
 * @note Diese Methode geht davon aus, dass die übergebene Straße (`street`) gültig ist und eine Verbindung zu `city` hat.
 *       Die Gültigkeit der übergebenen Parameter wird nicht überprüft.
 */
City* Map::getOppositeCity(const Street* street, const City* city) const {
    return street->getOppositeCity(city);
}
/**
 * @brief Retrieves the length of the specified street.
 *
 * This method calls the `getLength()` method of the provided street (`street`)
 * to obtain the length of the street.
 *
 * @param street A pointer to the street for which the length is to be retrieved.
 * @return The length of the street.
 *
 * @note This method assumes that the provided street (`street`) is valid.
 *       It does not validate the parameters passed to it.
 */
double Map::getLength(const Street* street) const {
    return street->getLength();
}
/**
 * @brief Sets the list of streets to be highlighted on the map.
 *
 * This method replaces the current list of highlighted streets with a new list
 * provided as an argument.
 *
 * @param newStreets The new list of streets to highlight.
 */
void Map::setHighlightedStreets(QList<Street*> newStreets) {
    this->highlightedStreets = newStreets;
}

Map::~Map(void){

}
