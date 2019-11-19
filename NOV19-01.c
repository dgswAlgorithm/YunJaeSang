int main() {

	int input[] = { 6, 0, 8, 2, 3, 0, 4, 0, 1 };
	int size = sizeof(input) / sizeof(input[0]);

	int y = 0;
	for (int x = 0; x < size; ++x)
	{
		if (input[x] != 0)
		{
			int tmp = input[x];
			input[x] = 0;
			input[y++] = tmp;
		}
	}

	

	return 0;
}