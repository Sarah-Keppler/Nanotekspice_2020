/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#include <iostream>
#include "4069_not.hpp"

nts::Not4069::Not4069() noexcept
{
    _values.fill(nts::Tristate::UNDEFINED);
    std::pair<IComponent *, std::size_t> defPair{nullptr, 0};

    for (int i = 0; 14 > i; ++i)
	_lks.insert(std::pair<std::size_t, LKINFO>{i + 1, defPair});
}

void nts::Not4069::setName(std::string &name) noexcept
{
    _name = name;
}

void nts::Not4069::simulate(std::size_t tick) noexcept
{
    return;
    std::cout << tick << std::endl;
}

nts::Tristate nts::Not4069::compute(std::size_t pin) noexcept
{
    if (2 == pin || 4 == pin || 6 == pin || 8 == pin || 10 == pin || 12 == pin)
	computeOutput(pin);
    else
	computeInput(pin);
    return _values[pin - 1];
}

void nts::Not4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) noexcept
{
    _lks[pin].first = &other;
    _lks[pin].second = otherPin;
}

void nts::Not4069::dump() const noexcept
{
    std::cout << " composant 4069not:" << std::endl;
    for (std::size_t it = 0, et = _values.size(); et != it; ++it)
	if (it && 7 != it && 14 != it) {
	    std::cout << "  pin " << it << ": ";
	    if (nts::Tristate::UNDEFINED == _values[it - 1])
		std::cout << "U" << std::endl;
	    else
		std::cout << _values[it - 1] << std::endl;
	}
}

void nts::Not4069::computeOutput(const std::size_t pin) noexcept
{
    if (2 == pin) {
	computeInput(1);
	_values[pin - 1] = notBlock(1);
    } else if (4 == pin) {
	computeInput(3);
	_values[pin - 1] = notBlock(3);
    } else if (6 == pin) {
	computeInput(5);
	_values[pin - 1] = notBlock(5);
    } else if (8 == pin) {
	computeInput(9);
	_values[pin - 1] = notBlock(9);
    } else if (10 == pin) {
	computeInput(11);
	_values[pin - 1] = notBlock(11);
    } else if (12 == pin) {
	computeInput(13);
	_values[pin - 1] = notBlock(13);
    }
}

void nts::Not4069::computeInput(const std::size_t pin) noexcept
{
    if (!_lks[pin].first)
	return;
    _values[pin - 1] = _lks[pin].first->compute(_lks[pin].second);
}

nts::Tristate nts::Not4069::notBlock(const std::size_t pin) noexcept
{
    if (nts::Tristate::UNDEFINED == _values[pin - 1])
	return nts::Tristate::UNDEFINED;
    return (_values[pin - 1]) ? nts::Tristate::FALSE : nts::Tristate::TRUE;
}
