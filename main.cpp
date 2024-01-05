/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References


 1) convert the pointer usage (except for 'const char*') to reference types or
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference and don't change the return type either.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr.
 there is only one reason for `compare` to return nullptr.
 Update this std::cout expression to specify why nullptr was returned.

 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

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
        std::cout << "one or more arguments to the compare() function is a nullptr or all arguments' 'distance' member variable all have the same value." << std::endl;
    }
    else
    {
        std::cout << "the smaller one is " << smaller->name << std::endl;
    }

    U firstU;
    float updatedValue = 5.f;
    std::cout << "[static func] firstU's multiplied values: \n" <<
              Z::functionA(&firstU, &updatedValue) << std::endl;

    U secondU;
    std::cout << "[member func] secondU's multiplied values: \n" <<
              secondU.updateValue(&updatedValue) << std::endl;
}
