/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#include <iostream>
#include "Output.hpp"

nts::Output::Output() noexcept : _valuePin{nts::Tristate::UNDEFINED}
{
}

void nts::Output::setName(std::string &name) noexcept
{
    _name = name;
}

void nts::Output::simulate(std::size_t tick) noexcept
{
    return;
    std::cout << tick << std::endl;
}

nts::Tristate nts::Output::compute(std::size_t pin) noexcept
{
    if (_lkComp && _lkPin)
	_valuePin = _lkComp->compute(_lkPin);
    return _valuePin;
    std::cout << pin << std::endl;
}

void nts::Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) noexcept
{
    if (1 != pin)
	return;
    _lkComp = &other;
    _lkPin = otherPin;
}

void nts::Output::dump() const noexcept
{
    if (nts::Tristate::UNDEFINED == _valuePin)
	std::cout << "U" << std::endl;
    else
	std::cout << _valuePin << std::endl;
}
