#include "header.h"

void Selection_sort(int* arr, int Amount_of_elements) {
        int min, temp;                                          // для поиска минимального элемента и для обмена
        for (int i = 0; i < Amount_of_elements - 1; i++)
        {
            min = i;                                            // запоминаем индекс текущего элемента
                                                                // ищем минимальный элемент чтобы поместить на место i-ого
            for (int j = i + 1; j < Amount_of_elements; j++)    // для остальных элементов после i-ого
            {
                if (arr[j] < arr[min])                          // если элемент меньше минимального,
                    min = j;                                    // запоминаем его индекс в min
            }
            temp = arr[i];                                      // меняем местами i-ый и минимальный элементы
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }