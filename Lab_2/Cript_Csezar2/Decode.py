DIC = {chr(x): x-97 for x in range(97, 123)}

def get_key(dic, val):
    '''получение ключа по значению словаря'''
    for i in dic.items():
        if val in i:
            return i[0]

def decode(string, key):
    new_string = ''
    for i in string:
        if i not in DIC:
            new_string += i
            continue
        ch = DIC[i] - key
        if ch < 0:
            ch = 26 + ch
        new_string += get_key(DIC, ch)
    return print(new_string)

def main():
    print("Данная программа дешифрует текст зашифрованый шифром Цезаря.")
    code = str(input("Введите шифровку: "))
    key = int(input("Введите ключ: "))
    decode(code, key)

if __name__ == '__main__':
    main()