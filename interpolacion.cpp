#include "interpolacion.h"

using namespace std;

// Realiza interpolacion bilineal para aumentarl tamaño de una matriz
vector<vector<float>> interpolarBilineal(
    const vector<vector<int>>& matrizOriginal,
    int nuevoAncho,
    int nuevoAlto
)
{
    int filasOriginales=matrizOriginal.size();
    int columnasOriginales=matrizOriginal[0].size();

    // Crear matriz resultado
    vector<vector<float>>matrizInterpolada(nuevoAlto,vector<float>(nuevoAncho)
    );
    //factores de escala
    float escalaX=(float)(columnasOriginales - 1)/(nuevoAncho - 1);

    float escalaY=(float)(filasOriginales-1)/(nuevoAlto - 1);

    // Recorrer cada posicion de la nueva matriz
    for(int filaNueva=0;filaNueva<nuevoAlto; filaNueva++)
    {
        for(int columnaNueva=0;columnaNueva<nuevoAncho;columnaNueva++)
        {
            // Posicion en la matriz original
            float x=columnaNueva *escalaX;
            float y=filaNueva *escalaY;

            // Coordenadasvecinas
            int x1=(int)x;
            int y1=(int)y;

            int x2=min(x1+1,columnasOriginales -1);

            int y2=min(y1 + 1,filasOriginales-1);
            // Parte decimal
            float dx=x-x1;
            float dy=y-y1;

            //Valores vecinos
            float valor11=matrizOriginal[y1][x1];
            float valor12=matrizOriginal[y1][x2];

            float valor21=matrizOriginal[y2][x1];
            float valor22=matrizOriginal[y2][x2];

            //nterpolacion bilineal
            float valorInterpolado=valor11*(1-dx)*(1-dy)+valor12*dx*(1-dy)+valor21*(1-dx)*dy+valor22*dx*dy;
            matrizInterpolada[filaNueva][columnaNueva]=valorInterpolado;
        }
    }
    return matrizInterpolada;
}