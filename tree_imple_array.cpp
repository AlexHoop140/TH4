#include <iostream>
#define max 1000

using namespace std;

typedef char dataType;
typedef int Node;

struct Tree{
    dataType data[max];
    Node parent[max];
    int maxNode;
};

typedef Tree TREE;
TREE T;

void init_tree(TREE &T){
    T.maxNode = 0;
}

bool empty_tree(TREE T){
    return T.maxNode == 0;
}

Node Parent(Node n, TREE T){
    if((empty_tree(T)) || (n>T.maxNode-1) || (n<0)){
        return -1;
    } else{
        return T.parent[n];
    }
}

dataType nodeLabel(Node n, TREE T){
    if(!empty_tree(T) && (n >= 0) && (n <= T.maxNode-1)){
        return T.data[n];
    } else{
        return -1;
    }
}

Node Root(TREE T){
    if(!empty_tree(T))
        return 0;
    else
        return -1;
}

Node LeftMostChild(Node n, TREE T){
    Node i;
    if(n < 0) return -1;
    i = n + 1;
    while (i <= T.maxNode-1){
        if(T.parent[i] == n)
            return i;
        else i = i + 1;
    }

    return -1;
}

Node RightSibling(Node n, TREE T){
    Node i, parent;
    if(n < 0) return -1;
    parent = T.parent[n];
    i = n + 1;
    while((i <= T.maxNode-1)){
        if(T.parent[i] == parent) 
            return i;
        else i = i + 1;
    }
    return -1;
}

void ReadTree(TREE &T){
    int i;
    init_tree(T);

    cout << "Cay co bao nhieu nut? " << endl;
    cin >> T.maxNode;
    cout << "Nhap nhan cua nut goc kieu char " << endl;
    cin >> T.data[0];

    T.parent[0] = -1;
    for(int i = 1; i < T.maxNode; i++){
        cout << "Nhap cha cua nut so nguyen " << i << endl;
        cin >> T.parent[i];
        cout << "Nhap nhan cua nut kieu char " << i << endl;
        cin >> T.data[i]; 
    }

}

void PreOrder(Node n, TREE T){
    
    cout << nodeLabel(n, T) << " ";
    Node i = LeftMostChild(n, T);
    while(i != -1){
        PreOrder(i, T);
        i = RightSibling(i, T);
    }
    
}

void InOrder(Node n, TREE T){
    Node i = LeftMostChild(n, T);
    if(i != -1)
        InOrder(i, T);
    
    cout << nodeLabel(n, T) << " ";
    
    i = RightSibling(i, T);
    
    while(i != -1){
        InOrder(i, T);
        i = RightSibling(i, T);
    }
}

void PostOrder(Node n, TREE T){
    Node i = LeftMostChild(n, T);
    while(i != -1){
        PostOrder(i, T);
        i = RightSibling(i, T);
    }

    cout << nodeLabel(n, T) << " ";
}

int main(){
    cout << " ==== Nhap du lieu tong quat ====" << endl;
    ReadTree(T);
    cout << " **** Duyet tien tu **** " << endl;
    PreOrder(Root(T), T);
    cout << endl << " **** Duyet trung tu **** " << endl;
    InOrder(Root(T), T);
    cout << endl << " **** Duyet hau tu **** " << endl;
    PostOrder(Root(T), T);

    return 0;
}