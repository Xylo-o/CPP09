/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:38:40 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/27 17:31:19 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int calculatePoland(const std::string& input) {
	std::stack<int> rpn;
	std::istringstream iss(input);
	std::string token;
	while (iss >> token) {
		
	}
	return rpn.top();
}