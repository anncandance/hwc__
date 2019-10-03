#include <iostream>
#include"ivanov.h"
#include"sidorov.h"
#include"petrov.h"

void tax(){
    std::cout<<"land:"<<std::endl;
    ivanov::tax();
    std::cout<<"houses:"<<std::endl;
    sidorov::tax();
    std::cout<<"cars:"<<std::endl;
    petrov::tax();
}

int main() {
    std::cin>>ivanov::rate;
    for(int i=0; i<ivanov::N; ++i){
        std::cin>>ivanov::names[i]>>ivanov::passport_data[i]>>ivanov::No[i]>>ivanov::square[i]>>ivanov::price[i];
    }

    std::cin>>sidorov::rate;
    for(int i=0; i<sidorov::N; ++i){
        std::cin>>sidorov::names[i]>>sidorov::passport_data[i]>>sidorov::address[i]>>sidorov::part[i]>>sidorov::price[i];
    }

    std::cin>>petrov::rate;
    for(int i=0; i<petrov::N; ++i){
        std::cin>>petrov::names[i]>>petrov::passport_data[i]>>petrov::No[i]>>petrov::factory_n[i]>>petrov::price[i];
    }
    tax();
    return 0;
}

