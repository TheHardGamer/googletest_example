#include <cctype>
#include <string.h>
#include "LibCode.hpp"

using namespace std;

bool isPositive(int x)
{
	return x >= 0;
}

int countPositive(vector <int> inputVector)
{
	return count_if(inputVector.begin(), inputVector.end(), isPositive);
}

int sum(int a, int b)
{
	return a + b;
}

void toUpperC(char * inputStr)
{
	for(int i=0; i<strlen(inputStr); i++) 
	{
		inputStr[i] = toupper(inputStr[i]);
	}
}

string toUpperCpp(string inputStr)
{
	transform(inputStr.begin(), inputStr.end(),inputStr.begin(), ::toupper);
	return inputStr;
}

