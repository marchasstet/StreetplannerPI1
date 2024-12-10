// #include "streets.h"
// #include "city.h"


// Streets::Streets(City* intiCity1,City* intitCity2):city1(intiCity1),city2(intitCity2) {}
// //Streets::~Streets() {}


// void Streets::draw(QGraphicsScene& scene) const{
//     QPen pen;
//     pen.setColor(Qt::blue);
//     pen.setWidth(2);
//     scene.addLine((city1->getX()),(city1->getY()),(city2->getX())+3,(city2->getY())+3,pen);
// }
// void Streets::drawRed(QGraphicsScene& scene) const{
//     QPen pen;
//     pen.setColor(Qt::red);
//     pen.setWidth(2);
//     scene.addLine((city1->getX()),(city1->getY()),(city2->getX())+3,(city2->getY())+3,pen);
// }
// bool Streets::verbundeneStaedte(QList<City*>&cityListe)const{
//     if(city1==city2){return false;}
//     City* exist=nullptr;
//     for(auto city:cityListe){
//         if(city==city1 && exist == city2){
//             return true;
//         }
//         else if(city==city1){
//             exist=city1;
//         }
//         else if(city==city2&&exist==city1){
//             return true;
//         }
//         else if(city==city2){
//             exist=city2;
//         }
//     }
//     return false;
// }
