#include<stdio.h>

int Fib(int n1);

int main(){
	
	int n1, amount;
    scanf("%d", &amount);
    for (int i = 0; i < amount; ++i) {
        scanf("%d", &n1);
        printf("%d\n", Fib(n1));
    }

	return 0;
}

int Fib(int n1){
	
	if(n1 == 0){
		return 0;
	}
	if(n1 == 1){
		return 1;
	}
	if(n1 > 1){
		return Fib(n1-1)+Fib(n1-2);
	}
}
