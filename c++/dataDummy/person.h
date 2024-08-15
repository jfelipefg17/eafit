#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

// Definición de la clase Persona
class Person {
private:
    std::string name;  // Atributo para almacenar el nombre de la persona
    int age;            // Atributo para almacenar la edad de la persona
    long long id;// Atributo para almacenar el ID de la persona
    std::string gender;
    std::string country;
    std::string email;
    long long phone;
    double stature;
    double weight;
    double difficulty;
    double execution;



public:
    // Constructor
    Person(const std::string &name, int age, long long id, std::string gender, std::string country, std::string email, long long phone, double stature, double weight, double difficulty, double execution);  // Constructor que inicializa los atributos

    // Métodos getter (accesores)
    std::string getName() const;  // Método para obtener el nombre de la persona
    int getAge() const;            // Método para obtener la edad de la persona
    long long getId() const;// Método para obtener el ID de la persona
    std::string getGender() const;
    std::string getCountry() const;
    std::string getEmail() const;
    long long getPhone() const;
    double getStature() const;
    double getWeight()  const;
    double getDifficulty() const;
    double getExecution() const;
    // Métodos setter (mutadores)
    void setName(const std::string &name);  // Método para establecer el nombre de la persona
    void setAge(int age);                     // Método para establecer la edad de la persona
    void setId(long long id);// Método para establecer el ID de la persona
    void setGender(const std::string gender);
    void setCountry(const std::string country);
    void setEmail(const std::string email);
    void setPhone(long long phone);
    void setStature(double stature);
    void setWeight(double weight);
    void setExecution(double execution);
    void setDifficulty(double difficulty);


    // Sobrecarga del operador << para imprimir el objeto Persona
    friend std::ostream& operator<<(std::ostream &out, const Person &persona);

    // Sobrecarga de los operadores >, < y == con respecto a la edad
    bool operator>(const Person &other) const;
    bool operator<(const Person &other) const;
    bool operator==(const Person &other) const;
};

#endif // PERSON_H
