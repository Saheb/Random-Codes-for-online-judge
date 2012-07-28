//link for the problem is here.
//http://www.codechef.com/problems/CSUMD/
#include<stdio.h>
#include<iostream>
using namespace std;
#define MOD 1000000007
unsigned long long int ar[15];
unsigned long long int proc(unsigned long long int n)
{
	unsigned long long int left,right,side1,side2,f1,f2,f3,f4;
	short int arr[50];
	arr[0]=0;
	while(1)
		{
		arr[0]=arr[0]+1;
		arr[arr[0]]=n%2;
		n=(n/2)+arr[arr[0]];
		if(n==3||n==4)
			break;

		}
		if(n==3)
			{
			left=16;
			right=6;
			side1=2;
			side2=1;
			}
		else
			{
			left=44;
			right=16;
			side1=6;
			side2=2;
			}

	for(int i=arr[0];i>0;i--)
		{
			if(arr[i]==0)
				{
				 	f1 = left*left + 2*right*right;
                    f2 = left*right+ 2*right*side1;
                    f3 = right*right+ 2*side1*side1;
                    f4 = right*side1+ 2*side1*side2;
				}
			else
				{
					f1 = left*right+ 2*right*side1;
                	f2 = right*right+ 2*side1*side1;
                	f3 = right*side1+ 2*side1*side2;
                	f4 = side1*side1+ 2*side2*side2;
				}
			left = f1%1000000007;
            right = f2%1000000007;
            side1 = f3%1000000007;
            side2 = f4%1000000007;
		}
		return left;
		}
int main()
{
	int t;
	unsigned long long int n;
	ar[1]=1;
	ar[2]=3;
	for(int i=3;i<=10;i++)
	{
		ar[i]=2*(ar[i-1]+ar[i-2])%MOD;
	}
	scanf("%d",&t);
	while(t--)
	{
		cin>>n;
		if(n<=10)
			{
			printf("%u\n",ar[n]);
			}
		else
			{
			printf("%u\n",(proc(n-1)+proc(n-2))%MOD);
			}
	}
return 0;
}
