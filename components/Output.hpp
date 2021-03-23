/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <string>
#include "IComponent.hpp"

namespace nts
{
    class Output : public nts::IComponent
    {
    public:
	Output() noexcept;
        ~Output() = default;

	void setName(std::string &name) noexcept;
	
        void simulate(std::size_t tick) noexcept;
        nts::Tristate compute(std::size_t pin) noexcept;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) noexcept;
        void dump() const noexcept;
    private:
	std::string _name;
	IComponent *_lkComp;
	std::size_t _lkPin;
	nts::Tristate _valuePin;
    };
}

#endif /* OUTPUT_HPP */
