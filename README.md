# 3150-lab6

instructions for use:

- in order to run, first make sure any necessary c/c++ extensions are installed
- in the terminal, run the line: 
g++ -std=c++17 -Iinclude -o testtokens tokenizer.cpp tokentest.cpp
- this line will compile the tests and put the results in a file called 'testtokens'
- in order to read the file, next run the following line in the terminal: 
./testtokens


notes on files included:

- doctest.h - for testing
- tokenizer.h - definitions for all functions needed
- tokenizer.cpp - implementation of functions listed in header file
- tokentest.cpp - testing and test cases for everything in tokenizer.cpp
- testfile.txt - testing file with sample text to be read