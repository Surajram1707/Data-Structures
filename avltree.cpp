#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  struct node *left;
  struct node *right;
  int height;
};
typedef struct node *position;
class avltree
{
 public:
 int height(position p)
{
  if(p==NULL)
  {
    return -1;
  }
  else
  {
    return p->height;
  }
}
 position insert(position T,int x)
 {
  if(T==NULL)
  {
   T=new node;
   T->data=x;
   T->left=T->right=NULL;
   T->height=0;
   cout<<"\nInserted\n";
  }
  else if(x<T->data)
  {
   T->left=insert(T->left,x);
   if(height(T->left)-height(T->right)==2)
   {
     if(x<T->left->data)
     {
       T=singlerotateleft(T);
     }
     else
      {
        T=doublerotateleft(T);
      }
   }
  }
  else if(x>T->data)
  {
   T->right=insert(T->right,x);
   if(height(T->left)-height(T->right)==-2)
   {
     if(x<T->right->data)
     {
       T=singlerotateright(T);
     }
     else
      {
        T=doublerotateright(T);
      }
   }
   
  }
T->height=max(height(T->left),height(T->right))+1;
  return T;
}
position singlerotateleft(position k2)
{
  position k1=k2->left;
  k2->left=k1->right;
  k1->right=k2;
  k2->height=max(height(k2->left),height(k2->right))+1;
  k1->height=max(height(k1->left),k2->height)+1;
  return k1;
}
position singlerotateright(position k2)
{
  position k1=k2->right;
  k2->right=k1->left;
  k1->left=k2;
  k2->height=max(height(k2->left),height(k2->right))+1;
  k1->height=max(height(k1->left),k2->height)+1;
  return k1;
}
position doublerotateleft(position k3)
{
 k3->left=singlerotateright(k3->left);
 return singlerotateleft(k3);
} 
position doublerotateright(position k3)
{
 k3->right=singlerotateleft(k3->right);
 return singlerotateright(k3);
} 
void preorder(position T)
{

 if(T==NULL)
 {
  return;
   }
cout<<T->data<<"\n";
 preorder(T->left);
 preorder(T->right);
}
void inorder(position T)
{

 if(T==NULL)
 {
  return;
 }
 inorder(T->left);
 cout<<T->data<<"\n";
 inorder(T->right);
}
void postorder(position T)
{
 if (T==NULL)
 {
  return;
 }
 postorder(T->left);
 postorder(T->right);
 cout<<T->data<<"\n";
}
position find(position T,int x)
{
 if(T==NULL)
 {
  return NULL;
 }
 else if(x<T->data)
{
 return find(T->left,x);
}
else if(x>T->data)
{
 return find(T->right,x);
}
else
{
 return T;
}
}
position findmax(position T)
{
 if(T->right!=NULL)
 {
  findmax(T->right);
 }
 else
 {
  return T;
}
}
position findmin(position T)
{
 if(T->left!=NULL)
 {
  findmin(T->left);
 }
 else
{
 return T;
}
}
};
main()
{
 avltree b;
 position root;
 root=NULL;
 root=b.insert(root,50);
 root=b.insert(root,25);
 root=b.insert(root,30);
 root=b.insert(root,75);
 cout<<"\nPreorder Traversal\n";
 b.preorder(root);
cout<<"\nInorder Traversal\n";
 b.inorder(root);
 cout<<"\nPostorder Traversal\n";
 b.postorder(root);
 cout<<"\nFinding...\n";
 position y=b.find(root,30);
 cout<<"\nFound at "<<y;
 cout<<"\nFinding max\n";
 position z=b.findmax(root);
cout<<"\nMax element found at "<<z;
cout<<"\nMax element is "<<z->data;
 cout<<"\nFinding min\n";
 position a=b.findmin(root);
 cout<<"\nMin element found at "<<a;
 cout<<"\nMin element is"<<a->data;
 }


