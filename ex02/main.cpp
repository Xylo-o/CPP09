/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:38:46 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/28 19:41:20 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	std::vector<int> vect;
	std::deque<int> deq;
	if (!parseInput(argc, argv, vect, deq)) {
        return 1;
    }
	printSequence("Before: ", vect);
	printSequence("Before: ", deq);
	return 0;
}