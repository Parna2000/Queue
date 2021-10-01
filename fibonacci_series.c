// fibonacci series
#include<stdio.h>
#include<stdlib.h>

int fibonacci(int n){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 1;
    }
    else{
        return (fibonacci(n-1)+fibonacci(n-2));
    }
}

int main(){
    int n;
    printf("Enter the number of terms you want to find:\n");
    scanf("%d",&n);
    printf("The required fibonacci series is:\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ",fibonacci(i));
    }
    printf("\n");
    return 0;
}