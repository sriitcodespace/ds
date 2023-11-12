#include <iostream>
using namespace std;

struct node
{
int data;
struct node *left;
struct node *right;
};

struct node *root=NULL,*new_node,*temp,*New,*cur,*parent,*is,*sp;

void create()	
{
New=new node();
cout<<"enter element";
cin>>New->data;
New->left=NULL;
New->right=NULL;
}

void insert()
{
create();
if (root==NULL)
{
root=New;
}
else

{
cur=root;
while(cur!=New)
if(New->data<cur->data)
{
if(cur->left==NULL)

{
cur->left=New;
break;
}else
cur=cur->left;
}

else if(New->data>cur->data)
{
if(cur->right==NULL)

{
cur->right=New;
break;
}
else
cur=cur->right;
}
else
{
cout<<"duplicate";
return;
}
}
}

void preorder(struct node *cur)
{
if(cur!=NULL)
{
cout<<cur->data<<"->";

preorder(cur->left);
preorder(cur->right);

}
else

return;

}
void postorder(struct node *cur)
{
if(cur!=NULL)
{

postorder(cur->left);
postorder(cur->right);
cout<<cur->data<<"->";
}
else

return;
}

void inorder(struct node *cur)
{
if(cur!=NULL)
{

inorder(cur->left);
cout<<cur->data<<"->";
inorder(cur->right);
}
else{

return;
}
}
void deletion(){
int ele;
cout<<"enter element to delete";
cin>>ele;
if(root==NULL){
cout<<"list empty";
}
else{
cur=root;
while(cur->data!=ele){
parent=cur;
if(ele < cur->data){
cur=cur->left;
}
else{
cur=cur->right;
}
if(cur==NULL){
cout<<"element not found";
return;
}}
if(root==cur){
parent=root;
}
if(cur->left==NULL && cur->right==NULL){
parent->left==cur?parent->left=NULL:parent->right=NULL;
if(parent==cur){
root=NULL;
}
delete cur;
}
else if(cur->left!=NULL && cur->right==NULL){
parent->left==cur?parent->left=cur->left:parent->right=cur->left;
if(parent==cur){
root=cur->left;
}
delete cur;
}
else if(cur->left==NULL && cur->right!=NULL){
parent->left==cur?parent->left=cur->right:parent->right=cur->right;
if(parent==cur){
root=cur->right;
}
delete cur;
}
else{
sp=cur;
is=sp->right;
while(is->left!=NULL){
sp=is;
is=is->left;
}
cur->data=is->data;
sp->left==is?sp->left=is->right:sp->right=is->right;
delete is;
}}}
int main()
{
int ch,ele;
while (1)
{
cout<<"menu\n1.insert\t2.preorder\t3.inorder\t4.postorder\t5.exit\t6.delete\n";
cout<<"\nenter choice";
cin>>ch;
switch(ch)
{
case 1:
insert();
break;
case 2:
preorder(root);
break;
case 3:
inorder(root);
break;
case 4:
postorder(root);
break;
case 5:
exit(1);
break;
case 6:

deletion();
break;
default:cout<<"error";
}
}
}
