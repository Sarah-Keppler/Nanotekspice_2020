/*
** EPITECH PROJECT, 2020
** Sarah-Keppler
*/

#ifndef PARSER_HPP
#define PARSER_HPP

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include "../Core.hpp"
#include "InputConsole.hpp"

#define cOut(data) std::cout << data << std::endl;
#define error(message) throw std::string{message}
#define LINK_LABEL ".links:"
#define CHIPSET_LABEL ".chipsets:"

namespace nts
{
    class Parser
    {
    public:
        /**
         * @brief Parses the file and initialize the core class
         *
         * @param filepath Path to the component file
         * @param core Reference to the main class
         */
        Parser(std::string const& filepath, nts::Core& core);
        ~Parser() = default;

        /**
         * @brief Simple struct to order the links and to avoid to have too many variables everywhere
         *
         */
        struct Link
        {
            std::pair<std::string, std::size_t> first;
            std::pair<std::string, std::size_t> second;
        };

        /**
         * @brief Opens a file and save first line in _lineContent and stream in _stream
         *
         * @param filepath Path to the file
         */
        std::ifstream openFile(std::string const &filepath);

        /**
         * @brief Saves arguments in _input variable
         *
         * @param ac
         * @param av
         */
        void saveArguments(int ac, char **av);

        /**
         * @brief Returns asked input
         *
         * @param name Name of Input
         * @return (InputArg const& input)
         */
        InputArg const& findInput(std::string const &name) const;

        void createLink(Core& core);

        void checkLinkValidity(nts::Core::Link const& link) const;

    private:
        std::stringstream _stream;
        std::vector<InputArg> _inputs;
        std::vector<std::pair<std::string, std::string>> _typeComponent;
        std::size_t _nPins;
    };
}

#endif /* PARSER_HPP */
