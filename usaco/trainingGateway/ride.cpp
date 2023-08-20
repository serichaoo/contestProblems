/*
ID: sericha1
TASK: ride
LANG: C++
*/

#include <cstring>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	char cometName[7];
	char groupName[7];
	fin >> cometName >> groupName;
	
	int finalCometProduct{1};
	int finalGroupProduct{1};
	for (int i = 0; i < strlen(cometName); i++)
	{
		finalCometProduct *= (cometName[i] - 64);
	}
	for (int j = 0; j < strlen(groupName); j++)
	{
		finalGroupProduct *= (groupName[j] - 64);
	}

	finalCometProduct %= 47;
	finalGroupProduct %= 47;
	
	if (finalCometProduct == finalGroupProduct)
		fout << "GO" << endl;
	else
		fout << "STAY" << endl;
	return 0;
}