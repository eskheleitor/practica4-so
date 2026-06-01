#include "matrix_validator.h"
using namespace std;
// Comprueba que la matriz tenga 16 filas y 16 columnas
bool validarMatriz(const vector<vector<int>>& matriz)
{
    // Comprobar que hay 16 filas
    if(matriz.size()!= 16)
    {
    return false;
    }
    // Comprobar que cada fila tiene 16 columnas
    for(const auto& fila : matriz)
    {
        if(fila.size()!=16) //si la fila es diferente de 16 columnas, la matriz es incorrecta
        {
        return false;
        }
    }
    // si la matriz es correcta
    return true;
}