/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:38:43 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/28 16:50:17 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <stdexcept>
#include <regex>

int calculatePoland(const std::string& input);
bool isOperator(const std::string& token);
int applyOperator(const std::string& op, int a, int b);