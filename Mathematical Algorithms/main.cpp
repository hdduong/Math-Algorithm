#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
void printStr(char * str, int * seqVisited, int size) {
	for (int i = 0; i < size; i++) {
		cout << str[seqVisited[i]];
	}
	cout << endl;
}
void permutationUtil(char * str, int size,int i, bool * visited, int * seqVisited, int length) {
	if (length == size) {
		printStr(str,seqVisited,size);
	}

	visited[i] = true;
	for (int j = 0; j < size; j++) {
		if (!visited[j]) {
			length++;
			seqVisited[length-1] = j;
			permutationUtil(str, size,j,visited,seqVisited,length);
			seqVisited[length-1] = -1;
			length--;
		}
	}
	visited[i] = false;
}


void Permutation(char * str) {
	if (str == NULL)
		return;
	int n = strlen(str);

	bool * visited  = (bool*)malloc(sizeof(bool) * n);
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	int * seqVisited  =(int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		seqVisited[i] = -1;
	}

	for (int i = 0; i < n;i++) {
		int length = 1;
		seqVisited[0] = i;
		permutationUtil(str,n,i,visited,seqVisited,length);
	}
	
}


void main() {
	char * str = "ABC";
	Permutation(str);
}