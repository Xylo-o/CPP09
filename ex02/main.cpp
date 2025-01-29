/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:38:46 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/29 17:11:30 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	std::vector<int> vect;
	std::deque<int> deq;
	if (!parseInput(argc, argv, vect, deq)) {
        return 1;
    }
	size_t entrySize = vect.size();
	std::cout << YELLOW << "====================VECTOR=====================" << NC << std::endl;
	printSequence("Before: ", vect);
	auto startVec = std::chrono::steady_clock::now();
    sortVect(vect);
    auto endVec = std::chrono::steady_clock::now();
    double timeVec = std::chrono::duration<double, std::micro>(endVec - startVec).count();
	printSequence("After: ", vect);
	std::cout << YELLOW << "=====================DEQUE=====================" << NC << std::endl;
	printSequence("Before: ", deq);
	auto startDeq = std::chrono::steady_clock::now();
    sortDeq(deq);
    auto endDeq = std::chrono::steady_clock::now();
    double timeDeq = std::chrono::duration<double, std::micro>(endDeq - startDeq).count();
	printSequence("After: ", deq);
	std::cout << BLUE << "=====================RESULTS=====================" << NC << std::endl;
    std::cout << "Time to process a range of " << entrySize
              << " elements with " << GREEN << "std::vector : " << NC
              << std::fixed << std:: setprecision(4) << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << entrySize
              << " elements with " << GREEN << "std::deque : " << NC 
              << std::fixed << std:: setprecision(4) << timeDeq << " us" << std::endl;
	return 0;
}