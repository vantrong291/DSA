#include<iostream>
#include<fstream>
using namespace std;

struct Node {
    int value;
    Node * next;
    };
struct Stack {
    Node * top = NULL;
    };

Stack newStack(char* filename) {
	ifstream in;
	in.open(filename);
	int number;
	Stack list;
	//if(in >> number) {list.top = new Node(); list.top->value = number;}
	list.top = new Node();
	Node *q = list.top;

	if(in >> number) {
	    in.close();
        in.open(filename);
        while(in >> number) {
            q->next = new Node();
            q->value = number;
            q = q->next;
        }
        q=list.top;
        while(q->next->next!=NULL) {
            q=q->next;}
        q->next = NULL;
    }
	else list.top = NULL;
	return list;
    }

void printStack(Stack s) {
    if(s.top == NULL) cout << "Null";
	else {
	for(Node* q = s.top; q != NULL; q=q->next)
		cout << q->value << " ";
	cout << endl;
	}
}
bool isEmpty(Stack s) {
    return s.top == NULL;
    }

void push(Stack &s, int v) {
    if(s.top==NULL) {
        s.top = new Node();
        s.top->value = v;
        s.top->next = NULL;
    }
    else {
        Node * newN = new Node();
        newN->value = v;
        newN->next = s.top;
        s.top = newN;
    }
}

void pop(Stack &s) {
    if(s.top!=NULL) {
        s.top = s.top->next;
    }
    else cout << "Khong hop le!";
}

int top(Stack s) {
    if(s.top!=NULL) {
        return s.top->value;
    }
    else cout << "Khong hop le";
    return 0;
}


int main() {
    Stack nst = newStack("stack.txt");
    printStack(nst);
    cout << endl;
    push(nst, 477);
    printStack(nst);
    pop(nst);
    printStack(nst);
    //int v = top(nst);
    //cout << v;
}

//Stack
