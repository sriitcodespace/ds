#include<iostream>
using namespace std;
struct node
{
int data;
struct node *next;
};
struct node *front=NULL,*rear=NULL,*temp,*New_node;
void create()
{
int ele;
cout<<"enter element ";
cin>>ele;
New_node=new node();
New_node->data=ele;
New_node->next=NULL;
}
void enqueue()
{
create();
if(front==NULL )
{
front=New_node;
rear=New_node;
}
else
{
rear->next=New_node;
rear=New_node;
}
}
void dequeue()
{
if(front==NULL)
cout<<"queue unnderflow ";
else
{
temp=front;
front=front->next;
cout<<"deleted "<<temp->data<<" ";
delete temp;
}
}
void display()
{
if(front==NULL )
cout<<"empty list ";
else
{
temp=front;
while(temp!=NULL)
{
cout<<temp->data<<"->";
temp=temp->next;
}
}
}
int main()
{
int ch;
cout<<"1:enqueue\t2:dequeue\t3:display\t4:exit\n";
while(1)
{
cout<<"enter your choice ";
cin>>ch;
switch(ch)
{
case 1:enqueue();break;
case 2:dequeue();break;
case 3:display();break;
case 4:exit(0);
default:cout<<"invalid choice ";
}
}
return 0;
}

