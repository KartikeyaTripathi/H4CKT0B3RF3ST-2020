#include<stdio.h>
#include<stdlib.h>
struct bstree{
  int data;
  struct bstree *left,*right;
};
struct bstree *getnode();
struct bstree *insert(struct bstree *,struct bstree *);
struct bstree *delete(struct bstree *,int);
void inorder(struct bstree *);
void preorder(struct bstree *);
void postorder(struct bstree *);
struct bstree *minvalue(struct bstree *); //for inorder successor to use in delete
int main()
{
  struct  bstree *root=NULL,*newnode;
  int ch,num,key;
  while(1)
  {
    printf("\nENTER CHOICE\n");
    printf(" 1:INSERT\n 2:DELETE\n 3:INORDER\n   PREORDER\n   POSTORDER\n 4:EXIT\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: newnode=getnode();
              printf("ENTER THE NUMBER TO INSERT\n");
              scanf("%d",&num);
              newnode->data=num;
              root=insert(root,newnode);
              break;
      case 2:printf("ENTER THE NUMBER TO DELETE\n");
             scanf("%d",&key);
             root=delete(root,key);
             break;
      case 3:printf("INORDER TRAVERSAL IS\n");
             inorder(root);
             printf("\nPREORDER TRAVERSAL IS\n");
             preorder(root);
             printf("\nPOSTORDER TRAVERSAL IS\n");
             postorder(root);
             break;
      case 5:exit(0);
    }
  }
  return 0;
}

struct bstree *getnode()
{
  struct bstree *newnode;
  newnode=(struct bstree *)malloc(sizeof(struct bstree));
  newnode->left=NULL;
  newnode->right=NULL;
  return newnode;
}

struct bstree *insert(struct bstree *root,struct bstree *newnode)
{
  if(root==NULL)
  {return newnode;}
  if(newnode->data < root->data)
  root->left=insert(root->left,newnode);
  else //  if (newnode->data>root->data) we can use this also
  root->right=insert(root->right,newnode);

}
void inorder(struct bstree *root)
{
  if(root!=NULL)
  {
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
  }
}
void preorder(struct bstree *root)
{
  if(root!=NULL)
  {
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
  }
}
void postorder(struct bstree *root)
{
  if(root!=NULL)
  {
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
  }
}
struct bstree *delete(struct bstree *root,int key)
{
  if (root ==NULL)
  return root;
  if (key<root->data)
  {root->left=delete(root->left,key);}
  else if(key>root->data)
  {root->right=delete(root->right,key);}
  else
  {
    if(root->left==NULL)//if left child doesn't exist
    {struct bstree *temp=root->right;//copy right child
    free(root);//delete that root
    return temp;
    }
    else if(root->right==NULL)//if right child doesn't exist
    {
      struct bstree *temp=root->left;//copy left child
      free(root);//delete that root
      return temp;
    }
    struct bstree *temp=minvalue(root->right);
    root->data=temp->data;
    root->right=delete(root->right,temp->data);
  }
  return root;
}
struct bstree *minvalue(struct bstree *root)
{
  struct bstree *cur=root;
  while(cur->left!=NULL)
  {cur=cur->left;}
  return cur;
}
