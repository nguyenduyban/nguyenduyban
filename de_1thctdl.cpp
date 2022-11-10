//Thư viện

#include <iostream>
using namespace std;
const int MAX = 50;
struct DAYSO
{
	int n;
	int data[MAX];
};
void nhap(DAYSO &ds);
void xuat(DAYSO ds);
void chen1PT(DAYSO& ds, int pos, int x);
void truyXuatPT(DAYSO ds,int pos);
typedef int TYPEINFO;
struct NODE
{
	TYPEINFO data;
	NODE* link;
};
typedef NODE* NODEPTR;
void khoiTao(NODEPTR& list);
int isEmpty(NODEPTR list);
NODEPTR tao_NODE(TYPEINFO x);
NODEPTR them_Dau(NODEPTR& list, TYPEINFO x);
void nhap_DS(NODEPTR& list);
void xuat_DS(NODEPTR list);
void xuat_PT_Am(NODEPTR list);
void tongNhoHon5(NODEPTR list);
bool timX(NODEPTR list, TYPEINFO x);
void xoadau(NODEPTR& list);
void xoa_X(NODEPTR& list, TYPEINFO x);
void giaiPhong(NODEPTR& list);

// cài đặt 
#include "Header.h"
void nhap(DAYSO& ds)
{
	cout << "\nNhap so luong phan tu : ";
	cin >> ds.n;
	cout << "\nNhap ds ";
	for (int i = 0;i < ds.n;i++)
	{
		cout << "\nNhap ds[ " << i << " ]: ";
		cin >> ds.data[i];
	}
}
void xuat(DAYSO ds)
{
	for (int i = 0;i < ds.n;i++)
		cout << ds.data[i] <<" ";
}
void chen1PT(DAYSO& ds, int pos, int x)
{
	for (int i = ds.n - 1;i >= pos;i--)
		ds.data[i+1] = ds.data[i];
	ds.data[pos] = x;
	ds.n++;
}
void truyXuatPT(DAYSO ds, int pos)
{
	for (int i = 0;i < ds.n;i++)
		if (i == pos)
			cout << ds.data[i];
}
void khoiTao(NODEPTR& list)
{
	list = NULL;
}
int isEmpty(NODEPTR list)
{
	return(list == NULL ? 1 : 0);
}
NODEPTR tao_NODE(TYPEINFO x)
{
	NODEPTR p;
	p = new NODE;
	p->data = x;
	p->link = NULL;
	return p;
}
NODEPTR them_Dau(NODEPTR& list, TYPEINFO x)
{
	NODEPTR p;
	p = tao_NODE(x);
	p->link = list;
	list = p;
	return p;
}
void nhap_DS(NODEPTR& list)
{
	khoiTao(list);
	int x;
	do {
		cout << "\nNhap vao x (thoat -99): ";
		cin >> x;
		if (x == -99)
			break;
		them_Dau(list, x);
	} while (1);
}
void xuat_DS(NODEPTR list)
{
	NODEPTR p = list;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->link;
	}
}
void tongNhoHon5(NODEPTR list)
{
	int tong = 0;
	NODEPTR p = list;
	while (p != NULL)
	{
		if (p->data < 5)
			tong += p->data;
		p = p->link;

	}
	cout << "\nTong cac ptu <5 la : " << tong;
}
void xuat_PT_Am(NODEPTR list)
{
	NODEPTR p = list;
	while (p != NULL)
	{
		if (p->data < 0)
			cout << p->data << " ";
		p = p->link;
	}
}
bool timX(NODEPTR list, TYPEINFO x)
{
	NODEPTR p = list;
	while (p != NULL)
	{
		if (p->data == x)
			return true;
		p = p->link;
	}
	return false;
}
void xoadau(NODEPTR& list)
{
	NODEPTR p;
	if (list != NULL)
	{
		p = list;
		list = p->link;
		delete p;
	}
}
void xoa_X(NODEPTR& list, TYPEINFO x)
{
	NODEPTR before;
	NODEPTR p;
	if (timX(list, x) == false)
		cout << "\nKhong co ptu " << x << " trong DS ";
	else
	{
		cout << "\nDSLK sau khi xoa " << x << endl;

		while (timX(list, x) == true)
		{
			if (list->data == x)
				xoadau(list);
			else
			{
				p = list;
				before = list;
				while ((p != NULL) && (p->data != x))
				{ 
					before = p;
					p = p->link;
				}
				if (p != NULL)
				{
					before->link = p->link;
					delete p;
				}
			}
		}
	}
}
void giaiPhong(NODEPTR& list)
{
	NODEPTR p = list;
	while (p != NULL)
	{
		list = list->link;
		delete p;
		p = list;
	}
}

// chuong trinh
#include"Header.h"
int main()
{
  DAYSO a;
	nhap(a);
	cout << "\nDay so vua nhap la\n";
	xuat(a);
  cout << "\nNhap vi tri can chen them : ";
	cin >> pos;
  cout << "\nNhap ptu can chen them : ";
	cin >> x;
  chen1PT(a, pos, x);
	xuat(a);
	cout << "\nNhap vi tri can xuat :";
	cin >> pos;
	cout << "\nXuat ptu tai vi tri " << pos << endl;
	truyXuatPT(a, pos);
  
NODEPTR l;
	khoiTao(l);
	nhap_DS(l);
	cout << "\nDSLK vua nhap ";
	xuat_DS(l);
  cout << "\nCac phan tu am trong DS ";
	xuat_PT_Am(l);
  tongNhoHon5(l);
  cout << "\nNhap phan tu can xoa ";
	cin >> x;
	xoa_X(l, x);
	xuat_DS(l);
	giaiPhong(l);
}
