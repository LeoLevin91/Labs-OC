"""
    На стороне клиента:
    1) Принять сообщение от пользователя
    2) Зашифровать его
    3) Составить список [шифровка, ключ]
    4) Отправить серверу
    5) Принять от сервера расшифрованое сообещиние
"""

import sys
import pickle
import socket
serverHost = 'localhost'
serverPort = 9010

message = 'hello network world'
key = 3
x = pickle.dumps([message, key])

sockobj = socket.socket()
sockobj.connect((serverHost, serverPort))
sockobj.send(x)
data = sockobj.recv(1024)
print('Client receivied: ', pickle.loads(data))

sockobj.close
y = pickle.loads(data)
print(y)