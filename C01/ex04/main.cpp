/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:25:48 by trpham            #+#    #+#             */
/*   Updated: 2025/08/08 17:21:51 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>



static std::string	ft_replace(std::string read_str, 
	std::string s1, std::string s2)
{
	
	read_str.find(s1);
	
	return (read_str);
}

int	main(int ac, char **av)
{
	std::string		filename;
	std::string		s1;
	std::string		s2;

	std::string		read_str;
	
	if (ac != 4)
	{
		std::cout << "Invalid input\nUsage: ./sed <filename> <s1: to be replace> <s2>" 
			<< std::endl;
		return (EXIT_FAILURE);
	}
	filename = std::string(av[1]);
	s1 = std::string(av[1]);
	s2 = std::string(av[2]);
	// open infile
	std::ifstream	infile(filename);
	if (!infile.is_open())
	{
		std::cout << "Error: Cannot open file " << filename << std::endl;
		return (false);
	}
	// open file .replace in writing mode
	std::ofstream	outfile(filename + ".replace");
	// outfile.open(filename + ".replace");
	if (!outfile.is_open())
	{
		std::cout << filename << ".replace cannot be created" << std::endl;
		return (EXIT_FAILURE);
	}
	
	// write infile to outfile
	if (infile && outfile)
	{
		while (std::getline(infile, read_str)) // while reading not fail
		{
			read_str = ft_replace(read_str);
			outfile << read_str << std::endl;
		}
		if (infile.eof())
		{
			std::cout << "Reach EOF" << std::endl;
		}
		else
		{
			std::cout << "Error: read file failed" << std::endl;
			infile.close();
			outfile.close();
			return (EXIT_FAILURE);
		}
	}
	infile.close();
	outfile.close();
	
	return (EXIT_SUCCESS);
}