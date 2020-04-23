#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
typedef struct node* position;
class qlist
{
	public:
		position rear,front,temp;
	qlist()
	{
		front=rear=NULL;
	}
	
		void enqueue()
	{
		temp=new node;
		int data1;
		cout<<"\nEnter the data\n";
		cin>>data1;
		temp->data=data1;
		temp->next=NULL;
		if(front==NULL)
		{
			front=rear=temp;
		}
		else
		{
			rear->next=temp;
			rear=temp;
		}
		cout<<"\nInserted\n";
	}
	void dequeue()
	{
	  if(front==rear)
	  {
	  	front=rear=NULL;
	  }
	  else
	  {
	  	front=front->next;
	  }
	}
	void display()
	{
		position i;
		i=front;
		cout<<"\nDisplaying\n";
		while(i!=NULL)
		{
			cout<<i->data;
			i=i->next;
		}
	}
};
main()
{
    qlist a;

	
	int ch,op;
	do
	{
	cout<<"\nEnter choice";
	cout<<"\nMenu...\n1.Insert\n2.Delete\n3.Display\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
			{
				a.enqueue();break;
			}
		case 2:
			{
				a.dequeue();
				cout<<"\nDisplaying....\n";
				a.display();
				break;
				
			}
		case 3:
			{
				cout<<"\nDisplaying...\n";
				a.display();
				break;
			}
	}
	cout<<"\nDo you want to continue(0/1)";
	cin>>op;
}while(op==1);

}
