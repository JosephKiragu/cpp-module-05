#include "Bureaucrat.cpp"
#include "Form.cpp"

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

    try {
        Form taxForm("Tax Form", 2, 5);
        Bureaucrat bob("Bob", 2);
        std::cout << taxForm << std::endl;
        bob.signForm(taxForm);
        std::cout << taxForm << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}