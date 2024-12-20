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
#include "Array.tpp"

int main()
{
	try
	{
		unsigned int i;

		std::cout << "1. Empty Array" << std::endl;
		Array<int> emptyArray;
		std::cout << "Empty Array created. Size: " << emptyArray.size() << std::endl << std::endl;

		std::cout << "2. int - Array with 5 elements" << std::endl;
		unsigned int n = 5;
		Array<int> array(n);
		std::cout << "Array with " << n << " elements created. Size: " << array.size() << std::endl;
		std::cout << "Initialize the 5 elements" << std::endl;
		for (i = 0; i < n; ++i)
		{
			array[i] = static_cast<int>(i) * 10;
		}
		std::cout << "Array values: ";
		for (i = 0; i < n; ++i)
		{
			std::cout << array[i] << " ";
		}
		std::cout << std::endl << std::endl;

		std::cout << "2. string - Array with 5 elements" << std::endl;
	
		Array<std::string> array_s(n);
		std::cout << "Array with " << n << " elements created. Size: " << array.size() << std::endl;
		std::cout << "Initialize the 5 elements" << std::endl;
		array_s[0] = "42";
		array_s[1] = "Porto";
		array_s[2] = "jamendoe";
		array_s[3] = "Portugal";
		array_s[4] = "Don't panic";
		std::cout << "Array values: ";
		for (i = 0; i < n; ++i)
		{
			std::cout << array_s[i] << " ";
		}
		std::cout << std::endl << std::endl;


		std::cout << "3. copy constructor test" << std::endl;
		Array<int>copiedArray(array);
		std::cout << "copiedArray created. Size: " << copiedArray.size() << std::endl;
		std::cout << "copiedArray values: ";
		for (i = 0; i < copiedArray.size(); ++i)
		{
			std::cout << copiedArray[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Change original array[0] value to 100, the copiedArray should be 0" << std::endl;
		array[0] = 100;
		std::cout << "array[0] changed to 100" << std::endl;
		std::cout << "array[0]: " << array[0] << std::endl;
		std::cout << "copiedArray[0]: " << copiedArray[0] << std::endl << std::endl;

		std::cout << "4. overload assignment" << std::endl;
		Array<int> assignedArray;
		assignedArray = array;
		std::cout << "assignedArray created. Size: " << assignedArray.size() << std::endl;
		std::cout << "assignedArray values: ";
		for (i = 0; i < assignedArray.size(); ++i)
		{
			std::cout << assignedArray[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Change original array[0] value to 200, the copiedArray should be 100" << std::endl;
		array[0] = 200;
		std::cout << "array[0] changed to 200" << std::endl;
		std::cout << "array[0]: " << array[0] << std::endl;
		std::cout << "assignedArray[0]: " << assignedArray[0] << std::endl << std::endl;

		std::cout << "5. access to array[6] -> should throw an exception" << std::endl;
		std::cout << array[6] << std::endl;

	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}