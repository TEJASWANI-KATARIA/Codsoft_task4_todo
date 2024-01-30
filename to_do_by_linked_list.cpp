							//task 4 :)
						  //TO DO LIST 


#include<iostream>
#include<process.h>
#include<stdlib.h>
#include<string>
#define size 50
using namespace std;
struct node
{
	bool mark;
	char task[size];
	struct node * next;
}*head;
typedef struct node node;
void banner();
void menu();
void add_task();
void view_task();
void remove_task(int number);
void update_task(int location);
int main()
{
	head=NULL;
	int choice,number;
	banner();
	while (1)
	{
		menu();
		cin>>choice;
		switch(choice)
		{
			case 1 : add_task();
					 break;
			case 2 : if(head==NULL)
					 {
					 	cout<<"\nList is empty :( nothing to view\n";
					 }
					 else
					 {
					 	view_task();
					 }
					 break;
			case 3 : cout<<"\nhave you completed one task? lets update it...\n";
					 cout<<"which task you want to update...";
					 view_task();
					 cin>>number;
					 update_task(number);
					 cout<<"\tTASK UPDATED\n";
					 break;
			case 4 : if(head==NULL)
					 {
					 	cout<<"list is empty ...nothing to remove\n";
					 }
					 else
					 {
					 	view_task();
					 	cout<<"\nwhich task you want to remove? ";
					 	cin>>number;//it work as location...
					 	remove_task(number);
					 }
					 break;
			case 5 : exit(1);
					 break;
		}
	}
}
void banner()
{
	for(int i=0;i<=30;i++)
	{
		cout<<"-";
	}
	cout<<"\n\tTO DO LIST\n";
	for(int i=0;i<=30;i++)
	{
		cout<<"-";
	}	
}
void menu()
{
	cout<<"\n\tMENU\n";
	cout<<"\n1. ADD TASK\n2. VIEW TASK\n3. UPDATE TASK\n4. REMOVE TASK\n5. EXIT\n";
	cout<<"your choice : ";
}
void add_task()
{
//	char task;
	node *nn,*curr;
	curr=head;
	nn=( node*)(malloc (sizeof(node)));
	nn->next=NULL;
	nn->mark=0;
	cout<<"\nENTER TASK : ";
	cin>>nn->task;	
	if(head==NULL)
	{
		head=nn;
	}
	else
	{
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
		curr->next=nn;
	}
}
void view_task()
{
	cout<<"\nLIST OF TASK : \n";
	node *curr;
	int i=1;
	curr=head;
	while(curr!=NULL)
	{
		cout<<i<<" ";
		if(curr->mark==0)
		{
			cout<<":( ";
			cout<<curr->task<<" pending \n";
		}
		else
		{
			cout<<":) "<<curr->task<<"  completed\n";
		}
		i=i+1;
		curr=curr->next;
	}
}
void remove_task(int number)
{
	int i;
	node *curr;
	curr=head;
	if(number==1)
	{
		head=head->next;
	}
	else
	{
		for(i=1;i<number-1;i++)
		{
			curr=curr->next;
		}
		curr->next=curr->next->next;	
	}
	cout<<"task is removed\n";
}
void update_task(int location)
{
	node *curr;
	curr=head;
	int i;
	for(i=0;i<location-1;i++)
	{
		curr=curr->next;
	}
	if(curr->mark==0)
	{
		curr->mark=1;
	}
	else
	{
		cout<<"\nit is already completed\n";
	}
}
