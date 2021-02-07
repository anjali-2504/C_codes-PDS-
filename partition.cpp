#include<stdio.h>
int c;
void printArray(int p[], int n)
{++c;
	for (int i = 0; i < n; i++)
	printf("%d ",p[i]);
	printf("\n");

}
int *p;
void printAllUniqueParts(int n,int k)
{
	p[k] = n;
		printArray(p, k+1);
		int rem_val = 0;
		while (k >= 0 && p[k] == 1)
		{
			rem_val += p[k];
			k--;
		}
		if (k < 0) return;

		p[k]--;
		rem_val++;
		while (rem_val > p[k])
		{
			p[k+1] = p[k];
			rem_val = rem_val - p[k];
			k++;
		}
		printAllUniqueParts(rem_val,k+1);

}
int main()
{int n;
scanf("%d",&n);
p=(int*)malloc(n*sizeof(int));
if(p == NULL)
{
  printf("malloc of size %d failed!\n", 50);
  exit(1);
}
printAllUniqueParts(n,0);
printf("\n%d",c);
return 0;
}
