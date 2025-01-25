/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:39:18 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/25 14:55:40 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2 || !checkFile(argv[1])) {
		std::cerr << RED << "Error: " << NC << "could not open the fille." << std::endl;
		return 1;
	}
	return 0;
}