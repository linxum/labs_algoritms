//Написать программу генерации m - последовательностей 0 и 1, удовлетворяющих обоим требованиям :
//1)никакие 3  единицы не стоят рядом;
//2)число единиц превосходит число нулей.

#include <iostream>
#include <WIndows.h>

using namespace std;

bool check(int* result, int m)
{
    bool flag = true;
    int count1 = 0;
    int count0 = 0;
    for (int i = 0; i < m-2; i++)
    {
        if ((result[i] == 1) && (result[i+1] == 1) && (result[i+2] == 1))
        {
            flag = false;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (result[i] == 1)
        {
            count1++;
        }
        else
        {
            count0++;
        }
    }
    if (count1 <= count0)
    {
        flag = false;
    }
    return flag;
}

void Razm_P(int m, int n, int* result, int pos = 0)
{
    if (pos == m)
    {
        if (check(result, m))
        {
            for (int i = 0; i < m; i++)
            {
                cout << result[i];
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < n; ++i) 
        {
            result[pos] = i;
            Razm_P(m, n, result, pos + 1);
        }
    }
}

int main()
{
    int n = 2, m = 8;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int* result = new int[m];
    Razm_P(m, n, result);
}
