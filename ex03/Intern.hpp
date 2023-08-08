/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:42:59 by mkhairou          #+#    #+#             */
/*   Updated: 2023/08/07 16:17:21 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
public:
	Intern();
	Intern(const Intern &cpy);
	Intern &operator=(const Intern &copu);
	~Intern();
	AForm *createRobo(std::string target);
	AForm *createPresident(std::string target);
	AForm *createShrubbery(std::string target);
	AForm *makeForm(std::string FromType, std::string target);
};
