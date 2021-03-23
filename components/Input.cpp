/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#include <iostream>
#include "Input.hpp"

nts::Input::Input() noexcept : _valuePin{nts::Tristate::UNDEFINED}
{
}

void nts::Input::setName(std::string &name) noexcept
{
    _name = name;
}

void nts::Input::setValue(nts::Tristate value) noexcept
{
    _valuePin = value;
}

void nts::Input::simulate(std::size_t tick) noexcept
{
    return;
    std::cout << tick << std::endl;
}

nts::Tristate nts::Input::compute(std::size_t pin) noexcept
{
    return _valuePin;
    std::cout << pin << std::endl;
}

void nts::Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) noexcept
{
    if (1 != pin)
	return;
    _lkComp = &other;
    _lkPin = otherPin;
}

void nts::Input::dump() const noexcept
{
    if (nts::Tristate::UNDEFINED == _valuePin)
	std::cout << "U" << std::endl;
    else
	std::cout << _valuePin << std::endl;
}
