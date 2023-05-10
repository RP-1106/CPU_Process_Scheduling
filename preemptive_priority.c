#include <stdio.h>
#include <stdlib.h>

struct p{
	int pid,arrival,burst,priority;
	int wt,tat,rt,fat,ct;
};

struct p* sort(struct p* arr,int np)
{	struct p temp;
	for (int i=0 ; i<np-1; i ++)
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
{	int burst_time[10];
	int np;
	printf("Enter no.of processes : ");
	scanf("%d",&np);

	struct p* arr = (struct p*)malloc(sizeof(int)*np);

	for (int i=0 ; i<np ; i++)
	{	printf("Enter PID,arrival,burst,priority : ");
		scanf("%d%d%d%d",&(arr[i].pid),&(arr[i].arrival),&(arr[i].burst),&(arr[i].priority));
		burst_time[arr[i].pid]=arr[i].burst;
	}
	printf("\n");

	arr = sort(arr,np);

	int total_wt=0, total_tat=0, total_rt=0;
	float avg_wt, avg_tat, avg_rt;

	int count=0;
	int time;
	int id=0;
	int min_p=9999;

	arr[id].fat=arr[id].arrival;

	for (time=arr[id].arrival ; count!=np ; time++, arr[id].burst--)
	{	if (arr[id].burst==0)
		{	count++;

			arr[id].ct = time;
			arr[id].tat = arr[id].ct - arr[id].arrival;
			arr[id].wt = arr[id].tat - burst_time[arr[id].pid];
			arr[id].rt = arr[id].fat - arr[id].arrival;

			total_tat += arr[id].tat;
			total_wt += arr[id].wt;
			total_rt += arr[id].rt;

			if (count==np){
				break;
			}
		}

		min_p = 9999;
		for (int i=0 ; i<np ; i++)
		{	if (arr[i].arrival<=time && arr[i].burst>0)
			{	if (arr[i].priority<min_p){
					min_p = arr[i].priority;
					id = i;
				}
			}
		}

		if (arr[id].burst == burst_time[arr[id].pid]){
			arr[id].fat = time;
		}
	}

	avg_tat = total_tat / (float)np;
	avg_wt = total_wt / (float)np;
	avg_rt = total_rt / (float)np;

	printf("PID\tCT\tTAT\tWT\tRT\n");
	for (int i=0 ; i<np ; i++)
	{	printf("P%d\t%d\t%d\t%d\t%d\n",arr[i].pid,arr[i].ct,arr[i].tat,arr[i].wt,arr[i].rt);
	}
	printf("\n");

	printf("Avg_tat : %.2f\n",avg_tat);
	printf("Avg_wt  : %.2f\n",avg_wt);
	printf("Avg_rt  : %.2f\n",avg_rt);
}
