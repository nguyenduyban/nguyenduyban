// ĐỀ CÓ STACK 
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

//cau 2
void khoiTao(NODEPTR& list) {
	list = NULL;
}
bool ktRong(NODEPTR list) {
	if (list == NULL) return true;
	else return false;
}
NODEPTR makeNode(int x) {
	NODEPTR p = new node;
	p->data = x;
	p->link = NULL;
	return p;
}
NODEPTR themDau(NODEPTR& list, int x) {
	NODEPTR p = makeNode(x);
	if (ktRong(list) == true)
		list = p;
	else {
		p->link = list;
		list = p;
	}
	return p;
}
void xuatDSLK(NODEPTR ds) {
	for (NODEPTR p = ds; p != NULL; p = p->link)
		cout << p->data << "\t";
}
//câu a : đếm các node giá trị lẻ dslk
int demLe(NODEPTR ds) {
	int dem = 0;
	for (NODEPTR p = ds; p != NULL; p = p->link)
		if (p->data % 2 != 0)
			dem++;
	return dem;
}
//câu b : chèn node có giá trị x , k 
void chen(NODEPTR& ds) {
	int x, k;
	cout << "\nNhap gia tri can chen: ";
	cin >> x;
	cout << "\nNhap gia tri o truoc gia tri can chen: ";
	cin >> k;
	NODEPTR alter = makeNode(x);
	NODEPTR p = ds;
	NODEPTR q = ds;
	while (p->link != NULL and p->data != k)
	{
		q = p;
		p = p->link;
	}
	q->link = alter;
	alter->link = p;

}
//câu c
void tachDSLK(NODEPTR& ds) {
	int n;
	cout << "\nNhap gia tri : ";
	cin >> n;
	NODEPTR p = ds;
	while (p != NULL and p->data != n) {
		p = p->link;
	}
	if (p->link != NULL) {
		p->link = NULL;
	}
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
