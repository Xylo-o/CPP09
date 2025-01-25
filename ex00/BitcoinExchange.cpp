/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:34:48 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/25 20:34:13 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool checkFile(const std::string& str) {
	if (str.find(".csv") != std::string::npos) {
		return true;
	}
	return false;
}


int parseExchangeDatabase(const std::string& data) {
	std::ifstream file(data);
	if (!file.is_open()) {
		std::cerr << RED << "Error: " << NC << "failed to open file." << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(file, line)) {
		std::map<int, std::string> bitcoinDB = splitToTokens(line);
		for (const auto& pair : bitcoinDB) {
            if (checkDate(pair.second)) {
                std::cout << "Valid date found: " << pair.second << std::endl;
            } else if (checkValue(pair.second)) {
                std::cout << "Valid number found: " << pair.second << std::endl;
            } else {
                std::cout << "Invalid token: " << pair.second << std::endl;
            }
		}
	}
	file.close();
	return 0;
}

std::map<int, std::string> splitToTokens(const std::string& line) {
	std::map<int, std::string> tokens;
	std::istringstream iss(line);
	std::string token;
	int index = 0;
	while (std::getline(iss, token, ',')) {
		tokens[index++] = token;
	}
	return tokens;
}

bool checkDate(const std::string& date) {
	std::regex datePattern(R"(\\d{4}-\d{2}-\d{2})");
	return std::regex_match(date, datePattern);
}

bool checkValue(const std::string& value) {
	std::regex floatPattern(R"(^\d+(\.\d+)?&)");
	std::regex intPattern(R"(^\d+$)");
	if (std::regex_match(value, floatPattern) || std::regex_match(value, intPattern)) {
		std::regex rangePattern(R"(^([0-9]|[1-9][0-9]{1,2}|1000)(\.\d+)?$)");
		return std::regex_match(value, rangePattern);
	}
	return false;
}

// int parseInputFile(const std::string& data) {
// 	std::ifstream file(data);
// 	if (!file.is_open()) {
// 		std::cerr << RED << "Error: " << NC << "failed to open file." << std::endl;
// 	}
// 	std::string line;
// 	while (std::getline(file, line)) {
// 		std::cout << line << std::endl;
// 	}
// }