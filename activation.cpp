//Jordan Dent 200075430
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void setupArray(int*a, int n)
{
	srand((unsigned)time(NULL));
	for(int i=0; i<n; i++)
		a[i]=rand()%32;
}

void displayArray(int*a, int n)
{
	for(int i=0; i<n; i++)
	{
		printf("\t%d", a[i]);
		if((i+1)%8==0)
			printf("\n");
	}
	printf("\n");
}

void sortArray(int*a, int n)
{
	for (int i=0; i<n-1; i++)
	{
		int m=i;
		for (int j=i+1; j<n; j++)
			if (a[j]<a[m])
				m=j;
		if(i!=m)
		{
			int t=a[i];
			a[i]=a[m];
			a[m]=t;
		}
	}
}
int binarySearch(int*a, int t, int l, int r)
{
	printf("Current parameter: 1=%2d, r=%2d\n", 1 ,r);
	if(l<=r)
	{
		int m=(l+r)/2;
		int v=a[m];
		if(t==v)
			return m;
		else if(t<v)
			return binarySearch(a,t,l,m-1);
		else
			return binarySearch(a,t,m+1,r);
	}
	return -1;
}

int main()
{
	const int n=32;
	int a[n];
	setupArray(a,n);
	printf("Original array:\n");
	displayArray(a,n);
	sortArray(a,n);
	printf("Sorted array:\n");
	displayArray(a,n);
	int t= rand()%128;
	printf("Target=%d\n",t);
	int i=binarySearch(a,t,0,n-1);
	printf("Target index=%d\n",i);

	return 0;
};
