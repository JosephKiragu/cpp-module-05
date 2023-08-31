#include "Bureaucrat.cpp"

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;
        bob.decrementGrade();
        std::cout << bob << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}