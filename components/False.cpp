/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#include <iostream>
#include "False.hpp"

void nts::False::setName(std::string &name) noexcept
{
    _name = name;
}

void nts::False::simulate(std::size_t tick) noexcept
{
    return;
    std::cout << tick << std::endl;
}

nts::Tristate nts::False::compute(std::size_t pin) noexcept
{
    return nts::Tristate::FALSE;
    std::cout << pin << std::endl;
}

void nts::False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) noexcept
{
    if (1 != pin)
	return;
    _lkComp = &other;
    _lkPin = otherPin;
}

void nts::False::dump() const noexcept
{
    std::cout << _name << " " << 0 << std::endl;
}
