#ifndef FILE_H
#define FILE_H

#include <string>
#include <set>
#include <vector>

class File {
private:
    std::vector<std::set<std::string > > nombresListas; // Lista de conjuntos de nombres (masculinos y femeninos)
    std::vector<std::string> countries; // Lista de países

public:
    // Lee los nombres desde múltiples archivos y los almacena en listas
    void readFromFiles(const std::vector<std::string>& archivos);

    // Obtiene un nombre aleatorio de las listas de nombres
    std::string randomItem() const;

    // Determina el género del nombre dado basándose en las listas de nombres
    std::string chooseGender(const std::string& nombre) const;

    // Obtiene un país aleatorio de la lista de países
    std::string chooseCountry() const;
};

#endif // FILE_H
