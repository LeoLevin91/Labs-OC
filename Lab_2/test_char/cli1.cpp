//
// Created by leo on 13.03.19.
//
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
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


int main()
{
    string a;
    int key = 3;
    char b[100]; //Переменная где хранится результат

    cout << "Введите строку которую хотите зашифровать: " << endl;
    getline(cin, a);
    string result = encript(a, key);
    cout << "Зашифрованое слово: " << result << endl;
    for(int i = 0; i != result.length(); i++){
        b[i] = result[i];
    }

    //Переводим ключ в char
    //char buf[sizeof(b)];
    //char ch_key[1] = char(key);
    //char buf_key[sizeof(key)];



    int sock_cli;
    struct sockaddr_in addr;

    sock_cli = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_cli < 0)
    {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(3113); // или любой другой порт...
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if(connect(sock_cli, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("connect");
        exit(2);
    }

    send(sock_cli, b, sizeof(b), 0);

    //send(sock, &key, sizeof(buf_key), 0);
    //recv(sock, buf, sizeof(b), 0);

    //printf(buf);
    //close(sock_cli);
    shutdown(sock_cli, SHUT_RDWR);

    return 0;
}
