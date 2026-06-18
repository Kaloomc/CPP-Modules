/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 00:19:51 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/18 12:55:03 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isChar(const std::string& str) {
    return str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]);
}

static bool isPseudoLiteral(const std::string& str) {
    return (str == "nan" || str == "nanf" || str == "+inf" || str == "inf" || str == "-inf" || str == "+inff" || str == "inff" || str == "-inff");
}

static bool isInt(const std::string& str) {
    size_t i = 0;
    if (str[i] == '-' || str[i] == '+') i++;
    if (i == str.length()) return false;
    for (; i < str.length(); i++) {
        if (!std::isdigit(str[i])) return false;
    }
    return true;
}

static bool isFloat(const std::string& str) {
    if (str[str.length() - 1] != 'f') return false;
    size_t i = 0;
    bool hasDot = false;
    if (str[i] == '-' || str[i] == '+') i++;
    for (; i < str.length() - 1; i++) {
        if (str[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return hasDot;
}

static bool isDouble(const std::string& str) {
    size_t i = 0;
    bool hasDot = false;
    if (str[i] == '-' || str[i] == '+') i++;
    for (; i < str.length(); i++) {
        if (str[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return hasDot;
}

static void printChar(double val, bool isImpossible) {
    std::cout << "char: ";
    if (isImpossible || val < std::numeric_limits<char>::min() || val > std::numeric_limits<char>::max() || std::isnan(val)) {
        std::cout << "impossible\n";
    } else if (!std::isprint(static_cast<char>(val))) {
        std::cout << "Non displayable\n";
    } else {
        std::cout << "'" << static_cast<char>(val) << "'\n";
    }
}

static void printInt(double val, bool isImpossible) {
    std::cout << "int: ";
    if (isImpossible || val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max() || std::isnan(val)) {
        std::cout << "impossible\n";
    } else {
        std::cout << static_cast<int>(val) << "\n";
    }
}

static void printFloat(float val, bool isImpossible) {
    std::cout << "float: ";
    if (isImpossible) {
        std::cout << "impossible\n";
    } else {
        std::cout << std::fixed << std::setprecision(1) << val << "f\n";
    }
}

static void printDouble(double val, bool isImpossible) {
    std::cout << "double: ";
    if (isImpossible) {
        std::cout << "impossible\n";
    } else {
        std::cout << std::fixed << std::setprecision(1) << val << "\n";
    }
}

void ScalarConverter::convert(const std::string& literal) {
    if (isPseudoLiteral(literal)) {
        bool isFloatPseudo = (literal[literal.length() - 1] == 'f' && literal != "inf" && literal != "-inf" && literal != "+inf");
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        if (isFloatPseudo) {
            float f = static_cast<float>(std::strtod(literal.c_str(), NULL));
            std::cout << "float: " << literal << "\n";
            std::cout << "double: " << static_cast<double>(f) << "\n";
        } else {
            double d = std::strtod(literal.c_str(), NULL);
            std::cout << "float: " << static_cast<float>(d) << "f\n";
            std::cout << "double: " << literal << "\n";
        }
        return;
    }

    if (isChar(literal)) {
        char c = literal[0];
        printChar(static_cast<double>(c), false);
        printInt(static_cast<double>(c), false);
        printFloat(static_cast<float>(c), false);
        printDouble(static_cast<double>(c), false);
        return;
    }

    double val = std::strtod(literal.c_str(), NULL);
    bool isImpossible = false;

    if (!isInt(literal) && !isFloat(literal) && !isDouble(literal)) {
        isImpossible = true;
    }

    printChar(val, isImpossible);
    printInt(val, isImpossible);
    printFloat(static_cast<float>(val), isImpossible);
    printDouble(val, isImpossible);
}