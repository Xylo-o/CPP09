/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:38:51 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/29 15:26:00 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <chrono>
#include <cctype>
#include <stdexcept>
#include <algorithm>

bool parseInput(int argc, char** argv, std::vector<int> vect, std::deque<int> deq);
void printSequence(const std::string& prefix, const std::vector<int>& vect);
void printSequence(const std::string& prefix, const std::deque<int>& deq);
void sortDeq(const std::deque<int>& deq);