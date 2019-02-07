#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct stack {				// stack class
	int data[64];
	int top;
	stack(){top=-1;}
	void push(int x){data[++top]=x;}
	int pop(){return data[top--];}
};

	/* Hello world.
	this is a block comment. */


int main() {
	char b[80];				// character buffer
	stack s;				// stack object
	int length;				// length of string


	// ask user to type an integer expression in prefix notation
	printf("Type an integer expression in prefix notation:\n"); 
	gets(b);
	length=strlen(b);

	// evaluate the prefix notation here
	int i=length-1;
	while(i>=0) {
	     if(isdigit(b[i])) {
			int j=i;
			while(isdigit(b[i])) 
				i--;
			int k=i+1;
			s.push(b[k]-'0');
			k++;
			while(k<=j) {
				s.push(s.pop()*10+b[k]-'0');
				k++;
			}
	     }
	     else  if(b[i]=='+') {
			s.push(s.pop()+s.pop());
			i--;
	     }
	     else if(b[i]=='-') {	
			int v=s.pop();
			s.push(v-s.pop());
			i--;
	     }
	     else if(b[i]=='*') {
			s.push(s.pop()*s.pop());
			i--;
	     }
	     else if(b[i]=='/') {
			int v=s.pop();
			s.push(v/s.pop());
			i--;
	     }
	     else
			i--;	
	}

	// print the notation and the evaluation result
	printf("%s = %d \n",  b,  s.pop());

	return 0;
}
