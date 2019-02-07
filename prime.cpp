//Michael Davis
//200040001

#include "iostream"
#include "stdio.h"
#include "stdlib.h"

using namespace std;

class node
{
	public:
		int v;
		node *next;
		node(int x){v = x;next = 0; }
};

class list
{
	public:
		node *head;
		node *tail;
		bool empty (){ return !head;   }
		
      void add (int x);
		int get(){  return head->v;   }
      
		list(){ head = tail = 0;  }
		~list();
};

void list::add(int x)                     //Implement the member function add (int x) and the destructor ~list()here
{
    if(empty()){
        head=tail=new node(x);
    }
    else{
        tail->next = new node(x);
        tail = tail->next;
    }

}

list::~list()
{
    node *temp;
	while(head){
	    temp = head->next;
		delete head;
		head = temp;                  //delete h;
	}
	tail = 0;
}

class primelist : public list{            //Implement the member function add(intx) and the destructor ~list() here
	public:
		int length();
		int largest(){return tail->v;}
		void expand();
		void display();
		primelist():list(){add(2);}
};

void primelist::expand()             //Implement the member function length(), expand(), and display() here
{
	int next = largest() + 1;
	while (true){
	    bool prime = true;
	    for(int i =2 ; i<next; i++){
	        if(next % i == 0){
	            prime = false;
	            break;
	        }
	    }
	    if(prime){
	        add(next);
	        break;
	    }
	    next++;
	}
}
int primelist::length(){
    
    node* curr = head;
    int count =0;
    while(curr){
        count++;
        curr = curr->next;
    }
    
    return count;
    
}
void primelist::display(){
    
    node* curr = head;
    
    while(curr){
        printf("%d ", curr->v);
        curr= curr->next;
    }
    printf("\n");
}
int main(int argc, char*argv[]){
	int n = atoi(argv[1]);
	primelist p1;
	while(p1.largest()<n)
	{
	    p1.expand();
	}
	
	printf("This list contains %d prime numbers:\n" , p1.length());
	
	p1.display();

	return 0;
}
