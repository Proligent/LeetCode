#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cctype>

extern void trimRightTrailingSpaces(std::string &input);
extern void trimLeftTrailingSpaces(std::string &input);
extern std::vector<int> stringToIntegerVector(std::string input);