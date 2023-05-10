#include <stdio.h>
#include <stdlib.h>

struct p{
	int pid,arrival,burst;
};

struct p* sort(struct p* arr, int np)
{	struct p temp;
	for (int i=0 ; i<np-1 ; i++)
	{	for (int j=0 ; j<np-i-1 ; j++)
		{	if (arr[j].arrival > arr[j+1].arrival)
			{	temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	return arr;
}

void main()
{	int np;
	printf("Enter no.of processes : ");
	scanf("%d",&np);

	struct p* arr = (struct p*)malloc(sizeof(int)*np);

	for (int i=0 ; i<np ; i++)
	{	printf("Enter PID,Arrival,Burst : ");
		scanf("%d%d%d",&(arr[i].pid),&(arr[i].arrival),&(arr[i].burst));
	}
	printf("\n");

	arr = sort(arr,np);

	int time=arr[0].arrival;
	printf("PID\tStart\tEnd\n");
	for (int i=0 ; i<np ; i++)
	{	printf("P%d\t%d\t%d\n",arr[i].pid,time,time+arr[i].burst);
		time+=arr[i].burst;
	}
}
