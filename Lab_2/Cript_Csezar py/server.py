#!/usr/bin/env python
# -*- coding: utf-8 -*-
import socket
import pickle
myHost = ''
myPort = 9010

"""
    На стороне сервера. 
    1) Получить список [зашифрованое сообщение, ключ],
    2) Разбить этот список на переменные
    3) Произвести расшифровку
    4) Отправить клиенту расшифрованое сообщение
    
"""
sockobj = socket.socket()
sockobj.bind((myHost, myPort))
sockobj.listen(5)

while True:
    connection, address = sockobj.accept()
    print("Server connected by ", address)
    while True:
        data = connection.recv(1024)
        if not data:
            break
        connection.send(data)
    connection.close()
