#include <iostream>
#include <string>
#include <vector>

using namespace std;

int maxSamples(int nNotes, int maxPitch)
{
	if (nNotes < maxPitch)
		return (nNotes * (nNotes + 1) / 2);
	else
		return (maxPitch * (maxPitch + 1) / 2 + (nNotes - maxPitch) * maxPitch);
}

int main()
{
	int nNotes, maxPitch, nSamples;
	cin >> nNotes >> maxPitch >> nSamples;
	if (nSamples < nNotes || nSamples > maxSamples(nNotes, maxPitch))
	{
		cout << -1;
		return 0;
	}
	if (maxPitch == 2)
	{
		int nDifferent = nSamples - nNotes;
		for (int i = 0; i < nNotes - nDifferent; i++)
			cout << 1 << ' ';
		bool isOne = true;
		for (int i = 0; i < nDifferent; i++)
		{
			int placeholder;
			if (isOne)
				placeholder = 2;
			else
				placeholder = 1;
			cout << placeholder;
			isOne = !isOne;
			if (i != nDifferent - 1)
				cout << ' ';
		}
		return 0;
	}

	// 1 1 ... 1 1 2 3 4 ... 1 2 3 4 1 2 3 4 1 2 3 1 
	// case 1: k ends before finishing the first 1 2 3 4
	//int nBegRepeats;
	//int nMidRepeats;
	//int nFromLast; // nBegRepeats + maxPitch^2 * (nMidRepeats-1) + maxPitch(maxPitch+1)/2 + nFromLast = nSamples
	//			   // nBegRepeats + nMidRepeats * maxPitch + 1 = nNotes
	//				// nSamples - nNotes = maxPitch(maxPitch * nMidRepeats - maxPitch - nMidRepeats) - 1
	//				// = maxPitch((maxPitch - 1)(nMidRepeats-1) - 1) - 1
	//if (nSamples > maxPitch * (maxPitch + 1) / 2)
	//{
	//	nFromLast = ((nSamples - nNotes - maxPitch * (maxPitch + 1) / 2) + 1) % maxPitch;
	//	nMidRepeats = (((nSamples - nNotes - maxPitch * (maxPitch + 1) / 2) + 1 - nFromLast) / maxPitch) % maxPitch;
	//	nBegRepeats = nNotes - 1 - nMidRepeats * maxPitch;
	//	for (int i = 0; i < nBegRepeats; i++)
	//		cout << "1 ";
	//	for (int i = 0; i < nMidRepeats; i++)
	//		for (int j = 1; j <= maxPitch; j++)
	//			cout << j << ' ';
	//	cout << maxPitch - nFromLast + 1;
	//	return 0;
	//}
}
