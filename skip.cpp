//Michael Davis
//CSC431
//skip.cpp
#include <stdio.h>
int main (int argc, char *argv[])
{
	FILE *inFile, *outFile;
	if (inFile=fopen(argv[1], "r" ))
	{
		outFile=fopen(argv[2], "w");
		char c1,c2;
		c2= getc(inFile);
		while(c2!=EOF)
		{
			c1=c2;
			c2=getc(inFile);
		if(c1=='/' && c2=='*') 
		{             //skip a block comment
			while(c1!='*' || c2!='/')
			{
				c1=c2;
				c2=getc(inFile);
			}
			putc('\n',outFile);
			c2=getc(inFile);
			c1=c2;
			c2=getc(inFile);
		}
		else if (c1=='/' && c2=='/') 
		{      //skip a line comment
			while(c2!='\n')
			{
				c1=c2;
				c2=getc(inFile);
			}
			putc('\n',outFile);
			c2=getc(inFile);
			c1=c2;
			c2=getc(inFile);
		}
		putc(c1,outFile);
		}
		fclose(inFile);
		fclose(outFile);
	}
		return 0;
}

