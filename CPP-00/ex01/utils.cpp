/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 02:33:03 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/11 02:42:01 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string formatColumn(std::string str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}