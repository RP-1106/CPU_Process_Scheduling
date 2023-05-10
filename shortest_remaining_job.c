#include <stdio.h>
#include <stdlib.h>

struct p{
	int pid,arrival,burst;
};

struct p* sort(struct p* arr,int np)
{	struct p temp;
	for (int i=0 ; i<np-1 ; i++)
	{	for (int j=0 ; j<np-i-1 ; j++)
		{	if (arr[j].burst > arr[j+1].burst)
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
	{	printf("Enter PID,arrival,burst : ");
		scanf("%d%d%d",&(arr[i].pid),&(arr[i].arrival),&(arr[i].burst));
	}
	printf("\n");

	arr = sort(arr,np);

	int flag[np];
	for (int i=0 ; i<np ; i++){
		flag[i]=-1;
	}

	int time=0 ;
	printf("PID\tStart\tEnd\n");
	for (int i=0 ; i<np ; i++)
	{	if (arr[i].arrival==0){
			flag[arr[i].pid]=1;
			printf("P%d\t%d\t%d\n",arr[i].pid, time, time+arr[i].burst);
			time+=arr[i].burst;
			break;
		}
	}

	for (int k=0 ; k<np ; k++)
	{
		for (int i=0 ; i<np ; i++)
		{	if (flag[arr[i].pid]!=1)
			{	if (arr[i].arrival<time)
				{	printf("P%d\t%d\t%d\n",arr[i].pid, time, time+arr[i].burst);
					flag[arr[i].pid]=1;
					time+=arr[i].burst;
					i=np;
				}
			}
		}
	}
}
