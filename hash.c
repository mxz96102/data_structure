#include <stdio.h>
#include <stdlib.h>
void create_index();
void create_node();
void insert();
struct index*head;
int g_flag=0;

struct index{
	int key;
	struct node*enter;
	struct index*next;
};

struct node{
	int num;
	struct node*next;
};

void create_index(){
	struct index*temp,*p1;
	int n=0;
	while(n<=10){
		temp=(struct index*)malloc(sizeof(struct index));
		if (temp==NULL){
			printf("meerror\n");
			exit(1);}
		if (n==0){
			head=temp;
			p1=head;}
		temp->key=n;
		p1->next=temp;
		p1=temp;
		n++;
		}
	printf("index created completely\n");
}

void create_node(){
	while(g_flag==0)
		insert();
	printf("hash created completely\n");
}

void insert(){
	struct index*p;
	struct node*temp,*p1,*p2;
	int n,m,flag;
	flag=scanf("%d",&n);
	if(!flag){
		printf("input error\n");
		exit(1);}
	if(flag==EOF)
		g_flag=1;
	temp=(struct node*)malloc(sizeof(struct node));
	if (temp==NULL){
		printf("meerror\n");
		exit(1);}
	temp->num=n;
	p=head;
	m=n%10;
	while(m!=(p->key))
		p=p->next;
	if(p->enter==NULL)
		p->enter=temp;
	else {
		p1=p->enter;
		while(p1->next!=NULL)
			p1=p1->next;
		p1->next=temp;
		}
}

struct node*find(int n){
	struct node*p1;
	struct index*p;
	int m;
	
	m=n%10;
	p=head;
	while(m!=(p->key)&&p!=NULL)
		p=p->next;
	p1=p->enter;
	if(p1==NULL||p==NULL){
		printf("oop,we didn't find it in heap\n");
	    return NULL;}

	while(n!=(p1->num)&&p1!=NULL)
		p1=p1->next;
	if(p1==NULL||p==NULL){
        printf("oop,we didn't find it in heap\n");
        return NULL;}

	return p1;
}

void delete(struct node*p1){
	struct node*p2;
	struct index*p;
	int m;
	m=(p1->num)%10;
	p=head;
	while(m!=(p->key))
		p=p->next;
	if((p->enter)==p1&&(p1->next)==NULL)
		p->enter=NULL;
	else if(p->enter==p1)
		p->enter=p1->next;
	else {p2=p->enter;
		while((p2->next)!=p1)
			p2=p2->next;
		p2->next=p1->next;}
	free(p1);
}

void menu(){
	struct node*p;
	int n;
	printf("Hello!Can you hear me?....\n");
	create_index();
	printf("Well,let's input some integers to create your hash now\nwarning:if input is illegal,we have right to shut down the program.\n");
	create_node();
A:	printf("What can I didly do for you?\n\t1.insert data\n\t2.search the heap\n\t3.exit\n");
	scanf("%d",&n);
	switch(n){
		case 1:
			printf("please input a integers now\nwarning:if input is illegal,we have right to shut down the program.\n");
			insert();
			goto A;
			break;
		case 2:
			printf("what num is you looking for?");
			if(!scanf("%d",&n)){
				printf("input error\n");
			    exit(1);}
			p=find(n);
			if(p==NULL)
				goto A;				
			printf("we find:%d,what you want to do\n\t1.delete it\n\t2.exit\n",p->num);
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
