/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 20:28:06 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/19 02:26:06 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

template <typename T>
void doubleElement(T& element) {
    element *= 2;
}

void exclaimString(std::string& str) {
    str += "!";
}

int main() {
    // -------------------------------------------------------------------------
    std::cout << "--- Test 1: Integer Array (Print) ---" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original: ";
    iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    // -------------------------------------------------------------------------
    std::cout << "\n--- Test 2: Integer Array (Modify and Print) ---" << std::endl;
    iter(intArray, intLen, doubleElement<int>);
    
    std::cout << "Doubled:  ";
    iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    // -------------------------------------------------------------------------
    std::cout << "\n--- Test 3: Double Array (Const Float/Double) ---" << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3};
    size_t doubleLen = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Doubles:  ";
    iter(doubleArray, doubleLen, printElement<double>);
    std::cout << std::endl;

    // -------------------------------------------------------------------------
    std::cout << "\n--- Test 4: String Array (Modification) ---" << std::endl;
    std::string strArray[] = {"Hello", "World", "C++"};
    size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Original: ";
    iter(strArray, strLen, printElement<std::string>);
    std::cout << std::endl;

    iter(strArray, strLen, exclaimString);

    std::cout << "Modified: ";
    iter(strArray, strLen, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}