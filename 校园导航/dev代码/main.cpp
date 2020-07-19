#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include"view.h"
#include"data.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	initData();
	welcomeView();
	system("pause");
	return 0;
}
