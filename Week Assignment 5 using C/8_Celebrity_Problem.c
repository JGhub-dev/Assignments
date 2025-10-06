#include <stdio.h>
#include <stdlib.h>
int main(){int n;scanf("%d",&n);int M[n][n];for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&M[i][j]);int a=0,b=n-1;while(a<b){if(M[a][b])a++;else b--;}int c=a;for(int i=0;i<n;i++){if(i==c)continue;if(M[c][i]||!M[i][c]){printf("-1\n");return 0;}}printf("%d\n",c);}