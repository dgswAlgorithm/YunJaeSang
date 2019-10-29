#include "stdafx.h"

#define N 100 
#define NetSize 5
void main() {
	int river[N];
	for (int x = 0; x < 100; ++x)
	{
		river[x] = rand() % 10;

		printf("%d ", river[x]);
	}
	putchar('\n');



	int most_fish = 0;
	int most_spot = 0;
	for (int x = 0; x < 100 - NetSize; ++x)
	{
		int sum = 0;
		for (int y = 0; y <= NetSize; ++y) sum += river[x + y];
		if (most_fish < sum)
		{
			most_fish = sum;
			most_spot = x;
		}
	}

	for (int x = 0; x < most_spot; ++x) printf("  ");
	for (int x = 0; x < NetSize * 2 - 1; ++x) printf("-");

	putchar('\n');
	printf("Best spot is %d, there is %d of fishes", most_spot, most_fish);
}