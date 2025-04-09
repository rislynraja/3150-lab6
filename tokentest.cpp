#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"

#include <iostream>
#include <sstream>
#include <istream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <cmath>
#include <regex>

#include "tokenizer.h"


TEST_CASE("testing_read_text_file") {
  ifstream myfile("testfile.txt");
  map<string, int> result = read_text_file(myfile);

  map<string, int> expected = { // for my own reference while writing test cases
    {"i", 0}, {"had", 1}, {"always", 2}, {"thought", 3}, {"jack", 4}, {"gisburn", 5}, {"rather", 6}, {"a", 7}, {"cheap", 8}, {"genius", 9}, {"though", 10}, {"good", 11},
    {"fellow", 12}, {"enough", 13}
  };

  CHECK(result["i"] == 0);
  CHECK(result["had"] == 1);
  CHECK(result["always"] == 2);
  CHECK(result["thought"] == 3);
  CHECK(result["jack"] == 4);
  CHECK(result["gisburn"] == 5);
  CHECK(result["rather"] == 6);
  CHECK(result["a"] == 7);
  CHECK(result["cheap"] == 8);
  CHECK(result["genius"] == 9);
  CHECK(result["though"] == 10);
  CHECK(result["good"] == 11);
  CHECK(result["fellow"] == 12);
  CHECK(result["enough"] == 13);

}

TEST_CASE("testing_output_int") {
  ifstream myfile("testfile.txt");
  map<string, int> result = read_text_file(myfile);

  map<string, int> expected = { // for my own reference while writing test cases
    {"i", 0}, {"had", 1}, {"always", 2}, {"thought", 3}, {"jack", 4}, {"gisburn", 5}, {"rather", 6}, {"a", 7}, {"cheap", 8}, {"genius", 9}, {"though", 10}, {"good", 11},
    {"fellow", 12}, {"enough", 13}
  };

  CHECK(outputint(result,"i") == 0);
  CHECK(outputint(result,"had") == 1);
  CHECK(outputint(result,"always") == 2);
  CHECK(outputint(result,"thought") == 3);
  CHECK(outputint(result,"jack") == 4);
  CHECK(outputint(result,"gisburn") == 5);
  CHECK(outputint(result,"rather") == 6);
  CHECK(outputint(result,"a") == 7);
  CHECK(outputint(result,"cheap") == 8);
  CHECK(outputint(result,"genius") == 9);
  CHECK(outputint(result,"though") == 10);
  CHECK(outputint(result,"good") == 11);
  CHECK(outputint(result,"fellow") == 12);
  CHECK(outputint(result,"enough") == 13);

  CHECK(outputint(result,"notaword") == -1); // making sure that a word that is not in the test file will return -1

}

TEST_CASE("testing_output_string") {
  ifstream myfile("testfile.txt");
  map<string, int> result = read_text_file(myfile);

  map<string, int> expected = { // for my own reference while writing test cases
    {"i", 0}, {"had", 1}, {"always", 2}, {"thought", 3}, {"jack", 4}, {"gisburn", 5}, {"rather", 6}, {"a", 7}, {"cheap", 8}, {"genius", 9}, {"though", 10}, {"good", 11},
    {"fellow", 12}, {"enough", 13}
  };

  CHECK(outputstring(result,0) == "i");
  CHECK(outputstring(result,1) == "had");
  CHECK(outputstring(result,2) == "always");
  CHECK(outputstring(result,3) == "thought");
  CHECK(outputstring(result,4) == "jack");
  CHECK(outputstring(result,5) == "gisburn");
  CHECK(outputstring(result,6) == "rather");
  CHECK(outputstring(result,7) == "a");
  CHECK(outputstring(result,8) == "cheap");
  CHECK(outputstring(result,9) == "genius");
  CHECK(outputstring(result,10) == "though");
  CHECK(outputstring(result,11) == "good");
  CHECK(outputstring(result,12) == "fellow");
  CHECK(outputstring(result,13) == "enough");

  CHECK(outputstring(result,99999999) == ""); // empty string for a index that doesn't exist

}

TEST_CASE("testing_output_all") {
  map<string, int> data = { // testing with manually input data instead of file because file is too large to test manually
    {"goodbye", 0},
    {"hello", 1},
    {"sky", 2},
    {"world", 3}
  };

  string expected = "Word: goodbye Token: 0\nWord: hello Token: 1\nWord: sky Token: 2\nWord: world Token: 3\n";

  CHECK(outputall(data) == expected);

}