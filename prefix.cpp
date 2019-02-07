//Jordan Dent//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
using namespace std;

struct stack
{
	int data[64];
	int top;
	stack(){top=-1;}
	void push(int x){data[++top]=x;}
	int pop(){return data[top--];}
};

int main()
{
	char b[80];
	stack s;
	int length;
	printf("Type an integer expression in prefix notation:\n");
	gets(b);
	length=strlen(b);
	int i=length-1;
	while(i>=0)
	{
		if(isdigit(b[i]))
		{
			int j=i;
			while(isdigit(b[i]))
				i--;
			int k=i+1;
			s.push(b[k]- '0');
			k++;
			while(k<=j)
			{
				s.push(s.pop()*10+b[k]- '0' );
				k++;
			}
		}
		else if (b[i]=='+')
		{
			s.push(s.pop()+s.pop());
			i--;
		}
		else if (b[i]=='-')
		{
			int v=s.pop();
			s.push(v-s.pop());
			i--;
		}
		else if (b[i]=='*')
		{
			int v=s.pop();
			s.push(v*s.pop());
			i--;
		}
		else if (b[i]=='/')
		{
			int v=s.pop();
			s.push(v/s.pop());
			i--;
		}
		else i--;
	}

		printf("%s=%d\n",b,s.pop());
		return 0;
	}



