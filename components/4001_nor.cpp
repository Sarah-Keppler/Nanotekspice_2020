/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#include <iostream>
#include "4001_nor.hpp"

nts::Nor4001::Nor4001() noexcept
{
    _values.fill(nts::Tristate::UNDEFINED);
    std::pair<IComponent *, std::size_t> defPair{nullptr, 0};

    for (int i = 0; 14 > i; ++i)
	_lks.insert(std::pair<std::size_t, LKINFO>{i + 1, defPair});
}

void nts::Nor4001::setName(std::string &name) noexcept
{
    _name = name;
}

void nts::Nor4001::simulate(std::size_t tick) noexcept
{
    return;
    std::cout << tick << std::endl;
}

nts::Tristate nts::Nor4001::compute(std::size_t pin) noexcept
{
    if (3 == pin || 4 == pin || 11 == pin || 10 == pin)
	computeOutput(pin);
    else
	computeInput(pin);
    return _values[pin - 1];
}

void nts::Nor4001::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) noexcept
{
    _lks[pin].first = &other;
    _lks[pin].second = otherPin;
}

void nts::Nor4001::dump() const noexcept
{
    std::cout << " composant 4001nor:" << std::endl;
    for (std::size_t it = 0, et = _values.size(); et != it; ++it)
	if (it && 7 != it && 14 != it) {
	    std::cout << "  pin " << it << ": ";
	    if (nts::Tristate::UNDEFINED == _values[it - 1])
		std::cout << "U" << std::endl;
	    else
		std::cout << _values[it - 1] << std::endl;
	}
}

void nts::Nor4001::computeOutput(const std::size_t pin) noexcept
{
    if (3 == pin) {
	computeInput(1);
	computeInput(2);
	_values[pin - 1] = norBlock(1, 2);
    } else if (4 == pin) {
	computeInput(6);
	computeInput(5);
	_values[pin - 1] = norBlock(6, 5);
    } else if (11 == pin) {
	computeInput(12);
	computeInput(13);
	_values[pin - 1] = norBlock(12, 13);
    } else if (10 == pin) {
	computeInput(8);
	computeInput(9);
	_values[pin - 1] = norBlock(8, 9);
    }
}

void nts::Nor4001::computeInput(const std::size_t pin) noexcept
{
    if (!_lks[pin].first)
	return;
    _values[pin - 1] = _lks[pin].first->compute(_lks[pin].second);
}

nts::Tristate nts::Nor4001::norBlock(const std::size_t pin1, const std::size_t pin2) noexcept
{
    nts::Tristate vpin1 = _values[pin1 - 1], vpin2 = _values[pin2 - 1];
    if (nts::Tristate::FALSE == vpin1 && nts::Tristate::FALSE == vpin2)
	return nts::Tristate::TRUE;
    if ((nts::Tristate::UNDEFINED == vpin1 && nts::Tristate::FALSE == vpin2) ||
	(nts::Tristate::UNDEFINED == vpin1 && nts::Tristate::UNDEFINED == vpin2) ||	
	(nts::Tristate::FALSE == vpin1 && nts::Tristate::UNDEFINED == vpin2))
	return nts::Tristate::UNDEFINED;
    return nts::Tristate::FALSE;
}
