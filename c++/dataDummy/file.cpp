#include "file.h"         // Incluye el encabezado de la clase File para usar su definición.
#include <fstream>        // Incluye la biblioteca estándar <fstream> para manejar operaciones de archivos.
#include <random>         // Incluye la biblioteca estándar <random> para generar números aleatorios.

void File::readFromFiles(const std::vector<std::string>& archivos) {
    // Ajusta el tamaño del vector `nombresListas` para que tenga el mismo número de elementos que el vector de archivos.
    nombresListas.resize(archivos.size());

    // Itera sobre cada archivo en el vector de archivos.
    for (size_t i = 0; i < archivos.size(); ++i) {
        std::ifstream archivo(archivos[i]);  // Abre el archivo actual para lectura.
        std::string nombre;

        // Lee cada línea del archivo y la inserta en el conjunto correspondiente en `nombresListas`.
        while (std::getline(archivo, nombre)) {
            nombresListas[i].insert(nombre);  // Inserta el nombre en el conjunto de la lista correspondiente.
        }
    }
}

std::string File::randomItem() const {
    // Verifica si `nombresListas` está vacío y devuelve una cadena vacía si lo está.
    if (nombresListas.empty()) {
        return "";
    }

    // Inicializa un generador de números aleatorios con una semilla basada en el reloj del sistema.
    std::random_device rd;
    std::mt19937 gen(rd());

    // Crea una distribución uniforme para seleccionar un índice aleatorio de la lista de listas.
    std::uniform_int_distribution<size_t> listaDis(0, nombresListas.size() - 1);
    size_t listaIndex = listaDis(gen);  // Genera un índice aleatorio para seleccionar una lista.

    // Obtiene una referencia constante a la lista de nombres seleccionada.
    const std::set<std::string>& listaSeleccionada = nombresListas[listaIndex];

    // Crea una distribución uniforme para seleccionar un índice aleatorio dentro de la lista seleccionada.
    std::uniform_int_distribution<size_t> nombreDis(0, listaSeleccionada.size() - 1);

    // Iterador para recorrer el conjunto y avanzar a una posición aleatoria dentro de él.
    std::set<std::string>::const_iterator it = listaSeleccionada.begin();
    std::advance(it, nombreDis(gen));  // Avanza el iterador a una posición aleatoria.

    // Devuelve el nombre en la posición aleatoria del conjunto.
    return *it;
}
