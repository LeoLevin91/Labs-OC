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



int main(){
    int sock, listener;
    struct sockaddr_in addr;
    char buf[1024];
    int bytes_read; //Сколько байтов считывать за раз

    listener = socket(AF_INET, SOCK_STREAM, 0);
    if (listener < 0){
        perror("Error socket");
        exit(1);
    }

    //Заполняем структуру
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9090);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    //Связываем сокет с адресом и номером порта (только для сервера)
    if(bind(listener, (struct sockaddr*)&addr, sizeof(addr)) < 0){
        perror("Error bind");
        exit(2);
    }
    //Подключаем слушателя
    listen(listener, 1);

    while(1){
        sock = accept(listener, NULL, NULL);
        if (sock < 0){
            perror("Error accept");
            exit(3);
        }
        while(1){
            bytes_read = recv(sock, buf, 1024, 0);
            if(bytes_read<=0) break;
            send(sock, buf, bytes_read, 0);
        }
        close(sock);
    }
    return 0;
}