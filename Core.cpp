/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#include <iostream>
#include <algorithm>
#include <memory>
#include <csignal>
#include "Core.hpp"
#include "Error.hpp"
#include "parser/Parser.hpp"
#include "Factory.hpp"
#include "components/Input.hpp"
#include "components/Output.hpp"
#include "components/Clock.hpp"

unsigned short nts::Core::_signalRcvd = 0;

nts::Core::Core(std::string const &filename) : _tick{0}
{
    Parser parser{filename, *this};

    // Simulate the true and false components
    for (std::unordered_map<std::string, std::unique_ptr<nts::IComponent>>::const_iterator it = _comps.cbegin(), et = _comps.cend(); et != it; ++it)
	(*it).second->compute(1);
}

void nts::Core::setLink(Link& link)
{
    // Does the component exist?
    if (_comps.find(link.first.first) == _comps.end())
	throw nts::Error("Unknow component name '" + link.first.first + "'.");
    if (_comps.find(link.second.first) == _comps.end())
	throw nts::Error("Unknow component name '" + link.second.first + "'.");

    // Set the links in both ways
    _comps[link.first.first].get()->setLink(link.first.second, *_comps[link.second.first].get(), link.second.second);
    _comps[link.second.first].get()->setLink(link.second.second, *_comps[link.first.first].get(), link.first.second);
}

void nts::Core::addComponent(std::string const& type, std::string const& name)
{
    std::unique_ptr<nts::IComponent> compo;

    // Does the name is already used?
    if (_comps.find(name) != _comps.end())
	throw nts::Error{"'" + name + "': name already used"};

    // Create the component and add it to the list
    compo = _factory.createComponent(type);
    _comps.emplace(name, std::move(compo));
}

void nts::Core::run() noexcept
{
    // Take all arguments after the [file.nts] as command from the user
    /*
      std::vector<std::string>args{_parser.getDataArgs()};
    */
    std::vector<std::string>args{};//{"simulate", "display"}; // tmp
    for (std::string cmmd : args) {
	std::cout << "> " << cmmd;
	cmmd.erase(std::remove(cmmd.begin(), cmmd.end(), ' '), cmmd.end());	
	if (!cmmd.compare("exit"))
	    return;
	else if (!cmmd.compare("display"))
	    display();
	else if (!cmmd.compare("dump"))
	    dump();
	else if (!cmmd.compare("simulate"))
	    simulate();
	else if (!cmmd.compare("loop"))
	    loop();
	else if (cmmd.find("=") != std::string::npos)
	    changeValue(cmmd);
	else
	    std::cout << " -- Bad input --" << std::endl;
    }

    // Get a command from the user and act in consequence
    // Other ways to end the loop: CTRL+D
    std::string cmmd;
    std::cout << "> ";
    while (std::getline(std::cin, cmmd)) {
	cmmd.erase(std::remove(cmmd.begin(), cmmd.end(), ' '), cmmd.end());
	if (!cmmd.compare("exit"))
	    return;
	else if (!cmmd.compare("display"))
	    display();
	else if (!cmmd.compare("dump"))
	    dump();
	else if (!cmmd.compare("simulate"))
	    simulate();
	else if (!cmmd.compare("loop"))
	    loop();
	else if (cmmd.find("=") != std::string::npos)
	    changeValue(cmmd);
	else
	    std::cout << " -- Bad input --" << std::endl;
	std::cout << "> ";
    }
}

void nts::Core::display() noexcept
{
    // Display tick
    std::cout << "tick: " << _tick << std::endl;

    // Get and Sort the Input and Ouput components
    std::vector<std::string> inputs, outputs;
    for (std::unordered_map<std::string, std::unique_ptr<nts::IComponent>>::const_iterator it = _comps.cbegin(), et = _comps.cend(); et != it; ++it) {
	if (dynamic_cast<Input *>((*it).second.get()))
	    inputs.push_back((*it).first);
	if (dynamic_cast<Clock *>((*it).second.get()))
	    inputs.push_back((*it).first);
	if (dynamic_cast<Output *>((*it).second.get()))
	    outputs.push_back((*it).first);
    }
    std::sort(inputs.begin(), inputs.end());
    std::sort(outputs.begin(), outputs.end());

    // Display Input and Output components
    std::cout << "input(s):" << std::endl;
    for (std::string str : inputs) {
	std::cout << "  " << str << ": ";
	_comps[str]->dump();
    }
    std::cout << "output(s):" << std::endl;
    for (std::string str : outputs) {
	std::cout << "  " << str << ": ";
	_comps[str]->dump();
    }
}

void nts::Core::dump() const noexcept
{
    // Display by using the dump() of every components. (May change the display method)
    for (std::unordered_map<std::string, std::unique_ptr<nts::IComponent>>::const_iterator it = _comps.cbegin(), et = _comps.cend(); et != it; ++it) {
	std::cout << (*it).first << ": ";
	(*it).second->dump();
    }
}

void nts::Core::simulate() noexcept
{
    // Increase tick
    ++_tick;

    // Simulate
    for (std::unordered_map<std::string, std::unique_ptr<nts::IComponent>>::const_iterator it = _comps.cbegin(), et = _comps.cend(); et != it; ++it)
	(*it).second->simulate(_tick);

    // Update Values
    for (std::unordered_map<std::string, nts::Tristate>::const_iterator it = _changes.begin(), et = _changes.end(); et != it; ++it) {
	if (dynamic_cast<nts::Input *>(_comps[(*it).first].get()))
	    ((nts::Input *)_comps[(*it).first].get())->setValue(it->second);
	else
	    ((nts::Clock *)_comps[(*it).first].get())->setValue(it->second);
    }
    _changes.clear();

    // Compute every output to compute the whole circuit
    for (std::unordered_map<std::string, std::unique_ptr<nts::IComponent>>::const_iterator it = _comps.cbegin(), et = _comps.cend(); et != it; ++it)
	if (dynamic_cast<Output *>((*it).second.get()))
	    (*it).second->compute(1);
}

void nts::Core::signalHandler(int signum __attribute__((unused)))
{
    ++_signalRcvd;
}

void nts::Core::loop() noexcept
{
    // Simulate and Display until the program received the SIGINT signal
    signal(SIGINT, nts::Core::signalHandler);
    while (!_signalRcvd) {
	simulate();
	display();
    }
    --_signalRcvd;
}

void nts::Core::changeValue(std::string const line) noexcept
{
    // Get the Name part and the Value part
    std::size_t found = line.find("=");
    std::string name = line.substr(0, found), value = line.substr(found + 1);

    // Verify value
    if (1 != value.size() || std::string::npos != value.find_first_not_of("10U")) {
	std::cout << "Wrong input" << std::endl;
	return;
    }

    // Prepare value
    nts::Tristate v = nts::Tristate::UNDEFINED;
    if (!value.compare("1"))
	v = nts::Tristate::TRUE;
    else if (!value.compare("0"))
	v = nts::Tristate::FALSE;

    // Save the changement the value of the component named as 'name'
    for (std::unordered_map<std::string, std::unique_ptr<nts::IComponent>>::const_iterator it = _comps.cbegin(), et = _comps.cend(); et != it; ++it)
	if (!name.compare((*it).first)) {
	    if (dynamic_cast<nts::Input *>((*it).second.get()) ||
		dynamic_cast<nts::Clock *>((*it).second.get())) {
		_changes.insert(std::pair<std::string, nts::Tristate>{name, v});
		// difference between make_pair and create directly a pair?
	    }
	    return;
	}

    // The component named as 'name' does not exist
    std::cout << " -- Wrong input --" << std::endl;
}
