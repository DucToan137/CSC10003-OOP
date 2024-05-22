#include <iostream>
#include <memory>
#include "main.h"
#include "Cat.h"
#include "RandomInteger.h"

int main()
{
    //Cat* kitty = new Cat();
    std::shared_ptr<Cat> kitty = std::make_shared<Cat>();
    //update1(kitty);

    std::cout << kitty->weight() << " kg\n";

    Cat doraemon(100, 1.293);
    std::cout << doraemon.height() << " m\n";

    int value(10);
    std::cout << value;

    // Tên biến không nên viết tắt
    // Cá biệt: dob date of birth, Random number generator
    RandomInteger rng; 
    const int COUNT = 10;
    const int MAX_VALUE = 100;

    for (int i = 0; i < COUNT; i++) {
        std::cout << rng.next(MAX_VALUE) << " ";
    }

    Cat doremi;
    doremi.input();
    doremi.output();
}

void update1(std::shared_ptr<Cat> cat) {
    std::cout << "Inside update1, count:"
        << cat.use_count() << "\n";

    update2(cat);
    std::cout << "After update2, count:"
        << cat.use_count() << "\n";
}

void update2(std::shared_ptr<Cat> cat) {
    std::cout << "Inside update2, count:"
        << cat.use_count() << "\n";

    update3(cat);
    std::cout << "After update3, count:"
        << cat.use_count() << "\n";
}

void update3(std::shared_ptr<Cat> cat) {
    std::cout << "Inside update3, count:"
        << cat.use_count() << "\n";
}