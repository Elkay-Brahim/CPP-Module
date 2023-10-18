/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:20:22 by bchifour          #+#    #+#             */
/*   Updated: 2023/10/06 13:24:44 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_insertion.hpp"

int main (int ac, char **av)
{
    if(ac == 1)
        return 1;
    std::vector<std::vector<int> > doubleVector;
    std::list<std::list<int> > doubleList;
    std::vector<int> vc;
    std::list<int> vL;
    (void)ac;
    std::string str = av[1];
    std::string token;
    int i = 2;
    while(ac-- > 2)
    {
       str += " ";
       str += av[i];
       i++;
    }
    std::istringstream ss(str);
    char *end;
    while (std::getline(ss, token, ' '))
    {
        if (token == "")
            return 1;
        int i = strtod(token.c_str(), &end);
        if(*end != '\0' || i < 0)
            return 1;
        vc.push_back(i);
        vL.push_back(i);
        doubleVector.push_back(vc);
        doubleList.push_back(vL);
        vc.clear();
        vL.clear();
    }
    std::cout << "\033[94mBefore : \033[39m" << str << std::endl;
    std::clock_t start = std::clock();
    merge_insertion_v(doubleVector);
    std::clock_t eend = std::clock();
    std::clock_t clockTicksTaken = eend - start;
    long clocksPerSecond = CLOCKS_PER_SEC;
    double durationInMicroseconds = (double)clockTicksTaken / clocksPerSecond * 1000000;
    print_doublevector(doubleVector);
    std::cout << "\nTime to process a range of \033[94m" << doubleVector.size() << "\033[39m elements with std::vector : \033[94m" << durationInMicroseconds << "\033[39m us" << std::endl;
    start = std::clock();
    merge_insertion_l(doubleList);
    eend = std::clock();
    clockTicksTaken = eend - start;
    durationInMicroseconds = (double)clockTicksTaken / clocksPerSecond * 1000000;
    std::cout << "\nTime to process a range of \033[94m" << doubleVector.size() << "\033[39m elements with std::list   : \033[94m" << durationInMicroseconds << "\033[39m us" << std::endl;
}