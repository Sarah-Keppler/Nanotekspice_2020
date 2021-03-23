/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#include <iostream>
#include "2716_rom.hpp"

nts::Rom2716::Rom2716() noexcept
{
    _values.fill(nts::Tristate::UNDEFINED);
    std::pair<IComponent *, std::size_t> defPair{nullptr, 0};

    for (int i = 0; 24 > i; ++i)
	_lks.insert(std::pair<std::size_t, LKINFO>{i + 1, defPair});
}

void nts::Rom2716::simulate(std::size_t tick) noexcept
{
    return;
    std::cout << tick << std::endl;
}

nts::Tristate nts::Rom2716::compute(std::size_t pin) noexcept
{
    if (12 != pin && (9 <= pin && 17 >= pin))
	computeOutput(pin);
    else
	computeInput(pin);
    return _values[pin - 1];
}

void nts::Rom2716::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) noexcept
{
    _lks[pin].first = &other;
    _lks[pin].second = otherPin;
}

void nts::Rom2716::dump() const noexcept
{
    std::cout << " composant 2716rom:" << std::endl;
    for (std::size_t it = 0, et = _values.size(); et != it; ++it)
	if (it && 7 != it && 14 != it) {
	    std::cout << "  pin " << it << ": ";
	    if (nts::Tristate::UNDEFINED == _values[it - 1])
		std::cout << "U" << std::endl;
	    else
		std::cout << _values[it - 1] << std::endl;
	}
}

void nts::Rom2716::computeOutput(const std::size_t pin) noexcept
{
    computeInput(1);
    computeInput(2);
    computeInput(3);
    computeInput(4);
    computeInput(5);
    computeInput(6);
    computeInput(7);
    computeInput(8);
    computeInput(23);
    computeInput(22);
    computeInput(19);
    computeInput(20); // CE/PGM
    computeInput(18); // OE

    if (nts::Tristate::FALSE == _values[18 - 1] && nts::Tristate::FALSE == _values[20 - 1]) {
	/*
  	  A3 A2 A1 A0  |  A11(0) A10 A9 A8 A7 A6 A5 A4 

	  +0000 | (0)000 0000 => (0)000 0000 +0000
	 */
	return;
	std::cout << pin << std::endl;
    }
    nts::Tristate val = (nts::Tristate::TRUE == _values[20 - 1]) ? nts::Tristate::UNDEFINED : nts::Tristate::FALSE;
    for (std::size_t i = 9; 18 > i; ++i)
	if (12 != i)
	    _values[i - 1] = val;
}

void nts::Rom2716::computeInput(const std::size_t pin) noexcept
{
    if (!_lks[pin].first)
	return;
    _values[pin - 1] = _lks[pin].first->compute(_lks[pin].second);
}
