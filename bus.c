#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#define SWAP(type,ax,by) do{type temp=ax;ax=by;by=temp;}while(0)
int c = 6;
int n = 2;
int m = 3; //����������������
int bus(int* arr, int target, int size)// c�� ���� �Ѵ� �ִ� ���, n�� �� �ο�, m�� ������ ��
{
	int left, right, mid;
	
	int mid_index,left_index=0,right_index=size-1;
	left = arr[left_index];
	right = arr[right_index];
	int cnt = 0;//������ ��   m 
	int max_len;//�ִ� ��� �ð�
	int bus_people;// �����Ѵ� �ִ��� c
	int fixed_mid_index=(left_index+right_index)/2;

	
	while (left_index <= right_index)
	{
		max_len = (left + right) / 2; //7
		mid_index = (left_index + right_index) / 2;
		

		if ((arr[mid_index]-arr[left_index]) <= max_len)
		{
			if (mid_index - left_index <= c)
			{
				cnt++;
				left_index = mid_index + 1;
			}
			else
			{
				right_index = mid_index - 1;
				
			}
		}

		else
		{
			cnt++;
		right_index = mid_index - 1;
		}




		if (cnt > m)
		{
			left = max_len + 1;
			cnt = 0;
			left_index = 0, right_index = size - 1;
			
		}
		if (target == arr[mid])
			return mid;
		else if (target > arr[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}
int main()
{
	int n, m, c;
	int j;
	int min_index;
	int* t; //�����ð�
	int* interval;
	double start, end,es;
	start=clock();

	int targett=0;

	do {
		scanf("%d %d %d", &n, &m, &c);
	} while (n > 100000 || m > 100000 || c > n || n > m * c);

	t = malloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		printf("�����ð� �Է�: ");
		do {
			scanf("%d", &t[i]);
		} while (t[i] > 1000000000);
	}
	/*if (n == m * c)
	{

		return 0;
	}*/

	//����
	//for (int i = 0; i < n; i++) {
	//	min_index = i;
	//	for (j = i + 1; j < n; j++) {
	//		if (t[min_index] > t[j])
	//		{
	//			min_index = j;
	//			SWAP(int, t[i], t[min_index]);
	//		}
	//	}
	//	
	//}
	for (int i = 0; i < n; i++)
	{
		/*min_index = i;*/
		for (j = i + 1; j < n; j++)
		{
			if (t[i] > t[j])
			{
				SWAP(int, t[i], t[j]);
				/*min_index = j;*/
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d  ",t[i]);

	printf("Ÿ���Է�: ");
	scanf("%d", &targett);
	//printf("������: %d",_msize(t));/*
	printf("Ÿ����  %d�ε����� ����\n", bus(t,targett, _msize(t)));



	/*interval = calloc(n - 1, sizeof(int));
	j = 0;
	for (int i = 0; i < n-1; i++)
	{
		
			interval[j] = t[i+1] - t[i];
		printf("%d", interval[j]);
		j++;
	
	}*/


	/*for (int i = 0; i < n; i++)
	{
		printf("%d", t[i]);
	}*/




	end = clock();

	es = (double)(end - start);


	return 0;
}