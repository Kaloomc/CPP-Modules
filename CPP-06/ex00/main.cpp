/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 00:19:00 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/18 00:19:08 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Erreur : Nombre d'arguments invalide." << std::endl;
        std::cerr << "Usage : ./convert <valeur_littérale>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);

    return 0;
}