#include <stdio.h>
#include <stdlib.h>
struct node*head,*last;
void create();
void insert();
void menu();


struct node{
	int num;
	struct node*left;
	struct node*right;
	struct node*pre;
};


void create(){
	struct node*temp,*p1,*p2;
	int n;
	if(!scanf("%d",&n)){
		printf("input error\n");
		exit(1);}
	temp=(struct node*)malloc(sizeof(struct node));
	if (temp==NULL){
		printf("meerror\n");
		exit(1);}
	temp->num=n;
	head=temp;
	p1=temp;
	while(getchar()!=EOF)
		insert();
	p2=head;
	while(p2->left!=NULL)
		p2=p2->left;
	last=p2;
	printf("create complete\n");
}

void insert(){
	struct node*temp,*p1,*p2;
	int n,flag=0;
	p1=head;
	if(!scanf("%d",&n)){
		printf("input error\n");
		exit(1);}
	temp=(struct node*)malloc(sizeof(struct node));
	 if (temp==NULL){
		printf("meerror\n");
		return;}
	temp->num=n;

	while(flag==0){
	if((temp->num)<(p1->num)){
		temp->pre=p1;
		if(p1->left==NULL){
			p1->left=temp;
			flag=1;}
		else if((temp->num)==(p1->num)){
				temp->left=p1->left;
				p1->left=temp;}
		else p1=p1->left;
		}
	else {
		if(p1->right==NULL){
			p1->right=temp;
			flag=1;}
		else p1=p1->right;
		}
	}
}

struct node*find_min(){
	struct node*p1;
	p1=head;
	while(p1->left!=NULL)
		p1=p1->left;
	return p1;
}


void delete(struct node*p1){
	struct node*p2;
	
	if(p1==head){
		last=head;
		if((p1->right)==NULL){
			printf("deleting head isnt allowed!\n");
			exit(1);}
		else{
			p2=head;
			head=head->right;
			last=head;
			free(p2);
			}
	}else {
		p2=p1->pre;
		p2->left=p1->right;
		last=p2;
		free(p1);
		}
	
}

void menu(){
	struct node*p;
	int n;
	printf("to create the heap first, please input some integers now\nwarning:if input is illegal,we have right to shut down the program.\n");
	create();
A:	printf("please input the number to choose what you gonna do\n\t1.insert data;\n\t2.find min\n\t3.delete min\n\t4.exit\n");
	scanf("%d",&n);
	switch(n){
		case 1:
			printf("please input a integers now\nwarning:if input is illegal,we have right to shut down the program.\n");
			insert();
			goto A;
			break;
		case 2:
			p=find_min();
			printf("we find the min :%d,what you want to do\n\t1.delete it\n\t2.exit\n",p->num);
			scanf("%d",&n);
			switch(n){
				case 1:
					printf("....ok\n");
					delete(p);
					goto A;
					break;
				case 2:
					exit(1);
					break;
				default:
					printf("i dont understand.\n");
					exit(1);
					break;
				}
			break;
		case 3:
			p=find_min();
			printf("we find the min :%d,and delete it\n",p->num);
			delete(p);
			goto A;
			break;
		case 4:
			exit(1);
			break;
		default:
			printf("i dont understand.\n");
			exit(1);
			break;
	}	
}


int main(){
	menu();
	return 0;
}

