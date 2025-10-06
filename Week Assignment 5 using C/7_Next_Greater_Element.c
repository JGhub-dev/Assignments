#include <stdio.h>
#include <stdlib.h>
void nextGreater(int arr[],int n,int res[]){int*st=malloc(n*sizeof(int));int top=-1;for(int i=n-1;i>=0;i--){while(top!=-1&&st[top]<=arr[i])top--;res[i]=(top==-1)?-1:st[top];st[++top]=arr[i];}free(st);}
int main(){int n;scanf("%d",&n);int a[n],r[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);nextGreater(a,n,r);for(int i=0;i<n;i++)printf("%d ",r[i]);}