
#ifndef HWC_PETROV_H
#define HWC_PETROV_H
#include<iostream>
namespace petrov{
    const int N = 3;     // размер базы
    extern int rate;   //ставка налога
    extern std::string names[N];
    extern int passport_data[N];
    extern int No[N];
    extern int factory_n[N];
    extern int price[N];
    void tax();


}

#endif //HWC_PETROV_H
