#include <iostream>
#include <stack>
#include <queue>

typedef char DataType;
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

using namespace std;

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
    // Tree t1 = Create('K', NULL, NULL);
    // Tree t2 = Create('M', NULL, NULL);
    // Tree t3 = Create('L', NULL, t2);
    // Tree t4 = Create('F', t1, NULL);
    // Tree t5 = Create('E', NULL, t4);
    // Tree t6 = Create('J', NULL, NULL);
    // Tree t7 = Create('H', NULL, t6);
    // Tree t8 = Create('G', NULL, t7);
    // Tree t9 = Create('I', t3, NULL);
    // Tree t10 = Create('D', t9, NULL);
    // Tree t11 = Create('C', t8, t10);
    // Tree t12 = Create('B', t5, t11);
    // Tree T = Create('A', t12, NULL);

    // Tree t1 = Create('f', NULL, NULL);
    // Tree t2 = Create('h', NULL, NULL);
    // Tree t3 = Create('g', NULL, t2);
    // Tree t4 = Create('+', t3, NULL);
    // Tree t5 = Create('e', NULL, NULL);
    // Tree t6 = Create('d', NULL, t5);
    // Tree t7 = Create('+', t6, NULL);
    // Tree t8 = Create('c', NULL, t7);
    // Tree t9 = Create('*', t8, t1);
    // Tree t10 = Create('b', NULL, NULL);
    // Tree t11 = Create('a', NULL, t10);
    // Tree t12 = Create('+', t11, t9);
    // Tree t13 = Create('+', t12, t4);
    // // Tree t12 = Create('B', t5, t11);

    // Tree T = Create('*', t13, NULL);

    Tree T1 = Create3('E', NULL, NULL, NULL);
    Tree T2 = Create3('D', NULL, T1, NULL);
    Tree T3 = Create3('C', NULL, T2, T1);
    Tree T6 = Create3('H', NULL, NULL, NULL);
    Tree T5 = Create3('G', NULL, T6, NULL);
    Tree T4 = Create3('F', T5, NULL, NULL);
    Tree T7 = Create3('B', T3, T4, NULL);

    Tree T = Create3('A', T7, NULL, NULL);
    

    preOrder(T);
    cout << endl;
    preOrderWithoutRecursion(T);
    cout << endl << "Duyet trung tu" << endl;
    InOrder(T);
    cout << endl << "Duyet hau tu" << endl;
    PostOrder(T);
    cout << endl << "Duyet theo muc" << endl;
    LevelOrder(T);
}