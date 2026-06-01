#include "http_cliente.h"
#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;






// Envia una matriz interpolada al servidor de pkython
bool enviarMatriz(
    int idCaptura,
    const vector<vector<float>>& matriz
)
{
    CURL*conexion=curl_easy_init();
    if(conexion == nullptr)
    {
        cout <<"error al iniciar CURL" << endl;
        return false;
    }
    // Crear archivo json para enviar
    json datos;
    datos["capture_id"]=idCaptura;
    datos["width"]=matriz[0].size();
    datos["height"]=matriz.size();
    datos["data"]=matriz;
    string datosJson=datos.dump();
    // Cabecera HTTP
    struct curl_slist* cabeceras = nullptr;
    cabeceras =curl_slist_append(cabeceras,"Content-Type: application/json");
    // Configurar peticion
    curl_easy_setopt(conexion,CURLOPT_URL,"http://127.0.0.1:5000/upload");
    curl_easy_setopt(
        conexion,
        CURLOPT_HTTPHEADER,
        cabeceras
    );
    curl_easy_setopt(
        conexion,
        CURLOPT_POSTFIELDS,
        datosJson.c_str()
    );




    // Enviar
    CURLcode resultado =
    curl_easy_perform(conexion);
    if(resultado != CURLE_OK)
    {
        cout << "Error al enviar datos"
             << endl;
        curl_easy_cleanup(conexion);
        return false;
    }
    cout << "Captura "<< idCaptura<< " enviada correctamente"<< endl;
    curl_easy_cleanup(conexion);
    return true;
}