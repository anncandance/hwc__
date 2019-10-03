#ifndef HWC_IVANOV_H
#define HWC_IVANOV_H
#include<iostream>
namespace ivanov {
    const int N=3;      // размер базы
    extern int rate;   //ставка налога
    extern std::string names[N];
    extern int passport_data[N];
    extern int No[N];
    extern int square[N];
    extern int price[N];

    void tax();


}
#endif //HWC_IVANOV_H
