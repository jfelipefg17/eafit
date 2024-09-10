#ifndef PERSONA_H  // Comienza una guardia de inclusión para evitar inclusiones múltiples del archivo
#define PERSONA_H

#include <iostream>  // Incluye la librería iostream para la entrada y salida estándar
#include <string>    // Incluye la librería string para usar el tipo std::string

// Definición de la clase Persona
class Persona {
private:
    std::string nombre;  // Atributo para almacenar el nombre de la persona
    int edad;            // Atributo para almacenar la edad de la persona

public:
    // Constructor
    Persona(const std::string &nombre, int edad);  // Constructor que inicializa los atributos nombre y edad

    // Métodos getter (accesores)
    std::string getNombre() const;  // Método para obtener el nombre de la persona
    int getEdad() const;            // Método para obtener la edad de la persona

    // Métodos setter (mutadores)
    void setNombre(const std::string &nombre);  // Método para establecer el nombre de la persona
    void setEdad(int edad);                     // Método para establecer la edad de la persona

    // Sobrecarga del operador << para imprimir el objeto Persona
    friend std::ostream& operator<<(std::ostream &out, const Persona &persona);
};

#endif // PERSONA_H