/*
	Ethan Davis
	C++ Fall 2021
	Due: September 29, 2021
	Lab 3: User and File I/O
	Write an interactive C++ program that computes and outputs the mean and  population standard deviation of a set of four integers that are inputted by a file called “inMeanStd.dat” and the user (should handle both).
 */

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
	ifstream infile;
	infile.open("inMeanStd.dat");

	ofstream outfile;
	outfile.open("outMeanStd.dat");

	int i, inputArray[4], input1, input2, input3, input4; //enters the input file data as integers
	float mean, mean2, sum = 0.0, sum2 = 0.0, stdDeviation = 0.0, stdDeviation2 = 0.0, variance = 0.0, variance2 = 0.0, sum2Sq = 0.0; //sets the means, averages, standard deviations, and variances as floating point values

	infile >> input1 >> input2 >> input3 >> input4;

	//start the process of user input and output to the screen
	cout << "Enter the 4 integers you would like to find the mean and standard deviation for.\n";

	for (i = 0; i < 4; i++)
	{
		cin >> inputArray[i]; //enters all the integers into an array
	}

	cout << "\n";

	for (i = 0; i < 4; i++)
	{
		sum += inputArray[i]; //adds all the integers in the array together
	}

	mean = sum / 4; //calculates the mean

	for (i = 0; i < 4; i++)
	{
		variance += pow(inputArray[i] - mean, 2); //calculates the variance of the integers
	}

	stdDeviation = sqrt(variance / 4); //calculates standard deviation

	cout << "Mean = " << mean << "\n" << endl;
	cout << "Standard Deviation = " << stdDeviation << "\n" << endl;

	//start the process of input file data > output file data

	sum2 = input1 + input2 + input3 + input4; //the sum of the input file data
	mean2 = sum2 / 4; //the mean of the input file data
	variance2 = pow(input1 - mean2, 2) + pow(input2 - mean2, 2) + pow(input3 - mean2, 2) + pow(input4 - mean2, 2); //calculates the variance of the input file data
	stdDeviation2 = sqrt(variance2 / 4); //finds the standard deviation of the input file data

	outfile << "The mean of the input data is " << mean2 << "." << endl;
	outfile << "The standard deviation of the input data is " << stdDeviation2 << ".";

	infile.close();
	outfile.close();

	return 0;
}