/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#ifndef CORE_HPP
#define CORE_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include "components/IComponent.hpp"
#include "components/Output.hpp"
#include "Factory.hpp"

namespace nts {
    class Core
    {
    public:
	Core(std::string const &filename);
	~Core() = default;

	struct Link
	{
	    std::pair<std::string, std::size_t> first;
	    std::pair<std::string, std::size_t> second;
	};

	void run() noexcept;
	void addComponent(std::string const& type, std::string const& name);
	void setLink(Link& link);
    private:
	Factory _factory;
	std::unordered_map<std::string, std::unique_ptr<nts::IComponent>> _comps;
	std::size_t _tick;
	static unsigned short _signalRcvd;
	std::unordered_map<std::string, nts::Tristate> _changes;

	void display() noexcept;
	void dump() const noexcept;
	void simulate() noexcept;
	void loop() noexcept;
	static void signalHandler(int signum);
	void changeValue(std::string const line) noexcept;
    };
}

#endif /* CORE_HPP */
