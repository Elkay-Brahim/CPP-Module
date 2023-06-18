/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:34:08 by bchifour          #+#    #+#             */
/*   Updated: 2023/06/11 00:37:33 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Contact
{
	private:
		std::string first_name;
    	std::string last_name;
    	std::string nickname;
    	std::string phone_number;
		std::string darkest_secret;
	public:
		Contact();
		Contact(const std::string& fname, const std::string& lname, const std::string& nn, const std::string& phone, const std::string& secret);

	const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::string& getNickname() const;
    const std::string& getPhoneNumber() const;
	const std::string& getDarkestSecret() const;
};