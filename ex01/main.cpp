/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:38:37 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/27 17:46:26 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char** argv) {
	if (argc != 2) {
		std::cerr << RED << "Error: " << NC << "correct usage : ./RPN \"expression\"" << std::endl;
		return 1;
	}
    try {
        int result = calculatePoland(argv[1]);
        std::cout << GREEN <<  "Result: " << NC << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << NC << e.what() << std::endl;
        return 1;
    }
	return 0;
}