/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#ifndef NTS_2716_ROM_HPP
#define NTS_2716_ROM_HPP

#include <string>
#include <array>
#include <vector>
#include <map>
#include "IComponent.hpp"

#define LKINFO std::pair<IComponent *, std::size_t>

namespace nts
{
    class Rom2716 : public nts::IComponent
    {
    public:
	Rom2716() noexcept;
        ~Rom2716() = default;

        void simulate(std::size_t tick) noexcept;
        nts::Tristate compute(std::size_t pin) noexcept;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) noexcept;
        void dump() const noexcept;
    private:
	std::array<nts::Tristate, 24> _values;
	std::map<std::size_t, LKINFO> _lks;

	void computeOutput(const std::size_t pin) noexcept;
	void computeInput(const std::size_t pin) noexcept;
    };
}

#endif /* NTS_4081_HPP */
