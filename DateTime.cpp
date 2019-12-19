#include<iostream>
#include<stdlib.h>
#include<new>

using namespace std;

int binary(bool arr[1024]){
    int l = 0, r = 1024, m = 0;
    while(1)
    {
        m = (r - l) / 2;
        if(arr[m])          // ячейка занята
        {
            l = m + 1;
        }
        else{
            if(( m - 1 >= l )&&(!arr[m - 1]))        // ячейка свободна, перелет
            {
                r = m - 1;
            }
            else
                {
                if(arr[m - 1]) return m;            // первая свободная ячейка
                return -1;                          // нет свободных ячеек
                }
        }
    }

}

class DateTime
{
private:
    int day, month, year, hour, minute, second;
public:
    static DateTime objects[1024];
    static bool map[1024];

    static void * operator new(size_t sz)
    {
        int i = binary(map);
        cout<< "new " << i <<endl;
        try
        {
            if( i != -1)
        {
            map[i] = true;
            DateTime *ptr = & objects[i];
            return ptr;
        }
        else throw bad_alloc();
        }
        catch(bad_alloc& ba)
        {
            cerr << "no memory" << endl;
        }
    }

    void operator delete(void *ptr)
    {
        int index = ((int)ptr - (int)objects)/24; // расстояние в int между элементами=24
        cout << "deleted "<< index<<endl;
        map[index] = false;
        free(ptr);
    }

};


bool DateTime:: map[1024];
DateTime DateTime :: objects[1024];

