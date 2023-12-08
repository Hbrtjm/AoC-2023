#include <map>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

int contains_number(string s)
{
	for(int i = 0;i < s.length();i++)
		if(s[i] >= '0' && s[i] <= '9')
			return true;
	return false;
}

pair<int,int*> process(string line, int current,int maxcard, int *table)
{
	int win = 0,ans = 0,partial_ans = 0,cards = 0;
	map<string,int> wins;
	stringstream winning(line);
	string part,number;
	while(getline(winning,part,'|'))
	{
		if(cards % 2 == 0)
		{
			stringstream partstream(part);
			while(getline(partstream,number,' '))
			{
				// cout << "Currently" << number << "\n";
				if(number == "Card" || number.find(":") != string::npos || !contains_number(number))
					continue;
				// cout << "Writing: " << number << "\n";
				if(wins.count(number) <= 0)
					wins.insert(pair<string,int>(number,1));
			}
		}
		else
		{
                        stringstream partstream(part);
                        while(getline(partstream,number,' '))
                        {
                                if(number == "Card" || number.find(":") != string::npos || !contains_number(number))
                                        continue;
                                // cout << "Getting: " << number << "\n";
				if(wins.count(number) > 0)
				{
					if(partial_ans == 0)
						partial_ans = 1;
					else
						partial_ans *= 2;
					win++;
				}
                        }
			cout << " WIN " << win << " IN " << current  << " " << "\n";
			for(int i = current+1;i < win+current+1;i++)
			{
				if(i < maxcard+1)
					table[i] += table[current];
				cout << "Ith place"<< i << " value in the table" << table[i] << "\n"; 
			}
			wins.clear();
			cout << table[current] << "\n";
			ans += table[current];
			partial_ans = 0;
			win = 0;
		}
		cards++;
	}
	return pair<int,int*>(ans,table);
}

int main()
{
	string line,card_no;
	int ans = 0, maxcard = 0,current = 0;
	ifstream in1("infile4.txt");
	while(getline(in1,line,'\n'))
        {
                stringstream ss(line);
		getline(ss,card_no,' ');
		while(!contains_number(card_no))
			getline(ss,card_no,' ');
        	maxcard = max(stoi(card_no.substr(0,card_no.length()-1)),maxcard);
		// cout << maxcard << "\n";
	}
	ifstream in("infile4.txt");
        int table[maxcard-1];
        for(int i = 0;i < maxcard;i++)
        {
                table[i] = 1;
        }
	pair<int,int*> anstable = pair<int,int*>(ans,table);
	while(getline(in,line,'\n'))
	{

		anstable = process(line,current,maxcard,anstable.second);
		ans += anstable.first;
		current++;
	}
	cout << ans;
	return 0;
}
