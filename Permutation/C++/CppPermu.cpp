/*
Kevin Nguyen
Naive C++ program that outputs permutations of a given string.

How to run (linux):
	1.) open command line and cd into directory folder of where this code is
	2.) type in "g++ *.cpp -std=c++11 to compile cpp files
	3.) type in "a.out" to run the program
*/

//include statements
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//global declarations

//function declarations
void doPermutations(vector<char>);
void printVtr(vector<char>);

//main driver
int main(int argc, char const *argv[]) {
	//local Declarations
	std::vector<char> currVtr = {'a', 'b', 'c'};
	//call permutation function
	doPermutations(currVtr);
	return 0;
}

//function to do permutations
void doPermutations(vector<char> currVtr) {
	//local declarations
	int i = 0;

	cout << "PERMUTATIONS BELOW:" << endl;
	//loop through vector with next possibe permutations in range specified
	while(next_permutation(currVtr.begin(), currVtr.end())) {
		printVtr(currVtr); //<-- print contents
	}

	cout << endl;
	cout << "EXTRA PERMUTATIONS BELOW:" << endl;
	//EXTRA permutations with upperCase characters; loop through and turn characters one at a time for permutation
	while(i < currVtr.size()) {
		currVtr[i] = toupper(currVtr[i]);
		//loop and perform permputations with new updated vector
		while(next_permutation(currVtr.begin(), currVtr.end())) {
			printVtr(currVtr); //<-- print contents
		}
		i++;
	}
}

//this function prints out all characters given a vector
void printVtr(vector<char> myVtr) {
	//local declarations
	int i = 0, length = myVtr.size();

	//loop through all elements in vector and print them out
	while(i < length) {
		cout << myVtr[i]; //access and print out to standard out
		i++;
	}
	cout << endl; //new line
}