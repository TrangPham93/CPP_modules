/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:25:48 by trpham            #+#    #+#             */
/*   Updated: 2025/08/09 23:51:43 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>

static void	ft_replace(std::string* read_str, 
	std::string s1, std::string s2)
{
	std::size_t	s1_len = s1.length();
	
	while (1)
	{
		std::size_t	found = (*read_str).find(s1);
		if (found == std::string::npos)
			break ;
		(*read_str).erase(found, s1_len);
		(*read_str).insert(found, s2);
	}
	return ;
}

int	main(int ac, char **av)
{
	std::string		filename;
	std::string		s1;
	std::string		s2;
	std::string		read_str;
	
	if (ac != 4)
	{
		std::cout << "Invalid input: need 3 arguments\n"
			"Usage: ./sed <filename> <s1: to be replace> <s2>" << std::endl;
		return (EXIT_FAILURE);
	}

	filename = std::string(av[1]);
	s1 = std::string(av[2]);
	s2 = std::string(av[3]);
	
	// open infile
	std::ifstream	infile(filename);
	if (!infile.is_open())
	{
		std::cout << "Error: Cannot open file " << filename << std::endl;
		return (false);
	}
	
	// check if filename.replace exists
	std::string	new_file_name = filename + ".replace";
	std::ifstream	checkfile(new_file_name);
	if (checkfile.is_open())
	{
		std::cout << new_file_name << " already exists, cannot recreate" 
			<< std::endl;
		checkfile.close();
		return (EXIT_FAILURE);
	}
	
	// create file .replace in writing mode
	std::ofstream	outfile(new_file_name);
	if (!outfile.is_open())
	{
		std::cout << filename << ".replace cannot be created" << std::endl;
		infile.close();
		return (EXIT_FAILURE);
	}
	
	// write infile to outfile
	while (std::getline(infile, read_str)) // while reading not fail
	{
		ft_replace(&read_str, s1, s2);
		outfile << read_str << std::endl;
	}
	if (!infile.eof())
	{
		std::cout << "Error: read file failed" << std::endl;
		infile.close();
		outfile.close();
		return (EXIT_FAILURE);
	}
	
	infile.close();
	outfile.close();
	
	return (EXIT_SUCCESS);
}
