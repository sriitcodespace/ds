#include<iostream>
using namespace std;
struct node
{
int data;
struct node *next,*prev;
};
struct node *head=NULL,*new_node,*cur,*temp;
void create()
{
int ele;
new_node=new node();
cout<<"enter data";
cin>>ele;
new_node->data=ele;
new_node->next=NULL;
new_node->prev=NULL;
}
void insert_at_beginning()
{
create();
if(head==NULL)
{
head=new_node;
}
else
{
new_node->next=head;
head->prev=new_node;
head=new_node;
}
}
void insert_at_end()
{
create();
if(head==NULL)
{
head=new_node;
}
else
{
cur=head;
while(cur->next!=NULL)
{
cur=cur->next;
}
cur->next=new_node;
new_node->prev=cur;
}
}
void insert_at_position(int pos)
{
if(pos==1)
{
insert_at_beginning();
}
else
{
if(head==NULL)
{
create();
head=new_node;
 }
else
{
cur=head;
for(int i=1;i<pos;i++)
{
if(cur==NULL)
{
cout<<"given position is not found";
return;
}
else
{
cur=cur->next;
}
}
create();
new_node->next=cur;
new_node->prev=cur->prev;
cur->prev->next=new_node;
cur->prev=new_node;
}
}
}
void deletion_from_beginning()
{
if(head==NULL)
cout<<"link is empty";
else if(head->next==NULL)
head=NULL;
else
{
cur=head;
head=head->next;
head->prev=NULL;
delete cur;
}
}
void delete_from_end()
{
if(head==NULL)
cout<<"linl is empty";
else if (head ->next ==NULL)
head = NULL;
else
{
cur=head;
while(cur->next!=NULL)
{
cur=cur->next;
}
cur->prev->next=NULL;
delete cur;
}
}
void delete_from_position(int val)
{
if(head==NULL)
cout<<"list is empty";
else
{
cur=head;
while(cur->data!=val)
{
cur=cur->next;
if(cur==NULL)
{
cout<<"given node is not present";
exit(0);
}
}
if(cur==head)
deletion_from_beginning();
else
{
cur->prev->next=cur->next;
cur->next->prev=cur->prev;
delete cur;
}
}
}
void display_forward()
{
if(head==NULL)
cout<<"list is empty";
else
{
cur=head;
while(cur!=NULL)
{
cout<<cur->data<<"->";
cur=cur ->next;
}
}
}
void display_backward()
{
if(head==NULL)
cout<<"list is empty";
else
{
cur=head;
while(cur->next!=NULL)
{
cur=cur->next;
}
while(cur!=NULL)
{
cout<<cur->data<<"->";
cur=cur->prev;
}
}
}
int main()
{
int ch,ele,val,pos;
while(1)
{
cout<<"\n select your choice:\n 1.insert at beginning 2.insert at end 3.insert at position 4.delete from beginning 5.delete from end 6.delete from position 7.display fordward 8.display backward 9.exit\n";
cin>>ch;
switch(ch)
{
case 1:
insert_at_beginning();
break;
case 2:
insert_at_end();
break;
case 3:
cout<<"enter position";
cin>>pos;
insert_at_position(pos);
break;
case 4:
deletion_from_beginning();
break;
case 5:
delete_from_end();
break;
case 6:
cout<<"enter value";
cin>>val;
delete_from_position(val);
case 7:
display_forward();
break;
case 8:
display_backward();
break;
case 9:
exit(0);
break;
default:
cout<<"invalid choice";
break;
}
}
}

