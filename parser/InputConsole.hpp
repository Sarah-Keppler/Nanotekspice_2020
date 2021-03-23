/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-sarah.keppler [WSL: Ubuntu]
** File description:
** Input
*/

#pragma once

#include <string>

namespace nts
{
    class InputArg
    {
        public:
            InputArg(std::string const &argument);
            ~InputArg() = default;

            std::string name;
            std::string value;
    };
}

#include "Parser.hpp"
