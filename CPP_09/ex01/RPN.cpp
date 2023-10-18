/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    RPN.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:45:31 by bchifour          #+#    #+#             */
/*   Updated: 2023/10/06 15:48:22 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void rpn(std::string str)
{
    std::stack<int> s;
    std::string token;
   char  *end;
     std::istringstream ss(str);
    while (std::getline(ss, token, ' '))
    {
        
        if (!token.empty())
        {
            int i = strtod(token.c_str(), &end);
            if (*end != '\0' && s.size() > 1)
            {
                if ((i < 10 && i > -10) && i != 0)
                    return ;
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
                {
                    std::cout << "ERROR\n";
                    return;
                }
            }
            else if (*end == '\0'  && (i < 10 && i > -10))
            {
                s.push(i);
            }
            else
            {
                std::cout << "ERROR\n";
                return;
            }
        }
    }
    if (s.size() > 0)
        std::cout << s.top() << std::endl;
    return;
}