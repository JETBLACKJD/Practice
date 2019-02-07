//Jordan Dent//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
using namespace std;

struct stack
{
	int data [64];
	int top;
	stack() {top=-1;}
	void push (int x) {data [++top]=x;}
	int pop() {return data [top--];}
};

int main()
{
	char b[80];
	stack s;
	int length;
	int result;
	int operand1 = 5;
	int operand2 = 7;
	printf("30*( 10+30)");
	scanf ("%s" , b);
	length=strlen (b);
	switch(b[0])
	{
		case '+' : return 0;
			   s.push(result);
			   //cout<<result;
			   break;
		case '-' : return 1;
			   s.push(result);
			   //cout<<result;
			   break;
		case '*' : return 2;
			   s.push(result);
			   //cout<< result;
			   break;
		case '/' : return 3;
			   s.push(result);
			   //cout<<result;
			   break;
	}

printf("%s=%d/n" ,b,s.pop());
return 0;
}
