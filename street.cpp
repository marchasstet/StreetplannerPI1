#include "street.h"
#include "city.h"
#include <QtMath>

Street::Street(City* intiCity1,City* intitCity2):city1(intiCity1),city2(intitCity2) {}
//Streets::~Streets() {}

/**
 * @brief Draws the street between two cities on the QGraphicsScene.
 *
 * This method draws a line representing the street between two cities
 * on the provided QGraphicsScene. The line is drawn with a blue color
 * and a width of 2 pixels.
 *
 * @param scene The QGraphicsScene where the street will be drawn.
 */
void Street::draw(QGraphicsScene& scene) const{
    QPen pen;
    pen.setColor(Qt::blue);
    pen.setWidth(2);
    scene.addLine((city1->getX()),(city1->getY()),(city2->getX())+3,(city2->getY())+3,pen);
}
/**
 * @brief Draws the street between two cities in red color on the QGraphicsScene.
 *
 * This method draws a line representing the street between two cities
 * on the provided QGraphicsScene. The line is drawn with a red color
 * and a width of 2 pixels.
 *
 * @param scene The QGraphicsScene where the red street will be drawn.
 */
void Street::drawRed(QGraphicsScene& scene) const{
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(2);
    scene.addLine((city1->getX()),(city1->getY()),(city2->getX())+3,(city2->getY())+3,pen);
}
/**
 * @brief Checks if the street connects two cities from a given city list.
 *
 * This method checks if the street connects two cities from the provided city list.
 * It returns true if the street connects two distinct cities (city1 and city2) from
 * the list. If city1 is connected to city2 directly or vice versa, it considers them
 * connected.
 *
 * @param cityListe The list of cities to check connectivity against.
 * @return true if the street connects two distinct cities from the list, false otherwise.
 */
bool Street::verbundeneStaedte(QList<City*>&cityListe)const{
    if(city1==city2){return false;}
    City* exist=nullptr;
    for(auto city:cityListe){
        if(city==city1 && exist == city2){
            return true;
        }
        else if(city==city1){
            exist=city1;
        }
        else if(city==city2&&exist==city1){
            return true;
        }
        else if(city==city2){
            exist=city2;
        }
    }
    return false;
}
/**
 * @brief Get the opposite city connected by this street.
 *
 * Given one city connected by this street, this method returns the opposite city.
 * If the provided city is city1, it returns city2, and vice versa. If the provided
 * city is not connected by this street, it returns nullptr.
 *
 * @param city The city for which to find the opposite connected city.
 * @return The opposite city connected by this street, or nullptr if city is not connected.
 */
City* Street::getOppositeCity(const City* city) const {
    if (city == city1) return city2;
    else if (city == city2) return city1;
    else return nullptr;
}
/**
 * @brief Get the length of the street.
 *
 * Calculates and returns the Euclidean distance between the two cities connected
 * by this street.
 *
 * @return The length of the street as an integer.
 */
int Street::getLength() const {
    int xDiff = city1->getX() - city2->getX();
    int yDiff = city1->getY() - city2->getY();

    return qSqrt(xDiff*xDiff + yDiff*yDiff);
}
/**
 * @brief Check if the street connects a specific city.
 *
 * Determines whether the street connects to the given city.
 *
 * @param city Pointer to the city to check connection with.
 * @return True if the street connects to the city, false otherwise.
 */
bool Street::connectsCity(const City* city) const {
    return city == city1 || city == city2;
}
/**
 * @brief Get the first city connected by the street.
 *
 * This method returns a pointer to the first city connected by the street.
 *
 * @return Pointer to the first city connected by the street.
 */
City* Street::getCity1(){return city1;}
