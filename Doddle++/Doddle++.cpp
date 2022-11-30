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

class OldSchoolEmployer {
public:
    string Name;
    Employee* Worker;

    OldSchoolEmployer(string name, Employee* worker) {
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
    // Notice how VS doesn't even warn about this...
    auto stud1 = Student("StackMan1", "StudMuffin", 23);
    Student stud2("StackMan2", "StudMuffin", 32);

    auto* leaky = new Student("Leaky", "StudSchool", 65);
    std::cout << "My name is " << leaky->Name << std::endl;
    return -1;
}

int DemonstrateOldSchoolCleanup() {
    // Check the destructor calls...
    auto* employee = new Employee("Bilbo", "SomeComp", 42);
    OldSchoolEmployer employer("SomeComp", employee);
    return +1;
}

int DemonstrateModernCppCleanup() {
    // Check the destructor calls...
    auto* employee = new Employee("Bilbo", "SomeComp", 42);
    ModernSchoolEmployer employer("SomeComp", employee);
    return +1;
}


int main() {
    // Allocating an object on the heap
    auto heapy = "Heapy";
    auto company = "Blah";
    auto age = 42;
    auto* employee = new Employee(heapy, company, age);

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

    // Demonstrate old school cleanup techniques
    auto value2 = DemonstrateOldSchoolCleanup();

    // Demonstrate modern techniques
    auto value3 = DemonstrateModernCppCleanup();
}



