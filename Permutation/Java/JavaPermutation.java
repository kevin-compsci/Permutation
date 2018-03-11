/*
Kevin Nguyen
Naive Java program that outputs permutations of a given string (does not consider unique permutations). This method is not memory efficient.

How to run (linux):
	1.) open command line and cd into directory folder of where this code is
	2.) type in "javac *.java" to compile java files
	3.) type in "java JavaPermutation"
*/

//imports
import java.io.*;
import java.util.*;

//class
class JavaPermutation {
	//Global Declarations

	//main driver
	public static void main(String[] args) {
		//local Declarations
		pDriver("abc"); //<--- string for permutation
	}

	//function definitions below
	//pDriver is the driver function to start permutations
	public static void pDriver(String s) {
		//call function permu to do permuations
		permu("", s, s.length()); 
	} 

	//permu function performs permutations and outputs it to screen
	public static void permu(String start, String currStr, int length) {
		//local declaratons
		int i = 0, newLength = 0;
		String newStart = "", newCurrStr = "";

		//base case of length 0 --> no more characters to consider then print result?
		if(length <= 0) {
			System.out.println(start); //output permutations
		}
		else {
			//iterate over all characters in current string and recursive call for more permutations
			while(i < length) {
				newStart = start + currStr.charAt(i); //concatenate initial with new extra char --> expands starting size
				newCurrStr = currStr.substring(0, i) + currStr.substring(i+1, length); //concat substrings with increasing ith value
				newLength = newCurrStr.length();
				permu(newStart, newCurrStr, newLength); //recursive call, keep building result list
				i++; //increment
			}
		}
	}
}
