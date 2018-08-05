/*
 * A little program demonstrating how a try - catch construct might look like in C++
 */
#include <vector>
#include <iostream>
#include <string>

std::vector<int> array;
std::string begin_end_delimiter(50, '*');

int main()
{
	std::cout << std::endl << begin_end_delimiter << std::endl;
	try {
	    array.at(1000) = 0;
	}
    // Exception should be caught by reference, though
	catch (std::out_of_range o) {
	    if (o.what()) {
	    	std::cout << "Exception during vector access attempt. 'exception.what()' = " << o.what() << std::endl;
	    }
	}
	std::cout << begin_end_delimiter << std::endl << std::endl;
	return 0;
}
