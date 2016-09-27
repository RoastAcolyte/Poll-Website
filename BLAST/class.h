#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std; 

class MiniBlast
{
	public: 
		void input();
		//reads the file
		void setkmer();
		//random kmer
		int getthedifference(int loc, string gene);
		//gets the diffrence between the request and line
		string gettheline(int loc, int size);
		//gets the line of the file
		void output();
		//prints the results
		void checkformatch();
		//checks to find a match
		
	private: 
		map<string, vector<int> > thekmer;
		//kmer map or amount that will be indexed
		vector <string> genelines;
		//the gene file
		int amtkmer;
		//the number to be indexed
		string genome;
		//the string that will be searched
		map<string, vector<int> > mapposition;
		//the position you are in
		map<string, int> mapquery;
		//the request
		
};

/*
For the second implementation
class MiniBlast
{
	public: 
		void input();//reads the file
		void setkmer();//random kmer
		int getthedifference(int pos, string gene);//gets the diffrence between the request and line
		string gettheline(int pos, int size);//gets the line of the file
		void output();//prints the results
		void checkformatch();//checks to find a match
		
	private: 
		vector<string> thekmer;//the vector that will be indexed
		vector <string> genes;//the gene file
		int amtkmer;//the number to be indexed
		string genome;//the string that will be searched
		map<string, vector<int> > mapposition;//the position you are in
		vector<string> pos;//the vector with the position
		vector<string> query;//the vector with the query
		vector<string> solutions;//the vector that holds the solutions
		
};

*/