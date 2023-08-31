#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string.h>

#include "Bureaucrat.cpp"

class Form {
public:
    class GradeTooHighException : public std::exception {
    public:
       const char * what() const throw() {
           return "Form grade too high!";
       } 
    };
    class GradeTooLowException : public std::exception {
    public:
        const char * what() const throw() {
            return "Form grade too low!";
        }
    };

private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    //constructor
    Form(const std::string &name, int gradeToSign, int gradeToExecute) 
        : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), isSigned(false) {
        if (gradeToSign < 1 || gradeToExecute < 1) {
            throw GradeTooHighException();
        }
        if (gradeToSign > 150 || gradeToExecute > 150) {
            throw GradeTooLowException();
        }
    }

    // Getter methods
    std::string getName() const {return name;}
    bool getIsSigned() const {return isSigned;}
    int getGradeToSign() const {return gradeToSign;}
    int getGradeToExecute() const { return gradeToExecute;}

    // beSigned method
    void beSigned(const Bureaucrat &bureaucrat) {
        if (bureaucrat.getGrade() > gradeToSign) {
            throw GradeTooLowException();
        }
        isSigned = true;
    }

    // overload insertion operator
    friend std::ostream &operator<<(std::ostream &out, const Form &form) {
        out << form.getName() << ", form grade to sign " << form.getGradeToSign()
            << ", form grade to execute " << form.getGradeToExecute()
            <<", is signed: " << (form.getIsSigned() ? "yes" : "No");
        return out;
    }
};

#endif