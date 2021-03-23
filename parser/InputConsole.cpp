/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-sarah.keppler [WSL: Ubuntu]
** File description:
** Input
*/

#include "InputConsole.hpp"

static std::string& ltrim(std::string& str)
{
    auto it{ std::find_if(str.begin(), str.end(), [](char c) {
        return !(std::isspace<char>(c, std::locale::classic()));
    }) };
    str.erase(str.begin(), it);
    return str;
}

static std::string& rtrim(std::string& str)
{
    auto it{ std::find_if(str.rbegin(), str.rend(), [](char c) {
        return !(std::isspace<char>(c, std::locale::classic()));
    }) };
    str.erase(it.base(), str.end());
    return (str);
}

nts::InputArg::InputArg(std::string const& argument)
{
    if (argument.find_first_of('=') != argument.find_last_of('='))
        error("Invalid syntax (unexpected token '=').");
    if (argument.find_first_of('=') == std::string::npos) error("Missing value.");

    std::string inputName{ argument.substr(0, argument.find_first_of('=')) };
    std::string inputValue{ argument.substr(argument.find_first_of('=') + 1) };
    ltrim(rtrim(inputName));
    ltrim(rtrim(inputValue));
    if (inputName.size() == 0) error("Missing name.");
    if (inputValue != "0" && inputValue != "1") error("Input value must be either 0 or 1.");
    name = inputName;
    value = inputValue;
}
