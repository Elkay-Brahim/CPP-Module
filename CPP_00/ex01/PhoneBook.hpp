/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:35:11 by bchifour          #+#    #+#             */
/*   Updated: 2023/06/11 00:43:59 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class PhoneBook
{
	private:
	    Contact contacts[8];
	    int contact_count;
	
	public:
		PhoneBook();
	
	void addContact(const Contact& contact);
	void searchContact();
	void run();
};