/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:34:51 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/26 20:21:09 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <regex>
#include "Colors.hpp"

bool checkFile(const std::string& str);
int parseExchangeDatabase(const std::string& data, std::map<std::string, float>& database);
std::map<std::string, std::string> splitToTokens(const std::string& line);
bool checkDate(const std::string& date);
bool checkValue(const std::string& value);
bool isValidFloat(const std::string& str);
// int parseInputFile(const std::string& data);
