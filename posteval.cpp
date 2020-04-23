#include<iostream>

using namespace std;
class A
{ public:
  char expr[100];
  int n,m;
  int stack[6];
  int top;
  A()
  { top=-1;}
  void read()
  { cout<<"enter the elements in array";
     cin>>expr;
  }
void func()
  { for(int i=0;expr[i]!='\0';i++)
    {
        if(expr[i]>='a'&&expr[i]<='z')
              {
                cout<<"enter the value";
                cin>>m ;
                 push(m);
                }

     else
       { int x=pop();
         int y=pop();
         if(expr[i]=='+')
        {
          int z=y+x;
                push(z);
        }
         else if(expr[i]=='-')
         { int z=y-x;push(z);}
         else if(expr[i]=='*')
        {          int z=y*x; push(z);}
          else
        {           int z=y/x;push(z); }
        }
     }
     int ans=pop();
      cout<<"the result is"<<ans;
   }

  void push(int x)
  { top++;
    stack[top]=x;
  }
  int pop()
  { int x = stack[top];
    top--;
        return x;
  }

};
main()
{ A a;
  a.read();
a.func();
}

	
		


