#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

// Definición de la clase Person
class Person {
private:
    std::string name;  // Atributo para almacenar el nombre de la persona
    int age;           // Atributo para almacenar la edad de la persona
    long long id;      // Atributo para almacenar el ID de la persona
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
    Person(const std::string &name, int age, long long id, const std::string gender, const std::string country, const std::string email,
           long long phone, double stature, double weight, double difficulty, double execution);

    // Métodos getter (accesores)
    std::string getName() const;
    int getAge() const;
    long long getId() const;
    std::string getGender() const;
    std::string getCountry() const;
    std::string getEmail() const;
    long long getPhone() const;
    double getStature() const;
    double getWeight() const;
    double getDifficulty() const;
    double getExecution() const;

    // Métodos setter (mutadores)
    void setName(const std::string &name);
    void setAge(int age);
    void setId(long long id);
    void setGender(const std::string gender);
    void setCountry(const std::string country);
    void setEmail(const std::string email);
    void setPhone(long long phone);
    void setStature(double stature);
    void setWeight(double weight);
    void setExecution(double execution);
    void setDifficulty(double difficulty);

    // Método para obtener el puntaje total (difficulty + execution)
    double getTotalScore() const;

    // Método para obtener todos los datos como una cadena de texto
    std::string getData() const;

    // Sobrecarga del operador << para imprimir el objeto Person
    friend std::ostream& operator<<(std::ostream &out, const Person &persona);

    // Sobrecarga de los operadores >, < y == con respecto a la edad
    bool operator>(const Person &other) const;
    bool operator<(const Person &other) const;
    bool operator==(const Person &other) const;
};

#endif // PERSON_H
