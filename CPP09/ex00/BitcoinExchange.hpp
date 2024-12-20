/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <cstdlib>


# define YEAR_BEGIN 2009
# define MONTH_BEGIN 1
# define DAY_BEGIN 2

# define FIRST_YEAR 0
# define LENGTH_YEAR 4
# define FIRST_MONTH 5
# define LENGTH_MONTH 2
# define FIRST_DAY 8
# define LENGTH_DAY 2
# define DB_HISTORIC "data.csv"

class BitcoinExchange
{
private:
	std::map<std::string, float> historic_rates;
	std::ifstream input;
	std::string line;
	std::string first_param;
	std::string second_param;
	bool type;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void print(std::string& first_param, float& second_param);
	bool check_date(int year, int month, int day, bool leap);
	bool check_first_day(int year, int month, int day);
	bool leap_date(std::string date_string);
	bool valid_date_string(std::string date_to_validate);
	bool valid_rate_string(std::string rate_to_validate);
	bool split_params();
	bool get_db_info();
	bool init_db(const char* file_name, const bool type_input);
	bool test_load_file(const char* file_name);
	bool validate_first_line();
};

#endif