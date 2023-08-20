/*
ID: sericha1
TASK: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void pay(int payer, int payment, int numberOfReceivers, int *balances, int *receivers)
{
    balances[payer] -= payment - payment % numberOfReceivers;
    for (int i = 0; i < numberOfReceivers; i++)
    {
        balances[receivers[i]] += payment / numberOfReceivers;
    }
}

int nameToIndex(string person, string *people, int numberOfPeople)
{
    for (int i = 0; i < numberOfPeople; i++)
    {
        if (person == people[i])
            return i;
    }
    return -1;
}

int main()
{
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");

    int numberOfPeople{};
    fin >> numberOfPeople;
    int balances[10] = { 0 };
    int payer{};
    int payment{};
    int numberOfReceivers{};

    string people[10];
    for (int i = 0; i < numberOfPeople; i++)
    {
        string namePlaceholder;
        fin >> namePlaceholder;
        people[i] = namePlaceholder;
    }
    for (int i = 0; i < numberOfPeople; i++)
    {
        string payerString;
        fin >> payerString;
        payer = nameToIndex(payerString, people, numberOfPeople);
        fin >> payment;
        fin >> numberOfReceivers;
        if (numberOfReceivers != 0)
        {
            int receivers[10];
            for (int j = 0; j < numberOfReceivers; j++)
            {
                string namePlaceholder;
                fin >> namePlaceholder;
                receivers[j] = nameToIndex(namePlaceholder, people, numberOfPeople);
            }
            pay(payer, payment, numberOfReceivers, balances, receivers);
        }
    }
    for (int i = 0; i < numberOfPeople; i++)
        fout << people[i] << ' ' << balances[i] << endl;
    return 0;
}
