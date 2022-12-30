#pragma once
#include <iostream>
#pragma once
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <locale>
#include <codecvt>
#include <vector>
#include <map>
using namespace std;
class modAlphaCipher
{
private:
    string numAlpha ="АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    map<char,int> alphaNum;
    vector<int> key;
    vector<int> convert(const string& s);
    string convert(const vector<int>& v);
public:
    modAlphaCipher() = delete;
    modAlphaCipher(const string& skey);
    string encrypt(const string& open_text);
    string decrypt(const string& cipher_text);
};