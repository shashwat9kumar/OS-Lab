#include <iostream>

using namespace std;


typedef struct node
{
    int value;
    int time;
    struct node *next;
};
node *head = new node;




void doit(int *cp,int *wt, int n, int tq)
{
    int done[n];
    for(int i=0;i<n;i++)
    {
        done[i]=1;
    }
    int all=0;

    while(all != n)
    {
        all=0;

        for(int i=0;i<n;i++)
        {
            if(cp[i]>= tq && cp[i]!=0 && done[i]!=0)
            {
                node *temp =new node;
                temp->next = NULL;
                temp->value=i+1;
                temp->time=tq;

                if(head==NULL)
                {
                    head=temp;
                }
                else{
                    node *x=head;
                    for(;x->next!=NULL;x=x->next)
                    {
                        ;
                    }
                    x->next=temp;
                }
                cp[i]=cp[i]-tq;


                for(int x=0;x<n;x++)
                {
                    if(x==i || done[x]==0 || cp[i]!=0)
                    {
                        ;
                    }
                    else{
                        wt[x]+=tq;
                    }
                }
            }

            else if(cp[i]<tq && cp[i]!=0 && done[i]!=0)
            {
                node *temp =new node;
                temp->next = NULL;
                temp->value=i+1;
                temp->time=cp[i];

                if(head==NULL)
                {
                    head=temp;
                }
                else{
                    node *x=head;
                    for(;x->next!=NULL;x=x->next)
                    {
                        ;
                    }
                    x->next=temp;
                }
                cp[i]=0;
                
                
                for(int x=0;x<n;x++)
                {
                    if(x==i || done[x]==0 || cp[i]!=0)
                    {
                        ;
                    }
                    else{
                        wt[x]+=cp[i];
                    }
                }
            }

            else if(cp[i]==0)
            {
                done[i]=0;
            }


             
        }

        for(int j=0;j<n;j++)
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
    for(node *temp=head->next;temp!=NULL;temp=temp->next)
    {
        cout<<temp->value<<"\t"<<temp->time<<endl;
    }
}

void wtp(int *wt, int n)
{
    cout<<"\n\n\n";
    for(int i=0;i<n;i++)
    {
        cout<<(i+1)<<"\t"<<wt[i]<<endl;
    }
}

/*int main()
{
    int cp[]={2,3,4,1};
    int wt[]={0,0,0,0};
    int n=4;
    int tq=2;
    doit(cp,wt,n,tq);
    traversal();
    wtp(wt, n);
    return 0;
}
*/

