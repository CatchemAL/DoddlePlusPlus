#pragma once // this is a header guard
#include <iostream>  // <XYZ> means search our include paths
#include <ostream>   // "XYZ.h" means search relative to the current directory

using namespace std;


class Employee {
public:
    string _name;
    string _company;
    int _age;

    Employee(string name, string company, int age) {
        _name = name;
        _company = company;
        _age = age;
    }

    ~Employee() {
        std::cout << "Destructor is being called for EMPLOYEE: " << this->_name << "." << std::endl;
    }
};

class OldSchoolEmployer {
public:
    string Name;
    Employee* Worker;

    OldSchoolEmployer(std::string name, Employee* worker) {
        Name = name;
        Worker = worker;
    }

    ~OldSchoolEmployer() {
        std::cout << "Employer Destructor goes here. Don't forget to murder your employee!!" << std::endl;
        delete Worker;
    }
};

class ModernSchoolEmployer {
public:
    string Name;
    std::unique_ptr<Employee> Worker;

    ModernSchoolEmployer(string name, Employee* worker) {
        Name = name;
        Worker = std::make_unique<Employee>(*worker);
    }

    ~ModernSchoolEmployer() {
        std::cout << "Employer Destructor goes here. Smart pointers will murder the employee for us!!" << std::endl;
    }
};