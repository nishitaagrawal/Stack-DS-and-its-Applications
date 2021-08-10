#include<iostream>
using namespace std;
int stack[100],top=-1 , size=100;
int push()
{
	int data;
	if(top==size-1)
	{
		cout<<"Overflow! ";
	}
	else
	{
		cout<<"Enter the data : ";
		cin>>data;
		top++;
		stack[top]=data;
	}
}
int pop()
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
int display()
{
	if(top>=0)
	{
		cout<<"The elements are : ";
		for(int i=top;i>=0;i--)
		{
			cout<<stack[i]<<" ";
		}
		cout<<"\nTop value : "<<stack[top];
	}
	else
	{
		cout<<"Underflow";
	}
}
int main()
{
	int choice;
	cout<<"MENU\n";
	cout<<"Press 1 to PUSH \nPress 2 to POP \nPress 3 to DISPLAY \nPress 4 to EXIT";
	while(choice!=4)
	{
		cout<<"\n\nEnter the choice : ";
		cin>>choice;
		switch(choice)
		{
			case(1):push();display();break;
			case(2):pop();display();break;
			case(3):display();break;
			case(4):break;
			default:cout<<"Invalid choice ";
		}
	}
}
