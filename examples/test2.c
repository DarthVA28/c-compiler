int printf(char const *format, ...);

int factorial(int n) {
	if (n <= 0) 
		return 1;
	else 
		return n*factorial(n-1);
	
}

int fibonacci(int a, int b, int n) {
	if (n <= 0) {
		return a;
	}
	else {
		while (n > 0) {
		int t;
		t = b;
		b = a+b;
		a = t;
		n = n-1;
		}
		return b;
	}
}

int main() {
	int x = fibonacci(factorial(1), factorial(2), factorial(5));
	// int x = fibonacci(1,1,2);
	printf("The answer is: %d\n",x);
  	return x;
}