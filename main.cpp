/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

Create a branch named Part1

Purpose:  This project will show you the difference between member functions and
static class functions, as well as the difference between pointers and
references and the code semantics that accompany pointers and references.

 Pointers

 Please look at the screenshot in the files to see what happens if you paste
this assignment into an existing cpp file in an xcode project

 Task: replace all of the <#place holder#> placeholders with proper names and
types that will make this program compile and run.

 press the Compile, link and run... button and work your way through all of the
error messages.


 steps:

 1) finish implementing the constructor for T. the constructor parameters need
to initialize 2) and 3)

 2) provide a member variable in T of a type of your choosing that works with
the compare function below T note the name of the variable used in the compare
function

 3) provide a member variable of type std::string in T that works with the
*first* cout statement in main(). note the name of the variable used in the
*first* cout statement in main()

 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if
statements. see 8) for a hint about what type to use.

 6) finish instantiating the two T instances being declared in main(), based on
the constructor you finished implementing in T Their names (line 105,106) are
different than the member variables names (line 77), even tho the placeholders
share the same name. Don't let this confuse you.

 7) Declare 'f' with the proper type so the call to f.compare works

 8) call f.compare() with the correct arguments, based on 2) and 5)

 9) correct the cout that uses smaller's member variable with some safe pointer
usage. the possible return values of the compare() function should give you a
hint. Also: if smaller == nullptr, make the cout statement explain the reasons
that `f.compare()` might return nullptr. hint: There are multiple reasons

 10) complete the implementation for the static function in <structName2>

 11) call the <structName2> static function correctly in main()

 12) replicate the functionality of <structName2>'s static function by
implementing a member function in U that does the same thing.

 13) remember the rules for using pointers!  What is the one thing we always do
before we use a pointer?

 After you finish, click the [run] button.  Clear up any errors or warnings as
best you can.
 */

#include <iostream>
#include <string>
struct T 
{
    int distance;
    std::string name;
    T(int v, const char* letterName) 
    {
        if (letterName == nullptr) return;
        distance = v;             // Implicit "this"
        this->name = *letterName; // Explicit "this"
    }
};

struct A 
{
    T* compare(T* a, T* b) 
    {
        if (a != nullptr && b != nullptr) 
        {
            if (a->distance < b->distance) return a;
            if (a->distance > b->distance) return b;
        }
        return nullptr;
    }
};

struct U 
{
    float value1{0}, value2{0};
    float updateValue(float* updatedValue)
    {
        if (updatedValue == nullptr) return 0.0f;
        std::cout << "U's value1 value: " << this->value1 << std::endl;
        this->value1 = *updatedValue;
        std::cout << "U's value1 updated value: " << this->value1 << std::endl;
        while (std::abs(this->value2 - this->value1) > 0.001f) 
        {
            this->value2 += 0.01f;
        }
        std::cout << "U's value2 updated value: " << this->value2 << std::endl;
        return this->value2 * this->value1;
    }
};

struct Z 
{
    static float functionA (U* that, float* updatedValue) 
    {
        if (that == nullptr || updatedValue == nullptr) return 0.0f;
        std::cout << "U's value1 value: " << that->value1 << std::endl;
        that->value1 = *updatedValue;
        std::cout << "U's value1 updated value: " << that->value1 << std::endl;
        while (std::abs(that->value2 - that->value1) > 0.001f) 
        {
            that->value2 += 0.01f;
        }
        std::cout << "U's value2 updated value: " << that->value2 << std::endl;
        return that->value2 * that->value1;
    }
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left,
 entering a message, and click [Commit and push].

 If you didn't already:
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single
 message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main() 
{
    T firstSign(11, "A");
    T secondSign(17, "B");

    A f;
    auto* smaller = f.compare(&firstSign, &secondSign);

    if (smaller == nullptr) 
    {
        std::cout << "Smaller returned a nullptr. This may be due to any of the following possibilities: the T structs that are passed on are not properly initialized; or they point to a nullptr themselves; or the return value of the compare function is returning a nullptr." << std::endl;
    }
    else
    {
        std::cout << "the smaller one is << " << smaller->name << ".\nIf compare() returns a nullptr, then nothing will print out."<< std::endl;
    }

    U firstU;
    float updatedValue = 5.f;
    std::cout << "[static func] firstU's multiplied values: \n" <<
    Z::functionA(&firstU, &updatedValue) << std::endl; 

    U secondU;
    std::cout << "[member func] secondU's multiplied values: \n" <<
    secondU.updateValue(&updatedValue) << std::endl;
}
