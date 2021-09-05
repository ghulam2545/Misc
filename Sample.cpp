#include <iostream>
#include <vector>
using namespace std;

int add(int&& a, int&& b) {
	return a + b;
}

int main() {
	
	int p = 10;
	int q = 30;
	cout<< add(10, 30);
	
    return 0;
}
