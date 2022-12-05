// Doddle++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> // #XYZ is a pre-processor directive
#include <vector>

#include "Employee.h" // header files do not get compiled
#include "GradientDescent.h" // header files get included into a cpp and that is when they get compiled
#include "YieldCurve.h" // cpp files get compiled

using namespace std; // cpp files get compiled individually into individual object files *.obj
// then the linker stitches together all the object files into an .exe

// using namespace::std;

void display_primitive_sizes();
void fun_with_pointers();
void fun_with_references();
void fun_with_classes();
void FunWithLoggers();
void fun_with_virtual();
void fun_with_arrays();
void fun_with_strings();
void FunWithConst();
void FunWithCopyConstructors();
void FunWithStacks();
void MakingMyOwnString();
void FunWithVectors();
void FunWithTuples();
void FunWithTemplates();
void fun_with_macros();
void FunWithFunctionPointers();
void FunWithLambdas();

class Student {
public:
    string m_name;
    string m_university;
    int m_age;

    Student(const string& name, const string& university, const int age)
        : m_name(name), m_university(university), m_age(age)
    {
    }

    ~Student() {
        std::cout << "Destructor is being called for STUDENT: " << this->m_name << "." << std::endl;
    }
};

int create_a_leak() {
    // Notice how VS doesn't even warn about this...
    auto stud1 = Student("StackMan1", "StudMuffin", 23);
    Student stud2("StackMan2", "StudMuffin", 32);

    auto* leaky = new Student("Leaky", "StudSchool", 65);
    std::cout << "My name is " << leaky->m_name << std::endl;
    return -1;
}

int demonstrate_old_school_cleanup() {
    // Check the destructor calls...
    auto* employee = new Employee("Bilbo", "SomeComp", 42);
    OldSchoolEmployer employer("SomeComp", employee);
    return +1;
}

int demonstrate_modern_cpp_cleanup() {
    // Check the destructor calls...
    auto* employee = new Employee("Bilbo", "SomeComp", 42);
    ModernSchoolEmployer employer("SomeComp", employee);
    return +1;
}

int adder(int x, int y) {
    return x + y;
}



double funky(double x, double y) {
    return (x - 3.0) * (x - 3.0) + (y - 4.0) * (y - 4.0);
}

double funky_x(double x, double y) {
    return 2 * (x - 3.0);
}

double funky_y(double x, double y) {
    return 2 * (y - 4.0);
}


int main() {

    display_primitive_sizes();
    fun_with_pointers();
    fun_with_references();
    fun_with_classes();
    FunWithLoggers();
    fun_with_virtual();
    fun_with_arrays();
    fun_with_strings();
    FunWithConst();
    FunWithCopyConstructors();
    FunWithStacks();
    MakingMyOwnString();
    FunWithVectors();
    FunWithTuples();
    FunWithTemplates();
    fun_with_macros();
    FunWithFunctionPointers();
    FunWithLambdas();

    int a = 5;
    int* ap = &a;
    int** app = &ap;
    int b = 5;
    int* bp = &b;
    int** bpp = &bp;

    bpp = nullptr;
    

    (*ap)++;

    bool is_five = a == 5;
    if (is_five)
    {
        std::cout << "Num is 5" << std::endl;
    }
    else
    {
        std::cout << "Num is not 5" << std::endl;
    }
        

    // Allocating an object on the heap
    auto heapy = "Heapy";
    auto company = "Blah";
    auto age = 42;
    auto* employee = new Employee(heapy, company, age);

    std::cout << "Hello World! My name is " << employee->_name << " and I work for " << employee->_company << std::endl;

    // Here we must free it using delete (new => delete, malloc => free)
    delete employee;

    std::cout << "Done." << std::endl;

    // Allocating an object on the stack
    auto shelf_stacker = Employee("StackMan", "Ford", 23);
    std::cout << "Hello World! My name is " << shelf_stacker._name << " and I work for " << shelf_stacker._company << std::endl;

    // No need to free as it was allocated on the stack
    // delete employee;
    std::cout << "Done." << std::endl;

    auto value = create_a_leak();
    std::cout << value << std::endl;

    // Demonstrate old school cleanup techniques
    auto value2 = demonstrate_old_school_cleanup();

    // Demonstrate modern techniques
    auto value3 = demonstrate_modern_cpp_cleanup();

    // Function pointers
    int (*f)(int, int) = adder;
    auto g = f(4, 5);
    std::cout << "The answer is: " << g << std::endl;

    double x = 0.0, y = 0.0;
    gradient_descent(&x, &y, 0.1, 1e-12, funky, funky_x, funky_y);
    std::cout << "The answer is: (" << x << ", " << y << " )" << std::endl;


    const vector tenors = { 1.0, 2.0, 3.0, 4.0 };
    vector rates = { 0.01, 0.02, 0.03, 0.04 };

    const YieldCurve yield_curve(tenors, rates);
    double discount_factor = yield_curve.getDiscountFactor(42.0);



    // std::cin.get();
}



