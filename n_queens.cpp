#include "stdafx.h"
#include <iostream>

using namespace std;

#include <time.h>
#include <vector>
#include <random>
#include <opencv2/opencv.hpp>

#define CLASS 1

#if CLASS

constexpr int width = 12;
constexpr int number_queen = 12;
int queen_on_map[width][width] = { 0, };

bool queen(const int queen_number, const int qx, const int qy, const int map[width][width]) {
	int temp_map[width][width] = { 0, };

	queen_on_map[qx][qy] = 1;
	if (queen_number == 0) return true;

	for (int x = 0; x < width; ++x)
	{
		for (int y = 0; y < width; ++y)
		{
			if (map[x][y] || x == qx || y == qy || x - y == qx - qy || x + y == qx + qy)
				temp_map[x][y] = 1;
		}
	}

	for (int x = 0; x < width; ++x)
	{
		for (int y = 0; y < width; ++y)
		{
			if (temp_map[x][y] == 0)
				if (queen(queen_number - 1, x, y, temp_map))
					return true;
		}
	}
	queen_on_map[qx][qy] = 0;
	return false;
}

bool queen(const int queen_number) {
	int map[width][width] = { 0, };
	for (int x = 0; x < width; ++x)
	{
		for (int y = 0; y < width; ++y)
		{
			if (map[x][y] == 0)
				if (queen(queen_number - 1, x, y, map))
					return true;
		}
	}
}

int main() {
	if (!queen(number_queen))
		cout << "Failed to solve" << endl;

	for (int y = 0; y < width; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			cout << (queen_on_map[x][y] ? "■" : "□");
		}
		cout << endl;
	}
}