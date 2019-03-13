//
// Created by leo on 12.03.19.
//

#include <iostream>
using namespace std;

string encript(string text, int key) {
    string newWord = "";
    for(char ch:text){
        if(!isalpha(ch)){
            newWord += ch;
            continue;
        }
        else if (ch >= 'A' && ch <= 'Z'){
            ch += (key % 26);
            if (ch > 'Z')
                ch -=26;
            newWord+=ch;
        }
        else if (ch >= 'a' && ch <= 'z'){
            ch +=(key%26);
            if (ch > 'z')
                ch -= 26;
            newWord+=ch;
        }
    }
    return newWord;
}




int main(){
    string a;
    int key;

    string b;
    cout << "Введите строку которую хотите зашифровать: " << endl;
    getline(cin, a);
    cout << "Введите ключ: " << endl;
    cin >> key;
    cout << "Шифровка: " << encript(a, key) << endl;

}