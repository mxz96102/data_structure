#include <stdio.h>
#include <stdlib.h>
struct index*in_head;

struct index{
	int key;
	void *enter;
	struct index*next;
};

struct hash_list{
	int num;
	int content;
	struct hash_list*next;
};

void mk_index(){
	int n=0;
	struct index*p1,*p2;
	in_head=p1;
	while (n>10){
		p1->key=n;
		p2=p1;
		p1=(struct index*)malloc(sizeof(struct index));
		if(p1==NULL)
			printf("error");
		p2->next=p1;
		n++；
	}
}	

void hash_input(){
	struct index*i_p;
	struct hash_list*h_p;
	struct hash_list*temp;
	int n=1;
	while(n==1){
		temp=(struct hash_list*)malloc(sizeof(struct hash_list));
		scanf("%d %d",&temp->num,&temp->content);
		if(temp==NULL){	
			printf("error");
			break;}
		if((temp->num)==0)
			break;
		i_p=in_head;
		while(i_p->next!=NULL){
			if ((temp->num)%10==(i_p->key)){
				if (i_p->enter==NULL)
					(i_p->enter)=temp;
				else {
					h_p=(i_p->enter);
					while(h_p->next!=NULL)
						h_p=h_p->next;
					h_p->next=temp;}
				i_p=(i_p->next);
			}
		}
	}
}
				
struct hash_list*find(int n){
	int m;
	struct index*i_p;
	struct hash_list*h_p;
	m=n%10;
	i_p=in_head;
	while(i_p->key!=m&&i_p->next!=NULL)
		i_p=i_p->next;
	h_p=(i_p->enter);
	while(h_p->num!=n&&h_p->next!=NULL)
		h_p=h_p->next;
	return h_p;
}


int main(){
	struct hash_list*find(int n);
	struct hash_list*p;
	int n;
	mk_index();
	hash_input();
	printf("ss\n");
	scanf("%d",&n);
	p=find(n);
	printf("%d",p->content);
	return 0;
}

