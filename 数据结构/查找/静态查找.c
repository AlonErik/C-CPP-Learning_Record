#include<stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 	//�洢�ռ��ʼ������

int F[100];			//쳲���������

typedef int Status;		//�������״̬����

//ʹ��˳�������㷨 (���ڱ�);
Status Sequential_Search(int *a, int n, int key)
{	
	int i;
	for(i=1; i<=n; i++)
	{
		if(a[i]==key)
			return i;
	}
	return OK;
}

//ʹ��˳�������㷨 (���ڱ�);
Status Sequential_Search2(int *a, int n, int key)
{
	int i;
	a[0] = key;			//����a[0]Ϊ�ؼ���ֵ, ��Ϊ�ڱ�
	i = n;				//������β����ʼ
	while(a[i]!=key)
	{
		i--;
	}
	return OK;
}

//�۰����;
Status Binary_Search(int *a, int n, int key)
{
	int low, high, mid;
	low = 1;
	high = n;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(key<a[mid])
			high = mid-1;
		else if(key>a[mid])
			low = mid+1;
		else
			return mid;
	}
	return OK;
}

//��ֵ����;		mid=(low+high)/2 --> low+(high-low)/2 ---> low+[(key-a[low])(high-low)/(a[high]-a[low])]
Status Interpolation_Search(int *a, int n, int key)
{
	int low, high, mid;
	low = 1;
	high = n;
	while(low<=high)
	{
		mid = low+(high-low)*(key-a[low])/(a[high]-a[low]);		//���в�ֵ
		if(key<a[mid])
			high = mid-1;
		else if(key>a[mid])
			low = mid+1;
		else
			return mid;
	}
	return OK;
}

//쳲���������(���ûƽ�ָ�ԭ��);
Status Fibonacci_Search(int *a, int n, int key)
{
	int low, high, mid, i, k;
	low = 1;
	high = n;
	k = 0;
	while(n>F[k]-1)		//����n����쳲��������е�λ��
		k++;
	for(i=n; i<F[k]-1; i++)		//��a������ȱ�ٵ���ֵ����
		a[i] = a[n];
	while(low<=high)
	{
		mid = low+F[k-1]-1;
		if(key<a[mid])			//�·�Χ�ǵ�low~��mid��
		{						//��ʱ, ��Χ����ΪF[k-1]-1��
			high = mid-1;
			k = k-1;
		}
		else if(key>a[mid])		//�·�Χ�ǵ�m+1~��high��
		{						//��ʱ, ��Χ����ΪF[k-2]-2��
			low = mid+1;
			k = k-2;
		}
		else
		{
			if(mid<=n)
				return mid;		//�����˵��mid��Ϊ���ҵ���λ��
			else
				return n;		//mid>n˵���ǲ�ȫ��ֵ, ����n
		}
	}
	return OK;
}

int main(void)
{
	int a[MAXSIZE+1], i, result;
	int arr[MAXSIZE] = {0, 1, 16, 24, 35, 47, 59, 62, 73, 88, 99};
	for(i=0; i<=MAXSIZE; i++)
	{
		a[i] = i;
	}
	result = Sequential_Search(a, MAXSIZE, MAXSIZE);
	printf("Sequential_Search:  %d \n", result);
	result = Sequential_Search2(a, MAXSIZE, MAXSIZE);
	printf("Sequential_Search2: %d \n", result);
	result = Binary_Search(arr, 10, 62);
	printf("Binary_Search: %d \n", result);
	result = Interpolation_Search(arr, 10, 62);
	printf("Interpolation_Search: %d \n", result);
	F[0] = 0;
	F[1] = 1;
	for(i=2; i<100; i++)
	{
		F[i] = F[i-1]+F[i-2];
	}
	result = Fibonacci_Search(arr, 10, 62);
	printf("Fibonacci_Search: %d \n", result);
	
	return 0;
}
