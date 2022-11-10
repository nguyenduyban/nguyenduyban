//bổ xung thuvien.h
void khoiTao(NODEPTR& list);
int isEmpty(NODEPTR list);
NODEPTR tao_NODE(TYPEINFO x);
NODEPTR them_Dau(NODEPTR& list, TYPEINFO x);
void nhap_DS(NODEPTR& list);
void xuat_DS(NODEPTR list);

//bổ xung caidac.cpp ghi trước trên hàm bool timx
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

bổ xung chươngtrinh
#include"Header.h"
int main()
{
	//DAYSO a;
	//nhap(a);
	//cout << "\nDay so vua nhap la\n";
	//xuat(a);
	//int pos, x;
	//cout << "\nNhap vi tri can xoa : ";
	//cin >> pos;
	//xoa1PT(a, pos);
	//cout << "\nDay so sau khi xoa ";
	//xuat(a);
	//cout << "\nNhap vi tri can thay the ";
	//cin >> pos;
	//cout << "\nNhap ptu can thay the ";
	//cin >> x;
	//thayThe(a, pos, x);
  
 cout << "-------------------------------";
 NODEPTR l;
	int x;
	khoiTao(l);
	nhap_DS(l);
	cout << "\nDSLK vua nhap ";
	xuat_DS(l);
  tongChan(l);
  cout << "\nNhap phan tu can xoa ";
	cin >> x;
	xoa_X(l, x);
	xuat_DS(l);
  }
