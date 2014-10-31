#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void printArr(int *arr, bool * visited, int size) {
	for (int i = 0; i < size; i++) {
		if (visited[i])
			cout << arr[i] << " ";
	}
	cout << endl;
}

void combinationUtil(int arr[], int size, int r, int start, int length, bool *visited) {
	if (length == r) {
		printArr(arr,visited,size);
		return;
	}

	int j = 1;
	while (start + j < size) {
		visited[start + j] = true;
		combinationUtil(arr,size,r,start + j, length + 1, visited);
		visited[start + j] = false;
		j++;
	}
}

void combination(int arr[], int size, int r) {
	bool * visited = (bool *) malloc(sizeof(bool) * size);

	for (int i = 0; i < size;i++)
		visited[i] = false;

	int length = 1;
	for (int i = 0;i < size; i++) {
		visited[i] = true;
		combinationUtil(arr,size, r, i, length, visited);
		visited[i] = false;
	}
}
void main() {
	int arr[] = {1, 2, 3, 4};
	int r = 3;
	int size = sizeof(arr)/ sizeof(int);

	combination(arr,size,r);
}