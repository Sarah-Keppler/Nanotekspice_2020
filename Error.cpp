/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#include "Error.hpp"

nts::Error::Error(std::string const &message) noexcept : _message{message}
{
}

char const *nts::Error::what() const noexcept
{
    return _message.c_str();
}
