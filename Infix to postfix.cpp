#include<iostream> //infix to postfix conversion
#include<string.h>
using namespace std;
char stack[100];
int top=-1;
void push(char data)
{
	top++;
	stack[top]=data;
}
char pop()
{
	int data=stack[top];
	top--;
	return data;
}
int priority(char a)
{
	if(a=='^')
		return 4;
	else if(a=='*' || a=='/')
		return 3;
	else if(a=='+' || a=='-')
		return 2;
	else if(a=='(')
		return 1;
	else
		return 0;
}
int main()
{
	char s[100];
	char *e,x;
	cout<<"Enter the expression : ";
	gets(s);
	cout<<"After conversion : ";
	e=s;
	while(*e!='\0')
	{
		if(isalnum(*e))
		{
			cout<<*e;
		}
		else if(*e=='(')
		{
			push(*e);
		}
		else if(*e==')')
		{
			while((x=pop())!='(')
			{
				cout<<x;
			}
		}
		else
		{
			while(priority(stack[top]) >= priority(*e))
			{
				cout<<pop();	
			}
			push(*e);;
		}
		e++;
	}
	while(top!=-1)
	{
		cout<<pop();
	}
	return 0;
}

