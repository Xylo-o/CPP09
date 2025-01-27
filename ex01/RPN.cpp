/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:38:40 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/27 17:51:51 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool isOperator(const std::string& token) {
	return token == "+" || token == "-" || token == "*" || token == "/";
}

int applyOperator(const std::string& op, int a, int b) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) throw std::runtime_error("cannot divide by zero");
        return a / b;
    }
    throw std::runtime_error("invalid operator");
}

int calculatePoland(const std::string& input) {
	std::stack<int> rpn;
	std::istringstream iss(input);
	std::string token;
	while (iss >> token) {
		if (isOperator(token)) {
			if(rpn.size() < 2) {
				throw std::runtime_error("invalid expression");
			}
			int b = rpn.top(); rpn.pop();
			int a = rpn.top(); rpn.pop();
			int result = applyOperator(token, a, b);
			rpn.push(result);
		} else {
			int value = std::stoi(token);
			if (value > 9) {
				throw std::runtime_error("too big numbers in the expression");
			}
			rpn.push(std::stoi(token));
		}
	}
	if (rpn.size() != 1) {
		throw std::runtime_error("invalid expression");
	}
	return rpn.top();
}