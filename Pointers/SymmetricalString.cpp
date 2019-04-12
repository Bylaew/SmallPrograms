#include <iostream> 

int bufferLen = 0;
int sLen = 1;
int tLen = 0;

char* symmFragCheck(char* astr, int a_size) {
	char* s_str = astr;
	char* e_str = (astr + a_size) - 2;
	char res[80];
	int j = 0;
	for (int i = 0; i < (a_size) / 2; i++) {
		if (*s_str != *e_str) {
			res[j] = *s_str;
			j++;
		}
		s_str++;
		e_str--;	
	}
	for (int i = 0; i < (a_size) / 2 + 1; i++) {
		if (*s_str != *e_str) {
			res[j] = *e_str;
			j++;
		}
		e_str++;
		s_str--;
	}
	tLen = j;
	return res;
}

void fillArr(char* from, char* whre, int lenghtFrom, int lenghtWhere) {
	for (int c = 0; c < lenghtWhere; c++) {
		whre[c] = *(symmFragCheck(from, lenghtFrom) + c);
	}
}

void outputArr(char* arr, int lenght) {
	for (int c = 0; c < lenght; c++) {
		std::cout << *(arr + c);
	}
	std::cout << std::endl;
}

int main(){
	std::cout << "Enter the buffer length: ";
	std::cin >> bufferLen;
	char *str = new char[bufferLen];
	std::cout << "Enter the string: ";
	std::cin >> str;
	for (char *tempStr = str; *tempStr != '\0'; tempStr++) { sLen++; }
	symmFragCheck(str, sLen);
	char* nStr = new char[tLen];
	fillArr(str, nStr, sLen, tLen);
	std::cout << "Example: sflkfqwerttrewqjlssf -> sflkfjlssf " << std::endl;
	outputArr(nStr, tLen);
	std::cout << "String's length before processing:\t" << sLen << std::endl;
	std::cout << "String's length after processing:\t" << sLen - tLen << std::endl;
	delete[] str;
	delete[] nStr;
	system("pause");
	return 0;
}
