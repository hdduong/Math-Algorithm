#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void copyArr(int arr[], int i, int j, int * arrRet, int m, int n) {
	for (int k = i, l = m; k <= j, l <=n; k++,l++) {
		arrRet[l] = arr[k];
	}
}

void printArr(int *arr, int from, int to) {
	for (int i = from; i <= to; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void printArr(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int addMiddle(int arr[], int i, int j, int ** retArr) {
	int numElement = ( j - i) + 1;

	int middle = i + (j - i) / 2;
	if (arr[middle] < 9) {
		int * arrRet = (int*)malloc(sizeof(int) * numElement);
		
		copyArr(arr,i,j,arrRet,0,numElement-1);
		arrRet[(numElement-1)/2] = arr[middle] + 1;
		
		if (!(numElement & 1)) arrRet[(numElement-1)/2+1] = arr[middle+1] + 1;
		
		*retArr = arrRet;
		return numElement;
	}
	else { //arr[middle]  = 9
		int carry  = 1;
		int k = middle-1;
		while (k >= i) {
			(arr[k] < 9) ? (carry = 0) : (carry=1);
			k--;
		}
		if (carry == 0) {
			int * arrRet = (int*)malloc(sizeof(int) * numElement);
			copyArr(arr,i,j,arrRet,0,numElement-1);
			
			if (numElement & 1) {
				
				int left = middle-1;
				int right = middle + 1;
				
				arrRet[(numElement-1)/2] = 0;
				carry = 1;
				int middleArrRet = (numElement-1)/2;
				int leftArrRet = middleArrRet - 1;
				int rightArrRet = middleArrRet + 1;
				while (left >= i) {
					if (carry) { 
						if (arr[left] != 9) {
							arrRet[leftArrRet] = arr[left] + 1;
							arrRet[rightArrRet] = arr[right] + 1;
							carry = 0;
						} else {
							arrRet[leftArrRet] = 0;
							arrRet[rightArrRet] = 0;
							carry = 1;
						}					
					} else {
						arrRet[leftArrRet] = arr[left] ;
						arrRet[rightArrRet] = arr[right] ;
						carry = 0;
					}
					leftArrRet--;
					rightArrRet++;
					left--;
					right++;
				}

			} else {
				int left = middle;
				int right = middle + 1;
				arr[left] = 0; arr[right] = 0;
				carry = 1;


			}

			*retArr = arrRet;
			return numElement;
		} else if (carry == 1) {
			int * arrRet = (int*)malloc(sizeof(int) * (numElement + 1) );
				
			for (int l = i; l <= j;l++) arrRet[l-i+1] = 0;
			arrRet[0] = 1; arrRet[numElement] = 1;
			
			*retArr = arrRet;
			return numElement + 1;
		}
	}
}

int findFirstNotPal(int arr[], int size) {
	int middle = (size - 1) / 2;
	int left = -1;
	int right = -1;
	int firstPosition = -1;

	if (size & 1)  { left = middle -1; right = middle + 1; }
	else {left = middle; right = middle + 1; }

	while (left >= 0) {
		if (arr[left] == arr[right]) {
			left--;
			right++;
		} else {
			firstPosition = left;
			break;
		}
	}

	return firstPosition;
}

int findFirstPositionNot9(int arr[], int size) {
	int middle = (size - 1) / 2;
	int firstPosition = -1;

	while (middle >= 0) {
		if (arr[middle] != 9) {
			return middle;
		} else {
			middle--;
		}
	}

	return middle;

}


void nextSmallestPalindrome(int arr[], int size) {
	int firstPosition = findFirstNotPal(arr,size);
	int * arrMiddle = &firstPosition;
	int * arrRet = &firstPosition;
	
	if (firstPosition == -1)  {
		int findFirstNode9 = findFirstPositionNot9(arr,size);
		if (findFirstNode9 >= 0) {
			int numElement = addMiddle(arr,findFirstNode9,size-1-findFirstNode9,&arrMiddle);
			arrRet = (int*)malloc(sizeof(int) * (numElement + findFirstNode9 * 2) );
			
			copyArr(arr,0,findFirstNode9-1,arrRet,0,findFirstNode9-1);
			copyArr(arrMiddle,0,numElement-1,arrRet,findFirstNode9, findFirstNode9 + numElement -1 );
			copyArr(arr,findFirstNode9 + numElement, size-1,arrRet,findFirstNode9 + numElement,findFirstNode9 + numElement + findFirstNode9 - 1);
			printArr(arrRet,(numElement + findFirstNode9 * 2));
		} else {
			int numElement = addMiddle(arr,0,size-1,&arrRet);
			printArr(arrRet,numElement);
		}
		
	} else {
		int numElement = addMiddle(arr,firstPosition+1,size-1-firstPosition-1,&arrMiddle);
		arrRet = (int*)malloc(sizeof(int) * (numElement + firstPosition * 2) );
			
		copyArr(arr,0,firstPosition,arrRet,0,firstPosition);
		copyArr(arrMiddle,0,numElement-1,arrRet,firstPosition+1, firstPosition + numElement);
		
		int i = 0, j = 0;
		for (i = 0, j = firstPosition + numElement + firstPosition + 1; i >= 0, j>= firstPosition + numElement + 1; i++,j--) {
			arrRet[j] = arrRet[i];
		}
		printArr(arrRet,(numElement + (firstPosition + 1) * 2));
	}

	
}

void main() {
	//int num[] = {1,2,9,2,1};
	//int n = 5;

	/*int arr[]={9,1,1,9};
	int size = 4;
	int n = size - 1;
	
	int * arrRet = &n;
	int numElement = addMiddle(arr,0,n,&arrRet);

	printArr(arrRet,numElement);*/

	int num[] = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2};
	//int num[] = {9,9,9,9,9};
	//int num[] = {1,2,9,2,1};
	//int num[] = {9,1,1,9};
    int size = sizeof (num)/ sizeof(num[0]);
	
	/*int firstPosition = findFirstNotPal(num,size);
	cout << firstPosition << endl;*/

	nextSmallestPalindrome(num,size);

}