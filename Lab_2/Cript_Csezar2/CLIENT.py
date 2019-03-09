"""
    На стороне клиента:
    1) Принять сообщение от пользователя
    2) Зашифровать его
    3) Составить список [шифровка, ключ]
    4) Отправить серверу
    5) Принять от сервера расшифрованое сообещиние
"""
import pickle # Необходим для рвзбиения сообщения на биты
import socket
serverHost = 'localhost'
serverPort = 9010
DIC = {chr(x): x-97 for x in range(97, 123)}

def encode(string, key):
    '''шифрование'''
    new_string = ''
    for i in string:
        if i not in DIC:  # если символа нет в словаре оставляем как есть
            new_string += i
            continue
        ch = DIC[i] + key
        if ch > 25:  # букв в алфавите 26 (у нас счет с нуля)
            ch = ch - 26
        new_string += get_key(DIC, ch)
    return new_string


def get_key(dic, val):
    '''получение ключа по значению словаря'''
    for i in dic.items():
        if val in i:
            return i[0]

def dump(code, key):
    messageServer = [code, key]
    messageServer1 = pickle.dumps(messageServer)
    return messageServer1

def serv(dumpMessage):
    sockobj = socket.socket()
    sockobj.connect((serverHost, serverPort))
    sockobj.send(dumpMessage)
    data = sockobj.recv(1024)
    print('Расшифрованое сообщение: ', pickle.loads(data))
    sockobj.close


def main():
    print("Данная программа шифрует сообщение по алгоритму Цезаря.")
    message = str(input("Введите сообщение которое хотите зашифровать >> \n"))
    key = int(input("Введите ключ >> \n"))
    code = encode(message, key)
    dumpMessage = dump(code, key)
    print("Зашифрованое сообщение: " + code)
    serv(dumpMessage)

if __name__ == '__main__':
    main()