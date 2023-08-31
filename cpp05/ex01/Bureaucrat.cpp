#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string.h>
#include "Form.cpp"

class Bureaucrat {
public:
    // custom class exception
    class GradeTooHighException : public std::exception {
    public:
        const char * what() const throw() {
            return "Grade too high!";
        }
    };
    class GradeTooLowException : public std::exception {
    public:
        const char * what() const throw() {
            return "Grade too low";
        }
    };

private:
    const std::string name;
    int grade;


public:
    // constructor
    Bureaucrat(const std::string &name, int grade) : name(name), grade(grade) {
        if (grade < 1) {
            throw GradeTooHighException();
        }
        if (grade > 150) {
            throw GradeTooLowException();
        }

    }

    // Getter Methods
    std::string getName() const {
        return name;
    }

    int getGrade() const {
        return grade;
    }

    // Increment grade
    void incrementGrade() {
        if (grade - 1 < 1) {
            throw GradeTooHighException();
        }
        grade--;
    }

    // Decrement grade
    void decrementGrade() {
        if (grade + 1 > 150) {
            throw GradeTooLowException();
        }
        grade++;
    }

    // signForm method from class form(form.cpp)
    void signForm(Form &form) {
        try {
            form.beSigned(*this);
            std::cout << getName() << " signed " << form.getName() << std::endl;
        } catch (std::exception &e) {
            std::cout<< getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
            
        }
    }

    // Overload insertion operator

    friend std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
        out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
        return out;
    }

};


#endif