/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:38:51 by adprzyby          #+#    #+#             */
/*   Updated: 2025/01/28 18:58:16 by adprzyby         ###   ########.fr       */
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

bool parseInput(int argc, char** argv, std::vector<int> vect, std::deque<int> deq);