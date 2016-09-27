#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <string.h>
#include <map>
#include "class.h"


using namespace std;

void MiniBlast::input()
//this function will read the file and the commands that the users wishes the program to perform
{
	int query;//the request
	vector<int> location;//the position
	string stringholder, geneline;//the geneline to be found
	string text;//hmm input file
	cin >> stringholder;//take in the geneline
	cin >> text;//the file
	cin >> stringholder;
	cin >> amtkmer;//the length that will be searched
	while (stringholder != "quit")//while it does not find  quit command
	{
		cin >> stringholder;// string k
		cin >> query;//the query being searched
		cin >> geneline;//take in the genelines
		mapposition.insert(make_pair(geneline, location));
		//make a map of the geneline being searched and the position of the line
		genelines.push_back(geneline);
		//put the geneline being searched in the genelines
		mapquery.insert(make_pair(geneline, query));
		//make a map of the geneline being searched and the query
	}
	genelines.pop_back();
	fstream in_str(text.c_str());//for the text file
	in_str.is_open();//open it
	while (in_str >> stringholder)//while still taking in lines
		genome.append(stringholder);//append the lines onto the genome

}
void MiniBlast::setkmer()
{//set the random kmer
	string kmer;//string of the kmer size
	map<string, vector<int> >::iterator itr;//iterator for the map
	for (int i = 0; i < genome.size() - amtkmer + 1; i++)//loop for the size of the genome
	{
		vector<int> location;
		//vector position
		for (int j = 0; j < amtkmer; j++)
		//loop for the size of the kmer number
		{
			kmer.push_back(genome[i + j]);
			//insert the genome string for the size of the kmer
		}
		
		itr = thekmer.find(kmer);//find if the kmer exists 
		if (itr == thekmer.end())//if not
		{
			location.push_back(i);//put the position in the pos vector
			thekmer.insert(make_pair(kmer,location));//makr a pair of the 
		}
		else
		{
			itr->second.push_back(i);//put it in the second vector
		}
		kmer.clear();
	}
}

void MiniBlast::checkformatch()
//checks the lines to see if there is a match with what is being sought after
{
	int loc = 0;
	//start at position 0
	for (map<string, int>::iterator itr = mapquery.begin(); itr != mapquery.end(); itr++)
	//loop through the entirety of the map
	{
		string kmer;//string of the kmer
		for (int i = 0; i < amtkmer; i++)//loop for the size of the kmer number
		{
			kmer.push_back(itr->first[i]);//put the first value for the length of the kmer number into the kmer vector
		}
		map<string, vector <int> >::iterator itr2 = thekmer.find(kmer);//find if there is a match for the kmer
		if (itr2 != thekmer.end())
		//if there is a match
		{
			for (int i = 0; i < itr2->second.size(); i++)
			//loop for the size of the second value
			{
				if (itr2->second[i] < genome.size() - itr->first.size())
				//if a particular value of the second value vector is less than the genome size - the first value size
				{
					int counter = 0;
					//variable for the counter
					for (int j = 0; j < itr->first.size(); j++)
					//loop for the first value size
					{
					
						loc = itr2->second[i];
						//position is is the value of the second vector i which holds the line position
						if (genome[itr2->second[i] + j] != itr->first[j])//if the positions are not equal
							counter++;
							//increment the counter
						
					}
					if (counter <= itr->second)//if the counter is less than or equal to the second value
					{
						map<string, vector <int> >::iterator itr3 = mapposition.find(itr->first);//search the mao for the first value
						itr3->second.push_back(loc);//puthe pos in the second vector value
					}
				}
			}
		}
	}
}

string MiniBlast::gettheline(int loc, int size)
//gets the line that needs to be processed
{
	string geneline;
	//string for the line
	for (int i = 0; i < size; i++)
	//loop for the size
	{
		geneline.push_back(genome[loc + i]);
		//put the line in the geneline vector in the line position it should be in
	}

	return geneline;//return the line
}

int MiniBlast::getthedifference(int loc, string geneline)
//finds the diffrence between the request and the line processed
{
	int counter = 0;
	//counter variable
	for (int i = 0; i < geneline.size(); i++)
	//loop through the geneline size
	{
		if (genome[loc + i] != geneline[i])//if the genome position and geneline position are not the same
			counter++;
			//increment the diffrence between them
	}
	return counter;//return the diffrence
}



