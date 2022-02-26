//Christopher Andrade
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "utility.h"
#include "cards.h"
using namespace std;

int main(int argv, char **argc)
{
	if (argv < 3)
	{
		cout << "Please provide 2 file names" << endl;
		return 1;
	}

	ifstream cardFile1(argc[1]);
	ifstream cardFile2(argc[2]);
	string line;

	if (cardFile1.fail() || cardFile2.fail())
	{
		cout << "Could not open file " << argc[2];
		return 1;
	}

	Deck Set1, Set2;

	while (getline(cardFile1, line) && (line.length() > 0))
	{
		string hold = line.substr(0, 1);
		char suit[1];
		strcpy(suit, hold.c_str());
		string val = line.substr(2, 2);
		Selected card;
		card.setC(suit[0], val);
		Set1.insert(card);
	}

	cardFile1.close();

	while (getline(cardFile2, line) && (line.length() > 0))
	{
		string hold = line.substr(0, 1);
		char suit[1];
		strcpy(suit, hold.c_str());
		string val = line.substr(2, 2);
		Selected card;
		card.setC(suit[0], val);
		Set2.insert(card);
	}

	cardFile2.close();

	Selected blank('z', "0");

	Selected a = Set1.Min();
	Selected b = Set2.Max();
	//Selected aMax = Set1.Max();
	//Selected bMin = Set2.Min();

	while (!(a == blank) && !(b == blank))
	{
		if (Set2.contains(a))
		{
			Set2.remove(a);
			cout << "Alice picked matching card " << a.getSuit() << " " << a.getVal() << endl;
			Selected test = Set1.Successor(a);
			Set1.remove(a);
			a = test;
		}
		else if (!Set2.contains(a))
		{
			while (!(a == blank))
			{
				Selected test = Set1.Successor(a);
				a = test;
				if (Set2.contains(a))
				{
					Set2.remove(a);
					cout << "Alice picked matching card " << a.getSuit() << " " << a.getVal() << endl;
					Selected test = Set1.Successor(a);
					Set1.remove(a);
					a = test;
					break;
				}
			}
		}

		if (Set1.contains(b))
		{
			Set1.remove(b);
			cout << "Bob picked matching card " << b.getSuit() << " " << b.getVal() << endl;
			Selected test2 = Set2.Predecessor(b);
			Set2.remove(b);
			b = test2;
		}
		else if (!Set1.contains(b))
		{
			while (!(b == blank))
			{
				Selected test2 = Set2.Predecessor(b);
				b = test2;
				if (Set1.contains(b))
				{
					Set1.remove(b);
					cout << "Bob picked matching card " << b.getSuit() << " " << b.getVal() << endl;
					Selected test2 = Set2.Predecessor(b);
					Set2.remove(b);
					b = test2;
					break;
				}
			}
		}
	}

	cout << endl <<
		"Alice's cards: " << endl;
	Set1.Print();
	cout << endl <<
		"Bob's cards: " << endl;
	Set2.Print();
	return 0;
}