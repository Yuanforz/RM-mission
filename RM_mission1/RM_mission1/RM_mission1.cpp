//RMbasic_mission1 
//completed before 2023/9/18/14:51
//使用快速排序的递归版本
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <iostream>
#define SPACE " "
#define TAB "\t"

const int Length = 10;
const int MAX_NUM = 1000;
int* arr_location;//原数组地址，便于在每一步输出数组的值
using namespace std;

void sort(int* arr, int len);
void quick_sort(int arr[], int len);
void array_output(int arr[], int len);

int main()
{
	//starup
    srand(time(NULL));
    int arr[Length] = { 0 };
	arr_location=arr;
	for (int i = 0; i < Length; i++)
		arr[i] = rand() % MAX_NUM;

	//start quick sorting
	cout << "the random array is:" << endl;
	array_output(arr, Length);
	quick_sort(arr, Length);
	cout << "the current array is:" << endl;
	array_output(arr, Length);

    return 0;
}

void array_output(int arr[], int len)
{
	for (int i = 0; i < len; i++)
		cout << arr[i] << SPACE;
	cout << endl;
}

/*每次取最后元作为基准，将小于基准的元素放在temp数组前，将大于者放在后，
最后将temp拷贝至原数组完成一次排序，对两部分分别再次递归排序
*/
void sort(int* arr, int len)
{
	int* const temp = new int[len];
	int* p_small = temp;
	int* p_large = temp + len - 1;
	int position = 0;//基准在排序后的位置
	static int count = 0;//sort的调用次数
	count++;

	//start sorting
	for (int i = 0; i < len - 1; i++)
		if (arr[i] < arr[len - 1])
			*p_small++ = arr[i];
		else
			*p_large-- = arr[i];
	*p_small = arr[len - 1];

	//copy to arr
	position = p_small - temp;
	for (int i = 0; i < len; i++)
		arr[i] = temp[i];
	delete[] temp;

	//output the array
	cout << count << "times:";
	array_output(arr_location, Length);

	//sort next one
	if (position > 0)
		sort(arr, position);
	if (len - position - 1 > 0)
		sort(arr + position + 1, len - position - 1);
}

void quick_sort(int arr[], int len)
{
	sort(arr, len);
}