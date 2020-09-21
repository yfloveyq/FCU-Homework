#include<stdio.h>

int calc(int n1, int n2);
int sum = 1;
int main(){
	
	int num1, num2;
	
	scanf("%d%d", &num1, &num2);
	
	printf("\n%d", calc(num1,num2));
	return 0;
} 

int calc(int n1, int n2){
	
	if(n1 > 0 && n2 == 0){
		return 1;
	}
	
	sum *= n1;
	n2--;
	
	if(n2==0){
		return sum;
	}
	
	else{
		return calc(n1,n2);
	}	
}
