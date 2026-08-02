/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:38:37 by lvargas-          #+#    #+#             */
/*   Updated: 2026/08/02 19:59:27 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Lua", 42);
        Bureaucrat b("Alberto", 1);
        Bureaucrat c("Maria", 150);

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;

        b.incrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bad("Err", 0);
        std::cout << bad << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bad2("Err1", 151);
        std::cout << bad2 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}