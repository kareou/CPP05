/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:59:19 by mkhairou          #+#    #+#             */
/*   Updated: 2023/08/07 15:17:50 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5)
{
	target = "default";
	std::cout << "default constructor called \n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("formula", 25, 5)
{
	this->target = target;
	std::cout << "taget constructor called \n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm(cpy.getName(), cpy.getGradeToSign(), cpy.getGradeToExecute())
{
	*this = cpy;
	std::cout << "copy constructor called \n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "destructor called \n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copu)
{
	if (this == &copu)
		return *this;
	this->target = copu.target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned())
	{
		if (executor.getGrade() > this->getGradeToExecute())
			throw GradeTooHighException();
		else
		{
			std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
		}
	}
	else
	{
		throw GradeTooHighException();
	}
}
