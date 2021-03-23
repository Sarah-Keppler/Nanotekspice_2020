/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <memory>
#include "components/IComponent.hpp"

namespace nts {
    class Factory
    {
    public:
	Factory() = default;
	~Factory() = default;

	std::unique_ptr<nts::IComponent> createComponent(const std::string &type) const noexcept;
    private:
	std::unique_ptr<nts::IComponent> createInput() const noexcept;
	std::unique_ptr<nts::IComponent> createClock() const noexcept;
	std::unique_ptr<nts::IComponent> createTrue() const noexcept;
	std::unique_ptr<nts::IComponent> createFalse() const noexcept;
	std::unique_ptr<nts::IComponent> createOutput() const noexcept;
	std::unique_ptr<nts::IComponent> create2716() const noexcept;
	std::unique_ptr<nts::IComponent> create4001() const noexcept;
	std::unique_ptr<nts::IComponent> create4004() const noexcept;
	std::unique_ptr<nts::IComponent> create4008() const noexcept;
	std::unique_ptr<nts::IComponent> create4011() const noexcept;
	std::unique_ptr<nts::IComponent> create4013() const noexcept;
	std::unique_ptr<nts::IComponent> create4017() const noexcept;
	std::unique_ptr<nts::IComponent> create4030() const noexcept;
	std::unique_ptr<nts::IComponent> create4040() const noexcept;
	std::unique_ptr<nts::IComponent> create4069() const noexcept;
	std::unique_ptr<nts::IComponent> create4071() const noexcept;
	std::unique_ptr<nts::IComponent> create4081() const noexcept;
	std::unique_ptr<nts::IComponent> create4094() const noexcept;
	std::unique_ptr<nts::IComponent> create4512() const noexcept;
	std::unique_ptr<nts::IComponent> create4514() const noexcept;
	std::unique_ptr<nts::IComponent> create4801() const noexcept;
	std::unique_ptr<nts::IComponent> createLogger() const noexcept;
    };
}

#endif /* FACTORY_HPP */
