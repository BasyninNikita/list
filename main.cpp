#include <iostream>
using namespace std;
int ch;
struct node_t {
  int value;
  node_t * next;
};
void vyvod(node_t *&head,int p)
{
	node_t *x=head;
	for(int i=0;i<p;i++) {cout<<"+---+"; cout<<"    ";}cout<<endl;
	for(int i=0;i<p;i++)
	{
	    if(i>0) cout<<"--->";
		cout<<"| "<<x->value<<" |";
		x=x->next;
		}
		cout<<endl;
	for(int i=0;i<p;i++) {cout<<"+---+"; cout<<"    ";}cout<<endl;
}
void revers(node_t * head, int p){
    node_t *pred = head; 
    node_t *next = pred; 
    for (int i = 0; i< p/ 2 ; i++) { 
        int perv = pred->value;
        for (int  j=i; j < p - 1 - i; j++) {
            next = next->next;}
            pred->value = next->value;
            next->value = perv;
            pred = pred->next;
            next = pred;     } 
}
void del(node_t *&head)
{
node_t*x=head;
head=x->next;
x=0;
}
void add(node_t *&head,int value)
{
	node_t * x=new node_t;
	x->value=value;
	x->next=nullptr;
	if(head==nullptr){
		head=x;
	}
	else {
		node_t * last = head;
       while(last->next) {
           last = last->next;
       }
       last->next = x;
   }
   }
int main(int argc, char** argv) {
    int p=0;
	node_t *head=nullptr;
	vyvod(head,p);
	char op;
	while((cin>>op)&&(op!='q')){
	if (op=='+') {cin>>ch; add(head,ch);p++;}
	else if (op=='-'){del(head);p--;}
	else if (op=='/')revers(head,p);
	else if (op=='=')vyvod(head,p);
	vyvod(head,p);}
	return 0;
}
