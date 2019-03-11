#Создаем словарь со всеми буквами алфавита
DIC = {chr(x): x-97 for x in range(97, 123)}

#Кодирование
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
    return print(new_string)


def get_key(dic, val):
    '''получение ключа по значению словаря'''
    for i in dic.items():
        if val in i:
            return i[0]

#Начало программы
def main():
    print("Данная программа шифрует текст шифром Цезаря")
    message = str(input("Введите сообщение: \n"))
    key = int(input("Введите ключ \n"))
    encode(message, key)


if __name__ == '__main__':
    main()