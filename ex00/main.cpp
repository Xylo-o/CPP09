/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:39:18 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/28 17:22:15 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << RED << "Error: " << NC << "worng usage.\nCorrect usage: ./btc <file_name.txt>" << std::endl;
		return 1;
	}
	checkFile(argv[1]);
	std::map<std::string, float> database;
	if (parseExchangeDatabase("data.csv", database) != 0) {
		std::cerr << RED << "Error: " << NC << "could not load the database." << std::endl;
	}
	if (parseInputFile(argv[1], database) != 0) {
		std::cerr << RED << "Error: " << NC << "could not load the file." << std::endl;
	}
	return 0;
}