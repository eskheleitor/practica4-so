#ifndef INTERPOLACION_H
#define INTERPOLACION_H
#include <vector>
using namespace std;
//Convierte una matriz de un tamaño a otro
//utilizando interpolacion bilineal
vector<vector<float>> interpolarBilineal(
    const vector<vector<int>>& matrizOriginal,
    int nuevoAncho,
    int nuevoAlto
);
#endif