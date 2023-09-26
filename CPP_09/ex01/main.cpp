/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:38:05 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/24 17:07:01 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>


std::string _irase(std::string line, std::string part)
{
	while(1)
	{
		size_t Position = line.find(part);		
		if (Position != std::string::npos)
			line.erase(Position, part.length());
		else
			break;
	}
	return(line);
}

std::string _rplace(std::string line, std::string part)
{
	while(1)
	{
		size_t Position = line.find(part, Position);		
		if (Position != std::string::npos)
        {
        // std::cout << line+" "<< Position<<"\n" ;
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
    std::stack<int> s;
    std::stack<std::string> mul;
    std::string str = av[1];
    // std::istringstream ss;
   std::string token;
   char  *end;
    int nember;
    int i= 0;
    mul.push("*");
    mul.push("+");
    mul.push("-");
    mul.push("/");
    
    while(i < 4)
    {
    //  std::cout << str << std::endl;
       str =  _rplace(str, mul.top());
        mul.pop();
        i++;
    }
    std::istringstream ss(str);
    while (std::getline(ss, token, ' '))
    {
        
        if (!token.empty())
        {
        // std::cout << "token=> |"+token+"|\n";
            
            int i = strtod(token.c_str(), &end);
            if (*end != '\0' && s.size() > 1)
            {
                int top = s.top();
                s.pop();
                int top1 = s.top();
                s.pop();
                if (*end == '*')
                    s.push(top1 * top);
                else if (*end == '+')
                    s.push(top1 + top);
                else if (*end == '-')
                    s.push(top1 - top);
                else if (*end == '/')
                    s.push(top1 / top);
                else
                    std::cout << "ERROR\n";
                // std::cout <<"result " <<s.top() << "\n";
            }
            else 
            {
                // std::cout <<  "push " << i << std::endl;
                s.push(i);
            }
        }
        // std::cout<< token+"| " << i << "\n";
    }
    if (s.size() > 0)
        std::cout << s.top();
    // std::cout << "hi\n";
    // pause();
    // while (1)
    // {
    //     std::cout<< nember  <<  " "+token << std::endl;
        
    //     if (i > 4)
    //         break;
        // nember = strtod(str.c_str(), &token);
        // pause();
        // if (isdigit(str.c_str()))
        //     break;
        //    s.push(nember);
        // else
        // {
        //     int top = s.top();
        //      s.pop();
        //     int top1 = s.top();
        //     if (token == "+")
        //         s.push(top + top1);
        //     if (token == "*")
        //         s.push(top * top1);
        //     // if (token == "/");
        // }
        // token++;
        // str = 
        // std::cout << "=>  " + str+"|"  << std::endl;
    //     i++;
        
    // }
    return 0;

    /*
        Dog dog2; // constructor 
        Dog dog1 = dog2;
    */
    
}