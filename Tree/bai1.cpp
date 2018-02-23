#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

struct Node {
    int value;
    Node * firstChild = NULL;
    Node * nextSibling = NULL;
    };
struct Tree {
    Node * root = NULL;
    };
Tree createTree(char* filename) {
    ifstream in, in2; in.open(filename);
    string tempString;
    int n = 0, j = 0, i = 0, num;
    char a; int int1[40][40];
    while(getline(in, tempString)){
        //s[n] = tempString;
        n++;
        istringstream buffer(tempString);
        int number;
        while(buffer >> number) {
            int1[i][j] = number;
            j++;
        }
        i++; j = 0;
    }
    in.close();
    Tree tree[n];
    if(int1[0][0] == NULL) {tree[0].root = NULL;}
    for(int k = n-1; k >= 0; k--) {
        tree[k].root = new Node();
        tree[k].root->value =int1[k][0];
        tree[k].root->firstChild = new Node();
        tree[k].root->firstChild->value = int1[k][1];
        Node* q = tree[k].root->firstChild;
        int k1 = 2;
        while(int1[k][k1]!=NULL) {
            q->nextSibling = new Node();
            q->nextSibling->value=int1[k][k1];
            q->nextSibling->nextSibling = new Node;

            q = q->nextSibling;
            k1++;
        }
    }

    for(int k = 0; k < n; k ++) { if(int1[k][1] == NULL) { tree[k].root->firstChild =NULL;}
        else if(int1[k][2] == NULL) {
            tree[k].root->firstChild->nextSibling = NULL;
        }
        else if(int1[k][3] == NULL) {
            tree[k].root->firstChild->nextSibling->nextSibling =NULL;}
        else {
            Node *q = tree[k].root->firstChild;
            while(q->nextSibling->nextSibling != NULL ) { q = q->nextSibling;}
            q->nextSibling = NULL;}
    }
    //cout << tree[1].root->firstChild->nextSibling->nextSibling->nextSibling->value;
    int k2 = 0;
    for(int k = 0;k < n - 1; k++) {
        Node *q = tree[k].root->firstChild;
        k2 = k+1;
        while(q != NULL) {
            while(k2 < n) {
                if(q->value == int1[k2][0]) { q->firstChild = tree[k2].root->firstChild;
                }
                k2++;
            }
            q = q->nextSibling;
            k2 = k+1;
        }
    }
    return tree[0];
}
void print(Node * q) {
    if(q!=NULL) {
        cout << q->value<< " ";
    }
    //else cout << "NULL";
}
void printPre(Node*q) {
    if(q!=NULL) {

        print(q);
        if(q->firstChild!=NULL) { printPre(q->firstChild); }
        if(q->nextSibling!=NULL) { printPre(q->nextSibling); }
    }
    else cout << "NULL";
}

void pPost(Node * q) {
    if(q!=NULL){
        if(q->firstChild!=NULL) { pPost(q->firstChild);}
        if(q->nextSibling!=NULL) { pPost(q->nextSibling);}
        print(q);
    }
    else cout << "NULL";
}
void preOrder(Tree t) {
    printPre(t.root);
}
void postOrder(Tree t) {
    pPost(t.root);
}

int main() {
    Tree t = createTree("Tree.txt");
    preOrder(t);
    postOrder(t);
}
