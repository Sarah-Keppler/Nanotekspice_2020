/*
** EPITECH PROJECT, 2020
** Sarah-Keppler
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include "../Error.hpp"
#include "../components/IComponent.hpp"
#include "Parser.hpp"

static std::string& ltrim(std::string& s)
{
    auto it = std::find_if(s.begin(), s.end(),
                    [](char c) {
                        return !std::isspace<char>(c, std::locale::classic());
                    });
    s.erase(s.begin(), it);
    return s;
}

static std::string& rtrim(std::string& s)
{
    auto it = std::find_if(s.rbegin(), s.rend(),
                    [](char c) {
                        return !std::isspace<char>(c, std::locale::classic());
                    });
    s.erase(it.base(), s.end());
    return s;
}

static void clearLine(std::string& line)
{
    ltrim(rtrim(line));
}

nts::Parser::Parser(std::string const& filepath, Core& core) :
    _nPins{0}
{
    std::string line;
    std::ifstream file{openFile(filepath)};
    std::smatch match;

    /* NOTE - Skims the file and create each component till we find the link part or at eol */
    while (std::getline(_stream, line)) {
        /* NOTE - Just skip comment/empty/section name lines */
        clearLine(line);
        if (!line.find(LINK_LABEL)) break;
        if (line[0] == '#' || line.empty() || !line.find(CHIPSET_LABEL)) continue;
        if (line.find('#') != std::string::npos) {
            line = line.substr(0, line.find("#"));
            clearLine(line);
        }
        if (std::regex_search(line, match, std::regex{"^(\\S+)\\s+([^\\s(]+)(?:\\(([^\\s]+)\\))?$"})) {
            core.addComponent(match.str(1), match.str(2));
            _typeComponent.push_back({match.str(1), match.str(2)});
        }
        else throw nts::Error{"There are synthax errors."};
        ++_nPins;
    }
    if (_nPins == 0) throw nts::Error{"There is no component"};
    /* NOTE - Throw an error if there is no link label */
    if (line.find(LINK_LABEL)) throw nts::Error{"Missing link label"};
    /* NOTE - otherwise, create links */
    createLink(core);
}

std::ifstream nts::Parser::openFile(std::string const &filepath)
{
    std::ifstream file{filepath};
    std::stringstream buf;
    std::string lineContent;

    if (!std::regex_match(filepath, std::regex("(.+)(.nts$)")))
        throw nts::Error{"The file must end with the extension '.nts'"};
    if (!file.is_open()) throw nts::Error{"Cannot open file: " + filepath};
    buf << file.rdbuf();
    lineContent = buf.str();
    _stream = std::stringstream{lineContent};
    return (file);
}

void nts::Parser::checkLinkValidity(nts::Core::Link const& link) const
{
    for (auto& component : _typeComponent) {
        link.first.first.find(component.second);
        if (component.second == link.first.first) {
            if ((component.first == "output" || component.first == "input" ||
                component.first == "clock" || component.first == "false" ||
                component.first == "true") && link.first.second != 1)
                throw nts::Error{component.first + " must have 1 pin"};
            if ((component.first == "4081" || component.first == "4071" ||
                component.first == "4001" || component.first == "4030" || component.first == "4069")
                && link.first.second > 13)
                throw nts::Error{component.first + " cannot have more pins than 13"};
        }
    }
}

void nts::Parser::createLink(Core& core)
{
    nts::Core::Link link;
    std::string line;
    std::smatch match;

    /* NOTE - Skims the file and create each link till we're at eol */
    while (std::getline(_stream, line)) {
        /* NOTE - Just skip comment/empty/section name lines */
        /* REVIEW - Not sur it's necessary to check !line.find(CHIPSET_LABEL) */
        clearLine(line);
        if (line[0] == '#' || line.empty() || !line.find(CHIPSET_LABEL)) continue;
        if (std::regex_search(line, match, std::regex{"^(\\S+):(\\d+)\\s+(\\S+):(\\d+)"})) {
            link.first = {match.str(1), std::stoi(match.str(2))};
            link.second = {match.str(3), std::stoi(match.str(4))};
            if (link.second == link.first) throw nts::Error{"Impossible to link a born to itself"};
            checkLinkValidity(link);
            core.setLink(link);
        } else throw nts::Error{"There are synthax errors to set links."};
    }
}

void nts::Parser::saveArguments(int ac, char **av)
{
    std::size_t const count{ static_cast<std::size_t>(ac) };

    if (ac < 2) error("No file specified.");
    for (std::size_t i{2}; i < count; ++i) _inputs.emplace_back(av[i]);
}

nts::InputArg const& nts::Parser::findInput(std::string const &name) const
{
    for (auto const &input : _inputs)
        if (input.name == name) return (input);
    error("'" + name + "' is not initialized.");
}
