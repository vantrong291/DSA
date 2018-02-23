#include<iostream>
#include<fstream>
using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;
    Node(int v) {
        this->data= v;
        this->left = NULL; this->right = NULL;}
};
struct binaryTree {
    Node* root = NULL;
};

void travesalLevel(Node *q, int level);

Node* create(int a[], int start, int end) { if(start > end ) return NULL;
    Node * node; int i = (start + end)/2;// cout << "i " << i;
    node = new Node(a[i]);
    if(start == end) { return node;}
    node->left = create(a, start, i - 1);

    node->right = create(a, i + 1, end);

    //cout<< node->right->data;
    //tr.root->left = new Node;tr.root->left = tr1.root;
    //tr.root->right = new Node;tr.root->right = tr2.root;
}

void preOrder(Node * q) {
    if(q!=NULL) {
        cout << q->data << " ";
        if(q->left!=NULL) { preOrder(q->left);}
        if(q->right!=NULL) { preOrder(q->right);}
    }
}
binaryTree createTree(char* filename){
    int a[30], n = 0;
    ifstream in; in.open(filename);
    while(in >> a[n]) {
            n++;
    }
    binaryTree tr;
    if(n!=0) {
        tr.root = create(a, 0, n-1);
    }
    else tr.root = NULL;
    //for(int j = 0; j < n; j++) {
    //    cout << a[j] << " ";
    //}
    return tr;
}
int height(Node *q) { int h;
    if(q==NULL) { return 0;}
    else {
        int lefth=height(q->left);
        int rghth=height(q->right);

        if(lefth > rghth) h = lefth;
        else h = rghth;
    }
    return h + 1;
}

void levelTravel(Node* q) {
    if(q!=NULL) {
        int h = height(q);
        for(int i = 1; i <= h; i++) {
            travesalLevel(q,i);
        }
    }
    else cout << "NULL";
}
void travesalLevel(Node* q, int level) {
    if(q == NULL) { return;}
    if(level == 1) {
        cout << q->data << " ";
    }
    else {
        travesalLevel(q->left, level - 1);
        travesalLevel(q->right, level -1);
    }
}
bool hasLeft(binaryTree tr) {
    return (height(tr.root->left) > 0);
}
bool hasRight(binaryTree tr) { return height(tr.root->right) > 0;}

binaryTree left(binaryTree tr) {
    binaryTree tr1;
    if(hasLeft(tr)) {
        tr1.root = tr.root->left;
    }
    else tr1.root = NULL;
    return tr1;
}
binaryTree right(binaryTree tr) {
    binaryTree tr1;
    if(hasRight(tr)) {tr1.root = tr.root->right;}
    else tr1.root = NULL;
    return tr1;
    }


int main() {
    binaryTree tr = createTree("Tree.txt");

    levelTravel(tr.root); cout << endl;
    //binaryTree tr2 = left(tr);
    //levelTravel(tr2.root);
}
