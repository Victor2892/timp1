#include <iostream>
#include "Cipher.h"
#include <locale>
#include <codecvt>
int main()
{

    int e = 1;
    string r, str;
    int key;
    cout << "Добро пожаловать в программу!" << endl;
    cout << "1 - операция шифрования шифром табличной маршрутной перестановки.\n";
    cout << "2 - операция расшифрования шифра табличной маршрутной перестановки.\n";
    cout << "exit - завершить работу программы." << endl;
    while (e != 2) {
        locale loc("ru_RU.UTF-8");
        locale::global(loc);
        cout << "Укажите операцию: ";
        cin >> r;
        if (r == "1") {
            cout << "Введите строку для зашифрования: ";
            cin.get();
            getline(cin, str);
            cout << "Введите ключ (количество столбцов): ";
            cin >> key;
            wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
            wstring wstr = codec.from_bytes(str);
            Cipher e(key);
            cout<<codec.to_bytes(e.encrypt(wstr))<<endl;
        }

        if (r == "2") {
            cout << "Введите строку для расшифрования: ";
            cin.get();
            getline(cin, str);
            cout << "Введите ключ (количество столбцов): ";
            cin >> key;
            wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
            wstring wstr = codec.from_bytes(str);
            Cipher d(key);
            cout<<codec.to_bytes(d.decrypt(wstr))<<endl;
        }
        if (r == "exit") {
            cout << "До новых встреч!" << endl;
            e = 2;
            break;
        }
    }
    return 0;
}
