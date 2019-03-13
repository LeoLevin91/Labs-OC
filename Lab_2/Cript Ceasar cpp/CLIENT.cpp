//
// Created by leo on 12.03.19.
//
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
using namespace std;

char message[] = "Hello!";
char buf[sizeof(message)];



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
//
//int main()
//{
//    //----Спрашиваем о словах---
//    string a;
//    int key;
//
//    string b;
//    cout << "Введите строку которую хотите зашифровать: " << endl;
//    getline(cin, a);
//    cout << "Введите ключ: " << endl;
//    cin >> key;
//    cout << encript(a, key) << endl;
//
//
//
//
//    //Создадим переменную для сокета
//    int sock;
//    // Создадим структуру sockaddr
//    struct sockaddr_in addr;
//    //Создадим сокет
//    /*В параметры функции socket передается информация о домене, тип сокета и протокол*/
//    sock = socket(AF_INET, SOCK_STREAM, 0);
//    if (sock < 0){
//        perror("Error create socket");
//        exit(1);
//    }
//
//    /*Заполним структуры sockaddr для клиента*/
//    addr.sin_family = AF_INET; //По умолчанию
//    addr.sin_port = htons(9090);    //Номер порта для соединения
//    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);  //Содержит IP адресс порта 32 бита
//
//    //Попытка приконектится
//    if(connect(sock, (struct sockaddr*)&addr, sizeof(addr))<0){
//        perror("Error connect");
//        exit(2);
//    }
//
//    /*Отдаем и принимаем данные*/
//    send(sock, message, sizeof(message), 0);
//    recv(sock, buf, sizeof(buf), 0);
//
//    printf(buf);
//    return 0;
//}
