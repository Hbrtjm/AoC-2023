#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <climits>

struct line
{
	long firstSet;
	long secondSet;
	long interval;
};

std::vector< std::pair<  long long , long long > > process(std::vector< line > table, std::vector<std::pair <long long, long long > > originalPairs)
{
	std::pair<long long, long long> temp;
	for(int i = 0;i < originalPairs.size();i++)
        {
                for(int j = 0;j < table.size();j++)
                {
                        //std::cout << "Original " << originalPairs[i].first << " " << originalPairs[i].second << " : " << table[j].secondSet << " " << table[j].secondSet + table[j].interval - 1 << "\n";
	                // First case, fully left inside
			if(table[j].secondSet <= originalPairs[i].first && originalPairs[i].first + originalPairs[i].second - 1 <= table[j].secondSet + table[j].interval - 1)
			{
	 			std::cout << "Changed: " << originalPairs[i].first << " to ";
	                        originalPairs[i].first = (originalPairs[i].first - table[j].secondSet) + table[j].firstSet;
	                        std::cout << originalPairs[i].first << "\n";
	                        break;
			}
			//Second case, left part inside 
			else if(table[j].secondSet <= originalPairs[i].first && originalPairs[i].first <= table[j].secondSet + table[j].interval - 1)
			{
				std::cout << "Case 2\n";
				long long newDistance;
                                std::cout << "Split " << originalPairs[i].first << " " << originalPairs[i].second << " to ";
                                std::pair<long long, long long> temp;
                                newDistance = table[j].secondSet + table[j].interval - 1 - originalPairs[i].first;
                                temp = std::make_pair((originalPairs[i].first - table[j].secondSet) + table[j].firstSet,newDistance);
                                originalPairs[i] = std::make_pair(table[j].secondSet + table[j].interval - 1,originalPairs[i].second-newDistance);
                                originalPairs.insert(originalPairs.begin() + i,temp);
                                i++;
                                std::cout << originalPairs[i-1].first << " " << originalPairs[i-1].second << " " << originalPairs[i].first << " " << originalPairs[i].second << "\n";
				// Save the pair first and delete from the list
				// originalPairs.delete(originalPairs.begin()+i);
				// originalPairs.insert(o);
			}
			//Third case, right part inside
			else if(table[j].secondSet >= originalPairs[i].first && originalPairs[i].first + originalPairs[i].second >= table[j].secondSet && originalPairs[i].first + originalPairs[i].second <= table[j].secondSet + table[j].interval - 1)
			{                             
			     	std::cout << "Case 3\n";	
				long long newDistance;
                                std::cout << "Split " << originalPairs[i].first << " " << originalPairs[i].second << " to ";
                                newDistance = originalPairs[i].first + originalPairs[i].second - 1 - table[j].secondSet;
                                temp = std::make_pair(table[j].firstSet,newDistance);
                                originalPairs[i] = std::make_pair(originalPairs[i].first,originalPairs[i].second-newDistance);
                                originalPairs.insert(originalPairs.begin() + i,temp);
                                i++;
                                std::cout << originalPairs[i-1].first << " " << originalPairs[i-1].second << " " << originalPairs[i].first << " " << originalPairs[i].second << "\n";
			}
			// Forth case, the interval is inside
			else if(table[j].secondSet >= originalPairs[i].first && originalPairs[i].first + originalPairs[i].second >= table[j].secondSet + table[j].interval - 1)
			{
				std::cout << "Case 4\n";
				std::pair<long long, long long> temp1;
			        long long newDistance;
                                std::cout << "Split " << originalPairs[i].first << " " << originalPairs[i].second << " to ";
                                

				newDistance = originalPairs[i].first + originalPairs[i].second ;
				temp = std::make_pair(table[j].secondSet+table[j].interval,newDistance);
				temp1 = std::make_pair(table[j].firstSet,table[j].interval);
                                originalPairs[i] = std::make_pair(originalPairs[i].first,originalPairs[i].second-newDistance-table[j].interval);
                                
				
				originalPairs.insert(originalPairs.begin() + i,temp);
                                originalPairs.insert(originalPairs.begin() + i,temp1);

				i+=2;
                                std::cout << originalPairs[i-2].first << " " << originalPairs[i-2].second << " "  << originalPairs[i-1].first << " " << originalPairs[i-1].second << " " << originalPairs[i].first << " " << originalPairs[i].second << "\n";
			}
		}
        }
	// std::vector<std::pair<long long,long long>> temp;
	return originalPairs;
}

