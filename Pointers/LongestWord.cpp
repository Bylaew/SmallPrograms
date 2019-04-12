#include <iostream>

char* check(char* forcheck, char* checked, int max) {
	int i = 0;
	for (; *forcheck != '\0' && *forcheck != ' '; forcheck++) {
		if (i <= max) {
			checked[i] = *forcheck;
			i++;
		}
	}
	checked[max] = '\0';
	return checked;
}
char* longestWord(char* str) {
	int i = 1;
	int max = 0;
	int a = 0;
	int k = 0;
	char* fstr = str;
	char* sstr = str;
	for (; *sstr != '\0'; sstr++) {
		if (*sstr == ' ') {
			i++;
		}
	}
	int* counter = new int[i];
	for (; *fstr != '\0'; fstr++) {
		a++;
		if (*fstr == ' ') {
			counter[k] = a - 1;
			k += 1;
			a = 0;
		}
		counter[k] = a;
	}
	for (int f = 0; f <= k; f++) {
		 std::cout << "The word # " << f << " is " << counter[f] << " characters long" << std::endl;
		if (counter[f] > max) {
			max = counter[f];
		}
	}
	char* tmpLongest = new char[max];
	char* longest = new char[max];
	a = 0;
	 for (; *str != '\0'; str++) {
		tmpLongest[a] = *str;
		a++;
		 if (*str == ' ') {
		a -= 1;
			 if (a == max) {
				 return check(tmpLongest, longest, max);
			 }
		a = 0;
		 }
	 }
	 return check(tmpLongest, longest, max);
}


int main() {
	setlocale(LC_ALL, "Rus");
	char arr[] = { "Operation system is cool" };
	char* longestW = longestWord(arr);
	std::cout << "Longest word: ";
	for (; *longestW != '\0'; longestW++) {
		std::cout << *longestW;
	}
	std::cout << std::endl;
	return 0;
}
