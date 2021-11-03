#include "header.h"

void Merger_sort(int* arr, int* tmp, int left_index, int right_index) { //��������� - ������� ������ ���������������� �������
  //��������� ������� �������
    if (left_index < right_index) {
        Merger_sort(arr, tmp, left_index, ((left_index + right_index) / 2)); //����� ����� ������ ����� ������������� ����� ����� �������
        //������ �������� - ��� �������� �������
        Merger_sort(arr, tmp, ((left_index + right_index) / 2) + 1, right_index); //����� ����� ������ ����� ������������� ������ �����

        //***********************************//
        //������� ���� ��������������� ��������
        //***********************************//

        int left_spot = left_index, right_spot = ((left_index + right_index) / 2) + 1, i, sorted_spot = left_index;
        //��������� � ������ ������ ��������� �� ��������� �� ������, ��������� sorted_spot ������� � ���, ��� ������ �������� �� ��������� �������
        while ((left_spot <= ((left_index + right_index) / 2)) && (right_spot <= right_index)) { //���� �� ��������� ���� �� ���������, ���������� � ���������� � ������� ������
            if (arr[left_spot] <= arr[right_spot]) { //���������� �� �������� ������ ��� � ������ ������
                tmp[sorted_spot] = arr[left_spot];
                left_spot++; //���� ������� ������ ������� ������������, ������������� ���������
                sorted_spot++; //���������� ��������� ������
            }
            else {
                tmp[sorted_spot] = arr[right_spot]; //����������
                right_spot++;
                sorted_spot++;
            }
        }
        if (left_spot > ((left_index + right_index) / 2)) { //���� ����� �������� �����������
            while (right_spot <= right_index) {
                tmp[sorted_spot] = arr[right_spot];
                right_spot++;
                sorted_spot++;
            }
        }
        else { //���� ������ �������� �����������
            while (left_spot <= ((left_index + right_index) / 2)) {
                tmp[sorted_spot] = arr[left_spot];
                left_spot++;
                sorted_spot++;
            }
        }

        for (i = left_index; i <= right_index; i++) //���������� �������, ����������� �������� ������� �� ���������� � �������
            arr[i] = tmp[i]; //����������� ������ ����� �������, ������������� ��������
    }
}