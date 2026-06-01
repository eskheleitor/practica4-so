#ifndef JSON_READER_H
#define JSON_READER_H
#include <vector>
#include <string>
using namespace std;
// struct de la captura
struct Capture
{
    int id;
    vector<vector<int>> matriz;
};
//Lee todas las capturas del archivo json
vector<Capture> leerJson(const string& nombreArchivo);
#endif