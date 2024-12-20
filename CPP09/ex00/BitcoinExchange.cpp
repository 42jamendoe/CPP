/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	historic_rates = copy.historic_rates;

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
		return (*this);
	historic_rates = other.historic_rates;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{

}

void BitcoinExchange::print(std::string& first_param, float& second_param)
{
	std::map<std::string, float>::iterator index = historic_rates.lower_bound(first_param);
	if (index == historic_rates.end() || (index != historic_rates.begin() && first_param.compare(index->first)))
		index--;
	std::cout << first_param << " => " << second_param << " = " << index->second * second_param << std::endl;
}

bool BitcoinExchange::check_first_day(int year, int month, int day)
{
	if (year < YEAR_BEGIN)
		return true;
	if (year == YEAR_BEGIN)
	{
		if (month < MONTH_BEGIN || (month== MONTH_BEGIN && day < DAY_BEGIN))
			return true;
	}
	return false;
}

bool BitcoinExchange::check_date(int year, int month, int day, bool leap)
{
	int limit;

	if (month == 2 && leap)
		limit = 29;
	else if (month == 2)
		limit = 28;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		limit = 30;
	else
		limit = 31;
	if (check_first_day(year, month, day))
		return true;
	if (month < 1 || month > 12)
		return true;
	if (day < 1 || day > limit)
		return true;
	return false;
}
//
bool BitcoinExchange::leap_date(std::string date_string)
{
	bool leap;

	std::string year_str = date_string.substr(FIRST_YEAR, LENGTH_YEAR);
	std::string month_str = date_string.substr(FIRST_MONTH, LENGTH_MONTH);
	std::string day_str = date_string.substr(FIRST_DAY, LENGTH_DAY);
	int year = atoi(year_str.c_str());
	int month = atoi(month_str.c_str());
	int day = atoi(day_str.c_str());
	if (year % 4 == 0)
	{
		if (year % 100 == 0 && year % 400 != 0)
			leap = false;
		else
			leap = true;
	}
	else
		leap = false;
	if (check_date(year, month, day, leap))
	{
		std::cout << "Error: bad input => " << date_string << std::endl;
		return true;
	}
	return false;
}


bool BitcoinExchange::valid_rate_string(std::string rate_to_validate)
{
	float tmp;

	tmp = atof(rate_to_validate.c_str());
	if (tmp < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return true;
	}
	if (tmp > 1000 && type)
	{
		std::cout << "Error: too large a number." << std::endl;
		return true;
	}
	return false;
}

bool BitcoinExchange::valid_date_string(std::string date_to_validate)
{
	size_t i = 0;

	if (date_to_validate.size() != 10)
		return true;
	while ( i < 10)
	{
		if ((!isdigit(date_to_validate[i]) && i != 4 && i != 7) || (date_to_validate[i] == '-' && i != 4 && i != 7))
		{
			std::cout << "Error: bad input => " << date_to_validate << std::endl;
			return true;
		}
		i++;
	}
	return false;
}

bool BitcoinExchange::split_params()
{
	if (!type)
	{
		first_param = line.substr(0, line.find_first_of(','));
		second_param = line.substr(line.find_first_of(',') + 1, line.size());
	}
	else
	{
		if (line[10] != ' ' || line[12] != ' ')
		{
			std::cout << "Error: bad input => " << line << std::endl;
			return true;
		}
		first_param = line.substr(0, line.find_first_of('|') - 1);
		second_param = line.substr(line.find_first_of('|') + 2, line.size());
	}
	return false;
}

bool BitcoinExchange::BitcoinExchange::get_db_info()
{
	while (!input.eof())
	{
		getline(input, line);
		if (!line.empty()) {
			if (!split_params())
			{
				if (valid_date_string(first_param) || leap_date(first_param) || valid_rate_string(second_param))
				{
					if (!type)
					{
						input.close();
						return true;
					}
				}
				else
				{
					float quantity;
					quantity = atof(second_param.c_str());
					if (!type)
						historic_rates.insert(std::pair<std::string, float>(first_param, quantity));
					else
						print(first_param, quantity);
				}
			}
		}
	}
	return false;
}

bool BitcoinExchange::validate_first_line()
{
	getline(input, line);
	if ((line != "date,exchange_rate" && !type) || (line != "date | value" && type))
	{
		std::cerr << "Error: the first line has wrong format." << std::endl;
		input.close();
		return (true);
	}
	return (false);
}

bool BitcoinExchange::test_load_file(const char* file_name)
{
	input.open(file_name);
	if (!input.is_open())
	{
		std::cerr << "Error: could not open file: "<< file_name << std::endl;
		return (true);
	}
	return (false);
}

bool BitcoinExchange::init_db(const char* file_name, const bool type_input)
{
	type = type_input;
	if (test_load_file(file_name))
		return true;
	if (validate_first_line())
		return true;
	if (get_db_info())
		return true;
	input.close();
	return false;
}
