#
#Kevin Nguyen
#Basic program for Python that outputs permutations on a given string or sequence of characters.
#
#How to run (linux):
#	1.) open command line and cd into directory folder of where this code is
#	2.) type in "python PythonPermu.py"

#import statements
import sys;
import array;

#function implementation/definition below
#function permu will perform permutations and output results to screen
def permu(start, currStr, length):
	#local declarations
	i, newLength = 0, 0;
	newStart, newCurrStr = "", "";

	#base case --> no more characters to consider? print it out the permutation so far
	if(length <= 0):
		print start; #<-- print results
	else:
		#loop over all characters of the currStr and find substrings for more permutations
		while(i < length):
			newStart = start + currStr[i]; #concatenate initial with new extra char --> expands starting size
			newCurrStr = currStr[0:i] + currStr[(i+1):length]; #concat substrings with increasing ith value
			newLength = len(newCurrStr);
			permu(newStart, newCurrStr, newLength); #recursively call for more permutation on new params
			i=i+1;

#main driver below
currStr = "abcd"; #<---- String for permutation!
length = len(currStr);
permu("", "abcd", length); #<-- call permutation function