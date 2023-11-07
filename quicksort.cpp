#include<iostream>
using namespace std;
int quicksort(int A[],int low,int high)

{
int pivot=A[low],i=low+1,j=high,temp;
while(i<=j)
{
while(A[i]<pivot)
{
i++;
}
while(A[j]>pivot)
{
j--;
}
if(i<j)
{
temp=A[i];
A[i]=A[j];
A[j]=temp;
}
}
temp=A[low];
A[low]=A[j];
A[j]=temp;
return j;
}
void partition(int A[],int low,int high)
{
if(low<high)
{
int p=quicksort(A,low,high);
partition(A,low,p-1);
partition(A,p+1,high);
}
else
return;
}
int main()
{
int A[20],n;
cout<<"ENTER ARRAY SIZE\n";
cin>>n;
cout<<"ENTER ARRAY ELEMENTS\n";
for(int i=0;i<n;i++)
{
cin>>A[i];
}
partition(A,0,n-1);
cout<<"ELEMENTS AFTER SORTING\n";
for(int i=0;i<n;i++)
{
cout<<A[i]<<"\t";
}
return 0;
}


