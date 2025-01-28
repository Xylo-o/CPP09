/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:38:46 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/28 17:29:07 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << RED "Error : " << NC << "invalid usage.\nCorrect usage: ./PmergeMe <arguments>" << std::endl;
		return 1;
	}
	(void) argv;
	return 0;
}