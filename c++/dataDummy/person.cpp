#include "person.h"

// Definición del constructor
Person::Person(const std::string &name, int age, long long id, const std::string gender, const std::string country, const std::string email, long long phone, double stature, double weight, double difficulty, double execution)
        : name(name), age(age), id(id), gender(gender), country(country), email(email), phone(phone), stature(stature), weight(weight), difficulty(difficulty), execution(execution){}

// Definición de los métodos getter
std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

long long Person::getId() const {
    return id;
}

std::string Person::getGender() const {
    return gender;
}

std::string Person::getCountry() const {
    return country;
}

std::string Person::getEmail() const {
    return email;
}

long long Person::getPhone() const {
    return phone;
}

double Person::getStature() const {
    return stature;
}

double Person::getWeight() const {
    return weight;
}

double Person::getDifficulty() const {
    return difficulty;
}

double Person::getExecution() const {
    return execution;
}

// Definición de los métodos setter
void Person::setName(const std::string &name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::setId(long long id) {
    this->id = id;
}
void Person::setGender(const std::string gender) {
    this->gender = gender;
}
void Person::setCountry(const std::string country) {
    this->country = country;
}
void Person::setEmail(const std::string email) {
    this->email = email;
}
void Person::setPhone(long long phone) {
    this->phone = phone;
}
void Person::setStature(double stature) {
    this->stature = stature;
}
void Person::setWeight(double weight) {
    this->weight = weight;
}
void Person::setDifficulty(double difficulty) {
    this->difficulty = difficulty;
}
void Person::setExecution(double execution) {
    this-> execution = execution;
}



// Definición de la sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Person &persona) {
    out << "ID: " << persona.id << ", Gender: " << persona.gender << ", Name: " << persona.name << ", Country: " << persona.country << ", Email: " << persona.email << ", Phone: " << persona.phone <<", Age: " << persona.age <<", Stature: " << persona.stature <<", Weight: " << persona.weight <<", Difficulty: " << persona.difficulty << ", Execution: " << persona.execution;
    return out;
}

// Sobrecarga del operador >
bool Person::operator>(const Person &other) const {
    return this->age > other.age;
}

// Sobrecarga del operador <
bool Person::operator<(const Person &other) const {
    return this->age< other.age;
}

// Sobrecarga del operador ==
bool Person::operator==(const Person &other) const {
    return this->age == other.age;
}
