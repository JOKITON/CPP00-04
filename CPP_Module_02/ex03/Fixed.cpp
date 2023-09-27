/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:53:34 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/09/28 01:41:33 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ex00 Functions
// --------------

Fixed::Fixed( void ) : fixed (0) {
	//std::cout << "[Fixed] Constructor called" << std::endl;
	return ;
}

Fixed::~Fixed( void ) {
	//std::cout << "[Fixed] Destructor called" << std::endl;
	return ;
}

Fixed::Fixed( Fixed& p) {
	std::cout << "[Fixed] Copy Constructor called" << std::endl;
	this->fixed = p.fixed;
	//*this = p; // deep copy, not appropiate in this case
}

Fixed& Fixed::operator=( Fixed& p ) {
	std::cout << "[Fixed] Copy Assigment Operator Called" << std::endl;
	if (this != &p) // Check for self-assignment
		this->fixed = p.getRawBits();
	return (p);
}

int	Fixed::getRawBits() const {
	//std::cout << "[Fixed] getRawBits called" << std::endl;
	return (this->fixed);
}

void	Fixed::setRawBits( int const raw ) {
	this->fixed = raw;
}

// ex01 Functions
// --------------

Fixed& Fixed::operator=( const Fixed& p ) {
	std::cout << "[Fixed] Copy Assigment Operator Called" << std::endl;
	if (this != &p) // Check for self-assignment
		this->fixed = p.getRawBits();
	return ((Fixed&)p);
}

Fixed::Fixed ( const Fixed& p) {
	std::cout << "[Fixed] Const Copy Constuctor called." << std::endl;
	this->fixed = p.fixed;
	//*this = p; // Calls Copy Assigment Operator, not appropiate in this case
}

Fixed::Fixed ( const int p) {
	//std::cout << "[Fixed] Int Constuctor called." << std::endl;
	this->fixed = p * (1 << this->fract);
}

Fixed::Fixed ( const float p) {
	//std::cout << "[Fixed] Float Constuctor called." << std::endl;
	this->fixed = roundf(p * (1 << this->fract));
}

float	Fixed::toFloat ( void ) const {
	return static_cast<float>(this->fixed) / (1 << this->fract);
}

int	Fixed::toInt ( void ) const {
	return (int)(this->fixed / ( 1 << this->fract));
}

std::ostream& operator<<(std::ostream& out, const Fixed& t) {
    out << t.toFloat();
    return out;
}

// ex02 Functions
// --------------

bool Fixed::operator>(const Fixed& p) const {
    if ((this->fixed * (1 << this->fract)) > (p.fixed * (1 << p.fract)))
        return true;
    return false;
}

bool Fixed::operator<(const Fixed& p) const {
    if ((this->fixed * (1 << this->fract)) < (p.fixed * (1 << p.fract)))
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed& p) const {
    if ((this->fixed * (1 << this->fract)) >= (p.fixed * (1 << p.fract)))
        return true;
   	else
		return false;
}

bool Fixed::operator<=(const Fixed& p) const {
    if ((this->fixed * (1 << this->fract)) <= (p.fixed * (1 << p.fract)))
        return true;
    else
		return false;
}

bool Fixed::operator==(const Fixed& p) const {
    if ((this->fixed * (1 << this->fract)) == (p.fixed * (1 << p.fract)))
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed& p) const {
    if ((this->fixed * (1 << this->fract)) != (p.fixed * (1 << p.fract)))
        return true;
    return false;
}

Fixed Fixed::operator+(const Fixed& p) const {
    Fixed result;
    result.fixed = this->fixed + p.fixed;
    return result;
}

Fixed Fixed::operator-(const Fixed& p) const {
    Fixed result;
    result.fixed = this->fixed - p.fixed;
    return result;
}

Fixed Fixed::operator*(const Fixed& p) const {
    Fixed result;
    result.fixed = (this->fixed * p.fixed) >> 8;
    return result;
}

Fixed Fixed::operator/(const Fixed& p) const {
    Fixed result;
    result.fixed = (this->fixed / p.fixed) << 8;
    return result;
}

Fixed& Fixed::operator++( void ) {
    std::cout << "[Fixed] Pre-increment operator called" << std::endl;
	this->fixed++;
	return (*this);
}

Fixed Fixed::operator++( int ) {
    std::cout << "[Fixed] Post-increment operator called" << std::endl;
	this->fixed++;
	return (*this);
}

Fixed& Fixed::operator--( void ) {
    std::cout << "[Fixed] Pre-decrement operator called" << std::endl;
	this->fixed--;
	return (*this);
}

Fixed Fixed::operator--( int ) {
    std::cout << "[Fixed] Post-decrement operator called" << std::endl;
	Fixed t(*this);
	this->fixed--;
	return (t);
}
