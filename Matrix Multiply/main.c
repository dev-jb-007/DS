//
//  main.c
//  Matrix Multiply
//
//  Created by Dev Patel on 13/08/21.
//

#include <stdio.h>
void createMatrix(int r1,int c1,int A[][c1])
{
    for (int i=0; i<r1; i++) {
        for (int j=0; j<c1; j++) {
            scanf("%d",&A[i][j]);
        }
    }
}
void result(int r1,int c1,int r2,int c2,int A[][c1],int B[][c2])
{
    int C[r1][c2];
    if(c1!=r2)
    {
        printf("Multiplication Not Possible");
        return;
    }
    else{
        
        int i,j,k;
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                C[i][j]=0;
                for(k=0;k<c2;k++)
                {
                    C[i][j]+=A[i][k]*B[k][j];
                }
            }
        }
    }
    for (int i=0; i<r1; i++) {
        for (int j=0; j<c2; j++) {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
}
int main(int argc, const char * argv[]) {
    int r1,c1,r2,c2;
    scanf("%d %d",&r1,&c1);
    int A[r1][c1];
    createMatrix(r1, c1,A);
    scanf("%d %d",&r2,&c2);
    int B[r1][c1];
    createMatrix(r2,c2,B);
    result(r1, c1, r2, c2, A, B);
    return 0;
}
