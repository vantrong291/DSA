#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) {
    this->data = v; this->left=NULL; this->right = NULL;
    }
};
struct BST {
    Node * root = NULL;
    BST(){
        root = NULL;
    }
    ~BST(){
        root = NULL;
    }
};

Node* Insert(Node *q, int data) {
    if(q==NULL){
        q = new Node(data);
        return q;
    }
    else {
        if(data < q->data) {q->left=Insert(q->left, data);}
        else q->right = Insert(q->right, data);
    }
}

BST create(char *filename) {
    ifstream in; in.open(filename);
    int n = 0, a[30]; BST tr;
    while(in >> a[n]) {n++;}
    //BST tr;
    tr.root = new Node(a[0]);
    if(n==0) {tr.root = NULL;}
    else { for(int i = 1; i < n; i++) {
                Insert(tr.root, a[i]);

        }
    }
    in.close();
    return tr;
}
int height(Node* q) {
    int h;
    if(q==NULL) {return 0;}
    else {
        h = height(q->left)>height(q->right) ? height(q->left) + 1 : height(q->right) + 1; return h;
    }
}
void Travesal(Node * q, int a);
void levelTravel(Node* q) {
    if(q!=NULL) {
        int h = height(q);
        for(int i = 1 ; i <= h; i++) {
            Travesal(q, i);
        }
    }
    else cout << "NULL";
}
void Travesal(Node * q, int a) {
    if(q==NULL) {return;}
    if(a==1) {
        cout << q->data << " ";
    }
    else {
        Travesal(q->left, a-1);
        Travesal(q->right, a-1);
    }
}
Node* searchNode(Node*q,int v);
Node* minNode(Node* q) {
    Node *q1 = q;
    while(q1->left != NULL) { q1 = q1->left; }
    return q1;
}

Node* deleteNode(Node* q, int v){
    if(q==NULL) { return q;}
    if(v < q->data) { q->left = deleteNode(q->left, v);}
    else if(v > q->data) {q->right = deleteNode(q->right, v);}
    else {
        if(q->left == NULL && q->right!=NULL) {
            Node * a = q;
            q = q->right;
            free(a);
            return q;
        }
        if(q->right == NULL && q->left != NULL) {
            Node* a = q; q = q->left;
            free(a);
            return q;
        }
        if(q->left == NULL && q->right == NULL) {
            q = NULL;
            return q;
        }
        if(q->left != NULL && q->right != NULL) {
            Node* a = minNode(q->right);
            q->data = a->data;
            q->right = deleteNode(q->right, a->data);
        }
        //return q;
    }
    return q;
}
void deleteNodeTree(BST &tr, int v) {
    tr.root = deleteNode(tr.root, v);
}

Node* searchNode(Node* q, int v){
    if(q == NULL || q->data == v) {
        return q;
    }
    else {
        if(v < q->data) searchNode(q->left, v);
        else searchNode(q->right, v);

    }
}


void preOrder(Node* q) {
    if(q != NULL) {
        cout << q->data << " ";
        if(q->left!=NULL) preOrder(q->left);
        if(q->right!=NULL) preOrder(q->right);
    }
    else {cout << "NULL";}
}

int main() {
    BST tr = create("Tree.txt");
    //tr.~BST();
    Node* q = searchNode(tr.root, 8);
    if(q != NULL) {
        cout<<q->data;}
    preOrder(tr.root); cout << endl;
    levelTravel(tr.root); cout << endl;
    deleteNodeTree(tr, 4);
    preOrder(tr.root);
}
