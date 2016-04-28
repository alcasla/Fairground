#include "Euclidea.h"

float distanciaEuclidea( float x1, float x2, float y1, float y2 )
{
   float dis = pow(x1-y1, 2) + pow(x2-y2, 2);
   return sqrt(dis);
}
