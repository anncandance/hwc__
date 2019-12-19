#ifndef HWC_POLINOMINAL_H
#define HWC_POLINOMINAL_H
#include<iostream>


class polinominal {
    int deg;
    double* cf;

public:
    // конструктор по умолчанию
    polinominal();

    // конструктор с параметрами
    polinominal(int d, double*c);

    // деструктор
    ~polinominal();

    // конструктор копирования
    polinominal(const polinominal &p);

     //конструктор перемещения
    polinominal(polinominal&& p);

    // присваивание через копирование
    polinominal& operator=(const polinominal& p);

    // индексация
    double& operator[](int i) const;

    // вызов функции
    double operator()(double x) const;

     //конструктор преобразования
    polinominal(int x);

     //конструктор по списку инициализации
    polinominal(const std::initializer_list<double> &list);


    // методы
    void init(int d, double*c);
    void destroy();
    double & coef(int i) const;
    double value(double x) const;

    // операторы
    friend polinominal operator+(const polinominal &p, const polinominal &q);
    friend polinominal operator-(const polinominal &p, const polinominal &q);
    friend polinominal operator*(const polinominal &p, const polinominal &q);
    friend polinominal operator/(const polinominal &p, const polinominal &q);
    friend polinominal operator%(const polinominal &p, const polinominal &q);


    // ввод-вывод
    friend std::ostream & operator<<(std::ostream & st, polinominal p);
    friend std::istream & operator>>(std::istream & st,polinominal & p);

};


#endif //HWC_POLINOMINAL_H
