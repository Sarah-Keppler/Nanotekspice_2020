/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#include <iostream>
#include "Logger.hpp"

nts::Logger::Logger() noexcept
{
    _values.fill(nts::Tristate::UNDEFINED);
    std::pair<IComponent *, std::size_t> defPair{nullptr, 0};

    for (int i = 0; 10 > i; ++i)
	_lks.insert(std::pair<std::size_t, LKINFO>{i + 1, defPair});
}

void nts::Logger::simulate(std::size_t tick __attribute__((unused))) noexcept
{
}

nts::Tristate nts::Logger::compute(std::size_t pin) noexcept
{
    computeInput(1);
    computeInput(2);
    computeInput(3);
    computeInput(4);
    computeInput(5);
    computeInput(6);
    computeInput(7);
    computeInput(8);
    computeInput(9);
    computeInput(10);
    return _values[pin - 1];
}

void nts::Logger::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) noexcept
{
    _lks[pin].first = &other;
    _lks[pin].second = otherPin;
}

void nts::Logger::dump() const noexcept
{
    std::cout << " composant logger:" << std::endl;
    for (std::size_t it = 0, et = _values.size(); et != it; ++it)
	if (it && 7 != it && 14 != it) {
	    std::cout << "  pin " << it << ": ";
	    if (nts::Tristate::UNDEFINED == _values[it - 1])
		std::cout << "U" << std::endl;
	    else
		std::cout << _values[it - 1] << std::endl;
	}
}

void nts::Logger::computeInput(const std::size_t pin) noexcept
{
    if (!_lks[pin].first)
	return;
    _values[pin - 1] = _lks[pin].first->compute(_lks[pin].second);
}
