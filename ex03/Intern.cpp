/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:43:00 by mkhairou          #+#    #+#             */
/*   Updated: 2023/08/07 16:19:43 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &cpy)
{
	*this = cpy;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &copu)
{
	(void)copu;
	return *this;
}

AForm *Intern::createPresident(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::createRobo(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string FromType, std::string target)
{

	std::string Names[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm *(Intern::*array[3])(std::string) = {&Intern::createPresident,&Intern::createRobo,&Intern::createShrubbery};
	int i = 0;
	while(i < 3)
	{
		if(Names[i] == FromType)
		{
			std::cout << "Intern creat from " + FromType << std::endl;
			return (this->*array[i])(target);
		}
		i++;
	}
	if(i == 3)
		std::cout << "there is no fomr with that type \n";
	return NULL;
}
