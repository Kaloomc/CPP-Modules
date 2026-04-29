/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:18:35 by fgarnier          #+#    #+#             */
/*   Updated: 2026/04/29 17:19:35 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int ac, char **av) {
	
    if (ac != 4) {
        std::cerr << "Error: Wrong number of arguments." << std::endl;
        std::cerr << "Usage: ./replace [filename] [s1] [s2]" << std::endl;
        return 1;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    if (s1.empty()) {
        std::cerr << "Error: The string to replace (s1) cannot be empty." << std::endl;
        return 1;
    }

    std::ifstream ifs(filename.c_str());
    if (!ifs.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "' (maybe a directory or permission denied)." << std::endl;
        return 1;
    }

    std::ostringstream oss;
    oss << ifs.rdbuf();
    std::string content = oss.str();
    ifs.close();

    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length(); 
    }

    std::string outName = filename + ".replace";
    std::ofstream ofs(outName.c_str());
    if (!ofs.is_open()) {
        std::cerr << "Error: Could not create output file '" << outName << "'." << std::endl;
        return 1;
    }

    ofs << content;
    ofs.close();

    return 0;
}