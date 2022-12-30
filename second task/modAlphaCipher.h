#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <locale>
#include <codecvt>
#include <algorithm>
using namespace std;
class modAlphaCipher
{
private:
    int newkey;
public:
    modAlphaCipher() = delete;
    modAlphaCipher(const int& key): newkey(key) {};
    string coder(const string& open_st);
    string decoder(const string& cipher_st);
};