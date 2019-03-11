//
// Created by leo on 11.03.19.
//
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main() {
//    /*Инициализация map*/
//    map <string,int> myFirstMap = {{ "Mother", 37 },
//                                   { "Father", 40 },///map явно инициализирована
//                                   { "Brother", 15 },
//                                   { "Sister", 20 }};
//    map <int,string> first = {{1, "qwer"},
//                            {2, "qwe"}};
//
//    /*Вывод осуществляется посредствам цикла, который выводит сначала ключ (first) а потом значение (second)*/
//    for (auto iteration = first.begin(); iteration!=first.end(); iteration++){
//        cout << iteration->first<< endl;
//    }
//
//    /*Занесение значений в явно не инициализированый map()*/
//    char C;
//    map <int, char> mySecondMap;
//    for (int i = 0, C='a'; i < 5; ++i, ++C ){
//        mySecondMap.insert(pair<int, char>(i,C));
//    }
//    //Вывод явно не инициализированого map() на экран
//    for(auto it = mySecondMap.begin(); it!=mySecondMap.end(); ++it){
//        cout << it->first << " : " << it->second << endl;
//    }

    /*Реализуем контейнер с большими и маленькими буквами*/
    char c;
    char b;
    map <int,char> DIC;
    for(int i = 0, c='A';  c<='Z'; ++i, ++c){
        DIC.insert(pair<int, char>(i, c));
    }
    for(int i = 26, b='a'; b<='z'; ++i, ++b){
        DIC.insert(pair<int, char>(i, b));
    }
    for(auto it = DIC.begin(); it!=DIC.end(); it++){
        cout << it->first << " : " << it->second << endl;
    }




}