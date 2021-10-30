#include <iostream>
#include <stack>
#include <queue>

using namespace std;

typedef string DataType;
struct Cell{
    DataType Data;
    Cell *Leftmost_Child;
    Cell *Right_Sibling;
};

typedef Cell* Node;
typedef Node Tree;

Node Create(DataType v, Tree lms, Tree rsl){
    Node n;
    n = new Cell;
    n->Data = v;
    n->Leftmost_Child = lms;
    n->Right_Sibling = rsl;

    return n;
}
/*
Node Create3(DataType v, Tree lms, Tree mid, Tree rsl){
    Node n;
    n = new Cell;
    n->Data = v;
    n->Leftmost_Child = lms;
    // if(lms != NULL)
        n->Right_Sibling = mid;
    if(mid != NULL)
        mid->Right_Sibling = rsl;

    return n;
}
*/


Node leftChild(Node root){
    if(root != NULL){
        return root->Leftmost_Child;
    } else 
        return NULL;
}

Node rightChild(Node root){
    if(root != NULL){
        return root->Right_Sibling;
    } else 
        return NULL;
}

int isLeaf(Node root){
    if(root != NULL){
        return (leftChild(root)==NULL) && (rightChild(root)==NULL);
    }
    return 0;
}

void preOrder(Node rt) {
    cout << rt->Data << " ";
    
    if (!isLeaf(rt)) {
        Node temp = leftChild(rt);
        while (temp != NULL) {
            preOrder(temp);
            temp = rightChild(temp);
        }
    }
}

void preOrderWithoutRecursion(Node root){
    Node p = root;
    stack<Node> ptr_list;
    while(p != NULL || !ptr_list.empty()){
        while(p != NULL){
            cout << p->Data << " ";
            ptr_list.push(p);
            p = p->Leftmost_Child;
        }

        p = ptr_list.top();
        ptr_list.pop();
        p = p->Right_Sibling;
    }
    
}

void InOrder(Node n){
    Node i = leftChild(n);
    if(i != NULL)
        InOrder(i);
    
    cout << n->Data << " ";
    
    i = rightChild(i);
    
    while(i != NULL){
        InOrder(i);
        i = rightChild(i);
    }
}

void PostOrder(Node n){
    Node i = leftChild(n);
    while(i != NULL){
        PostOrder(i);
        i = rightChild(i);
    }

    cout << n->Data << " ";
}

void LevelOrder(Node root){
    if(root == NULL) 
        return;
    
    queue<Node> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        while(n > 0){
            Node p = q.front();
            q.pop();
            cout << p->Data << " ";

            for(Node c = p->Leftmost_Child; c != NULL; c = c->Right_Sibling){
                q.push(c);
            }

            n--;
        }

        cout << endl;
    }
}

int main(){
    Tree t1 = Create("Kaggle pro", NULL, NULL);
    Tree t2 = Create("Mike P", NULL, NULL);
    Tree t3 = Create("Lemon nade", NULL, t2);
    Tree t4 = Create("F u", t1, NULL);
    Tree t5 = Create("Eco", NULL, t4);
    Tree t6 = Create("Jackson", NULL, NULL);
    Tree t7 = Create("Huge", NULL, t6);
    Tree t8 = Create("Goft gold", NULL, t7);
    Tree t9 = Create("ID", t3, NULL);
    Tree t10 = Create("Delity deky", t9, NULL);
    Tree t11 = Create("Charlie karlos", t8, t10);
    Tree t12 = Create("Binary Search", t5, t11);
    Tree T = Create("Aged", t12, NULL);
    
    cout << endl << "===== Duyet tien tu =====" << endl;
    preOrder(T);
    cout << endl;
    preOrderWithoutRecursion(T);
    cout << endl << "===== Duyet trung tu =====" << endl;
    InOrder(T);
    cout << endl << "===== Duyet hau tu =====" << endl;
    PostOrder(T);
    cout << endl << "===== Duyet theo muc =====" << endl;
    LevelOrder(T);
}