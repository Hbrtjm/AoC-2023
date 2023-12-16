#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class HashMap()
{

};

long long hashFunction(std::vector<std::string> sequence)
{
    long long answer = 0;
    int result = 0;
    for(std::string token : sequence)
    {
        result = 0;
        for(char character : token)
        {
            //std::cout << character;
            result =  ( ( result + (int)character ) * 17 ) % 256;
        }
        //std::cout << " " << result % 256 << "\n";
        answer += result;
    }
    return answer;
}

int main()
{
    std::vector<std::string> startSequence;
    std::string line,token;
    std::ifstream in("infile15.txt");
    in >> line;
    std::stringstream sequence(line);
    while(getline(sequence,token,','))
    {
        startSequence.push_back(token);
    }
    std::cout << hashFunction(startSequence);
}
