﻿/// 厦门大学计算机专业 | 前华为工程师
/// 专注《零基础学编程系列》  http://lblbc.cn/blog
/// 包含：Java | 安卓 | 前端 | Flutter | iOS | 小程序 | 鸿蒙
/// 公众号：蓝不蓝编程
/// 
#include <iostream>
#include <vector>
using namespace std;

void printArray(int* array, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << array[i] << " ";
    }
}


void sortMe(int* array, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int index = array[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (i < j && array[j] >= index)
        {
            j--;
        }
        if (i < j)
        {
            array[i] = array[j];
            i++;
        }
        while (i < j && array[i] < index)
        {
            i++;
        }
        if (i < j)
        {
            array[j] = array[i];
            j--;
        }
    }
    array[i] = index;
    sortMe(array, low, i - 1);
    sortMe(array, i + 1, high);
}


void sort(int* array, int count)
{
    sortMe(array, 0, count - 1);
}

int main()
{
	int array[5] = { 2, 1, 5, 4, 3 };
	int count = sizeof(array) / sizeof(int);
	cout << "排序前: "; printArray(array,count);
	sort(array,count);
	cout << "排序后: "; printArray(array,count);
	return 0;
}