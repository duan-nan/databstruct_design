#include<iostream>
#include<stdlib.h>
#include<stdlib.h>
#include"view.h"
#include"data.h" 

void welcomeView(){
	printf("\n\n\n\n\n");
	printf("\t\t\t\t    ******************************************************\n");
	printf("\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t    *---------------------Welcome!-----------------------*\n");
	printf("\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t    *-----------------南工校园导航系统-------------------*\n");
	printf("\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t    *-------------------按回车键继续---------------------*\n");
	printf("\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t    ******************************************************\n");
	getchar();
	system("cls"); 
	mainView();
}

void mainView(){
	int a;
	printf("\n\n\n\n\n");
	printf("\t\t\t\t    ******************************************************\n");
	printf("\t\t\t\t    *----------------------主界面------------------------*\n");
	printf("\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t    *----------------1、进入导航系统---------------------*\n");
	printf("\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t    *----------------2、学校简介-------------------------*\n");
	printf("\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t    *----------------3、退出程序-------------------------*\n");
	printf("\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t    *----------------4、制作人---------------------------*\n");
	printf("\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t    ******************************************************\n");
	scanf("%d",&a);
	while(1){
		
	if(a == 1){
		system("cls");
		travelView(); 
		break;
	}else if(a == 2){
		system("cls");
		schoolView(); 
		break;
	}else if(a == 3){
		system("cls");
		exitView(); 
		break;
	}else if(a == 4){
		system("cls");
		authorView(); 
		break;
	} else{
		printf("\n\n\n\t\t输入错误请重新输入！\n\n\n\n");
		scanf("%d",&a); 
	}
	}
}

void travelView(){
	int b,Id,i,j,p,q;
	char name[100];
	printf("\n\n\n\n\n");
	printf("\t\t\t\t ■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\t\t\t\t ■                                          ■\n");
	printf("\t\t\t\t ■  欢 迎 使 用  南 工  校 园 导 航 系 统   ■\n");
	printf("\t\t\t\t ■                                          ■\n");
	printf("\t\t\t\t ■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\n\n\n");
	printf("\t\t\t    1、遍历所有景点；\t\t\t2、查询任意景点信息；\n\n\n");
	printf("\t\t\t    3、查询任意两景点间的最短路径；     4、返回至主界面；\n");
	printf("\n\n\n");
	printf("请选择查询方式\n"); 
	scanf("%d",&b); 
	while(1){
	if(b == 1){
		system("cls");
		int n = searchStyle();
		system("cls");
		cloList();
		if(n == 1){			
			printf("请输入当前所在景点编号：\n"); 
			scanf("%d",&Id);
			while(1){
				if(Id>=1&&Id<=25){
					for(i=1;i<=25;i++){
						if(i!=Id){
							dijkstra(Id,i);
						}
					}
					printf("\n\n按回车键返回至导航系统界面\n\n");
					getchar();getchar();
					system("cls");
					mainView();
					break;
				}else{
					printf("\n\n该景点不存在，请您重新输入\n\n");
					scanf("%d",&Id);
				}
			}
			break;
		}else if(n == 2){
			cloList();
			printf("请输入当前所在景点名称：\n"); 
			scanf("%s",&name);
			Id = changeToId(name);
			while(1){
					if(Id>=1&&Id<=25){
					for(i=1;i<=25;i++){
						if(i!=Id){
							dijkstra(Id,i);
						}
					}
					printf("\n\n按回车键返回至导航系统界面\n\n");
					getchar();getchar();
					system("cls");
					mainView();
					break;
				}else{
					printf("\n\n该景点不存在，请您重新输入\n\n");
					scanf("%s",&name);
					Id = changeToId(name);
				}
			}
			break;
		}else if(n == 0){
			system("cls"); 
			mainView();
		}
		break;
		}else if(b == 2){
		system("cls");
		int n = searchStyle();
		system("cls");
		cloList();
		if(n == 1){
			printf("请输入当前所在景点编号：\n"); 
			scanf("%d",&Id);
			while(1){
				if(Id>=1&&Id<=25){
				    showInformation(Id);
					printf("按回车键返回至导航系统界面\n\n");
					getchar();getchar();
					system("cls");
					mainView();
					break;
				}else{
					printf("输入的编号不存在，请重新输入!\n");
					scanf("%d",&Id); 
				}
			}
		}else if(n == 2){
			printf("请输入景点名称:\n");
			scanf("%s",name);
			Id = changeToId(name);
			while(1){
				if(Id>=1&&Id<=25){
				    showInformation(Id);
					printf("按回车键返回至导航系统界面\n\n");
					getchar();getchar();
					system("cls");
					mainView();
					break;
				}else{
					printf("输入的景点不存在，请重新输入!\n");
					scanf("%s",name); 
				}
			}
		
		}else if(n == 0){
			system("cls"); 
			mainView();
		}
		break;
	}else if(b == 3){
		system("cls");
		int n = searchStyle();
		system("cls");
		cloList();
		if(n == 1){
			printf("请输入起点景点编号：\n");
			scanf("%d",&p);
			printf("\n请输入终点景点编号：\n");
			scanf("%d",&q);
			while(1){
				if(p>=1&&p<=25&&q>=1&&q<=25&&p!=q){
				    dijkstra(p,q);
					printf("按回车键返回至导航系统界面\n\n");
					getchar();getchar();
					system("cls");
					mainView();
					break;
				}else{
					printf("\n输入不合法！请重新输入！\n\n");
					printf("请输入起点景点编号：\n");
					scanf("%d",&p);
					printf("\n请输入终点景点编号：\n");
					scanf("%d",&q);
				}
			}
		}else if(n == 2){
			printf("请输入起点景点名称：\n");
			scanf("%s",name);
			p = changeToId(name);
			printf("\n请输入终点景点名称：\n");
			scanf("%s",name);
			q = changeToId(name);
			while(1){
				if(p>=1&&p<=25&&q>=1&&q<=25&&p!=q){
				    dijkstra(p,q);
					printf("按回车键返回至导航系统界面\n\n");
					getchar();getchar();
					system("cls");
					mainView();
					break;
				}else{
					printf("\n输入不合法！请重新输入！\n\n");
					printf("请输入起点景点名称：\n");
					scanf("%s",name);
					p = changeToId(name);
					printf("\n请输入终点景点名称：\n");
					scanf("%s",name);
					q = changeToId(name);

				}
			}
		}else if(n == 0){
			system("cls");
		mainView(); 
		break;
		}
		break;
	}else if(b == 4){
		system("cls");
		mainView(); 
		break;
	}else{
		printf("\n\n\n\t\t输入错误请重新输入！\n\n\n\n");
		scanf("%d",&b); 
	}
	}
}

