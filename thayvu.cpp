void doiChuoi(char* s) {
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] >= 'A' and s[i] <= 'Z')
			s[i] = s[i] + 32;
	}
}
void main() {
	

	char s[100];
	cout << "Nhap chuoi: ";
	cin.getline(s, 100);
	cout << "\nCHuoi ban dau: " << s;
	doiChuoi(s);
	cout << "\nChuoi sau khi doi: " << s;

}
