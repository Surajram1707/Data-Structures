#include<iostream>
using namespace std;
class binheap
{
	public:
		int i,child;
	    int h[10];
		int size=5;
		void insert()
		{
			int x;
			cout<<"\nEnter the element\n";
			cin>>x;
		    size++;
			for(i=size;x<h[i/2]&&i>=1;i++)
			{
				h[i]=h[i/2];
			}
			
				h[i]=x;
				cout<<"\nInserted\n";
		}
			
		
		int deleter()
		{
			int minele=h[1];
			size--;
			for(i=1;(2*i)<size;i=child)
			{
			
				child=2*i;
				if(h[child]>h[child+1])
				{
					int last=h[size];
					child=2*i+1;
					cout<<last<<"\n";
				}
				h[i]=h[child];
			
				cout<<"Size="<<size;
			}
		}
		void display()
		{
			for(i=1;i<=size;i++)
			{


				cout<<"\nDisplaying..\n";
				cout<<h[i]<<"\n";
		}
		}
};
main()
{
	binheap b;
		for(int i=0;i<5;i++)
	{
		b.insert();
	}

//	b.display();
	cout<<"\nDeleting..\n";
	b.deleter();
	b.display();
}
