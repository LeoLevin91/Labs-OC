"""Данный код производит зfdашифровку методом 'шифра Цезаря'"""

# msgc=""
#
# def main(k):
#     global msgc
#     if k<0 or k>231:
#         print ("Error!")
#         raise SystemExit
#     Input = input("\n[*] Write the text:\n[text] >> ")
#     for x in range(len(Input)):
#         letter=Input[x]
#         if letter.isupper():
#             x=ord(letter)
#             x=x+k
#             msgc+=chr(x)
#         if letter.islower():
#             x=ord(letter)
#             x=x+k
#             msgc+=chr(x)
#     crypt=open("text_crypt.txt","w")
#     print("\nCrypt-text: "+msgc+"\n")
#     crypt.write(msgc)
#     crypt.close()

# Глобальная переменная где будут хранится зашифрованый текст
msgc = ""
def criptCaesar(k):
    global msgc
    if k < 0 or k > 231:
        print("Error!")
        exit(0)
    # Сообщение вводимое пользователем
    inputC = input("\n Write the text:\n [text] >>")
    #inputC.encode('ascii', 'ignore')
    # print(ord(inputC))
    for x in range(len(inputC)):
        letter = inputC[x]
        if letter.isspace():
            msgc += " "
        if (ord(letter) >= 33 and ord(letter) <= 63) or (ord(letter)>=91 and ord(letter)<=96)or (ord(letter)>=123 and ord(letter)<=126):
            x = ord(letter)
            x=x+k
            msgc+=chr(x)
            #msgc += letter
        # if letter.isdigit() == False and letter.isalpha() == False:
        #     msgc += letter
        if letter.isupper():
            x=ord(letter)
            x=x+k
            msgc+=chr(x)
        if letter.islower():
            x=ord(letter)
            x=x+k
            msgc += chr(x)
    return msgc


print(criptCaesar(6))
