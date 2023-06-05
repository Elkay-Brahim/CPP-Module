/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   My_Awesome_PhoneBook.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:22:49 by bchifour          #+#    #+#             */
/*   Updated: 2023/05/25 21:48:13 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>


class Contact
{
	private:
		std::string first_name;
    	std::string last_name;
    	std::string nickname;
    	std::string phone_number;
		std::string darkest_secret;
	public:
		Contact() {}		
		Contact(const std::string& fname, const std::string& lname, const std::string& nn, const std::string& phone, const std::string& secret)
		    : first_name(fname), last_name(lname), nickname(nn), phone_number(phone), darkest_secret(secret) {}

	const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::string& getNickname() const;
    const std::string& getPhoneNumber() const;
	const std::string& getDarkestSecret() const;
};

class PhoneBook
{
	private:
	    Contact contacts[8];
	    int contact_count;
	
	public:
		PhoneBook() : contact_count(0), contacts(){}
	
	void addContact(const Contact& contact);
	void searchContact();
	void run();
};

// geters
const std::string& Contact:: getFirstName() const
{
	return (first_name);
}

const std::string& Contact:: getLastName() const
{
	return (last_name);
}

const std::string& Contact:: getNickname() const
{
	return (nickname);
}

const std::string& Contact:: getPhoneNumber() const
{
	return (phone_number);
}

const std::string& Contact:: getDarkestSecret() const
{
	return (darkest_secret);
}


void PhoneBook:: addContact(const Contact& contact)
{
	int i = 0;
	if (contact_count >= 8)
	{
		while(i < 7)
		{
			contacts[i] = contacts[i + 1];
			i++;
		}
		contacts[7] = contact;
	}
	else
		contacts[contact_count++] = contact;
	std::cout << "Contact added successfully." << std::endl;
}

void PhoneBook:: searchContact()
{
	int i = 0;
	int index;
	if (contact_count == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}
	std::cout << "Index      | First Name | Last Name  | Nickname   " << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	while (i < contact_count)
	{
        std::string fname = contacts[i].getFirstName();
        std::string lname = contacts[i].getLastName();
        std::string nn = contacts[i].getNickname();

        if (fname.length() > 10)
            fname = fname.substr(0, 9) + ".";
        else
            fname = std::string(10 - fname.length(), ' ') + fname;
        if (lname.length() > 10)
            lname = lname.substr(0, 9) + ".";
        else
            lname = std::string(10 - lname.length(), ' ') + lname;
        if (nn.length() > 10)
            nn = nn.substr(0, 9) + ".";
        else
            nn = std::string(10 - nn.length(), ' ') + nn;
		std::cout << std::to_string(i) << std::string(10 - std::to_string(i).length(), ' ') << "| " << fname << " | " << lname << " | " << nn << std::endl;
		i++;
	}
    std::cout << "Enter the index of the contact to display: ";
    std::cin >> index;
	if (index >= 0 && index < contact_count)
	{
		const Contact& contact = contacts[index];
		std::cout << "Contact Information:" << std::endl;
        std::cout << "First Name: " << contact.getFirstName() << std::endl;
        std::cout << "Last Name: " << contact.getLastName() << std::endl;
        std::cout << "Nickname: " << contact.getNickname() << std::endl;
        std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
	}
	else
		std::cout << "Invalid index." << std::endl;
	
}
void PhoneBook:: run()
{
	std::string command;
	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::cin >> command;

		if (command == "ADD")
		{
		    std::string fname, lname, nn, phone, secret;
            std::cout << "Enter the first name: ";
            std::cin >> fname;
            std::cout << "Enter the last name: ";
            std::cin >> lname;
            std::cout << "Enter the nickname: ";
            std::cin >> nn;
            std::cout << "Enter the phone number: ";
            std::cin >> phone;
            std::cout << "Enter the darkest secret: ";
            std::cin.ignore();
            std::getline(std::cin, secret);
			if (!fname.empty() && !lname.empty() && !nn.empty() && !phone.empty() && !secret.empty())
			{
                Contact contact(fname, lname, nn, phone, secret);
                addContact(contact);
			}
			else
				std::cout << "Contact fields cannot be empty." << std::endl;
		}
		else if (command == "SEARCH")
			searchContact();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command." << std::endl;
	}
}

int main()
{
	PhoneBook phonebook;
	phonebook.run();
	return (0);
}