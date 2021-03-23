/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#include <iostream>
#include <memory>
#include <functional>
#include <array>
#include "Factory.hpp"
#include "components/Input.hpp"
#include "components/Clock.hpp"
#include "components/True.hpp"
#include "components/False.hpp"
#include "components/Output.hpp"
#include "components/2716_rom.hpp"
#include "components/4001_nor.hpp"
#include "components/4011_nand.hpp"
#include "components/4030_xor.hpp"
#include "components/4040_counter.hpp"
#include "components/4069_not.hpp"
#include "components/4081_and.hpp"
#include "components/4071_or.hpp"
#include "components/Logger.hpp"

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type) const noexcept
{
    std::array<std::function<std::unique_ptr<nts::IComponent>(const nts::Factory&)>, 22> functions{&nts::Factory::createInput,
	&nts::Factory::createClock,
	&nts::Factory::createTrue,
	&nts::Factory::createFalse,
	&nts::Factory::createOutput,
	&nts::Factory::create2716,
	&nts::Factory::create4001,
	&nts::Factory::create4004,
	&nts::Factory::create4008,
	&nts::Factory::create4011,
	&nts::Factory::create4013,
	&nts::Factory::create4017,
	&nts::Factory::create4030,
	&nts::Factory::create4040,
	&nts::Factory::create4069,
	&nts::Factory::create4071,
	&nts::Factory::create4081,
	&nts::Factory::create4094,
	&nts::Factory::create4512,
	&nts::Factory::create4514,
	&nts::Factory::create4801,
        &nts::Factory::createLogger};   
    std::array<std::string, 22> comps{"input",
	"clock",
	"true",
	"false",
	"output",
	"2716",
	"4001",
	"4004",
	"4008",
	"4011",
	"4013",
	"4017",
	"4030",
	"4040",
	"4069",
	"4071",
	"4081",
	"4094",
	"4512",
	"4514",
	"4801",
        "logger"};

    // Find the component to build
    // Exit if we never built the component
    for (std::size_t it = 0; 22 > it; ++it)
	if (!type.compare(comps[it]))
	    return functions[it](*this);
    // Default return
    return functions[0](*this);
}

std::unique_ptr<nts::IComponent> nts::Factory::createInput() const noexcept
{
    return std::unique_ptr<IComponent>(new Input{});
}

std::unique_ptr<nts::IComponent> nts::Factory::createClock() const noexcept
{
    return std::unique_ptr<IComponent>(new Clock{});
}

std::unique_ptr<nts::IComponent> nts::Factory::createTrue() const noexcept
{
    return std::unique_ptr<IComponent>(new True{});
}

std::unique_ptr<nts::IComponent> nts::Factory::createFalse() const noexcept
{
    return std::unique_ptr<IComponent>(new False{});
}

std::unique_ptr<nts::IComponent> nts::Factory::createOutput() const noexcept
{
    return std::unique_ptr<IComponent>(new Output{});
}

std::unique_ptr<nts::IComponent> nts::Factory::create2716() const noexcept
{
    exit(0);
    return std::unique_ptr<IComponent>(new Rom2716{});
}

std::unique_ptr<nts::IComponent> nts::Factory::create4001() const noexcept
{
    return std::unique_ptr<IComponent>(new Nor4001{});
}

std::unique_ptr<nts::IComponent> nts::Factory::create4004() const noexcept
{
    exit(0);
    return std::unique_ptr<IComponent>(new And4081{});
}

std::unique_ptr<nts::IComponent> nts::Factory::create4008() const noexcept
{
    exit(0);
    return std::unique_ptr<IComponent>(new And4081{});
}

std::unique_ptr<nts::IComponent> nts::Factory::create4011() const noexcept
{
    return std::unique_ptr<IComponent>(new Nand4011{});
}

std::unique_ptr<nts::IComponent> nts::Factory::create4013() const noexcept
{
    exit(0);
    return std::unique_ptr<IComponent>(new And4081{});
}

std::unique_ptr<nts::IComponent> nts::Factory::create4017() const noexcept
{
    exit(0);
    return std::unique_ptr<IComponent>(new And4081{});
}

std::unique_ptr<nts::IComponent> nts::Factory::create4030() const noexcept
{
    return std::unique_ptr<IComponent>(new Xor4030{});
}

std::unique_ptr<nts::IComponent> nts::Factory::create4040() const noexcept
{
    exit(0);
    return std::unique_ptr<IComponent>(new Counter4040{});
}

std::unique_ptr<nts::IComponent> nts::Factory::create4069() const noexcept
{
    return std::unique_ptr<IComponent>(new Not4069{});
}

std::unique_ptr<nts::IComponent> nts::Factory::create4071() const noexcept
{
    return std::unique_ptr<IComponent>(new Or4071{});
}

std::unique_ptr<nts::IComponent> nts::Factory::create4081() const noexcept
{
    return std::unique_ptr<IComponent>(new And4081{});
}

std::unique_ptr<nts::IComponent> nts::Factory::create4094() const noexcept
{
    exit(0);
    return std::unique_ptr<IComponent>(new And4081{});
}

std::unique_ptr<nts::IComponent> nts::Factory::create4512() const noexcept
{
    exit(0);
    return std::unique_ptr<IComponent>(new And4081{});
}

std::unique_ptr<nts::IComponent> nts::Factory::create4514() const noexcept
{
    exit(0);
    return std::unique_ptr<IComponent>(new And4081{});
}

std::unique_ptr<nts::IComponent> nts::Factory::create4801() const noexcept
{
    exit(0);
    return std::unique_ptr<IComponent>(new And4081{});
}

std::unique_ptr<nts::IComponent> nts::Factory::createLogger() const noexcept
{
    exit(0);
    return std::unique_ptr<IComponent>(new Logger{});
}
