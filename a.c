#include <stdio.h>

#include<math.h>

int main()

{

    int n;

    unsigned long long sum;

    printf("请输入要计算的N此方：");

    scanf("%d",&n);

    sum=pow(2,n);
    printf("%llu",sum);

    return 0;

}
