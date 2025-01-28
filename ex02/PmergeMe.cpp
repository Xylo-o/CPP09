/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:38:48 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/28 19:45:35 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool parseInput(int argc, char** argv, std::vector<int> vect, std::deque<int> deq) {
	if (argc < 2) {
		std::cerr << RED << "Error: " << NC << "invalid usage.\nCorrect usage: ./PmergeMe <arguments>" << std::endl;
		return false;
	}
	for (int i = 1; i < argc; ++i) {
		std::string arg = argv[i];
		for (char c : arg) {
			if (!isdigit(static_cast<unsigned char>(c))) {
				std::cerr << RED << "Error: " << NC << "given argument is not a correct number: " << RED << argv[i] << NC << std::endl;
				return false;
			}
		}
		long num = 0;
		try {
			num = std::stol(arg);
		} catch (std::invalid_argument&) {
			std::cerr << RED << "Error: " << NC << "given argument is not valid: " << RED << arg << NC << std::endl;
			return false;
		} catch (std::out_of_range&) {
			std::cerr << RED << "Error: " << NC << "given argument is out of range: " << RED << arg << NC << std::endl;
			return false;
		}
		// if (num <= 0) {
		// 	std::cerr << RED << "Error: " << NC << "given number mus be postive: " << RED << arg << NC << std::endl;
		// 	return false;
		// }
		vect.push_back(num);
		deq.push_back(num);
	}
	return true;
}

void printSequence(const std::string& prefix, const std::vector<int>& vect) {
    std::cout << prefix << " ";
    for (size_t i = 0; i < vect.size(); i++) {
        std::cout << vect[i];
        if (i + 1 < vect.size()) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void printSequence(const std::string& prefix, const std::deque<int>& deq) {
    std::cout << prefix << " ";
    for (size_t i = 0; i < deq.size(); i++) {
        std::cout << deq[i];
        if (i + 1 < deq.size()) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}