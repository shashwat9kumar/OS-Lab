#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Input the number of processes you want"<<endl;
	cin>>n;
	int wt[n],bt[n],tat[n],at[n];
	string p[n];
	cout<<endl;
	cout<<"Enter the names and burst times and arrival times of processes"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter for process "<<(i+1)<<endl;
		cin>>p[i];
		cin>>bt[i];
		cin>>at[i];
	}
	
	
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			wt[i]=0;
		}
		else
		{
			int sum=0;
			for(int j=0;j<i;j++)
			{
				sum=sum+bt[j];
			}
			wt[i]=sum;
		}
	}
	for(int i=0;i<n;i++)
	{
		wt[i]=wt[i]-at[i];
	}
	
	int awt=0,atat=0;
	cout<<endl;
	cout<<endl;
	cout<<"PN"<<"\t"<<"BT"<<"\t"<<"AT"<<"\t"<<"WT"<<"\t"<<"TAT"<<endl;
	for(int i=0;i<n;i++)
	{
		tat[i]=wt[i]+bt[i];
		cout<<p[i]<<"\t"<<bt[i]<<"\t"<<at[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
	}
	for(int i=0;i<n;i++)
	{
		awt+=wt[i];
		atat+=tat[i];
	}
	float aawt=((float)awt)/n;
	float aatat=((float)atat)/n;
	cout<<" \t \t \t"<<aawt<<"\t"<<aatat<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	
	for(int i=0;i<tat[n-1];i++)
	{
		cout<<"-";
	}
	cout<<endl;
	int x=1;
	for(int i=0;i<tat[n-1];i++)
	{
		if((i+1)==wt[x])
		{
			cout<<"|";
			x++;
			
		}
		else
		{
			cout<<" ";
		}
	}
	cout<<endl;
	for(int i=0;i<tat[n-1];i++)
	{
		cout<<"-";
	}
	
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	
	return 0;
}
