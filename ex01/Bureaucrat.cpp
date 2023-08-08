/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:59:22 by mkhairou          #+#    #+#             */
/*   Updated: 2023/08/07 12:45:01 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("default")
{
	std::cout << "default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade , std::string name) : name(name)
{
	std::cout << "parametric constructor called" << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy)
{
	std::cout << "copy constructor called" << std::endl;
	*this = cpy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copu)
{
	std::cout << "assignation operator called" << std::endl;
	if (this != &copu)
		this->grade = copu.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "destructor called" << std::endl;
}

const std::string Bureaucrat::getName() const
{
	return this->name;
}

 int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}

 void Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "the grade is too low to be intialized";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "the grade is too hight to be intialized";
}

void Bureaucrat::signForm( Form & form)
{
	try{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << "\n";
	}
	catch(const std::exception& e){
		std::cerr << this->getName() << " couldn’t sign " << form.getName();
		std::cerr << e.what() << "\n";
	}
}
