/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:34:51 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/26 22:55:52 by adprzyby         ###   ########.fr       */
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
void checkDate(const std::string& date);
bool checkValue(const std::string& value);
std::string trim(const std::string& str);
float calculateResult(const std::string& ammount, float exchangeRate);
int parseExchangeDatabase(const std::string& data, std::map<std::string, float>& database);
int parseInputFile(const std::string& data, std::map<std::string, float>& database);
