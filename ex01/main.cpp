/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 12:51:22 by lvargas-          #+#    #+#             */
/*   Updated: 2026/09/16 12:51:27 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat alice("Alice", 10);
        Bureaucrat bob("Bob", 120);

        Form tax("Tax form", 50, 20);
        Form permit("Permit", 5, 3);

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << tax << std::endl;
        std::cout << permit << std::endl;

        alice.signForm(tax);
        bob.signForm(tax);
        alice.signForm(permit);
        bob.signForm(permit);

        std::cout << tax << std::endl;
        std::cout << permit << std::endl;

        Form badHigh("BadHigh", 0, 10);
        std::cout << badHigh << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught in main: " << e.what() << std::endl;
    }
    return 0;
}
