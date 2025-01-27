/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:34:48 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/27 16:46:43 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool checkFile(const std::string& str) {
	if (str.find(".txt") != std::string::npos) {
		return true;
	}
	return false;
}

std::string trim(const std::string& str) {
    auto start = std::find_if_not(str.begin(), str.end(), [](unsigned char ch) {
        return std::isspace(ch);
    });
    auto end = std::find_if_not(str.rbegin(), str.rend(), [](unsigned char ch) {
        return std::isspace(ch);
    }).base();
    return (start < end ? std::string(start, end) : std::string());
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
        line = trim(line);
        if (line.empty()) {
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

bool validateLine(const std::string& date, const std::string& value, const std::string& line) {
    std::regex datePattern(R"(\d{4}-\d{2}-\d{2})");
    std::regex floatPattern(R"([-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?)");
    std::regex formatPattern(R"(\d{4}-\d{2}-\d{2} \| [-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?)");
	if (!std::regex_match(line, formatPattern)) {
        std::cerr << RED << "Error: " << NC << "bad input => " << line << std::endl;
        return false;
    }
	if (!std::regex_match(date, datePattern)) {
        std::cerr << RED << "Error: " << NC << "invalid date " << date << std::endl;
        return false;
    }
    if (!std::regex_match(value, floatPattern)) {
        std::cerr << RED << "Error: " << NC << "invalid value " << value << std::endl;
        return false;
    }
    float tmp = std::stof(value);
    if (tmp < 0) {
        std::cerr << RED << "Error: " << NC << "not a positive number " << value << std::endl;
        return false;
    } else if (tmp > 1000) {
        std::cerr << RED << "Error: " << NC << "too large number " << value << std::endl;
        return false;
    }
    return true;
}

int parseInputFile(const std::string& data, std::map<std::string, float>& dataBase) {
    std::ifstream file(data);
    if (!file.is_open()) {
        std::cerr << "Error: failed to open file." << std::endl;
        return 1;
    }
    std::string line;
    bool header = true;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        if (header) {
            header = false;
            continue;
        }
        line = trim(line);
        std::istringstream lineStream(line);
        std::string date, valueStr;
        if (!std::getline(lineStream, date, '|') || !std::getline(lineStream, valueStr)) {
            std::cerr << RED << "Error: " << NC << "bad input => " << line << std::endl;
            continue;
        }
        date = trim(date);
        valueStr = trim(valueStr);
        if (!validateLine(date, valueStr, line)) {
            continue;
		}
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