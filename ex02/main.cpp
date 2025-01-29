/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:38:46 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/29 15:26:08 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	std::vector<int> vect;
	std::deque<int> deq;
	if (!parseInput(argc, argv, vect, deq)) {
        return 1;
    }
	// printSequence("Before: ", vect);
	printSequence("Before: ", deq);
	sortDeq(deq);
	printSequence("After: ", deq);
	return 0;
}