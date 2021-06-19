#pragma once
#include <string>
#include <locale>
using namespace std;
class Cipher
{
private:
    int key;
public:
    Cipher() = delete;
    Cipher(const int k);
    wstring encrypt(wstring str);
    wstring decrypt(wstring str);
};