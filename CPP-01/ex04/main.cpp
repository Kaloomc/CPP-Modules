/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:18:35 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/12 16:50:22 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>

// Helper to check if string 'a' exists at current position
bool is_match(char *str, char *a) {
    int i = 0;
    while (a[i]) {
        if (str[i] != a[i]) return false;
        i++;
    }
    return true;
}

int main(int ac, char **av) {
    if (ac != 4) {
        std::cerr << "Usage: ./replace [filename] [s1] [s2]" << std::endl;
        return 1;
    }

    std::ifstream is(av[1], std::ifstream::in);
    if (!is) return 1;

    is.seekg(0, is.end);
    int length = is.tellg();
    is.seekg(0, is.beg);

    char *buffer = new char[length + 1];
    is.read(buffer, length);
    buffer[length] = '\0'; 
    is.close();

    std::string content(buffer);
    std::string s1 = av[2];
    std::string s2 = av[3];
	
    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }

	std::string outputFile(av[1]);;
	std::fstream output;
	outputFile.append(".replace");
	output.open(outputFile,std::ifstream::out | std::ifstream::trunc);
	output << content;
	
    delete[] buffer;
    return 0;
}