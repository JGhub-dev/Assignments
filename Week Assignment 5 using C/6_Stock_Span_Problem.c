#include <stdio.h>
#include <stdlib.h>
void calcSpan(int price[],int n,int S[]){int*st=malloc(n*sizeof(int));int top=-1;for(int i=0;i<n;i++){while(top!=-1&&price[st[top]]<=price[i])top--;S[i]=(top==-1)?i+1:i-st[top];st[++top]=i;}free(st);}
int main(){int n;scanf("%d",&n);int a[n],s[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);calcSpan(a,n,s);for(int i=0;i<n;i++)printf("%d ",s[i]);}