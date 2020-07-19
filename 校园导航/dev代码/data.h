#include<stdio.h>
#include<stdlib.h>
/*     信息初始化     */
void initData();
/*     信息列表       */
void cloList();
/*     信息转化       */
int changeToId(char s[]);
/*   迪杰斯特拉算法   */
void dijkstra(int v0,int v1);
/*    展示信息       */
void showInformation(int Id);
