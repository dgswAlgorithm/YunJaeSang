#include <stdlib.h>
#include <stdio.h>

int main() {

	int input[] = { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 };
	int size = sizeof(input) / sizeof(input[0]);

	int max_combo = -1;
	int max_cursor = -1;
#if 1
	for (int csr = 0; csr < size; ++csr)
	{
		int combo = 0;
		int head = -1;
		for (int x = 0; x < size; ++x)
		{
			if (input[x] == 1 || x == csr)
			{
				if (head == -1)
					head = x;
			}
			else
			{
				if (head != -1)
				{
					int new_combo = x - head;
					if (new_combo > combo)
						combo = new_combo;
					head = -1;
				}
			}
		}
		if (head != -1)
		{
			int new_combo = size - head;
			if (new_combo > combo)
				combo = new_combo;
			head = -1;
		}

		printf("When E[%d] is 1, There is %d-Combo\n", csr, combo);
		if (combo > max_combo)
		{
			max_combo = combo;
			max_cursor = csr;
		}
	}
#endif
	

	return 0;
}