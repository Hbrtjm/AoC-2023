#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <cctype>
#include <sstream>

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

int classify(string A)
{

}


bool condition(std::pair<std::string, int> A,std::pair<std::string, int> B)
{
	symbols = []
	int a = classify(A.first), b = classify(B.first);
	if(a == b)
	{
		for(int i 
	}
	return a > b;
}

void solve(std::vector<std::pair<std::string, int> > games)
{
	sort(games.begin(),games.end(),condition);
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
	return 0;
}

