void main() {
	int input[100] = { 9, 6, 8, 3, 4, 7 };
	int count = 6;
	int output[100];


	while (true)
	{
		bool is_sorted = true;
		for (int n = 0; n < count - 1; ++n)
		{
			if (input[n] >= input[n + 1]) 
			{
				is_sorted = false;
				break;
			}
		}
		if (is_sorted) break;


		for (int n = 0; n < count - 1; ++n)
		{
			if (input[n] >= input[n + 1])
			{
				int temp = input[n];
				input[n] = input[n + 1];
				input[n + 1] = temp;
			}
		}
	}

	for (int n = 0; n < count; ++n)
	{
		printf("%d, ", input[n]);
	}
	putchar('\n');
	for (int n = 0; n < count; ++n)
	{
		printf("%d, ", input[
			(n % 2 == 0) ? (n / 2) : ((n + count) / 2)
		]);
	}

	return;
}