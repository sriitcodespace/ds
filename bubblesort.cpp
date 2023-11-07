#include<iostream>
using namespace std;
int main()
{
int a[20],n,temp,flag=0;
cout<<"enter size of array";
cin>>n;
cout<<"enter elements";
for(int i=0;i<n;i++)
cin>>a[i];
for(int i=0;i<n;i++)
{
for(int j=0;j<n-i-1;j++)
{
flag=0;
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
flag=1;
}
}
if(flag==0)
{
break;}
}
cout<<"elements after sorting";

for(int i=0;i<n;i++)
{
cout<<a[i]<<"\t";

}
}
