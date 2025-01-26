/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:34:48 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/26 22:55:26 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool checkFile(const std::string& str) {
	if (str.find(".txt") != std::string::npos) {
		return true;
	}
	return false;
}

void checkDate(const std::string& date) {
	std::regex datePattern(R"(\d{4}-\d{2}-\d{2})");
	if (!std::regex_match(date, datePattern)) {
		std::cerr << RED << "Error: " << NC << "invalid date." << std::endl;
	}
}

bool checkValue(const std::string& value) {
	float tmp = std::stof(value);
	if (tmp < 0) {
		std::cerr << RED << "Error: " << NC << "not a positive number." << std::endl;
		return false;
	} else if (tmp > 1000) {
		std::cerr << RED << "Error: " << NC << "too large number." << std::endl;
		return false;
	}
    std::regex rangePattern(R"(^([0-9]|[1-9][0-9]{1,2}|1000)(\.\d+)?$)");
    if (!std::regex_match(value, rangePattern)) {
		std::cerr << RED << "Error: " << NC << "invalid value." << std::endl;
		return false;
	}
	return true;
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

float calculateResult(const std::string& ammount, float exchangeRate) {
	float newAmmount = std::stof(ammount);
	return newAmmount * exchangeRate;
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
            std::cerr << RED << "Error: " << NC << "bad input => " << line << std::endl;
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

int parseInputFile(const std::string& data, std::map<std::string, float>&dataBase) {
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
        	std::cerr << RED << "Error: " << NC << "bad input => " << line << std::endl;
            continue;
        }
		date = trim(date);
		valueStr = trim(valueStr);
        if (!checkValue(valueStr)) {
			continue;
		}
    	checkDate(date);
        auto it = dataBase.lower_bound(date);
        if (it == dataBase.end() || it->first != date) {
            if (it == dataBase.begin()) {
                std::cerr << "Error: no exchange rate found for date: " << date << std::endl;
                continue;
            }
            --it;
        }
        float exchangeRate = it->second;
		float result = calculateResult(valueStr, exchangeRate);
    	std::cout << date << " => " << valueStr << " * " << exchangeRate << " = " << result << std::endl;
	}
    file.close();
    return 0;
}