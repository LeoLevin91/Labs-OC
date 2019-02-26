#include <iostream>
#include "cmath"
#include "iomanip"

using namespace std;

//Необходимо задать точность вычислений
const double ACCURACY = 1e-6;


//---------------------Вспомогательные функции-----------------------------
bool comparasion(double new1, double old1) {
    if (abs(new1 - old1) < ACCURACY) {
        return true;
    } else {
        return false;
    }
}

long Factorial(int n) {
    long f = 1;
    if ((n == 0) || (n == 1))
        f = 1;
    else
        for (int i = 1; i <= n; i++) {
            f *= i;
            //cout << f << endl;
        }
    return f;

}

//---------------------Основные функции
double expa(double x) {
    //Данная функция будет вычислять экспоненту
    double result_new = 0; //?
    double result_old = 0; //Старое значение переменной
    double value = x;
//    for(int i = 0; i <=8; i++){
//        //result += (value*i)/Factorial(i);
//        result += pow(value, i)/Factorial(i);
//    }
    int i = 0;
    while (true) {
        result_old = result_new; // В result1 хранится старое значение result
        result_new += pow(value, i) / Factorial(i);   // Вычисляется значение result
        bool comp = comparasion(result_new, result_old); // Они сравниваются и результат записывается в переменную
        if (comp == true) {
            break;
        }
        //cout << result_new << endl;
        i++;

    }
    return result_new;
}

double feb_sin(double x) {
    double feb_sin_new = 0;
    double feb_sin_old = 0;
    double value = x;


    int n = 0;
    double degree_one1;
    double divide_one1;
    while (true) {
        feb_sin_old = feb_sin_new;
        degree_one1 = 4 * n + 3;
        divide_one1 = 2 * n + 1;
        feb_sin_new += (pow((-1), n) * pow(value, degree_one1)) / ((degree_one1) * Factorial(divide_one1));
        bool comp = comparasion(feb_sin_new, feb_sin_old);
        if (comp == true) {
            break;
        }
        //cout << feb_sin_new << endl;
        n++;
    }
    return feb_sin_new;
}

double feb_cos(double x) {
    double feb_cos_new = 0;
    double feb_cos_old = 0;
    double value = x;


    int n = 0;
    double degree_one;
    double divide_one;
    while (true) {
        feb_cos_old = feb_cos_new;
        degree_one = 4 * n + 1;
        divide_one = 2 * n;
        feb_cos_new += (pow((-1), n) * pow(value, degree_one)) / ((degree_one) * Factorial(divide_one));
        bool comp = comparasion(feb_cos_new, feb_cos_old);
        if (comp == true) {
            break;
        }
        //cout << feb_cos_new << endl;
        n++;
    }
    return feb_cos_new;
}

void go() {
    while (true) {
        cout << "Данная программа вычисляет экспоненту с помощью ряда, а так же интегралы Френеля" << endl;
        cout << "Введите 1 для вычисления экспоненты," << endl;
        cout << "Введите 2 для вычисления интеграла Френеля для sin" << endl;
        cout << "Введите 3 для вычисления интеграла Френеля для cos" << endl;
        cout << "Введите 0 для выхода" << endl;

        int num;
        cin >> num;
        if (num == 1) {
            double arg;
            cout << "Введите аргумент для экспаненты: " << endl;
            cin >> arg;
            cout << "Вычисление экспоненты с помощью библиотеки cmath: " << setprecision(9) << exp(arg) << endl;
            cout << "Вычисление экспоненты по алгоритму: " << setprecision(9) << expa(arg) << endl;
            cout << "_______________________________________________________________" << endl;
        } else if (num == 2) {
            double arg_sin;
            cout << "Введите аргумент для Фебега SIN: " << endl;
            cin >> arg_sin;
            cout << "Вычисление SIN по ряду Френеля: " << setprecision(5) << feb_sin(arg_sin)
                 << endl; //На калькуляторе 0,777938 после 4 итераций при arg = 1.5
            cout << "_______________________________________________________________" << endl;
        } else if (num == 3) {
            double arg_cos;
            cout << "Введите аргумент для Фебега COS: " << endl;
            cin >> arg_cos;
            cout << "Вычисление SIN по ряду Френеля: " << setprecision(5) << feb_cos(arg_cos)
                 << endl; ///На калькуляторе 0,777938 после 4 итераций при arg = 1.5
            cout << "_______________________________________________________________" << endl;
        } else if (num == 0) {
            exit(0);
        }
    }
}

int main() {
    go();
    return 0;
}

