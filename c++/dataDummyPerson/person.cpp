#include "person.h"
#include <sstream>

// Definición del constructor
// Inicializa un objeto Person con los valores proporcionados
Person::Person(const std::string &name, int age, long long id, const std::string gender, const std::string country, const std::string email,
               long long phone, double stature, double weight, double difficulty, double execution)
        : name(name), age(age), id(id), gender(gender), country(country), email(email), phone(phone), stature(stature),
          weight(weight), difficulty(difficulty), execution(execution) {}

// Definición de los métodos getter
// Devuelve el nombre de la persona
std::string Person::getName() const {
    return name;
}

// Devuelve la edad de la persona
int Person::getAge() const {
    return age;
}

// Devuelve el ID de la persona
long long Person::getId() const {
    return id;
}

// Devuelve el género de la persona
std::string Person::getGender() const {
    return gender;
}

// Devuelve el país de la persona
std::string Person::getCountry() const {
    return country;
}

// Devuelve el email de la persona
std::string Person::getEmail() const {
    return email;
}

// Devuelve el teléfono de la persona
long long Person::getPhone() const {
    return phone;
}

// Devuelve la estatura de la persona
double Person::getStature() const {
    return stature;
}

// Devuelve el peso de la persona
double Person::getWeight() const {
    return weight;
}

// Devuelve la dificultad del ejercicio de la persona
double Person::getDifficulty() const {
    return difficulty;
}

// Devuelve la ejecución del ejercicio de la persona
double Person::getExecution() const {
    return execution;
}

// Definición de los métodos setter
// Establece el nombre de la persona
void Person::setName(const std::string &name) {
    this->name = name;
}

// Establece la edad de la persona
void Person::setAge(int age) {
    this->age = age;
}

// Establece el ID de la persona
void Person::setId(long long id) {
    this->id = id;
}

// Establece el género de la persona
void Person::setGender(const std::string gender) {
    this->gender = gender;
}

// Establece el país de la persona
void Person::setCountry(const std::string country) {
    this->country = country;
}

// Establece el email de la persona
void Person::setEmail(const std::string email) {
    this->email = email;
}

// Establece el teléfono de la persona
void Person::setPhone(long long phone) {
    this->phone = phone;
}

// Establece la estatura de la persona
void Person::setStature(double stature) {
    this->stature = stature;
}

// Establece el peso de la persona
void Person::setWeight(double weight) {
    this->weight = weight;
}

// Establece la dificultad del ejercicio de la persona
void Person::setDifficulty(double difficulty) {
    this->difficulty = difficulty;
}

// Establece la ejecución del ejercicio de la persona
void Person::setExecution(double execution) {
    this->execution = execution;
}

// Definición del método para obtener el puntaje total
// Calcula y devuelve el puntaje total como la suma de dificultad y ejecución
double Person::getTotalScore() const {
    return difficulty + execution;
}

// Definición del método para obtener todos los datos como una cadena de texto
// Devuelve una representación textual completa de la persona
std::string Person::getData() const {
    std::ostringstream oss;
    oss << "ID: " << id << ", Gender: " << gender << ", Name: " << name << ", Country: " << country
        << ", Email: " << email << ", Phone: " << phone << ", Age: " << age << ", Stature: " << stature
        << ", Weight: " << weight << ", Difficulty: " << difficulty << ", Execution: " << execution
        << ", Total Score: " << getTotalScore();
    return oss.str();
}

// Definición de la sobrecarga del operador <<
// Permite imprimir un objeto Person usando el operador <<
std::ostream& operator<<(std::ostream &out, const Person &persona) {
    out << persona.getData();
    return out;
}

// Sobrecarga del operador >
// Compara dos objetos Person basándose en la edad
bool Person::operator>(const Person &other) const {
    return this->age > other.age;
}

// Sobrecarga del operador <
// Compara dos objetos Person basándose en la edad
bool Person::operator<(const Person &other) const {
    return this->age < other.age;
}

// Sobrecarga del operador ==
// Compara dos objetos Person basándose en la edad
bool Person::operator==(const Person &other) const {
    return this->age == other.age;
}
