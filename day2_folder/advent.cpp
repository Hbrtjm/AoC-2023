#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

int validate_line(string s,int *valid)
{
    int game_no = 0,indx = 0,value = 0,values[3] = {0,0,0};
    // stringstream ss(line);
    string token,element,letter;
    vector<string> sets;
    stringstream ss(s);
    // stringstream element_ss(element);

    while(s[indx] != ':')
    {
        if(s[indx] <= '0' && s[indx] >= '9')
        {
            game_no *= 10;
            game_no += s[indx] - '0';
        }
        indx++;
    }
    while (getline(ss, token, ';')) {
        sets.push_back(token);
    }
    for (const string& set_ : sets) {
        stringstream set_ss(set_);
        for(int i = 0;i < 3;i++)
            values[i] = 0;
        while (getline(set_ss, element, ',')) {
            stringstream element_ss(element);
            element_ss >> value >> letter;
            cout << value << letter;
            indx = -1;
            switch (letter[0]) {
                case 'r':
                    indx = 0;
                    break;
                case 'g':
                    indx = 1;
                    break;
                case 'b':
                    indx = 2;
                    break;
            }

        values[indx] = value;
        }
        for(int i = 0;i < 3;i++)
        {
            if(values[i] > valid[i])
                valid[i] = values[i];
        }
        }
        return valid[0]+valid[1]+valid[2];
}


int main()
{
    int valid[3] = {0,0,0};
    string s;
    int ans = 0;
    ifstream infile("in.txt");
    while(infile >> s)
    {
        cout << s;
        ans += validate_line(s,valid);
    }
    cout << ans;
    return 0;
}
