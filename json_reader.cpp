#include "json_reader.h"

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

//Lee el archivo JSON y carga todas las capturas
vector<Capture> leerJson(const string& nombreArchivo)//en el main cuando se tenga el archivo de verdad se sutituira el nombre
{
    //Abrir archivo
    ifstream archivo(nombreArchivo);

    //omprobar que existe
    if(!archivo.is_open())
    {
        cout <<"error al abrir el archivo: "<<nombreArchivo<<endl;
        return {};
    }

    json datosJson;
    archivo>>datosJson;
    vector<Capture> capturas;
    for(auto& capturaJson:datosJson["captures"])
    {
        Capture captura;
        captura.id=capturaJson["id"];
        captura.matriz=capturaJson["matrix"].get<vector<vector<int>>>();
        capturas.push_back(captura);
    }

    return capturas;
}