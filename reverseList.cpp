#include<iostream>
#include<string>
using namespace std;

class Node{
public:
	string s;
	Node *next;

	Node(string s){
		this->s = s;
		this->next = NULL;
	}
	string getString(){
		return this->s;
	}
	Node * getPointer(){
		return this->next;
	}
	
};

int main(){
	string s;
	Node *head = NULL,*p,*q,*r;
	while(cin>>s){
		if (s == "#")
			break;
		Node *node = new Node(s);
		if(head == NULL)
			head = node;
		else{
			p = head;
			while(p->next){
				p = p->next;
			}
			p->next = node;
		}

	}

	cout << "Origin List:" << endl;
	p = head;
	while(p){
		cout<<p->getString()<<endl;
		//q = p;	//q是p的前一个节点
		p = p->next;
	}

	Node *reverse_head;
	if(head == NULL){
		reverse_head = NULL;
	}
	else if(head->next == NULL){
		reverse_head = head;
	}
	else{
		p = head;
		q = p;	//q是p的前一个节点
		p = p->next;
		r = p->next;	//r是p的后一个节点
		q->next = NULL;
		while(p){

			p->next = q;
			q = p;
			p = r;
			if(p)	//一定要判断p值
				r = p->next;	
		}
		reverse_head = q;
	}
	
	p = reverse_head;
	cout << "Reversed List:" << endl;
	while(p){
		cout<<p->getString()<<endl;
		p = p->next;
	}
}
