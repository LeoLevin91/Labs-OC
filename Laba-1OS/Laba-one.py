import math
from scipy import integrate
from math import sin, cos

# Задаем переменную для точности вычислений
ACCURACY = 1e-6

#-----Вспомогательные функции-----


def composition(new1, old1):
    """Данная функция производит сравнение между двумя переменными
        new1 и old1"""
    if abs(new1-old1) < ACCURACY:
        return True
    else:
        return False

def factor(num):
    """Данная функция вычисляет факториал числа переданого ему"""
    fa = 1
    i = 1
    if num == 0 or num == 1:
        fa = 1
    else:
        for i in range(1, num+1):
            fa = fa * i
    return fa

#-----Основные функции-----
def expa(x):
    result_new = 0
    result_old = 0
    value = x
    i = 0
    while True:
        result_old = result_new
        result_new += pow(value, i) / factor(i)
        comp = composition(result_new, result_old)
        if comp == True:
            break
        i = i + 1
    return result_new


def feb_sin_row(x):
    feb_sin_new = 0
    feb_sin_old = 0
    value = x

    n = 0
    # degree_one = 4 * n + 3
    # divide_one = 2 * n + 1
    while True:
        feb_sin_old = feb_sin_new
        degree_one = 4 * n + 3
        divide_one = 2 * n + 1
        feb_sin_new += (pow((-1), n)*pow(value, degree_one))/((degree_one)*factor(divide_one))
        comp = composition(feb_sin_new, feb_sin_old)
        if comp == True:
            break
        n = n + 1
    return feb_sin_new

def feb_cos_row(x):
    feb_cos_new = 0
    feb_cos_old = 0
    value = x

    n = 0
    # degree_one = 4 * n + 1
    # divide_one = 2 * n
    while True:
        feb_cos_old = feb_cos_new
        degree_one = 4 * n + 1
        divide_one = 2 * n
        feb_cos_new += (pow((-1), n) * pow(value, degree_one)) / ((degree_one) * factor(divide_one))
        comp = composition(feb_cos_new, feb_cos_old)
        if comp == True:
            break
        n = n + 1
    return feb_cos_new

def feb_integral_sin(xmin, xmax, num_intervals):
        #Вычисляем ширину трапеции
        dx = (xmax-xmin)/num_intervals

        #Добавляем облать трапеций
        total_area = 0
        x = xmin
        for i in range(1, num_intervals):
            total_area = total_area + dx * (sin(x**2)+sin(x**2))/2
            x = x + dx
        return total_area

def feb_integral_cos(xmin, xmax, num_intervals):
        #Вычисляем ширину трапеции
        dx = (xmax-xmin)/num_intervals

        #Добавляем облать трапеций
        total_area = 0
        x = xmin
        for i in range(1, num_intervals):
            total_area = total_area + dx * (cos(x**2)+cos(x**2))/2
            x = x + dx
        return total_area

def go():
    while True:
        print("Данная программа вычисляет экспоненту с помощью ряда, а так же Интегралы Френеля")
        print("Введите '1' для вычисления экспоненты,")
        print("Введите '2' для вычисления интеграла Френеля для SIN")
        print("Ввделите '3' для вычисления интеграла Френеля для COS")
        print("Введите '4' для интегрирования Френеля для SIN")
        print("Введите '5' для интегрирования Френеля для COS")
        print("Введите '0' для выхода")

        num = int(input())
        if num == 1:
            print("Введите аргумент для экспаненты:")
            arg = float(input())
            print("Вычисление экспоненты с помощью библиотеки math: " + str(math.exp(arg)))
            print("Вычисление экспоненты с помощью реализованого алгоритма: " + str(expa(arg)))
            print("____________________________________________________________")
        elif num == 2:
            print("Введите аргумент для Френеля SIN:")
            agr_sin = float(input())
            print("Вычисление интеграла Френеля для SIN: " + str(feb_sin_row(agr_sin)))
            print("____________________________________________________________")
        elif num == 3:
            print("Введите аргумент для Френеля COS:")
            agr_cos = float(input())
            print("Вычисление интеграла Френеля для COS: " + str(feb_cos_row(agr_cos)))
            print("____________________________________________________________")
        elif num == 4:
            print("Введите границы интегрирование и шаг разбиения: ")
            inn = float(input())
            ouu = float(input())
            step = int(input())
            # result = feb_integral_sin(inn, ouu, step)
            print("Итог для SIN по методу трапеции (вычисление по алгоритму): " + str(feb_integral_sin(inn, ouu, step)))
            x = lambda x: sin(x**2)
            print("Итог для SIN (библиотека ScyPy): " + str(integrate.quad(x,inn,ouu)))
            print("____________________________________________________________")
        elif num == 5:
            print("Введите границы интегрирование и шаг разбиения: ")
            inn = float(input())
            ouu = float(input())
            step = int(input())
            # result = feb_integral_sin(inn, ouu, step)
            print("Итог для COS по методу трапеции (вычисление по алгоритму): " + str(feb_integral_cos(inn, ouu, step)))
            x = lambda x: cos(x**2)
            print("Итог для COS (библиотека ScyPy): " + str(integrate.quad(x,inn,ouu)))
            print("____________________________________________________________")
        elif num == 0:
            exit()
        else:
            print("Повторите свой выбор, символ который был вами введен НЕВЕРЕН!")


if __name__ == '__main__':
    go()