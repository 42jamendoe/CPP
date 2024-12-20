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
#include "Serializer.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	(void) argv;
	if (argc > 1)
	{
		std::cout << "Error\nUsage: ./serialize" << std::endl;
		return (1);
	}

	Data some_data;
	some_data.random_name = "jamendoe";

	std::cout << "The data pointer is:  " << &some_data << std::endl;
	uintptr_t raw = Serializer::serialize(&some_data);
	std::cout << "The serialized pointer to Data is: " << raw << std::endl << std::endl;
	Data* deserialized_some_data = Serializer::deserialize(raw);

	std::cout << deserialized_some_data << " has to be equal to " << &some_data << std::endl;
	std::cout << deserialized_some_data->random_name << " has to be equal to *jamendoe*" << std::endl;

	Data* nullptr_to_data = NULL;
	uintptr_t rawNull = Serializer::serialize(nullptr_to_data);
	Data* deserializedNull = Serializer::deserialize(rawNull);

	std::cout << "nullptr_to_data: " << nullptr_to_data << " has to be equal to deserializedNull: " << deserializedNull << std::endl;

	Data* aliasData = &some_data;
	uintptr_t rawAlias = Serializer::serialize(aliasData);
	Data* deserializedAlias = Serializer::deserialize(rawAlias);

	std::cout << aliasData << " has to be equal to " << &some_data << " and " << deserializedAlias << std::endl;
	std::cout << aliasData->random_name << " has to be equal to " << some_data.random_name << " and " << deserializedAlias->random_name << std::endl;


	uintptr_t rawMultiple = Serializer::serialize(&some_data);
	Data* deserializedMultiple1 = Serializer::deserialize(rawMultiple);
	Data* deserializedMultiple2 = Serializer::deserialize(rawMultiple);

	std::cout << &some_data << " has to be equal to " << deserializedMultiple1 << " and " << deserializedMultiple2 << std::endl;

	Data* dynamicData = new Data;
	dynamicData->random_name = "jamendoe_dinamic";

	uintptr_t rawDynamic = Serializer::serialize(dynamicData);
	Data* deserializedDynamic = Serializer::deserialize(rawDynamic);

	std::cout << deserializedDynamic << " has to be equal to " << dynamicData << std::endl;
	std::cout << deserializedDynamic->random_name << " has to be equal to *jamendoe*" << std::endl;
	delete dynamicData;

	return (0);
}
