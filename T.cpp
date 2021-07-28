//Ho ten: Hoang Minh Quan
//Masv: 653304
//lop : K65MMTA
//De:
/*



*/

#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    FILE *fp;
    fp = fopen("test.txt","r");

    int n;
    fscanf(fp, "%d \n",&n);

    int a[n];
    for (int i=0; i<n; i++)
        fscanf(fp, "%d ", &a[i]);

    printf("Day so chua sap xep: \n");
    for (int i=0; i<n; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");

    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (a[j] < a[j+1])
            {
                 int tmp = a[j];
                 a[j] = a[j+1];
                 a[j+1] = tmp;
            }
        }
    }

    printf("Day so da sap xep: \n");
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }

    // set precision
    float x = 5.666666;
    printf("%6.4f", x);

    fclose(fp);

    return 0;
}
