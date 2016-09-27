#include <iomanip>
#include <iostream>
#include <fstream>
#include "class.h"

using namespace std;

int main()
{
	MiniBlast data;
	//variable to hold the info
	data.input();
	//get the details and info from the input file
	data.setkmer();
	//set a random kmer
	data.checkformatch();
	//check to see if there is a line that meets the requirement
	data.output();
	//prints the results
}


/*
For the second implementation
int main()
{
	MiniBlast data;
	//variable to hold the info
	data.input();
	//get the details and info from the input file
	data.setkmer();
	//set a random kmer
	data.checkformatch();
	//check to see if there is a line that meets the requirement
	data.output();
	//prints the results
}

*/