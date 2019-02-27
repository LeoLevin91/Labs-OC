from scipy import integrate
from math import sin, cos
import math

# x = lambda x: sin(x**2)
# print(integrate.quad(x,0,1.5))


# def integral(xmin, xmax, num_intervals):
#     #Вычисляем ширину трапеции
#     dx = (xmax-xmin)/num_intervals
#
#     #Добавляем облать трапеций
#     total_area = 0
#     x = xmin
#     for i in range(1, num_intervals):
#         total_area = total_area + dx * (sin(x**2)+sin(x**2))/2
#         x = x + dx
#     return total_area
#
# print(integral(0, 1.5, 1000))

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


print("COS " + str(feb_integral_cos(0,1.5,5000)))
print("SIN " + str(feb_integral_sin(0,1.5,5000)))