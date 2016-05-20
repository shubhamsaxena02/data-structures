#include <bits/stdc++.h>


using namespace std;


struct node{
	int value;
	node * next;
};

void print_list(node *ll){
	cout<<"Current list is:\n";
	node *cur=ll;
	while(cur!=NULL){
		cout<<cur->value<<"->";
		cur=cur->next;
	}
	cout<<"\n";
}


void insert_end(node **ll,int value){
	if((*ll)==NULL){
//		cout<<"here\n";
		(*ll)=(node *)malloc(sizeof(node));
		(*ll)->next=NULL;
		(*ll)->value=value;
		return;	
	}
//	cout<<"out here\n";
	node *cur=(*ll);
	while(cur->next!=NULL){
		cur=cur->next;
	}
	cur->next=(node *)malloc(sizeof(node));
	cur->next->next=NULL;
	cur->next->value=value;
	return;
}

void insert_begin(node **ll,int value){
	if((*ll)==NULL){
//		cout<<"here\n";
		(*ll)=(node *)malloc(sizeof(node));
		(*ll)->next=NULL;
		(*ll)->value=value;
		return;	
	}
//	cout<<"out here\n";
	node *x;
	x=(node *)malloc(sizeof(node));
	x->value=value;
	x->next=(*ll);
	(*ll)=x;
	return;
}


void delete_end(node **ll){
	if((*ll)==NULL)
		return;
	if((*ll)->next==NULL){
		free((*ll));
		(*ll)=NULL;
		return;
	}
	node *cur=(*ll),*prev=NULL;
	while(cur->next!=NULL){
		prev=cur;
		cur=cur->next;
	}
	free(cur);
	cur=NULL;
	prev->next=NULL;
}


void delete_begin(node **ll){
	if((*ll)==NULL)
		return;
	if((*ll)->next==NULL){
		free((*ll));
		(*ll)=NULL;
		return;
	}
	node *cur=(*ll)->next;
	free((*ll));
	(*ll)=cur;
	return;
}


int main(){
	node * ll=NULL;
	insert_end(&ll,10);insert_end(&ll,20);insert_end(&ll,30);print_list(ll);insert_begin(&ll,40);insert_begin(&ll,50);insert_begin(&ll,60);print_list(ll);
	while(1){
		int ch=0;int v;
		cout<<"Main Menu:\n";
		cout<<"1 for insert at end of linked list\n";
		cout<<"2 for inserting at beginning of linked list\n";
		cout<<"3 for deleting at end of linked list\n";
		cout<<"4 for deleting at beginning of linked list\n";
		cout<<"0 for printing linked list\n";
		cout<<"anything else to exit()\n\n";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter integer to insert at end"<<"\n";
				cin>>v;
				insert_end(&ll,v);
				print_list(ll);
			 	break;
			case 2:
				cout<<"Enter integer to insert at beginning"<<"\n";
				cin>>v;
				insert_begin(&ll,v);
				print_list(ll);
				break;
			case 3:
				cout<<"Deleting from end"<<"\n";
				delete_end(&ll);
			 	break;
			case 4:
				cout<<"Deleting from begin"<<"\n";
				delete_begin(&ll);
				break;
			case 0:
				print_list(ll);
				break;
			default:
				exit(0);
				break;
		}
	}
	return 0;
}
