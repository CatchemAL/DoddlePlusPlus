#include <iostream>
#include <string>

class Worker
{
private:
    const std::string name_;

public:
    Worker(const std::string& name)
	    : name_(name)
    {
	    
    }

    std::string GetName() const
    {
        return name_;
    }

};



void FunWithConst()
{
    /*
	// Rust              C/C++
	    a: &T       ==   const T* const a; // can't mutate either
	mut a: &T       ==   const T* a;       // can't mutate what is pointed to
	    a: &mut T   ==   T* const a;       // can't mutate pointer
	mut a: &mut T   ==   T* a;             // can mutate both
	 */

    int k = 21;
    int m = 38;
    int* ptr = &k;                // A    mutable reference to a    mutable variable
    int* const ptr_nc = &k;       // An immutable reference to a    mutable variable
    const int* ptr_cn = &k;       // A    mutable reference to an immutable variable
    const int* const ptr_cc = &k; // An immutable reference to an immutable variable

    ptr = &m;       //    allowed
    (*ptr)++;       //    allowed

    // ptr_nc = &m; // disallowed
    (*ptr_nc)++;    //    allowed

    ptr_cn = &m;    //    allowed
    // (*ptr_cn)++; // disallowed

    // ptr_cc = &m; // disallowed
    // (*ptr_cc)++; // disallowed


    std::string bilbo = "Bilbo";
    const Worker worker(bilbo);
    const std::string& name = worker.GetName();
    std::cout << "Worker's name is " << name << std::endl;
}