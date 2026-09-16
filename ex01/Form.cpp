/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 11:43:34 by lvargas-          #+#    #+#             */
/*   Updated: 2026/09/16 12:56:41 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name("Unnamed"), is_signed(false), req_sign(100), req_exec(150)
{
    std::cout << "Form default constructor called." << std::endl;
}

Form::Form(const std::string name, const int req_sign, const int req_exec) 
    : name(name), is_signed(false), req_sign(req_sign), req_exec(req_exec)
{
    if (req_sign < 1 || req_exec < 1)
        throw GradeTooHighException();
    if (req_sign > 150 || req_exec > 150)
        throw GradeTooLowException();

    std::cout << "Form constructor called." << std::endl;
}

Form::Form(const Form& other) : name(other.name), is_signed(other.is_signed), req_sign(other.req_sign), req_exec(other.req_exec)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        this->is_signed = other.is_signed;
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::string Form::getName() const
{
    return(name);
}

bool Form::getIs_signed() const
{
    return(is_signed);
}

int Form::getReq_sign() const
{
    return(req_sign);
}

int Form::getReq_exec() const
{
    return(req_exec);
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName() << std::endl << "Is signed: " << form.getIs_signed() << std::endl
       << "Grade required to sign the form: " << form.getReq_sign() << std::endl 
       << "Grade required to execute the form: " << form.getReq_exec() << std::endl;
    return os;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (getIs_signed() == true)
        return ;
    if (bureaucrat.getGrade() <= getReq_sign())
        is_signed = true;
    else
        throw GradeTooLowException();
}
