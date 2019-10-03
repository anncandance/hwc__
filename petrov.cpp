#include"petrov.h"
using namespace petrov;
int petrov::rate;   //ставка налога
std::string petrov::names[N];
int petrov::passport_data[N];
int petrov::No[N];
int petrov::factory_n[N];
int petrov::price[N];
void petrov::tax(){
        for(int i=0; i<N; ++i){
            std::cout<<names[i]<<": factory_number: "<<factory_n[i]<<" price: "<<price[i]<<"tax: "<<rate *(price[i])<<std::endl;
        }

}
