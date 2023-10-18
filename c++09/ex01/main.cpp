/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:38:05 by bchifour          #+#    #+#             */
/*   Updated: 2023/10/06 15:57:26 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"


std::string _rplace(std::string line, std::string part)
{
    size_t Position = 0;
	while(1)
	{
        
		Position = line.find(part, Position);		
		if (Position != std::string::npos)
        {
			line.insert(Position, " ");
            Position += 2;
            line.insert(Position, " ");
        }
		else
			break;
	}
	return(line);
}


int main(int ac, char **av)
{
    if (ac == 1 || ac > 2)
        return 1;
    std::stack<std::string> mul;
    std::string str = av[1];
    int i= 0;
    mul.push("*");
    mul.push("+");
    mul.push("-");
    mul.push("/");
    
    while(i < 4)
    {
       str =  _rplace(str, mul.top());
        mul.pop();
        i++;
    }
    rpn(str);
    return 0; 
}