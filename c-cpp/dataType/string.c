int main() {
	int a = 4094;
	char s[10] = "123456789";
	for (int i = 0; i < 9; i++)
		printf("%s ", s + i);
	return 0;
}