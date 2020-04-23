#include<iostream>
using namespace std;
class queue
{
	public:
		int q[5];
		int front=0;
		int rear=-1;
		void enqueue()
		{
			int data;
			int l=isfull();
			if(!l)
			{
				cout<<"\nEnter the data\t";
				cin>>data;
				rear++;
				q[rear]=data;
			}
		}
		void dequeue()
		{
			if(!isempty())
			{
				int deleter;
				deleter=q[front];
				front ++;
				
			}
		}
		int isempty()
		{
			if(rear<front)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		int isfull()
		{
			if(rear==4)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		void display()
		{
			for(int i=front;i<=rear;i++)
			{
				cout<<q[i];
				
			}
		}
		
};
main()
{
	queue a;
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
