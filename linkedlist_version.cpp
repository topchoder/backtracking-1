//@Anurag Maurya i love recursion
#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
	int len;
	node()
	{
		len=1;
	}
	node(int x):data(x),len(1),next(0)
	{

	}
};

node *insert(node *root)//function for inserting in the list
{
	node *tem,*nu;
	int x;
	if(!root)
	{
        cout<<"enter data"<<"\n";
        cin>>x;
        nu=new node;
        nu->data=x;
        nu->next=NULL;
        root=nu;
	}
	else
	{
        tem=root;
        while(tem->next)
        	tem=tem->next;
        cout<<"enter data"<<"\n";
        cin>>x;
        nu=new node;
        nu->data=x;
        nu->next=NULL;
        nu->len=tem->len+1;
        tem->next=nu;
	}
	return root;
}

int display(node *tem)
{
	int c=0;
	while(tem)
	{
		cout<<tem->data<<" ";
		tem=tem->next;
		c++;
	}
	cout<<endl;
	return c;
}

void fibonacci_array(node *root,int n,node *tem,int l=0)
{
    for(int i=l;i<n;i++)//transversing through every possible indexes
    {
    	if(tem->next==NULL)//if we reached last element
    	{
    		return;
    	}
        if(tem->data>0&&tem->next->data>0&&tem->next->next)//case 1
        {
		tem->data--;
		tem->next->data--;
	        tem->next->next->data++;
	        display(root);
		fibonacci_array(root,n,tem,i);
		tem->data++;
		tem->next->data++;
	        tem->next->next->data--;
		tem=tem->next;
	}
	else if(tem->data>0&&tem->next->data>0&&tem->next->next==NULL)//case 2 
	{
                tem->data--;
                tem->next->data--;
                node *nu=new node;
                nu->data=1;
                nu->next=NULL;
                tem->next->next=nu;
                display(root);
                fibonacci_array(root,n+1,tem,i);
                tem->data++;
                tem->next->data++;
                tem->next->next=NULL;
                return;
	}
        else if(tem->data==0&&tem->next->data>0&&tem->next->next)//for avoiding the case when ith element is 0 while i+1th element is non zero
        {
	       fibonacci_array(root,n,tem->next,i+1);
	       return;
	}
   }
}

signed main()
{
    node *root=NULL;
    char ch;
    int x;
    do
    { 
        root=insert(root);//creating original array using list
        x=display(root);
        cout<<"again"<<"\n";
        cin>>ch;
     }while(ch=='y');
    
    cout<<"\n\n";
    x=display(root);//printing the original array
    node *tem=root;//pointer that will transverse the list while root will be fixxed
    fibonacci_array(root,x,tem);
    return 0;
}
