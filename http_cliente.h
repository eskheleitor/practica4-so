#ifndef HTTP_CLIENTE_H
#define HTTP_CLIENTE_H
#include <vector>
using namespace std;


// Envia una matriz interpolada al servidor Python
bool enviarMatriz(
    int idCaptura,
    const vector<vector<float>>& matriz
);
#endif