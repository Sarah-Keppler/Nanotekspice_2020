/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#include <iostream>
#include "4040_counter.hpp"

nts::Counter4040::Counter4040() noexcept : _lastCl{nts::Tristate::UNDEFINED}, _saveVal{0}
{
    _values.fill(nts::Tristate::UNDEFINED);
    std::pair<IComponent *, std::size_t> defPair{nullptr, 0};

    for (int i = 0; 16 > i; ++i)
	_lks.insert(std::pair<std::size_t, LKINFO>{i + 1, defPair});
}

void nts::Counter4040::simulate(std::size_t tick __attribute__((unused))) noexcept
{
}

nts::Tristate nts::Counter4040::compute(std::size_t pin) noexcept
{
    if (8 != pin && 16 != pin && 10 != pin && 11 != pin)
	computeOutput(pin);
    else
	computeInput(pin);
    return _values[pin - 1];
}

void nts::Counter4040::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) noexcept
{
    _lks[pin].first = &other;
    _lks[pin].second = otherPin;
}

void nts::Counter4040::dump() const noexcept
{
    std::cout << " composant 4040counter:" << std::endl;
    for (std::size_t it = 0, et = _values.size(); et != it; ++it)
	if (it && 7 != it && 14 != it) {
	    std::cout << "  pin " << it << ": ";
	    if (nts::Tristate::UNDEFINED == _values[it - 1])
		std::cout << "U" << std::endl;
	    else
		std::cout << _values[it - 1] << std::endl;
	}
}

void nts::Counter4040::computeOutput(const std::size_t pin) noexcept
{
    computeInput(11);
    computeInput(10);

    if (_values[10 - 1] == nts::Tristate::UNDEFINED)
	for (std::size_t it = 1; 15 > it; ++it)
	    if (8 != it && 10 != it && 11 != it)
		_values[it - 1] = nts::Tristate::UNDEFINED;
    if (nts::Tristate::TRUE == _values[11 - 1])
	_saveVal = 0;
    else if (nts::Tristate::FALSE == _values[10 - 1] && nts::Tristate::TRUE == _lastCl)
	++_saveVal;
    _lastCl = _values[10 - 1];
    if (12 == pin)
	_values[pin - 1] = nts::Tristate::UNDEFINED;
    else if ((_saveVal >> _values[pin - 1]) & 1)
	_values[pin - 1] = nts::Tristate::TRUE;
    else
	_values[pin - 1] = nts::Tristate::FALSE;
}

void nts::Counter4040::computeInput(const std::size_t pin) noexcept
{
    if (!_lks[pin].first)
	return;
    _values[pin - 1] = _lks[pin].first->compute(_lks[pin].second);
}
