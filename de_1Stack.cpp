// ĐỀ CÓ TÍNH TỔNG STACK
#include "Header.h"
void init_Stack(Stack& s) {
	s.top = NULL;
}
Nodeptr taoNode(int x) {
	Nodeptr p = new node;
	p->data = x;
	p->link = NULL;
	return p;
}
//câu b :hàm push
void push(Stack& s, int x) {
	Nodeptr p = taoNode(x);
	if (s.top == NULL)
		s.top = p;
	else {
		p->link = s.top;
		s.top = p;
	}
}
void output_Stack(Stack s) {
	for (Nodeptr p = s.top; p != NULL; p = p->link) {
		cout << p->data << "\t";
	}
}
//câu a hàm tính tổng
int tongChan(Stack s) {
	int tong = 0;
	for (Nodeptr p = s.top; p != NULL; p = p->link) {
		if (p->data % 2 == 0)
			tong = tong + p->data;
	}
	return tong;
}
//câu b : hàm thêm một phần tử
void themPhanTu(Stack& s) {
	int x;
	cout << "\nNhap phan tu can them: ";
	cin >> x;
	push(s, x);
	cout << "\nStack sau khi them phan tu : \t";
}

//câu 2
#include <iostream>
using namespace std;
typedef int TYPEINFO;
struct NODE {
	TYPEINFO data;
	NODE* link;
};
typedef NODE* NODEPTR;
void khoitao(NODEPTR& list);
int isEmpty(NODEPTR list);
NODEPTR tao_Node(TYPEINFO x);
NODEPTR themDau(NODEPTR& list, TYPEINFO x);
void xuat_DSLK(NODEPTR list);
int demLe(NODEPTR ds);
void chen(NODEPTR& list);
#include "Header.h"
void khoitao(NODEPTR& list) {
	list = NULL;
}
int isEmpty(NODEPTR list) {
	return (list == NULL ? 1 : 0);
}
NODEPTR tao_Node(TYPEINFO x) {
	NODEPTR p;
	p= new NODE;
	p->data = x;
	p->link = NULL;
	return p;
}
NODEPTR themDau(NODEPTR& list, TYPEINFO x) {
	NODEPTR p = tao_Node(x);
	p->link = list;
	list = p;
	return p;
}
void xuat_DSLK(NODEPTR list) {
	NODEPTR p = list;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->link;
	}
}
//câu a
int demLe(NODEPTR list) {
	int dem = 0;
	for (NODEPTR p = list; p != NULL; p = p->link)
		if (p->data % 2 != 0)
			dem++;
	return dem;
}
/câu b
void chen(NODEPTR& list) {
	int x, k;
	cout << "\nNhap gia tri can chen: ";
	cin >> x;
	cout << "\nNhap gia tri truoc gia tri can chen: ";
	cin >> k;
	NODEPTR alter = tao_Node(x);
	NODEPTR p = list;
	NODEPTR q = list;
	while (p->link != NULL and p->data != k)
	{
		q = p;
		p = p->link;
	}
	q->link = alter;
	alter->link = p;

}

//câu 3;
#include"Header.h"
void main() {
	Stack s;
	init_Stack(s);
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	push(s, 5);
	cout << "Stack : " << endl;
	output_Stack(s);
	cout << "\nTong phan tu chan trong stack la:\t" << tongChan(s) << endl;
	themPhanTu(s);
	output_Stack(s);
	cout << "\n\n";
}

#include "Header.h"
void main() {
	NODEPTR list;
	khoitao(list);
	themDau(list, 13);
	themDau(list, 12);
	themDau(list, 16);
	themDau(list, 29);
	cout << "Danh sach lien ket: \t ";
	xuat_DSLK(list);
	cout << "\nDem gia tri le: \t " << demLe(list);
	chen(list);
	xuat_DSLK(list);
}
