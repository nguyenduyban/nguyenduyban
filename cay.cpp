#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
typedef Node* B4N;
void init_Tree(B4N& root);
Node* tao_Node(int x);
int insertTree(B4N& root, Node* p);
void Nhap(B4N& root);
void LRN(B4N root);
void LNR(B4N root);
void NLR(B4N root);

//WRITEN CODE BY : NGUYEN DUY BAN , MSSV : DH52101856

#include "Header.h"
void init_Tree(B4N& root) {
    //gan node goc ve NULL
    root = NULL;
}
Node* tao_Node(int x) {
    //tao node moi
    Node* p = new Node;
    //neu cay nhi phan khong rong
    if (p != NULL) {
        //gan cay con trai va cay con phai mac dinh bang NULL
        p->left = NULL;
        p->right = NULL;
        //gan data bang x
        p->data = x;
    }
    //tra ve node p
    return p;
}
int insertTree(B4N& root, Node* p) {
    if (root != NULL) {
        if (root->data == p->data) {
            return 0;
        }
        if (root->data > p->data) {
            return insertTree(root->left, p);
        }
        else {
            return insertTree(root->right, p);
        }
    }
    else {
        root = p;
    }
}
void Nhap(B4N& root) {
    int n;
    cout << "Nhap so luong can cho cay :";
        cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cout << "\nNhap du lieu cho cay :";
        cin >> x;
        Node* p = tao_Node(x);
        insertTree(root, p);
    }
}
void LNR(B4N root) {
    if (root != NULL) {
        LNR(root->left);
        cout << "\t" << root->data;
        LNR(root->right);
    }
}
void LRN(B4N root) {
    if (root != NULL) {
        LRN(root->left);
        LRN(root->right);
        cout << "\t"<< root->data;
    }
}
void NLR(B4N root) {
    if (root != NULL) {
        cout << "\t" << root->data;
        NLR(root->left);
        NLR(root->right);
    }
}

#include"Header.h"
void main() {
	B4N root;
	init_Tree(root);
	Nhap(root);
    cout << "\n =================== WRITEN CODE BY : DUY BAN ( B4N ) ===================";
    //liet ke cay theo LNR
    cout << "\nLiet ke theo LNR :";
    LNR(root);
    //liet ke cay theo LRN
    cout << "\nLiet ke theo LRN : ";
    LRN(root);
    //liet ke cay theo NLR
    cout << "\nLiet ke theo NLR:";
    NLR(root);
}
