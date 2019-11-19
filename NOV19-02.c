#include <stdlib.h>
#include <stdio.h>

int main() {

	int input[] = { 1, 2, 3, -10, 5, 6, 7, 8 };
	int size = sizeof(input) / sizeof(input[0]);


	int max_left = 0;
	int max_right = 0;
	int max_sum = input[0];
	int left = 0;
	int right = 0;
	int sum = input[0];

	int wide = 1;
	while (1)
	{
		if (wide)
		{
			++right;
			if (right < size)
			{
				sum += input[right];
				if (sum > max_sum)
				{
					max_left = left;
					max_right = right;
					max_sum = sum;
				}
			}
			else
			{
				wide = 0;
				sum -= input[left];
				if (sum > max_sum)
				{
					max_left = left;
					max_right = right;
					max_sum = sum;
				}
				++left;
				if (left == size) break;
			}
		}
		else
		{
			--right;
			sum -= input[right];
			if (right > left)
			{
				if (sum > max_sum)
				{
					max_left = left;
					max_right = right;
					max_sum = sum;
				}
			}
			else
			{
				++left;
				if (left == size) break;
				right = left;
				sum = input[left];
				wide = 1;
				if (sum > max_sum)
				{
					max_left = left;
					max_right = right;
					max_sum = sum;
				}
			}
		}
	}

	return 0;
}