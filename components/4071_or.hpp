/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#ifndef NTS_4071_OR_HPP
#define NTS_4071_OR_HPP

#include <string>
#include <array>
#include <vector>
#include <map>
#include "IComponent.hpp"

#define LKINFO std::pair<IComponent *, std::size_t>

namespace nts
{
    class Or4071 : public nts::IComponent
    {
    public:
	Or4071() noexcept;
        ~Or4071() = default;

	void setName(std::string &name) noexcept;
	
        void simulate(std::size_t tick) noexcept;
        nts::Tristate compute(std::size_t pin) noexcept;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) noexcept;
        void dump() const noexcept;
    private:
	std::string _name;
	std::array<nts::Tristate, 14> _values;
	//std::vector<CINFO> _lks;
	std::map<std::size_t, LKINFO> _lks;
	//std::map<std::size_t, std::pair<IComponent *, std::size_t>> _tmap;
	// List that indicates
	/*
	  Its type
	  Its value
	  Its link
	*/
	// std::vector<std::map<std::size_t, std::pair<IComponent *, std::size_t>>>;
	// try without std::vector

	void computeOutput(const std::size_t pin) noexcept;
	void computeInput(const std::size_t pin) noexcept;
	nts::Tristate orBlock(const std::size_t pin1, const std::size_t pin2) noexcept;
    };
}

#endif /* NTS_4071_HPP */
