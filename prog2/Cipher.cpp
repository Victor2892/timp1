#include "Cipher.h"

Cipher::Cipher(const int k )
{
    key = k;
}

wstring Cipher::encrypt(wstring str)
{
    const int dlina = str.length();
    int count_stroki = ((dlina-1)/key)+1;
    int ind = 0;
    wchar_t matr[count_stroki][key];

    for (int i = 0; i < count_stroki; i++) {
        for (int j = 0; j < key; j++ ) {
            if (ind < dlina) {
                matr[i][j] = str[ind];
                ind++;
            } else {
                matr[i][j] =' ';
            }
        }
    }

    ind=0;
    str.clear();
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < count_stroki; j++ ) {
            if (ind <= dlina) {
                str = str + matr[j][i];
            }
            ind++;
        }
    }
    str[ind] = '\0';
    return str;
}

wstring Cipher::decrypt(wstring str)
{
    const int dlina = str.length();
    int count_stroki = ((dlina-1)/key)+1;
    int ind = 0;
    wchar_t matr[count_stroki][key];

    for (int i = 0; i < key; i++) {
        for (int j = 0; j < count_stroki; j++ ) {
            if (ind < dlina) {
                matr[j][i] = str[ind];
                ind++;
            } else {
                matr[j][i] = ' ';
                ind++;
            }
        }
    }
    ind = 0;
    str.clear();
    for(int i = 0; i < count_stroki; i++) {
        for (int j = 0; j< key; j++) {
            if (ind < dlina) {
                str = str + matr[i][j];
            }
            ind++;
        }
    }
    str[ind] = '\0';
    return str;
}
