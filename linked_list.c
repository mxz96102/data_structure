#include <stdio.h>
#include <stdlib.h>
#define LENTH sizeof(struct mylist)
struct mylist*head;
struct mylist*create();
struct mylist*find_previous(struct mylist*p);
struct mylist*find(int n,struct mylist*start);
void delete(struct mylist*to_del);
void printl();
void menu_0();
void insert(struct mylist*pre);
void menu_1();

int main(){
	printf("please create list first\n");
	create();
	menu_0();
	return 0;
}

struct mylist{
	int num;
	struct mylist*next;
	};

struct mylist*create(){				//to create a list with element num (use 0 to stop creat
	struct mylist*p1,*p2;
	int safe;
	p1=(struct mylist*)malloc(LENTH);
	if(!scanf("%d",&safe)){
		printf("illegal input!\n");
		return;}
	p1->num=safe;
	p1->next=NULL;
	while(p1->num!=0){
		if(head==NULL)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		p1=(struct mylist*)malloc(LENTH);
		if(!scanf("%d",&safe)){
			printf("illegal input!\n");
			return;
		}
		p1->num=safe;
	}
}

struct mylist*find_previous(struct mylist*p){		//to find the element position before input p from list 
	struct mylist*temp;

	temp=p;

	p=head;
	while(p->next!=temp&&p->next!=NULL)
		p=p->next;
	
	return p;
}

struct mylist*find(int n,struct mylist*start){ //to find the positon which the input num is first appear after start position
	struct mylist*p;

	p=start->next;
	while(p!=NULL&&p->num!=n)
		p=p->next;

	return p;
}

void delete(struct mylist*to_del){		//to delete the node of input position
	struct mylist*pre;
	
	pre=find_previous(to_del);
	if(to_del->next!=NULL)
		pre->next=to_del->next;
	else pre->next=NULL;
	free(to_del);
}

void insert(struct mylist*pre){		//to insert after pre positon
	struct mylist*temp;
	
	temp=malloc(LENTH);
	if(temp==NULL){
		printf("insert error, out of space\n");
		return;
	}
	printf("input the number");
	if(!scanf("%d",&temp->num)){
		printf("illeagal input\n");
		return;}
 	temp->next=pre->next;
	pre->next=temp;
}

void printl(){
	struct mylist*p;
	p=head;

	if(head->next==NULL)
		printf("list is null\n");
	while(p->next!=NULL){
		printf("%d\t",p->num);
		p=p->next;
	}
	printf("%d\n",p->num);
}

void menu_0(){
	int n;

	printf("\n\tdude, what's up?\n\t\t1.find num in list to do insert or delete\n\t\t2.show me out!\n\t\tinput the num to tell me\n");
	scanf("%d",&n);
	switch(n){
	case 1:
		menu_1();
		break;
	case 2:
		return;
		break;
	default:
		printf("I don't what you say.\n");
		return;
		break;
	}
}

void menu_1(){
	struct mylist*p;
	int n,j;
	printf("the list is :\n");
	printl();
	printf("input the num you looking for");
	if(!scanf("%d",&n)){
		printf("illigal input\n");
		return;}
	p=find(n,head);
A:	if (p==NULL){
		printf("404 not found\n");
		menu_1();}
	printf("\twhat you gonna do?\n\t\t1.delete it\n\t\t2.insert one behind it\n\t\t3.find next one.\n\t\t4.exit\n");
	if(!scanf("%d",&j)){
		printf("illeagal input\n");
		return;}	
	switch(j){
		case 1:
			delete(p);
			menu_1();
			break;
		case 2:
			insert(p);
			menu_1();
			break;
		case 3:
			p=find(n,p);
			goto A;
		case 4:
			break;
		default:
			printf("i dont know what you say");
			goto A;
	}
}
