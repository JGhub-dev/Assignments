#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char*dup(const char*s){char*r=malloc(strlen(s)+1);strcpy(r,s);return r;}
int main(){int q;scanf("%d\n",&q);char*s=dup("");char**st=malloc((q+5)*sizeof(char*));int top=-1;
for(int i=0;i<q;i++){int t;scanf("%d",&t);if(t==1){char w[100000];scanf("%s",w);st[++top]=s;char*ns=malloc(strlen(s)+strlen(w)+1);strcpy(ns,s);strcat(ns,w);s=ns;}
else if(t==2){int k;scanf("%d",&k);st[++top]=s;int len=strlen(s)-k;if(len<0)len=0;char*ns=malloc(len+1);strncpy(ns,s,len);ns[len]=0;s=ns;}
else if(t==3){int k;scanf("%d",&k);if(k>=1&&k<=strlen(s))printf("%c\n",s[k-1]);}
else if(t==4){if(top>=0){free(s);s=st[top--];}}}free(s);while(top>=0)free(st[top--]);free(st);}