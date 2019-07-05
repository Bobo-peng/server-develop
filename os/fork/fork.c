#include<stdio.h>
int main()
{
fork();
fork()&&fork()||fork();
fork();
printf("+\n");
}
/*
fork()&&fork()||fork();会产生5个分支
*/