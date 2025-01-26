/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:34:48 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/26 20:58:33 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool checkFile(const std::string& str) {
	if (str.find(".txt") != std::string::npos) {
		return true;
	}
	return false;
}

int parseExchangeDatabase(const std::string& data, std::map<std::string, float>& dataBase) {
    std::ifstream file(data);
    if (!file.is_open()) {
        std::cerr << "Error: Failed to open file." << std::endl;
        return 1;
    }
    std::string line;
    bool header = true;
    while (std::getline(file, line)) {
        if (header) {
            header = false;
            continue;
        }
        std::istringstream lineStream(line);
        std::string date, valueStr;
        if (!std::getline(lineStream, date, ',') || !std::getline(lineStream, valueStr)) {
            std::cerr << "Error: Incomplete line: " << line << std::endl;
            continue;
        }
        try {
            float value = std::stof(valueStr);
            dataBase[date] = value;
        } catch (const std::exception& e) {
            std::cerr << "Error: Failed to process value in line: " << line << " (" << e.what() << ")" << std::endl;
        }
    }
    file.close();
    return 0;
}

bool checkDate(const std::string& date) {
	std::regex datePattern(R"(\d{4}-\d{2}-\d{2})");
	return std::regex_match(date, datePattern);
}

bool checkValue(const std::string& value) {
    std::regex rangePattern(R"(^([0-9]|[1-9][0-9]{1,2}|1000)(\.\d+)?$)");
    return std::regex_match(value, rangePattern);
}

std::string trim(const std::string& str) {
    auto start = str.begin();
    while (start != str.end() && std::isspace(*start)) {
        start++;
    }

    auto end = str.end();
    do {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));

    return std::string(start, end + 1);
}


int parseInputFile(const std::string& data) {
	std::ifstream file(data);
	if (!file.is_open()) {
		std::cerr << RED << "Error: " << NC << "failed to open file." << std::endl;
	}
	std::string line;
	bool header = true;
	while (std::getline(file, line)) {
        if (header) {
            header = false;
            continue;
        }
		std::istringstream lineStream(line);
        std::string date, valueStr;

        if (!std::getline(lineStream, date, '|') || !std::getline(lineStream, valueStr)) {
            std::cerr << "Error: Incomplete line: " << line << std::endl;
            continue;
        }
		date = trim(date);
		valueStr = trim(valueStr);
        if (!checkValue(valueStr)) {
            std::cerr << "Error: Failed to process value in line: " << line << std::endl;
			continue;
		}
    	if (!checkDate(date)) {
			std::cerr << "Error: Invalid date: " << date << std::endl;
		}
    	std::cout << "Date: " << date << ", Value: " << valueStr << std::endl;
	}
    file.close();
    return 0;
}