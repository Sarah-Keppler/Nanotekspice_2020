/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#include <iostream>
#include <regex>
#include "Core.hpp"
#include "Error.hpp"

int main(int const ac, char ** const av)
{
    // Verify the arguments
    if (2 > ac) {
        std::cerr << av[0] << " must have at least 2 arguments" << std::endl;
        return 84;
    }

    // Load the nanotekspice
    try {
	nts::Core core{av[1]};
	core.run();
    } catch (nts::Error const &err) {
        std::cerr << err.what() << std::endl;
        return 84;
    } catch (std::regex_error const &regexErr) {
        std::cerr << regexErr.what() << std::endl;
        return 84;
    }
    return 0;
}
