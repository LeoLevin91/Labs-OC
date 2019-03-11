"""
    На стороне сервера.
    1) Получить список [зашифрованое сообщение, ключ],
    2) Разбить этот список на переменные
    3) Произвести расшифровку
    4) Отправить клиенту расшифрованое сообщение

"""
import socket
import pickle
myHost = ''
myPort = 9010
DIC = {chr(x): x-97 for x in range(97, 123)}


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

        # Собираем данные из дампа
        y = pickle.loads(data)

        # Разбиваем переменные
        criptMessage, key = y

        def dump(decriptMessage):
            """Задампить текст перед отправкой клиенту"""
            messageClient = pickle.dumps(decriptMessage)
            return messageClient

        def decode(criptMessage, key):
            """Декодирование criptMessage"""
            new_string = ''
            for i in criptMessage:
                if i not in DIC:
                    new_string += i
                    continue
                ch = DIC[i] - key
                if ch < 0:
                    ch = 26 + ch
                new_string += get_key(DIC, ch)
            return new_string

        def get_key(dic, val):
            """Получение ключа от словаря"""
            for i in dic.items():
                if val in i:
                    return i[0]

        decriptMessage = decode(criptMessage, key)   # Вызываем функицю декодирования
        print("Декодированое сообщение: " + decriptMessage)
        clientMessage = dump(decriptMessage)

        connection.send(clientMessage)
    connection.close()
