/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:39:18 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/25 20:34:07 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2 || !checkFile(argv[1])) {
		std::cerr << RED << "Error: " << NC << "could not open the file." << std::endl;
		return 1;
	}
	if (parseExchangeDatabase(argv[1]) != 0) {
		std::cerr << RED << "Error: " << NC << "could not load the database." << std::endl;
	}
	return 0;
}