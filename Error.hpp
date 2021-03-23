/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#ifndef ERROR_HPP
#define ERROR_HPP

#include <string>

namespace nts
{
    class Error
    {
    public:
	Error(std::string const &message) noexcept;
	~Error() = default;

	char const *what() const noexcept;
    private:
	std::string const _message;
    };
}

#endif /* ERROR_HPP */
