#include<iostream>
#include<fstream>
using namespace std;

struct Node {
    int value;
    Node * next;
    };
struct Queue {
    Node * first = NULL;
    Node * last = NULL;
    };

Queue newQueue(char* filename) {
	ifstream in;
	in.open(filename);
	int number;
	Queue list;
	list.first = new Node();
	Node *q = list.first;

	if(in >> number) {
	    in.close();
        in.open(filename);
        while(in >> number) {
            q->next = new Node();
            q->value = number;
            q = q->next;
        }
        q=list.first;
        while(q->next->next!=NULL) {
            q=q->next;}
        list.last = q;
        q->next = NULL;
    }
	else {
        list.first = NULL;
        list.last = NULL;
    }
	return list;
    }

void printQueue(Queue s) {
    if(s.first == NULL) cout << "Null";
	else {
	for(Node* q = s.first; q != NULL; q=q->next)
		cout << q->value << " ";
	cout << endl;
	}

}
bool isEmpty(Queue s) {
    return s.first == NULL;
    }

void enQueue(Queue &s, int v) {
    if(s.first==NULL) {
        s.first = new Node();
        s.first->value = v;
        s.first->next = NULL;
    }
    else {
        Node * newN = new Node();
        newN->value = v;
        newN->next = s.first;
        s.first = newN;
    }
}

void deQueue(Queue &s) {
    /*if(s.top!=NULL) {
        s.top = s.top->next;
    }
    else cout << "Khong hop le!";*/
    if(s.first == NULL) cout << "Error! Queue is empty!" << endl;
    else {
        if(s.first->next!=NULL) {
            Node * q = s.first;
            while(q->next!=s.last) {
                q = q->next;
            }
            s.last = q;
            s.last->next = NULL;
        }
        else s.first = NULL;
    }
}


int head(Queue s) {
    if(s.first!=NULL) {
        return s.first->value;
    }
    else cout << "Khong hop le";
    return 0;
}


int main() {
    Queue nst = newQueue("queue.txt");
    printQueue(nst);
    cout << endl;
    enQueue(nst, 477);
    printQueue(nst);
    deQueue(nst); deQueue(nst);
    deQueue(nst); deQueue(nst);
    printQueue(nst);
    cout << endl;
    int v = head(nst);
    cout << v;
}

//Queue
