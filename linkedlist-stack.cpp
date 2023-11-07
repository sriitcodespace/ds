#include<iostream>
using namespace std;
struct node
{
int data;
struct node *next;
};
struct node *top=NULL,*New_node,*temp;
void create()
{
int ele;
cout<<"enter element ";
cin>>ele;
New_node=new node();
New_node->data=ele;
New_node->next=NULL;
}
void push()
{
create();
if(top==NULL)
top=New_node;
else
{
New_node->next=top;
top=New_node;
}
}
void pop()
{
if(top==NULL)
cout<<"stack underflow ";
else
{
temp=top;
top=top->next;
cout<<"deleted "<<temp->data;
delete temp;
}
}
void display()
{
if(top==NULL)
cout<<"empty list ";
else
{
temp=top;
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
cout<<"1:push\t2:pop\t3:display\t4:exit\n";
while(1)
{
cout<<"enter your choice ";
cin>>ch;
switch(ch)
{
case 1:push();break;
case 2:pop();break;
case 3:display();break;
case 4:exit(0);
default:cout<<"invalid choice ";
}
}
return 0;
}
