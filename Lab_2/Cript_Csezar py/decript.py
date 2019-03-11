# """Данный код расшифровывает сообщение зашифрованое шифром Цезаря"""
# def decriptCaesar(k, criptText):
#     decriptMessage = ""
#     if k < 0 or k > 231:
#         print("Error Key")
#         exit(0)
#     for i in range(len(criptText)):
#         letter = criptText[i]
#         if letter.isspace():
#             decriptMessage += " "
#         if (ord(letter) >= 33 and ord(letter) <= 63) or (ord(letter)>=91 and ord(letter)<=96)or (ord(letter)>=123 and ord(letter)<=126):
#             i = ord(letter)
#             i=i-k
#             decriptMessage+=chr(i)
#         if letter.isupper():
#             i=ord(letter)
#             i=i-k
#             decriptMessage+=chr(i)
#         if letter.islower():
#             i=ord(letter)
#             i=i-k
#             decriptMessage+= chr(i)
#     return decriptMessage
#
# massage = input("Введите зашифрованое сообщение")
# key = input("Введите ключ")
# print(decriptCaesar(int(key), str(massage)))

