#include<string>
#include<exception>
#include<stdio.h>
#include<cstring>

class StringPtr {
    std :: string *s;
public:
    StringPtr(std::string *ss = nullptr): s(ss){};

    operator std::string* () // преобразование к уазателю на строку
    {
        return s;
    }
    int length()
    {
        return (*s).length();
    }
    std::string operator*() // разыменование
    {
        std::string d;
        if (s == nullptr) throw std::exception();
        if((*s).length()>5)
        {
            std::string e = "file:";
            for(int i=0; i<5; ++i){
                if((*s)[i]!=e[i]) return *s;
            }
            for(int i=5; i <(*s).length(); ++i)
            {
                d.push_back((*s)[i]);
            }
            return d;
        }
        else return *s;
    }
    std::string & operator[](int i) // индексация
    {   if(s != nullptr)
            return s[i];
        else throw std::out_of_range("index out of range");
    }
    StringPtr operator++()
    {
        return ++s;
    }
    StringPtr operator--()
    {
        return --s;
    }
    StringPtr operator++(int)
    {
        return s++;
    };
    StringPtr operator--(int)
    {
        return s++;
    };
    StringPtr operator+(int i)
    {
        return s + i;
    }
    StringPtr operator-(int i)
    {
        return s - i;
    }
    friend StringPtr operator+(int n, StringPtr c)
    {
        return n + c.s;
    }
    friend StringPtr operator-(int n, StringPtr c)
    {
        return c.s - n;
    }
    void hide()
    {
        if(s != nullptr)
        {
            char c[(*s).length()];
            std::strcpy(c, (*s).c_str());
            char buffer[10];
            tmpnam(buffer);
            FILE *tmp = fopen(buffer, "a+");
            //fprintf(tmp, "file:");
            fprintf(tmp, c);
            delete s;
            std::string a = "file:";
            char news[15];
            a.copy(news, 5, 0);
            for(int i=0; i<10; ++i){news[i+5]=buffer[i];}
            *s = news;
            // for(int i = 0; i < (*s).length(); ++i) std::cout<<(*s)[i];


           //  проверка записи строки
            char name[(*s).length()];
            rewind(tmp);
            fgets(name, (*s).length()+1, tmp);
            for(int i = 0; i < (*s).length(); ++i) std::cout<<name[i];
            std::cout<<"\n";
        }

    }

};


