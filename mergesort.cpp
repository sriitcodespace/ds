#include<iostream>
using namespace std;
int a[10],b[10];
void mergesort(int a[],int low,int high,int mid);

void partition(int a[],int low,int high)
{
if(low<high)
{
int mid=(low+high)/2;
partition(a,low,mid);
partition(a,mid+1,high);
mergesort(a,low,high,mid);
}else
return;
}

void mergesort(int a[],int low,int high,int mid)
{
int i=low,j=mid+1,k=low;
while(i<=mid && j<=high)
{
if(a[i]<a[j])
{
b[k]=a[i];
i++;
}
else
{
b[k]=a[j];
j++;
}
k++;
}
while(i<=mid)
{
b[k]=a[i];
i++;
k++;
}
while(j<=high)
{
b[k]=a[j];
j++;
k++;
}
for(int i=0;i<=high;i++)
{
a[i]=b[i];
}
}

int main()
{
int n;
cout<<"ENTER ARRAY SIZE\n";
cin>>n;
cout<<"ENTER ARRAY ELEMENTS\n";
for(int i=0;i<n;i++)
{
cin>>a[i];
}
partition(a,0,n-1);
cout<<"ELEMENTS AFTER SORTING\n";
for(int i=0;i<n;i++)
{
cout<<b[i]<<"\t";
}
return 0;
}
