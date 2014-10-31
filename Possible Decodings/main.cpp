#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// decode character 
bool decodeInt(int arr[], int size, int start, int length, char* decoded, int decodeLength) {
	if (start + length > size) return false;

	if (length == 1) {
		decoded[decodeLength] = arr[start] - 1 + 'A';
		return true;
	} else if (length == 2) {
		int value = arr[start+1] + arr[start] * 10;
		if (value <= 26) {
			decoded[decodeLength] = value - 1 + 'A';
			return true;
		} else{
			return false;
		}	
	}
}

void decodeUtil(int arr[], int size,int start, char* decodedStr,int decodedLength, int *count) {
	if (start >= size) {
		decodedStr[decodedLength] = '\0';
		printf("%s\n", decodedStr);
		*count = *count + 1;
		return;
	}

	bool succcess = decodeInt(arr,size, start,1,decodedStr,decodedLength);
	if (succcess) decodedLength++;

	if (start +  1 > size) return;
	decodeUtil(arr,size, start+1, decodedStr,decodedLength,count);
	
	decodedLength--;
	succcess = decodeInt(arr,size,start,2,decodedStr,decodedLength);
	if (succcess) decodedLength++;

	if ((start +  2 > size) || (!succcess) )return;
	decodeUtil(arr,size,start+2, decodedStr,decodedLength,count);
}

int* decode(int arr[], int size) {
	char* decodedStr = (char *) malloc(sizeof(char) * (size + 1) ); // 1 more character for end of string

	int decodedLength = 0;
	int * count = (int *) malloc(sizeof(int));
	* count = 0;

	decodeUtil(arr, size,0,decodedStr,decodedLength,count); //until index
	
	return count;
}

void main() {
	//int digits[] = {1,2,3,4};
	int digits[] = {1,2,1};
	int size = sizeof(digits)/sizeof(int);

	/* test for decodeInt */
	int length = 1;
	char * decoded = (char * )malloc( (length + 1) * sizeof(char));

	int* count = decode(digits,size);
	printf("Possible count: %d\n",*count);
	
}