void MiniBlast::output()
//prints the results found through the run
{
	map<string, vector <int> >::iterator itr;//make an iterator to loop through the map
	for (int i = 0; i < genelines.size(); i++)//loop through the size of the geneline lists
	{
		itr = mapposition.find(genelines[i]);//find if the query us found
		cout << "Query: " << genelines[i] << endl;
		if (itr->second.size() != 0)//if the size of the second value of the map if a 0
		{
			for (int j = 0; j < itr->second.size(); j++)//loop through the size of the second value of the map
			{
				cout << itr->second[j]<< " " << getthedifference(itr->second[j], itr->first) << " " << gettheline(itr->second[j], itr->first.size()) << endl;
				//print the line number, the diffrence and the string
			}
		}
		else
		{
			cout << "No Match" << endl;//then a match was not found
		}
	}
	
}


/*
/////////////////////////////////////THIS IS FOR THE EXTRA CREDIT IMPLEMENTATION///////////////////////////////////////////////////////////
Wrote this mainly using pseudo code, not really the actual code that will run, but I understand that the implementation will be worse and 
less efficient than using a map to solve the problem.

using namespace std;

void MiniBlast::read()
//this function will read the file and the commands that the users wishes the program to perform
{
	string stringholder, geneline;//the geneline to be found
	string text;//hmm input file
	int query;//the request
	vector<int> pos;//the position

	cin >> stringholder;//take in the geneline
	cin >> text;//the file
	cin >> stringholder;//
	cin >> amtkmer;
	while (stringholder != "quit")//while it does not find  quit command
	{
		string kmer;//
		cin >> stringholder;//
		cin >> query;//
		cin >> geneline;//
		query_vec.push_back(geneline);//this will make a vector of  what is being searched for
	}
	
	fstream in_str(text.c_str());
	in_str.is_open();
	while (in_str >> stringholder)
		genome.append(k);
	//this will take in a string to be searched
}
void MiniBlast::setkmer()
{
	string kmer;
	map<string, vector<int> >::iterator itr;
	for (int i = 0; i < genome.size() - amtkmer + 1; i++)
	{
		vector<int> pos;
		for (int j = 0; j < amtkmer; j++)
		{
			kmer.push_back(genome[i + j]);
		}
	
		for (int i=0; i<query_vec.begin(); i++){
			if (query_vec[i] != genome[i]){
				pos.push_back(i);
				solution.push_back(kmer);
			}
		}
		else
		{
			solution.push_back(kmer);	
		}
		kmer.clear();
	}
}

void MiniBlast::checkformatch()
//checks the lines to see if there is a match with what is being sought after
{
	int pos = 0;
	for (int i=0; query_vec.size(); i++)
	{
		string kmer;
		for (int i = 0; i < amtkmer; i++)
		{
			kmer.push_back(query[i]);
		}
		if (int j=0; solution.size(); j++)
		{
				if (solution[i].size() < genome.size())
				{
					int counter = 0;
					for (int k = 0; j < solution[i].size(); k++)
					{
					
						pos = itr2->second[j];
						if (genome[k] != solution[i][k])
							counter++;
						
					}
				}
			
		}
	}
}

int MiniBlast::getthedifference(int pos, string geneline)
//finds the diffrence between the request and the line processed
{
	int counter = 0;
	for (int i = 0; i < geneline.size(); i++)
	{
		if (genome[pos + i] != geneline[i])
			counter++;
	}
	return counter;
}

string MiniBlast::gettheline(int pos, int size)
//gets the line that needs to be processed
{
	string geneline;
	for (int i = 0; i < size; i++)
	{
		geneline.push_back(genome[pos + i]);
	}

	return geneline;
}

void MiniBlast::print()
//prints the results found through the run
{
	for (int i = 0; i < solution.size(); i++)
	{
		cout << "Query: " << genelines[i] << endl;
		if (solution[i] == genelines[i])
		{
			for (int j = 0; j < solution.size(); j++)
			{
				cout << solution[j]<< " " << get_difference(solution[j], genelines[i]) << " " << get_line(itr->second[j], itr->first.size()) << endl;
			}
		}
		else
		{
			cout << "No match \n";

		}
	}
	
}


*/