/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:32:43 by jamendoe          #+#    #+#             */
/*   Updated: 2024/06/10 09:33:10 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <fstream>
#include <string>

int ft_replace_string(const char* filename, std::string& s1, std::string& s2)
{
	std::string file_replace;
	size_t pos;

	file_replace = filename;
	file_replace.append(".replace");
	std::ifstream infile(filename, std::ifstream::in);
	if (!infile)
	{
		std::cout << "Error"<< std::endl << "Can't open " << filename << std::endl;
		return (1);
	}
	std::ofstream outfile(file_replace.c_str(), std::ifstream::out);
	if (!outfile)
	{
		infile.close();
		std::cout << "Error"<< std::endl << "Can't create " << file_replace << std::endl;
		return (1);
	}
	std::string text;
	while (std::getline (infile, text))
	{
		pos = 0;
		while ((int)(pos = text.find(s1, pos)) != -1)
		{
			text.erase(pos, s1.length());
			text.insert (pos, s2);
			pos += s2.length();
		}
		outfile << text << std::endl;;

	}
	infile.close();
	outfile.close();
	return (0);
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Error"<< std::endl << "Usage: " << argv[0] <<
		" <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	std::string s1;
	std::string s2;

	s1 = argv[2];
	s2 = argv[3];
	if (s1.empty())
	{
		std::cout << "Error"<< std::endl << "String1 is empty!" << std::endl;
		return (1);
	}
	if (ft_replace_string (argv[1], s1, s2))
		return (1);
	std::cout << "The file " << argv[1] << ".replace has been created!" << std::endl;
	return (0);
}
