#include <iostream>
#include <map>
#include <cmath>


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

string decript(string text, int key) {
    string newWord = "";
    for(char ch:text){
        if(ch < 65 || ch > 122){
            newWord+=ch;
        }
        else if (ch >= 97 && ch <= 122){
            if(ch-key<97){
                newWord+=ch-key+26;
            }
            else {
                newWord+=ch-key;
            }
        }
        else if (ch >= 65 || ch <= 90){
            if(ch-key<65){
                newWord+=ch-key+26;
            }
            else {
                newWord+=ch-key;
            }
        }
    }
    return newWord;
}


int main() {
    string a;
    int key;

    string b;
    cout << "Введите строку которую хотите зашифровать: " << endl;
    getline(cin, a);
    cout << "Введите ключ: " << endl;
    cin >> key;
    cout << decript(a, key) << endl;


}