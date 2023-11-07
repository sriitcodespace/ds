
#include<iostream>
using namespace std;
struct node 
{
int data;
struct node *next;
};
struct node  *head=NULL,*new_node,*temp,*cur;
void create();
void insert_beg();
void insert_end();
void insert_post(int post);
void delete_beg();
void delete_end();
void delete_post(int val);
void search(int ele);
void count_node();
void display();
int main()
{
int choice,post,ele,val;
while(1)
{
cout<<"\n 1. insert at beginning  2. insert at end  3. insert at given position  4. delete at beginning 5 . delete at end  6. delete at given position  7. search   8. count nodes  9.display  10. exit\n";
cout<<"enter your choice";
cin>>choice;
switch(choice)
{
case 1:
insert_beg();
break;
case 2:
insert_end();
break;
case 3: 
cout<<"enter position";
cin>>post;
insert_post(post);
break;
case 4:
delete_beg();
break;
case 5:
delete_end();
break;
case 6:
cout<<"enter value";
cin>>val;
delete_post(val);
break;
case 7:
cout<<"enter element";
cin>>ele;
search(ele);
break;
case 8:
count_node();
break;
case 9:
display();
break;
case 10:
exit(0);
break;
}
}
}
void create()
{
int ele;
new_node=new node();
cout<<"enter data";
cin>>ele;
new_node->data=ele;
new_node->next=NULL;
}
void insert_beg()
{
create();
if (head==NULL)
head=new_node;
else
{
new_node->next=head;
head=new_node;
}
}
void insert_end()
{
create();
if(head==NULL)
head=new_node;
else
{
temp=head;
while(temp->next!=NULL)
temp=temp->next;
temp->next=new_node;
}
}
void insert_post(int post)
{
create();
if(head==NULL)
{
head=new_node;
}
else
cur=head;
for(int i=1;i<post;i++)
{
temp=cur;
if(cur!=NULL)
{
cur=cur->next;
}
else if(cur->next==NULL)
{
insert_end();
}
}
temp->next=new_node;
new_node->next=cur;
}
void delete_beg()
{
if(head==NULL)
cout<<"list is empty";
else
{
temp=head;
head=head->next;
delete temp;
}
}
void delete_end()
{
if(head==NULL)
cout<<"list is empty";
else if(head->next==NULL)
head=NULL;
else
{
cur=head;
while(cur->next!=NULL)
{
temp=cur;
cur=cur->next;
}
delete cur;
temp->next=NULL;
}
}
void delete_post(int val)
{
if(head==NULL)
cout<<"list is empty";
else
{
cur=head;
while(cur->data!=val)
{
if(cur==NULL)
{
cout<<"the given node is not present";
break;
}
else
{
temp=cur;
cur=cur->next;
}
}
if(cur==head)
delete cur;
else
temp->next=cur->next;
delete cur;
}
}
void search(int ele)
{
int t=0;
if(head==NULL)
cout<<"list is empty";
else
{
cur=head;
while(cur!=NULL)
{
if(cur->data=ele)
{
cout<<"element found";
t=1;
break;
}
cur=cur->next;
if(t==0)
cout<<"element not found";
}
}
}

void count_node()
{
int count=0;
if(head==NULL)
cout<<"list is empty";
else
{
cur=head;
while(cur!=NULL)
{
count++;
cur=cur->next;
}
cout<<"no of nodes are"<<count;
}
}
void display()
{
if(head==NULL)
cout<<"empty list";
else
{
temp=head;
while(temp!=NULL)
{
cout<<temp->data<<"->";
temp=temp->next;
}
}
}