std::vector<long> process(std::vector<line> table, std::vector<long> originals)
{

	for(int i = 0;i < originals.size();i++)
	{
		for(int j = 0;j < table.size();j++)
		{
			//std::cout << "Original " << originals[i] << " " << table[j].secondSet << " " << table[j].secondSet + table[j].interval - 1 << "\n";
			if(table[j].secondSet <= originals[i] && originals[i] <= table[j].secondSet + table[j].interval - 1 )
			{
				std::cout << "Changed: " << originals[i] << " to ";
				originals[i] = (originals[i] - table[j].secondSet) + table[j].firstSet; 
				std::cout << originals[i] << "\n";
				break;
			}
		}
	}
	return originals;
}

bool isChar(char character)
{
	return (('a' <= character && character <= 'z') || ('A' <= character && character <= 'Z') || ('0' <= character && character <= '9'));
}

int main()
{
	long long answer = LONG_MAX;
	line singleLine;
	std::vector< std::pair < long long , long long > > originalPairs;
	std::vector<line> nums;
	std::vector<long> originals;
	std::string inString,tempString;
	std::ifstream in("infile5.txt"),in2("infile5.txt");
	getline(in,inString,'\n');
	std::stringstream originalsLine(inString);
	getline(originalsLine,tempString,' ');
	while(getline(originalsLine,tempString,' '))
	{
		originals.push_back(std::stol(tempString));
	}
	while(getline(in,inString,'\n'))
	{
		if(isChar(inString[0]))
		{
			while(getline(in,inString,'\n') && isChar(inString[0]))
			{		

				std::stringstream devided(inString);
				devided >> singleLine.firstSet >> singleLine.secondSet >> singleLine.interval;
				nums.push_back(singleLine);		
			}
			// originals = process(nums,originals);
			nums.clear();
		}
		// std::cout << "\n";
	}
	for(int i = 0;i < originals.size();i++)
	{
		// std::cout << originals[i] << "\n";
		// answer = std::min(originals[i],answer);
	}
	std::cout << answer << " ";
	
	std::pair<std::string,std::string> temp;	
	getline(in2,inString,'\n');
        std::stringstream originalPairLine(inString);
        getline(originalPairLine,tempString,' ');
	
	while(originalPairLine >> temp.first >> temp.second)
        {
                originalPairs.push_back(std::make_pair(std::stol(temp.first),std::stol(temp.second)));
		std::cout << originalPairs[originalPairs.size()-1].first << " " << originalPairs[originalPairs.size()-1].second << "\n"; 
	}

	while(getline(in2,inString,'\n'))
        {
                if(isChar(inString[0]))
                {
                        while(getline(in2,inString,'\n') && isChar(inString[0]))
                        {

                                std::stringstream devided(inString);
                                devided >> singleLine.firstSet >> singleLine.secondSet >> singleLine.interval;
                                nums.push_back(singleLine);
                        }
                        originalPairs = process(nums,originalPairs);
                        nums.clear();
                }
                std::cout << "---\n";
        }
	for(int i = 0;i < originalPairs.size();i++)
        {
                std::cout << originalPairs[i].first << " " << originalPairs[i].second << "\n";
                answer = std::min(originalPairs[i].first,answer);
        }
        std::cout << answer;
	return 0;	
}
