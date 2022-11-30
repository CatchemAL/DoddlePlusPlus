// Doddle++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// using namespace::std;

class Employee {
public:
    string Name;
    string Company;
    int Age;

    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }

    ~Employee() {
        std::cout << "Destructor is being called for EMPLOYEE: " << this->Name << "." << std::endl;
    }
};



class Student {
public:
    string Name;
    string University;
    int Age;

    Student(string name, string company, int age) {
        Name = name;
        University = company;
        Age = age;
    }

    ~Student() {
        std::cout << "Destructor is being called for STUDENT: " << this->Name << "." << std::endl;
    }
};

int CreateALeak() {
    
    auto stud1 = Student("StackMan1", "StudMuffin", 23);
    Student stud2("StackMan2", "StudMuffin", 32);

    auto* leaky = new Student("Leaky", "StudSchool", 65);
    std::cout << "My name is " << leaky->Name << std::endl;
    return -1;
}


int main() {
    // Allocating an object on the heap
    auto heapy = "Heapy";
    auto company = "Insight";
    auto age = 42;
    auto *employee = new Employee(heapy, company, age);

    std::cout << "Hello World! My name is " << employee->Name << " and I work for " << employee->Company << std::endl;

    // Here we must free it using delete (new => delete, malloc => free)
    delete employee;

    std::cout << "Done." << std::endl;

    // Allocating an object on the stack
    auto shelfStacker = Employee("StackMan", "Ford", 23);
    std::cout << "Hello World! My name is " << shelfStacker.Name << " and I work for " << shelfStacker.Company << std::endl;

    // No need to free as it was allocated on the stack
    // delete employee;
    std::cout << "Done." << std::endl;

    auto value = CreateALeak();
    std::cout << value << std::endl;
}



