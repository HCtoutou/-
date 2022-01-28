#include<iostream>
using namespace std;

void Merge_Sort(int* A, int left,int right,int* tmp)
{
	if (right - left > 0)
	{
		int center = left + (right - left) / 2;
		Merge_Sort(A, left, center, tmp);
		Merge_Sort(A, center+1, right, tmp);
		int lb = left;
		int rb = center+1;
		int first = left;
		while (lb <= center || rb <= right)
		{
			//如果左半部分越界 || 右半部分没越界且右半部分首元素小于左半部分首元素
			//则将右半部分元素加入临时数组
			if (lb > center || (rb <= right && A[lb] > A[rb]))
				tmp[first++] = A[rb++];
			else//否则将左半部分首元素加入临时数组
				tmp[first++] = A[lb++];

		}
		//将临时数组的元素放回原数组A中
		for (first = left; first <= right; first++)
		{
			A[first] = tmp[first];
		}
	}
}



int main()
{
	//简单的测试
	int A[8] = { 1,12,5,3,7,3,6,10 };
	int tmp[8] = { 0,0,0,0,0,0,0,0 };
	Merge_Sort(A, 0, 7, tmp);
	for (int i = 0; i < 8; i++)
		cout << A[i] << endl;
}
