#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>

bool check(std::vector<std::string> pathsList)
{
	for(const std::string& path : pathsList)
	{
		if(path[path.length()-1]!='Z')
			return false;
	}
	return true;
}

long long SCD(long long a,long long b)
{
	long temp;
	if(a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	while(b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;	
	}
	return a;
}

long long LCM(long long a,long long b)
{
	return a * b / SCD(a,b);
}

long long solve(std::map<std::string, std::pair< std::string, std::string  > > desertMap, std::string path)
{
	long long pathLength = 0,steps=1,currentDirection = 0,rightEntries = 0;
	std::string currentString = "AAA",currentDirectionString;
	std::vector<std::string> triplets;
	for(const auto& element : desertMap)
	{
		if(element.first[2] == 'A')
		{
			triplets.push_back(element.first);
		}
	}
	long long rightEntry[triplets.size()] = { 0 };
	while(rightEntries != triplets.size())
	{
		if(currentDirection == path.length())
		{
			currentDirection = 0;
		}
		currentString = ( path[currentDirection] == 'L' ? desertMap[currentString].first : desertMap[currentString].second );
		for(int i = 0;i < triplets.size();i++)
		{
			if('Z' ==  ( path[currentDirection] == 'L' ? desertMap[triplets[i]].first : desertMap[triplets[i]].second )[2] && rightEntry[i] == 0)
			{
				rightEntries++;
				rightEntry[i] = steps;
			}
			else
				triplets[i] = ( path[currentDirection] == 'L' ? desertMap[triplets[i]].first : desertMap[triplets[i]].second );
		}
		steps++;
		pathLength++;
		// std::cout << currentString << " Direction " << path[currentDirection] << "\n"; 
		currentDirection++;
		for(int element : rightEntry)
                	std::cout << element << "\n";
		std::cout << "\n";
	}
	pathLength = LCM(rightEntry[0],rightEntry[1]);
	for(int i = 2;i < triplets.size();i++)
	{
		pathLength = LCM(pathLength,rightEntry[i]);
	}
	for(std::string element : triplets)
		std::cout << element << "\n";
	return pathLength;
}


int main()
{
	std::map< std::string, std::pair< std::string,std::string> > elements;
	std::ifstream in("infile8.txt");
	std::string path,line,key,equalSign,valueStr,value1,value2;
	char paren,comma;
	getline(in,path,'\n');
	getline(in,line);
	while(getline(in,line,'\n'))
	{
        	size_t equalsPos = line.find('=');
        	key = line.substr(0, equalsPos - 1);
        	size_t startParen = line.find('(', equalsPos);
        	size_t commaPos = line.find(',', startParen);
        	size_t endParen = line.find(')', commaPos);
        	value1 = line.substr(startParen + 1, commaPos - startParen - 1);
        	value2 = line.substr(commaPos + 2, endParen - commaPos - 2);
        	elements[key] = std::make_pair(value1, value2);
	}
    	//for (const auto& entry : elements) 
	//{
        //	std::cout << entry.first << "=>" << entry.second.first << "" << entry.second.second << "\n";
    	//}
	std::cout << solve(elements,path);
	return 0;
}
