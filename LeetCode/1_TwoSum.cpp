#include "stdafx.h"

using namespace std;
/***************************************************
Question: How to jump multi-loop? Save time ...
1. try-catch
2. goto
3. function
****************************************************/
/***** Violent ******/
//1. try-catch
/*****
class Solution
{
public:
    vector<int> twoSum(vector<int>&nums, int target)
    {
        vector<int> result;
        try
        {
            for (unsigned int i = 0; i < (nums.size() - 1); i++) 
                for (unsigned int j = i + 1; j < nums.size(); j++)
                {
                    if (target == (nums[i] + nums[j]))
                    {
                        result.push_back(i);
                        result.push_back(j);
                        throw new exception();
                    }
                }
        }
        catch(std::exception)
        {    
        }
      
        return result;
    }
};
******/
//2. goto
/******************
class Solution
{
public:
    vector<int> twoSum(vector<int>&nums, int target)
    {
        vector<int> result;

        for (unsigned int i = 0; i < (nums.size() - 1); i++)      
            for (unsigned int j = i + 1; j < nums.size(); j++)
            {
                if (target == (nums[i] + nums[j]))
                {
                    result.push_back(i);
                    result.push_back(j);
                    goto HERE;
                }
            }
HERE:      
        return result;

        return result;
    }
};
*********************/
//3. return
class Solution
{
public:
    vector<int> twoSum(vector<int>&nums, int target)
    {
        vector<int> result; 
        for (unsigned int i = 0; i < (nums.size() - 1); i++)    
            for (unsigned int j = i + 1; j < nums.size(); j++)
            {
                if (target == (nums[i] + nums[j]))
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }

        cout << "Search Failed!" << endl;
        return result;
    }
};
/********* Hash table ***********/
//1. traverse one
//2. traverse two
int stringToInteger(string input)
{
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1)
{
    if (length == -1)
    {
        length = list.size();
    }

    if (length == 0)
    {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++)
    {
        int number = list[index];
        result += to_string(number) + ",";
    }

    return "[" + result.substr(0, result.length() - 1) + "]";
}

int main01()
{
    string line;
    cout << "Input a line number: ";
    while (getline(cin, line) && !line.empty())
    {
        vector<int> nums = stringToIntegerVector(line);
        cout << "Please input a target: ";
        getline(cin, line);
    
        int target = stringToInteger(line);

        vector<int> ret = Solution().twoSum(nums, target);
        string out = integerVectorToString(ret);
    
        cout << "Result: " + out << endl;
    }

    return 0;
}


