#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


int **M;

int bottom_up_dp(int n, int *s, int *v, int C)
{
    //write your code here
    for(int i =1; i<= n; i++){
        for(int j=1; j<= C ; j++){
            if(j-s[i] >= 0){
                int temp = M[i-1][j-s[i]] + v[i];
                if(temp > M[i-1][j]){
                    M[i][j] = temp;
                }
                else{
                    M[i][j] = M[i-1][j];
                }
            }
            else{
                M[i][j] = M[i-1][j];
            }
        }
    }
    return M[n][C];
}


int main ()
{
    int n,C;
    int function;
    int *s;
    int *v;
    int i,j;
    printf("Enter the number of items n:\n");
    scanf("%d",&n);
    printf("Enter the capacity C:\n");
    scanf("%d",&C);
    s = (int *) malloc(sizeof(int) * (n+1));
    v = (int *) malloc(sizeof(int) * (n+1));


    M = (int**)malloc((n+1)*sizeof(int*));

    for (int i = 0; i <= n; i++)
        M[i] = (int*)malloc((C+1) * sizeof(int));

    for(int k=0; k < n; k++){
        for(int j=0; j < C ; j++){
            M[k][j] = 0;
        }
    }

    printf("Enter the sizes of items (as a list, separate by spacing:\n");
    for (i=1;i<=n;i++)
        scanf("%d",&s[i]);

    printf("Enter the values of items (as a list, separate by spacing:\n");
    for (i=1;i<=n;i++)
        scanf("%d",&v[i]);

    printf("The maximum value is: %d \n", bottom_up_dp(n,s,v,C));

}