void schoolView(){
	printf("\n\n\n\n\n");
	printf("\t\t\t\t    ****************************************************\n");
	printf("\t\t\t\t    *                                                  *\n");
	printf("\t\t\t\t    *     南阳理工学院，简称“南工”，位于位于楚风汉韵 *\n");
	printf("\t\t\t\t    *                                                  *\n");
	printf("\t\t\t\t    * 荟萃之所，商圣范蠡、科圣张衡、医圣张仲景故里、诸 *\n");
	printf("\t\t\t\t    *                                                  *\n");
	printf("\t\t\t\t    * 葛亮躬耕地——历史文化名城河南南阳。             *\n");
	printf("\t\t\t\t    *                                                  *\n");
	printf("\t\t\t\t    *    南工是一所全日制公办普通本科院校  学校建于1987*\n");
	printf("\t\t\t\t    *                                                  *\n");
	printf("\t\t\t\t    * 年，前身为南阳大学,1993年更名为 南阳理工学院。   *\n");
	printf("\t\t\t\t    *                                                  *\n");
	printf("\t\t\t\t    ****************************************************\n");
	printf("\n\n\n\n\n");
	printf("按回车键返回主界面\n");
	getchar();getchar();
	system("cls");
	mainView(); 
} 


void exitView(){
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t∴∵∴∵∴∵∴∵∴∵∴∵∴∵∴\n");
	printf("\t\t\t\t\t∴∵                      ∴∵\n");
	printf("\t\t\t\t\t∴∵  感 谢 您 的 使 用   ∴∵\n");
	printf("\t\t\t\t\t∴∵                      ∴∵\n");
	printf("\t\t\t\t\t∴∵  祝 您 生 活 愉 快   ∴∵\n");
	printf("\t\t\t\t\t∴∵                      ∴∵\n");
	printf("\t\t\t\t\t∴∵∴∵∴∵∴∵∴∵∴∵∴∵∴\n");
	printf("\n\n\n"); 
	
}

void authorView(){
	printf("\n\n\n\n\n");
	printf("\t\t\t\t    ****************************************************\n");
	printf("\t\t\t\t    *                     制作人                       *\n");
	printf("\t\t\t\t    *                                                  *\n");
	printf("\t\t\t\t    *                  南阳理工学院                    *\n");
	printf("\t\t\t\t    *                                                  *\n");
	printf("\t\t\t\t    *              19级软件工程移动3班                 *\n");
	printf("\t\t\t\t    *                                                  *\n");
	printf("\t\t\t\t    *                     段楠                         *\n");
	printf("\t\t\t\t    *                                                  *\n");
	printf("\t\t\t\t    ****************************************************\n");
	printf("\n\n\n\n\n");
	printf("按回车键返回主界面\n");
	getchar();getchar();
	system("cls");
	mainView(); 
}

int searchStyle(){
	int i;
	system("cls");			//清屏 
	printf("\n");
	printf("\t\t\t\t                    *请输入查询方式*\n\n");
	printf("\t\t\t\t                  1、输入景点编号查询\n\n");
	printf("\t\t\t\t                  2、输入景点名称查询\n\n");
	printf("\t\t\t\t                  0、返回首页面\n\n\n\n\n\n\n");
	printf("请选择查询方式:");
	scanf("%d",&i);
	return i;
}
