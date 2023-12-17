#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <math.h>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <unordered_map>

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

enum class PokerHand {
    HighCard = 1,
    OnePair,
    TwoPair,
    ThreeOfAKind,
    FullHouse,
    FourOfAKind,
    FiveOfAKind
};

int classifyPokerHand(const std::string& hand) {
    int count[13] = {0};
    char symbols[13] = {'A', 'K', 'Q', 'T', '9', '8', '7', '6', '5', '4', '3', '2', 'J'};
    int jokerIdx = 12; // Index of 'J'

    for (char card : hand) {
        for (int i = 0; i < 13; ++i) {
            if (card == symbols[i] || card == 'J') {
                count[i]++;
                break;
            }
        }
    }

    int maxSame = 0;
    int maxIdx = 0;

    for (int i = 0; i < 13; ++i) {
        if (count[i] > maxSame || (count[i] == maxSame && i < maxIdx)) {
            maxSame = count[i];
            maxIdx = i;
        }
    }

    if (maxSame == 5) {
        return static_cast<int>(PokerHand::FiveOfAKind);
    } else if (maxSame == 4) {
        return static_cast<int>(PokerHand::FourOfAKind);
    } else if (maxSame == 3) {
        int pairs = 0;
        for (int i = 0; i < 13; ++i) {
            if (count[i] == 2) pairs++;
        }
        return (pairs == 1) ? static_cast<int>(PokerHand::FullHouse) : static_cast<int>(PokerHand::ThreeOfAKind);
    } else if (maxSame == 2) {
        int pairs = 0;
        for (int i = 0; i < 13; ++i) {
            if (count[i] == 2) pairs++;
        }
        return (pairs == 2) ? static_cast<int>(PokerHand::TwoPair) : static_cast<int>(PokerHand::OnePair);
    } else {
        return static_cast<int>(PokerHand::HighCard);
    }
}

int classify(std::string hand) {
	std::unordered_map<char, int> cardCount;
	int max_hand = 0;
	int joker = 0;
	char symbols[13] = {'A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2'};
	for (char card : hand) {
	    if(card!='J')
	    if (cardCount.find(card) == cardCount.end()) {
	        cardCount[card] = 1;
	    } else {
	        cardCount[card]++;
	    }
	    if(card == 'J')
	    {
	    	joker++;
	    }
	}

	int distinctCards = cardCount.size();
	int maxSameCards = 0;

	for (const auto& pair : cardCount) {
	    maxSameCards = std::max(maxSameCards, pair.second);
	}
	if (maxSameCards + joker == 5) {
	    return static_cast<int>(PokerHand::FiveOfAKind);
	} else if (maxSameCards + joker == 4) {
	    return static_cast<int>(PokerHand::FourOfAKind);
	} else if (maxSameCards + joker == 3 && distinctCards == 2) {
	    return static_cast<int>(PokerHand::FullHouse);
	} else if (maxSameCards + joker == 3) {
	    return static_cast<int>(PokerHand::ThreeOfAKind);
	} else if (maxSameCards + joker == 2 && distinctCards == 3) {
	    return static_cast<int>(PokerHand::TwoPair);
	} else if (maxSameCards + joker == 2) {
	    return static_cast<int>(PokerHand::OnePair);
	} else {
	    return static_cast<int>(PokerHand::HighCard);
	}
}

bool condition(std::pair<std::string, int> A,std::pair<std::string, int> B)
{
	char symbols[14] = {'A', 'K', 'Q', 'T', '9', '8', '7', '6', '5', '4', '3', '2','J'};
	int a = classify(A.first), b = classify(B.first);
	    if (a == b) {
			for (int i = 0; i < 5; ++i) {
			char cardA = A.first[i], cardB = B.first[i];
			int idxA = -1, idxB = -1;

			for (int j = 0; j < 14; ++j) {
			    if (symbols[j] == cardA) idxA = j;
			    if (symbols[j] == cardB) idxB = j;
			}
            //std::cout << A.first << " " << B.first << " " << a << " " << idxA << " " << idxB << "\n";
			if (idxA != idxB) return idxA > idxB;
	}
		    }
	return a < b;
}

long long solve(std::vector<std::pair<std::string, int> > games)
{
	std::sort(games.begin(),games.end(),condition);
	long long answer = 0;
	for(int i = 0;i < games.size();i++)
	{
		//std::cout << games[i].first << " " << games[i].second << " * " << i + 1 << "\n";
		answer += games[i].second * ( i + 1 );
	}
	return answer;
}

int main()
{
	std::vector< std::pair<std::string, int> > games;
	std::vector<int> bets;
	std::string hand,bet;
	std::ifstream in("infile7.txt");
	do
	{
		in >> hand >> bet;
		std::pair<std::string,int> temp = std::make_pair(hand,std::stoi(bet));
		games.push_back(temp);
		std::cout << games[games.size()-1].first << " " << games[games.size()-1].second << "\n";
	}while(!in.eof());
	games.erase(games.begin()+games.size()-1);
	std::cout << "\n";
	std::cout << solve(games) << "\n";
	return 0;
}

