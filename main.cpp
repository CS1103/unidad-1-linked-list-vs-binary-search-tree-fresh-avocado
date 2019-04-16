//Trabajo hecho por Gabriel Spranger, Benjamin Diaz, Rodrigo Céspedes
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include <ctime>

#include "LinkedList.h"
#include "BinarySearchTree.h"

using namespace std;

// Nombres de archivos
const string LOCATION_FILE = "Locations.csv";
const string SEARCH_FILE = "Search.txt";

int main() {

    // Declarando variables

    auto* ll =  new LinkedList();
    auto* bst = new BinarySearchTree();

    vector<int> vsearch;

    // Grabar Datos del archivo "Locations.csv" en ll

    load_ll_locations(ll, LOCATION_FILE);

    // Grabar Datos del archivo "Locations.csv" en bst

    load_bst_locations(bst, LOCATION_FILE);

    // Leer los datos del archivo "Search.txt" y grabarlos en vsearch

    ifstream search_data_source;
    search_data_source.open("Search.txt");

    string search_item;

    if (search_data_source.is_open()) {
        while (search_data_source.good()) {
            getline(search_data_source, search_item);
            vsearch.push_back(atoi(search_item.c_str()));
        }
    } else {
        cout << "No se pudo abrir el archivo Search.txt" << endl;
    }

    // Utilizar cada item de vsearch para buscar los lugares en ll y bst
    // Calcular los tiempos promedios en cada caso

    double avgtime_ll = 0;
    double avgtime_bst = 0;

    auto inicio = std::chrono::high_resolution_clock::now();
    for (const auto &id: vsearch) {
        // Buscar en ll
        ll->search(to_string(id));
    }
    auto fin = std::chrono::high_resolution_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio);

    cout << "El tiempo que demora la busqueda en LinkedList es: " << duracion.count() << " microsegundos." << endl;

//    auto inicio2 = std::chrono::high_resolution_clock::now();
//    for (const auto &id: vsearch){
//        // Buscar en bst
//        bst->search(id);
//    }
//    auto fin2 = std::chrono::high_resolution_clock::now();
//    auto duracion2 = std::chrono::duration_cast<std::chrono::microseconds>(fin2 - inicio2);
//    cout << "El tiempo que demora la busqueda en BinarySearchTree es: " << duracion2.count() << " microsegundos." << endl;


    delete ll;
    delete bst;

    return 0;
}