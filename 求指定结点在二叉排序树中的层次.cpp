#include<stdio.h>
#include<iostream>
using namespace std;
typedef struct TiNode

{
	int data;
	TiNode *rd,*ld;
}*BiTree;

void Insert(BiTree &T, int c)  //插入函数，采用递归，从根节点开始寻找合适的插入点
{
	if(c < T->data)
	{
		if( T->ld == NULL )    //如果没有左孩子，直接将值赋给左孩子
		{
			T->ld=new TiNode;
			T->ld->data = c;
			(T->ld)->ld = NULL;
			(T->ld)->rd = NULL;
		}
		else
		{
			Insert(T->ld,c);
		}
	}
	else
	{
		if( T->rd == NULL )     //如果没有右孩子，直接将值赋给右孩子
		{
			T->rd=new TiNode;
			T->rd->data = c;
			(T->rd)->ld = NULL;
			(T->rd)->rd = NULL;
		}
		else
		{
			Insert(T->rd,c);
		}
	}
}

void Creat(BiTree &T)         //创建函数（利用插入函数）
{
	T=new TiNode;
	T->ld = NULL;
	T->rd = NULL;

	int c ;
	scanf("%d",&c);
		T->data = c;            //创建根节点
	while(1){
            if(getchar()=='\n') break;
            cin>>c;
            Insert(T,c);
        }
}

int   Cc(  BiTree &T,int k,int &y)      //判断函数
{
	if(T!=NULL)
	{
	    if(T->data==k) y++;
		Cc(T->ld,k,y);
		Cc(T->rd,k,y);
	}
	return y;
}

int  Level(BiTree &T,int k){          //主要功能函数，获得结点层次
	int h=0;
	if(!T)
		return 0;
	while (T){

		if(T->data==k){
			h++;
			break;
		}
		else if(T->data>k){
			h++;
			T=T->ld;
		}
		else{
			h++;
			T=T->rd;
		}
	}
	return h;
}

int main()
{
    BiTree T;
	int k,y=0;
	Creat(T);
	scanf("%d",&k);
	if(Cc(T,k,y)==0)
        printf("非此树结点");
    else
        printf("%d",Level(T,k));
	return 0;
}
