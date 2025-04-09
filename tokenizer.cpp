#include <istream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <regex>
#include <map>
#include <iostream>

#include "tokenizer.h"

using namespace std;

map<string, int> read_text_file(istream & in_stream){ // reads text from a file, separates 
    map<string, int> data;
    string line;
    int nextId = 0; // to keep track of ids

    regex wordRegex("[A-Za-z0-9']+");

    while (getline(in_stream, line)) { // reading line by line from the input stream
        auto start = sregex_iterator(line.begin(), line.end(), wordRegex);
        auto end = sregex_iterator();

        for (sregex_iterator i = start; i != end; i++) {
            string word = (*i).str(); // getting a word from the line
            transform(word.begin(), word.end(), word.begin(), ::tolower); // using the transform function to lower the caps of all words

            if (data.find(word) == data.end()) {
                // if word is not in the map already, add it
                data[word] = nextId++; // assign and increment
            }
        }
    }

    return data; // returning the map
}

int outputint(map<string, int> data, string word){ // will output the numeric token associated with the string
    auto id = data.find(word);
    if (id != data.end()) {
        return id->second; // returning int which is the second value
    }
    else {
        return -1; // to show it's not there
    }
}

string outputstring(map<string, int> data, int num){ // will output the string associated with the numeric token
    for (const auto& pair : data) {
        if (pair.second == num) {
            return pair.first; // this is the string
        }
    }

    return ""; // returning if no matching string found
}

string outputall(map<string, int> data){ // outputs all strings and their associated tokens
    string printing; // what will be returned

    for (const auto& pair : data) {
        printing += "Word: " + pair.first + " Token: " + to_string(pair.second) + "\n";
    }

    return printing;
}
