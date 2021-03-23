/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#include <iostream>
#include "Clock.hpp"

nts::Clock::Clock() noexcept : _valuePin{nts::Tristate::UNDEFINED}
{
}

void nts::Clock::setName(std::string &name) noexcept
{
    _name = name;
}

void nts::Clock::setValue(nts::Tristate value) noexcept
{
    _valuePin = value;
}

void nts::Clock::simulate(std::size_t tick) noexcept
{
    if (_valuePin != nts::Tristate::UNDEFINED)
	_valuePin = (nts::Tristate::TRUE == _valuePin) ? nts::Tristate::FALSE : nts::Tristate::TRUE;
    return;
    std::cout << tick << std::endl;
}

nts::Tristate nts::Clock::compute(std::size_t pin) noexcept
{
    return _valuePin;
    std::cout << pin << std::endl;
}

void nts::Clock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) noexcept
{
    if (1 != pin)
	return;
    _lkComp = &other;
    _lkPin = otherPin;
}

void nts::Clock::dump() const noexcept
{
    if (nts::Tristate::UNDEFINED == _valuePin)
	std::cout << "U" << std::endl;
    else
	std::cout << _valuePin << std::endl;
}
