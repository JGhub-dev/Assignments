#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
long long eval(char*expr){long long st[1000];int top=-1;char*t=strtok(expr," ");while(t){if(isdigit(t[0])||(t[0]=='-'&&isdigit(t[1])))st[++top]=atoll(t);else{long long b=st[top--],a=st[top--];if(*t=='+')st[++top]=a+b;else if(*t=='-')st[++top]=a-b;else if(*t=='*')st[++top]=a*b;else if(*t=='/')st[++top]=a/b;}t=strtok(NULL," ");}return st[top];}
int main(){char buf[1000];fgets(buf,1000,stdin);buf[strcspn(buf,"\n")]=0;printf("%lld\n",eval(buf));}