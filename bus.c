#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#define SWAP(type,ax,by) do{type temp=ax;ax=by;by=temp;}while(0)
#define min(a,b) (((a)<(b))?(a):(b))


//tnwjd qqweqwewq

int bus(int* arr, int size)// c�� ���� �Ѵ� �ִ� ���, n�� �� �ο�, m�� ������ ��
{
	int left, right, mid;
	
	int mid_index,left_index=0,right_index=size-1;
	left = arr[left_index];
	right = arr[right_index];

	int cnt = 0;//������ ��   m 
	int max_time;//�ִ� ��� �ð�
	int bus_people;// �����Ѵ� �ִ��� c

	int final_time = 14;

	int check;

	while (left <= right)
	{
		mid = (left + right) / 2;
		max_time = mid;
		cnt = 0;
		while (left_index <= right_index)
		{
			
		
			if (arr[mid_index] - arr[left_index] <= max_time)
			{
				if (mid_index - left_index < c)
				{
					mid_index++;
					check = 1;
					continue;
				}
				else if (mid_index - left_index = c)
				{
					left_index = mid_index + 1;
					cnt++;
				}
				else
					right_index = mid_index - 1;
			
			}
			else if (check == 1)
			{
				left_index = mid_index;
				cnt++;
			}

			else {
				right_index = mid_index - 1;
			}


			mid_index = (left_index + right_index) / 2;
		}

		if (cnt <= m)
		{
			final_time = min(final_time, max_time);
			left = mid + 1;
		}
		else
			right = mid - 1;

	}

	return final_time;








}
int main()
{
	int n, m, c;
	int j;

	int t[100000]; //�����ð�

	double start, end,es;
	start=clock();



	//do {
	//	scanf("%d %d %d", &n, &m, &c);
	//} while (n > 100000 || m > 100000 || c > n || n > m * c);

	for (int i = 0; i < n; i++)
	{
		printf("�����ð� �Է�: ");
		do {
			scanf("%d", &t[i]);
		} while (t[i] > 1000000000);
	}

	
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


	//printf("������: %d",_msize(t));/*
	printf("Ÿ����  %ld �ε����� ����\n", bus(t, sizeof(t)/sizeof(int)));



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
