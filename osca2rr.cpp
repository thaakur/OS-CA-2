#include<iostream>
void rr(int no,int remt[10],int Cur_t,int arT[10], int bsT[10]);

int main()
{
	int Proc_no,j,no,CurT,RemProc,indicator,time_quan,wait,tut,arT[10],bsT[10],remt[10],x=1;
	indicator = 0;
	wait = 0;
	tut = 0;
	cout<<"Enter number of processes ";
	cin>>no;
	RemProc = no;

	cout<<"\nEnter the arrival time and burst time of the processes\n";
	for(Proc_no = 0;Proc_no < no;Proc_no++)
	{
		cout<<"\nProcess P\n",Proc_no+1;
		cout<<"Arrival time = ";
		cin>>arT[Proc_no];
		cout<<"Burst time = ";
		cin>>bsT[Proc_no];
		remt[Proc_no]=bsT[Proc_no];
	}
	cout<<"The details of time quantum are as follows:\n";
	cout<<"The time quantum for first round is 3.\n";
	time_quan=3;
	CurT=0;
	for
