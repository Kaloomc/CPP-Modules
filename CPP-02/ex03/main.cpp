/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:36:39 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/19 17:12:47 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point Sommet_A(0,0);
	Point Sommet_B(10,0);
	Point Sommet_C(0,10);

	Point point_test_1(2, 2);
	Point point_test_2(-1,-1);
	Point point_test_3(6,0);
	Point point_test_4(0,10);
	
	std::cout << "test 1 :" << bsp(Sommet_A,Sommet_B,Sommet_C,point_test_1) << std::endl;
	std::cout << "test 2 :" << bsp(Sommet_A,Sommet_B,Sommet_C,point_test_2) << std::endl;
	std::cout << "test 3 :" << bsp(Sommet_A,Sommet_B,Sommet_C,point_test_3) << std::endl;
	std::cout << "test 4 :" << bsp(Sommet_A,Sommet_B,Sommet_C,point_test_4) << std::endl;
	
	return 0;
}