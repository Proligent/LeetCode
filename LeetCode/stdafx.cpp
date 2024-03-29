#include "stdafx.h"


using namespace std;
void trimLeftTrailingSpaces(std::string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));

}
void trimRightTrailingSpaces(std::string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());      //base() : convert reverse_iterator to iterator
        
}
vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);

    input = input.substr(1, input.length() - 2);   // remove "[]"
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';

    while(getline(ss, item, delim))
    {
        output.push_back(stoi(item));
    }

    return output;
}