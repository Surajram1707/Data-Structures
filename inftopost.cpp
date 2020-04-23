#include<iostream>
#include<stack>
using namespace std;
int pri(char op)
{
        switch(op)
        {
                case '+':return 1;
                case '-':return 2;
                case '*':return 3;
                case '/':return 4;
                case '^':return 5;
        }
        return 0;
}
void postFix(string exp)
{
        stack<char> s;
        for(int i=0;i<exp.size();i++)
        {
                char t;
                if(exp[i] >= 97 && exp[i] <= 122)
                        cout<<exp[i];
                else
                {
                        if(s.empty())
                                s.push(exp[i]);
                        else if(exp[i] == '(')
                                s.push(exp[i]);
                        else if(exp[i] == ')')
                        {
                                while(s.top() != '(')
                                {
                                        cout<<s.top();
                                        s.pop();
                                }
                                s.pop();
                        }
                        else
                        {
                                do
                                {
                                        if(s.empty())
                                                break;
                                        t = s.top();
                                        if(pri(t) >= pri(exp[i]))
                                        {
                                                cout<<t;
                                                s.pop();
                                        }
                                }while(pri(t) >= pri(exp[i]));
                                s.push(exp[i]);
                        }
                }
        }
        while(!s.empty())
        {
                cout<<s.top();
                s.pop();
        }
        cout<<endl;
}
main()
{
        string exp;
        cout<<"\nEnter the expression:";
        cin>>exp;
        postFix(exp);
        
}
                                                            


