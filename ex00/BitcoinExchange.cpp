/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:34:48 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/25 18:18:09 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool checkFile(std::string str) {
	if (str.find(".txt") != std::string::npos) {
		return true;
	}
	return false;
}

int parseInputFile(std::string data) {
	std::ifstream file(data);
	if (!file.is_open()) {
		std::cerr << RED << "Error: " << NC << "failed to open file." << std::endl;
	}
	std::string line;
	while (std::getline(file, line)) {
		std::cout << line << std::endl;
	}
}

int parseExchangeDatabase(std::string data) {
	std::ifstream file(data);
	if (!file.is_open()) {
		std::cerr << RED << "Error: " << NC << "failed to open file." << std::endl;
		return 1;
	}
	
	std::string line;
	while (std::getline(file, line)) {
		std::cout << line << std::endl;
	}
	
	file.close();
	return 0;
}

void splitLines(std::string line) {
	
}