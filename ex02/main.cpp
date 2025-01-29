/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:38:46 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/29 16:36:41 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	std::vector<int> vect;
	std::deque<int> deq;
	if (!parseInput(argc, argv, vect, deq)) {
        return 1;
    }
	std::cout << YELLOW << "====================VECTOR=====================" << NC << std::endl;
	printSequence("Before: ", vect);
	sortVect(vect);
	printSequence("After: ", vect);
	std::cout << YELLOW << "=====================DEQUE=====================" << NC << std::endl;
	printSequence("Before: ", deq);
	sortDeq(deq);
	printSequence("After: ", deq);
	return 0;
}