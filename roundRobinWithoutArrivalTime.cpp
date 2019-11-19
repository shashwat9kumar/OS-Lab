#include<iostream>
using namespace std;

struct node
{
	struct node *next;
	int value;
	int time;
}*head;



int gc=0;

void doit(int *cp, int n, int tq)
{
	int done[n];
	for(int i=0;i<n;i++)
	{
		done[i]=1;
	}
	
	
	
	int all=0;
	
	while(all!=n)
	{
		all=0;
		
		
		for(int i=0;i<n;i++)
		{
			
			
			
			
			if(cp[i]>=tq && done[i]!=0)
			{		
				node *temp=new node;
				temp->next=NULL;
				temp->value=i+1;
				temp->time=tq;
				
				
				if(head==NULL)                //assigning new node its location
				{
					head=temp;
				}
				else
				{
					node *x=head;
					while(x->next!=NULL)
					{
						x=x->next;
					}
					x->next=temp;
				}
				
				
				cp[i]=cp[i]-tq;
				
				
				if(cp[i]==0)
				{
					done[i]=0;
				}
				
				
			}
			
			
			
			
			
			else if(cp[i]<tq && cp[i]>0 && done[i]!=0)
			{
				node *temp=new node;
				temp->next=NULL;
				temp->value=i+1;
				temp->time=cp[i];
				
				
				
				if(head==NULL)                //assigning new node its location
				{
					head=temp;
				}
				else
				{
					node *x=head;
					while(x->next!=NULL)
					{
						x=x->next;
					}
					x->next=temp;
				}
				
				
				cp[i]=0;
				
				done[i]=0;
				
			}
			
			
			else
			{
				done[i]=0;
			}
		}
		
		
		
		
		for(int j=0;j<n;j++)        //changing value of all variable if process is terminated(i.e. it has been done[i]=0)
		{
			if(done[j]==0)
			{
				all++;
			}
		}
		
		
		
	}
	
	
	
}




void traversal()
{
    gc=0;
    for(node *temp=head;temp!=NULL;temp=temp->next)
    {
        cout<<temp->value<<"\t"<<temp->time<<endl;
        gc+=temp->time+1;
    }
}




void gantt()
{
	
	cout<<endl;
	cout<<endl;
	cout<<endl;
	
	
	for(int i=0;i<gc;i++)
	{
		cout<<"--";
	}
	cout<<endl;
	for(node *temp=head;temp!=NULL;temp=temp->next)
    {
        cout<<"|"<<temp->value;
        for(int a=0;a<temp->time;a++)
        {
            cout<<"  ";
        }
    }
    cout<<"|\n";

    for(int i=0;i<gc;i++)
    {
        cout<<"--";
    }
    cout<<endl;
}



void wtf(int *wt, int n)
{
	for(int i=0;i<n;i++)
	{
		int nno=0; //node number
		
		int x=0;
		for(node *temp=head;temp!=NULL;temp=temp->next)
		{
			if(temp->value==(i+1))
			{
				nno=x;
			}
			x++;
		}
		
		//cout<<"\n\n\n"<<nno<<"\n\n\n";
		
		int ttw=0;       //time to wait
		x=0;
		for(node *temp=head;temp!=NULL  && x<nno;temp=temp->next)
		{
			if(temp->value!=(i+1))
			{
				ttw+=temp->time;
			}
			x++;
		}
		
		wt[i]=ttw;
	}
}



void calcTAT(int *wt,int *tat,int *bt,int n)
{
	for(int i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
	}
}



void printwtANDtat(int *wt,int *tat,int *bt, int n)
{
	cout<<endl;
	cout<<endl;
	
	cout<<"Process\tBT\tWT\tTAT"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<(i+1)<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
	}
	cout<<endl;
	cout<<endl;
}


void avg(int *wt, int *tat, int n)
{
	float swt=0.0,stat=0.0;
	for(int i=0;i<n;i++)
	{
		swt+=wt[i];
		stat+=tat[i];
	}
	
	cout<<endl;
	cout<<endl;
	swt/=n;
	stat/=n;
	cout<<"Average WT= "<<swt<<endl;
	cout<<"Average TAT= "<<stat<<endl;
}




int main()
{
	int cp[]={2,3,5,4};
	int bt[]={2,3,5,4};
    int n=4;
    int wt[n];
    int tat[n];
    int tq=2;
    doit(cp,n,tq);
    traversal();
    gantt();
    wtf(wt,n);
    calcTAT(wt,tat,bt,n);
    printwtANDtat(wt,tat,bt,n);
    avg(wt,tat,n);
    return 0;
}
