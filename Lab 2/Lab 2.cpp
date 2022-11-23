//Реализовать слияние строк матрицы в отдельный массив по возрастанию. Строки матрицы отсортированы по возрастанию

#include <iostream>

using namespace std;

int* Merge(int* first, int* second, int first_size, int second_size)
{
    int index1 = 0;
    int index2 = 0;
    int index_res = 0;
    int result_size = first_size + second_size;
    int* result = new int[result_size];

    while (index1 < first_size && index2 < second_size)
    {
        if (first[index1] < second[index2])
        {
            result[index_res] = first[index1];
            index1++;
        }
        else
        {
            result[index_res] = second[index2];
            index2++;
        }
        index_res++;
    }
    while (index1 < first_size)
    {
        result[index_res++] = first[index1++];
    }
    while (index2 < second_size)
    {
        result[index_res++] = second[index2++];
    }

    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int** A = new int* [n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }
    
    int* result = Merge(A[0], A[1], m, m);
    int result_size = m + m;
    for (int i = 2; i < n; i++)
    {
        result = Merge(result, A[i], result_size, m);
        result_size += m;
    }
    for (int i = 0; i < result_size; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}
