/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#include <iostream>
#include "True.hpp"

void nts::True::setName(std::string &name) noexcept
{
    _name = name;
}

void nts::True::simulate(std::size_t tick) noexcept
{
    return;
    std::cout << tick << std::endl;
}

nts::Tristate nts::True::compute(std::size_t pin) noexcept
{
    return nts::Tristate::TRUE;
    std::cout << pin << std::endl;
}

void nts::True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) noexcept
{
    if (1 != pin)
	return;
    _lkComp = &other;
    _lkPin = otherPin;
}

void nts::True::dump() const noexcept
{
    std::cout << _name << " " << 1 << std::endl;
}
