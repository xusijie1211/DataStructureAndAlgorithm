#include <stdio.h>
#include <math.h>
 
int main()
{
    double base, exponent, result;
 
    printf("基数: ");
    scanf("%lf", &base);
 
    printf("指数: ");
    scanf("%lf", &exponent);
 
    // 计算结果
    result = pow(base, exponent);
 
    printf("%.1lf^%.1lf = %.2lf", base, exponent, result);
 
    return 0;
}
