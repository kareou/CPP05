/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:09:25 by mkhairou          #+#    #+#             */
/*   Updated: 2023/08/07 14:54:29 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default",72,45)
{
	target = "default";
	std::cout << "default constructor called \n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("formula", 72, 45)
{
	this->target = target;
	std::cout << "taget constructor called \n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy.getName(), cpy.getGradeToSign(), cpy.getGradeToExecute())
{
	*this = cpy;
	std::cout << "copy constructor called \n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "destructor called \n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copu)
{
	if (this == &copu)
		return *this;
	this->target = copu.target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if(this->getIsSigned())
	{
		if(executor.getGrade() > this->getGradeToExecute())
			throw GradeTooHighException();
		else
		{
			int number = rand();
			std::cout << "waiting for result \n";
			if(number % 2 == 0)
				std::cout << target + " has been robotomized successfull\n";
			else
				std::cout << "failed to robotomy " + target << "\n";
		}
	}
	else
	{
		throw GradeTooHighException();
	}
}
