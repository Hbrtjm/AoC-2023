#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <math.h>
#include <cctype>
#include <sstream>
#include <algorithm>

template <class elementType, class valueType>
class hsmap{
	private:
		struct Node{
			elementType nodeElement;
		};
	public:
		hsmap()
		{
			std::cout << "Created";
		}
		~hsmap()
		{
			std::cout << "Destroyed";
		}
};

int classify(std::string A)
{
	std::map<char,int> mapped;
	for(int i = 0;i < A.length();i++)
		if(mapped[A[i]])
		{
			mapped[A[i]]++;
		}
		else
		{
			mapped[A[i]] = 1;
		}
	for(const auto& elem : mapped)
	{

	}	
	return 0;
}


bool condition(std::pair<std::string, int> A,std::pair<std::string, int> B)
{
	char symbols[13] = {'A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2'};
	int a = classify(A.first), b = classify(B.first);
	if(a == b)
	{
	}
	return a > b;
}

int solve(std::vector<std::pair<std::string, int> > games)
{
	std::sort(games.begin(),games.end(),condition);
	int answer = 0;
	for(int i = 0;i < games.size();i++)
	{
		answer += games[i].second * (n-i);
	}
	return answer;
}

int main()
{
	std::vector< std::pair<std::string, int> > games;
	std::vector<int> bets;
	std::string hand,bet;
	std::ifstream in("infile7.txt");
	while(!in.eof())
	{
		in >> hand >> bet;
		std::pair<std::string,int> temp = std::make_pair(hand,std::stoi(bet));
		games.push_back(temp);
		std::cout << games[games.size()-1].first << " " << games[games.size()-1].second << "\n";
	}
	std::cout << solve(games) << "\n";
	return 0;
}

