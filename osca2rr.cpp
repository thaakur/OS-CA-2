#include<stdio.h>
#include<conio.h>

void rr(int no,int remt[10],int Cur_t,int arT[10], int bsT[10]);

int main()
{
	int Proc_no,j,no,CurT,RemProc,indicator,time_quan,wait,tut,arT[10],bsT[10],remt[10],x=1;
	indicator = 0;
	wait = 0;
	tut = 0;
	printf("Enter number of processes ");
	scanf("%d",&no);
	RemProc = no;

	printf("\nEnter the arrival time and burst time of the processes\n");
	for(Proc_no = 0;Proc_no < no;Proc_no++)
	{
		printf("\nProcess P%d\n",Proc_no+1);
		printf("Arrival time = ");
		scanf("%d",&arT[Proc_no]);
		printf("Burst time = ");
		scanf("%d",&bsT[Proc_no]);
		remt[Proc_no]=bsT[Proc_no];
	}
	printf("The details of time quantum are as follows:\n");
	printf("The time quantum for first round is 3.\n");
	time_quan=3;
	CurT=0;
	for(Proc_no=0;RemProc!=0;)
	{
		if(remt[Proc_no]<=time_quan && remt[Proc_no]>0)
		{
			CurT+=remt[Proc_no];
			remt[Proc_no]=0;
			indicator=1;
		}
		else if(remt[Proc_no]>0)
		{
			remt[Proc_no]-=time_quan;
			CurT+=time_quan;
		}
		if(remt[Proc_no]==0 && indicator==1)
		{ printf("%d",Proc_no);
			RemProc--;
			printf("P %d",Proc_no+1);
			printf("\t\t\t%d",CurT-arT[Proc_no]);
			printf("\t\t\t%d\n",CurT-bsT[Proc_no]-arT[Proc_no]);
			wait+=CurT-arT[Proc_no]-bsT[Proc_no];
			tut+=CurT-arT[Proc_no];
			indicator=0;

		}
		if(Proc_no==no-1){
			x++;
			if(x==2){
				Proc_no=0;
				time_quan=6;

				printf("The time quantum for second round is 6. \n");
			}
			else{
				break;
			}
		}
		else if(CurT >= arT[Proc_no+1]){
			Proc_no++;
		}
		else{
			Proc_no=0;
		}
	}

	rr(no,remt,CurT,arT,bsT);

	return 0;
}

void rr(int no,int remt[10],int Cur_t,int arT[10], int bsT[10]){

	float avg_wait,avg_tut;
	int i,j,n=no,temp,btime[20],Proc_no[20],w_time[20],tut_t[20],total=0,loc;

    printf("Third round with least burst time.\n");

    for(i=0;i<n;i++)
    {
        btime[i]=remt[i];
        w_time[i]=Cur_t-arT[i]-btime[i];
		Proc_no[i]=i+1;
    }

    for(i=0;i<n;i++)
    {
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(btime[j]<btime[loc]){
            	loc=j;
            }
        }
        temp=btime[i];
        btime[i]=btime[loc];
        btime[loc]=temp;
        temp=Proc_no[i];
        Proc_no[i]=Proc_no[loc];
        Proc_no[loc]=temp;
    }

    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++){
        	w_time[i]+=btime[j];
        }
        total+=w_time[i];
    }

    avg_wait=(float)total/n;
    total=0;
    printf("\nProcess\t\tBurst time\t\twaiting time\t\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tut_t[i]=btime[i]+w_time[i];
        total=total + tut_t[i];
        printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d",Proc_no[i],btime[i],w_time[i],tut_t[i]);
    }
    avg_tut=(float)total/n;
    printf("\n\nAverage waiting time = %f",avg_wait);
    printf("\n Average turnaround time = %f\n",avg_tut);

}
