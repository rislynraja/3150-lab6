#ifndef _TOKENS_LAB_
#define _TOKENS_LAB_

#include <istream>
#include <vector>
#include <map>
#include <regex>

using namespace std;

// map<string, int> doubles_read_vector(istream & in_stream);
map<string, int> read_text_file(istream & in_stream); // reads text from a file, separates 

int outputint(map<string, int>, string); // will output the numeric token associated with the string
string outputstring(map<string, int>, int); // will output the string associated with the numeric token
string outputall(map<string, int>); // outputs all strings and their associated tokens

#endif