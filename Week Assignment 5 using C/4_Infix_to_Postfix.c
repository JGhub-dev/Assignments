#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int prec(char c){if(c=='^')return 3;if(c=='*'||c=='/')return 2;if(c=='+'||c=='-')return 1;return 0;}
int isOp(char c){return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';}
void infixToPostfix(const char*in,char*out){char st[1000];int top=-1,j=0;
for(int i=0;in[i];){if(in[i]==' '){i++;continue;}if(isalnum(in[i])){while(isalnum(in[i]))out[j++]=in[i++];out[j++]=' ';}
else if(in[i]=='('){st[++top]='(';i++;}else if(in[i]==')'){while(top!=-1&&st[top]!='(')out[j++]=st[top--],out[j++]=' ';if(top!=-1)top--;i++;}
else if(isOp(in[i])){char op=in[i++];while(top!=-1&&((prec(st[top])>prec(op))||(prec(st[top])==prec(op)&&op!='^'))&&st[top]!='('){out[j++]=st[top--];out[j++]=' ';}st[++top]=op;}}
while(top!=-1){out[j++]=st[top--];out[j++]=' ';}out[j]=0;}
int main(){char in[1000],out[2000];fgets(in,1000,stdin);in[strcspn(in,"\n")]=0;infixToPostfix(in,out);printf("%s\n",out);}