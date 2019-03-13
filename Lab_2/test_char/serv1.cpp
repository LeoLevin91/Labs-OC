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

int main()
{
    int sock, listener;
    struct sockaddr_in addr;
    char buf[1024];
    string aa;
    int key;

    listener = socket(AF_INET, SOCK_STREAM, 0);
    if(listener < 0)
    {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(3113);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        exit(2);
    }

    listen(listener, 1);

    while(1)
    {
        sock = accept(listener, NULL, NULL);
        if(sock < 0)
        {
            perror("accept");
            exit(3);
        }
        else {
            cout << "Соединение установленно" << endl;
        }

        while(1)
        {

            recv(sock, (char*)&key, sizeof(int), 0);
            recv(sock, buf, 1024, 0);

            cout << key << endl;
            cout << aa << endl;

            int k = key;
            string t = buf;
            string tt = decript(buf, k);
            cout << "РАсшифровка сервером: "<< tt;
            cout << "Ключ: (серв)" << k << endl;
            break;
        }


        break;
    }
    shutdown(sock, SHUT_RDWR);
    return 0;
}


