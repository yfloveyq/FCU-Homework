#include<stdio.h>

int calc(int m, int n);

int main(){
	
	int num1, num2, amount;
	scanf("%d", &amount);
    for (int i = 0; i < amount; ++i) {
        scanf("%d%d", &num1, &num2);
        printf("%d\n", calc(num1,num2));
    }

	
	
	return 0;
}

int calc(int m, int n){
	
	if(m==0){
		return n+1;
	}
	if(m>0 && n==0){
		return calc(m-1, 1);
	}
	if(m>0 && n>0){
		return calc(m-1, calc(m,n-1));
	}
	
	
	
}
