/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:14:08 by mkhairou          #+#    #+#             */
/*   Updated: 2023/08/07 16:21:12 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 25, 5)
{
	target = "default";
	std::cout << "default constructor called \n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("formula", 25, 5)
{
	this->target = target;
	std::cout << "taget constructor called \n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy.getName(), cpy.getGradeToSign(), cpy.getGradeToExecute())
{
	*this = cpy;
	std::cout << "copy constructor called \n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "destructor called \n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copu)
{
	if (this == &copu)
		return *this;
	this->target = copu.target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned())
	{
		if (executor.getGrade() > this->getGradeToExecute())
			throw GradeTooHighException();
		else
		{
			std::ofstream file;

			file.open(target + "_shrubbery");
			file << "    *    *  ()   *   \n"
        "        * /\\         *\n"
        "      *   /i\\\\    *  *\n"
        "    *     o/\\  *      \n"
        "       ///\\i\\\\    *\n"
        "     *   //o\\\\    *\n"
        "   *    /i////*      \n"
        "        /o/\\i\\\\   \n"
        "    //i//o\\\\\\\\     *\n"
        "    * /////\\\\i\\\\n"
        " *    //o//i\\\\*\\\\   *\n"
        "   * /i///*/\\\\\\o\\\\   \n"
        "    *   ||     *\n";

		}
	}
	else
	{
		throw GradeTooHighException();
	}
}

