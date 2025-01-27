/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:34:51 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/27 16:47:04 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
#include <cctype>
#include <locale>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <regex>
#include "Colors.hpp"

bool checkFile(const std::string& str);
std::string trim(const std::string& str);
bool validateLine(const std::string& date, const std::string& value, const std::string& line);
float calculateResult(const std::string& ammount, float exchangeRate);
int parseExchangeDatabase(const std::string& data, std::map<std::string, float>& database);
int parseInputFile(const std::string& data, std::map<std::string, float>& database);
