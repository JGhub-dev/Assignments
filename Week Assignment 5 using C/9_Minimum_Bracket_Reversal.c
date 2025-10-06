#include <stdio.h>
#include <string.h>
int minRev(const char*s){int n=strlen(s);if(n%2)return -1;char st[100000];int top=-1;for(int i=0;i<n;i++){if(s[i]=='{')st[++top]='{';else if(top!=-1&&st[top]=='{')top--;else st[++top]='}';}int open=0;while(top!=-1&&st[top]=='{'){open++;top--;}int close=top+1;return(open+1)/2+(close+1)/2;}
int main(){char s[100000];fgets(s,100000,stdin);s[strcspn(s,"\n")]=0;printf("%d\n",minRev(s));}