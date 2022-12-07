Quí Kiệt
void khoiTao(Queue& q)
{
	q.first = -1;
	q.last = -1;
}
int enQueue(int x, Queue& q)
{
	if (q.first == -1)
		q.first = 0;
	else if (q.last == MAX - 1)
	{
		for (int i = q.first; i <= q.last; i++)
			q.elem[i - q.first] = q.elem[i];
		q.last = MAX - 1 - q.first;
		q.first = 0;
	}
	q.last++;
	q.elem[q.last] = x;
	return q.last;
}
void nhap(Queue& q)
{
	int x;
	while (1)
	{
		cout << "\nNhap x: "; cin >> x;
		if (x == -99)break;
		enQueue(x, q);
	}
}
void xuat(Queue q)
{
	for (int i = q.first; i <= q.last; i++)
	{
		cout << q.elem[i] << " ";
	}
}
int getFront(Queue q)
{
	return q.elem[q.first];
}
int tichLe(Queue q)
{
	int tich=1;
	for (int i = q.first; i <= q.last; i++)
	{
		if(q.elem[i]%2!=0)
			tich *= q.elem[i];
	}
	return tich;
}
int tong(Queue q)
{
	int tong = 0;
	for (int i = q.first; i <= q.last; i++)
		tong += q.elem[i];
	return tong;
}
int deQueue(Queue& q)
{
	if (q.first == q.last)
		khoiTao(q);
	else
	{
		int t = q.elem[q.first];
		q.first++;
		return t;
	}
}
int demLe(Queue q)
{
	int dem = 0;
	for (int i = q.first; i <= q.last; i++)
		if (q.elem[i] % 2 != 0)
			dem++;
	return dem;
}
