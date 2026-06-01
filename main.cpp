#include <iostream>
#include "json_reader.h"
#include "matrix_validator.h"
#include "interpolacion.h"
#include "http_cliente.h"
using namespace std;
int main(){
    //leer todas las capturas del json
    vector<Capture> capturas=leerJson("tactile_captures_50.json");
    cout << "Capturas leidas: "<<capturas.size()<<endl;

    //rrecorrer todas las capturas
    for(const auto& captura:capturas)//vector nuevo(sustituye al for tradicional)
    {
        // Comprobar que la matriz sea 16x16
        if(!validarMatriz(captura.matriz))
        {
            cout << "Error en la captura "<<captura.id<< endl;
            continue;
        }

        // Interpolar la matriz a 128x128
        vector<vector<float>> matrizInterpolada=interpolarBilineal(captura.matriz,128,128
        );
        // Enviar al servidor Python
        enviarMatriz(
            captura.id,
            matrizInterpolada
        );
    }
    cout<<endl;
    cout<<"Proceso completado"<< endl;
    return 0;
}