#ifndef DATO_H
#define DATO_H

#include <string>

class Dato {
    private:
        std::string nombre;
    
    public:
        Dato(const std::string& nombre); // Constructor
        std::string getNombre() const;   // Método para obtener el nombre
};

#endif // DATO_H
