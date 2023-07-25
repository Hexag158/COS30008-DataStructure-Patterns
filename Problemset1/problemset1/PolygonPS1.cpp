#include "Polygon.h"

#include <stdexcept>

using namespace std;

float Polygon::getSignedArea() const {
    
    float result = 0.0f; 

    for (int i = 0; i < fNumberOfVertices;i++) {
        int j = (i + 1) % fNumberOfVertices;
        result += fVertices[j].getX() * fVertices[i].getY() - fVertices[j].getY() * fVertices[i].getX();
    }
    return result / 2;
}