#include<iostream>
#include<string.h>
using namespace std;
char stack[100];
int top=-1 , size=100;
int push(int data)
{
	if(top==size-1)
	{
		cout<<"Overflow! ";
	}
	else
	{
		top++;
		stack[top]=data;
	}
}
char pop()
{
	if(top==-1)
	{
		cout<<"Underflow";
	}
	else
	{
		int data=stack[top];
		top--;
		return data;
	}
}
int balance_parentheses()
{
    char s[10],t;
    cout <<"\nEnter string : ";
    cin >>s;
    int valid=0;
    for (int i=0;i<strlen(s);i++)
    {
        if(s[i]=='{' || s[i]=='[' || s[i]=='(')
		{
            push(s[i]);
        }
        else if(s[i]==')'|| s[i]=='}'|| s[i]==']')
        {
        	if(top==-1)
        	{
        		cout<<"Invalid string ";
			}
			else
			{
				t=pop();
				if(t=='(' && (s[i]==']' || s[i]=='}'))
				{
					valid=0;
				}
				else if(t=='[' && (s[i]==')' || s[i]=='}'))
				{
					valid=0;
				} 
				if(t=='{' && (s[i]==']' || s[i]==')'))
				{
					valid=0;
				}
				else
				{
					valid++;
				}
			}
		}
    }
	if(top>=0)
	{
		valid=0;
	}
	if(valid>=1)
	{
		cout<<"\nValid expression ";
	}
	else
	{
		cout<<"\nInvalid expression";
	}
	return 0;
}
int main()
{
    int n;
    cout<<"Enter number of test cases : ";
    cin>>n;
    for(int i=0;i<n;i++)
	{
        balance_parentheses();
    }
    return 0;
}
