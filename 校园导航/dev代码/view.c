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
	printf("\t\t\t\t    *-----------------�Ϲ�У԰����ϵͳ-------------------*\n");
	printf("\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t    *-------------------���س�������---------------------*\n");
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
	printf("\t\t\t\t    *----------------------������------------------------*\n");
	printf("\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t    *----------------1�����뵼��ϵͳ---------------------*\n");
	printf("\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t    *----------------2��ѧУ���-------------------------*\n");
	printf("\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t    *----------------3���˳�����-------------------------*\n");
	printf("\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t    *----------------4��������---------------------------*\n");
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
		printf("\n\n\n\t\t����������������룡\n\n\n\n");
		scanf("%d",&a); 
	}
	}
}

void travelView(){
	int b,Id,i,j,p,q;
	char name[100];
	printf("\n\n\n\n\n");
	printf("\t\t\t\t ����������������������������������������������\n");
	printf("\t\t\t\t ��                                          ��\n");
	printf("\t\t\t\t ��  �� ӭ ʹ ��  �� ��  У ԰ �� �� ϵ ͳ   ��\n");
	printf("\t\t\t\t ��                                          ��\n");
	printf("\t\t\t\t ����������������������������������������������\n");
	printf("\n\n\n");
	printf("\t\t\t    1���������о��㣻\t\t\t2����ѯ���⾰����Ϣ��\n\n\n");
	printf("\t\t\t    3����ѯ���������������·����     4�������������棻\n");
	printf("\n\n\n");
	printf("��ѡ���ѯ��ʽ\n"); 
	scanf("%d",&b); 
	while(1){
	if(b == 1){
		system("cls");
		int n = searchStyle();
		system("cls");
		cloList();
		if(n == 1){			
			printf("�����뵱ǰ���ھ����ţ�\n"); 
			scanf("%d",&Id);
			while(1){
				if(Id>=1&&Id<=25){
					for(i=1;i<=25;i++){
						if(i!=Id){
							dijkstra(Id,i);
						}
					}
					printf("\n\n���س�������������ϵͳ����\n\n");
					getchar();getchar();
					system("cls");
					mainView();
					break;
				}else{
					printf("\n\n�þ��㲻���ڣ�������������\n\n");
					scanf("%d",&Id);
				}
			}
			break;
		}else if(n == 2){
			cloList();
			printf("�����뵱ǰ���ھ������ƣ�\n"); 
			scanf("%s",&name);
			Id = changeToId(name);
			while(1){
					if(Id>=1&&Id<=25){
					for(i=1;i<=25;i++){
						if(i!=Id){
							dijkstra(Id,i);
						}
					}
					printf("\n\n���س�������������ϵͳ����\n\n");
					getchar();getchar();
					system("cls");
					mainView();
					break;
				}else{
					printf("\n\n�þ��㲻���ڣ�������������\n\n");
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
			printf("�����뵱ǰ���ھ����ţ�\n"); 
			scanf("%d",&Id);
			while(1){
				if(Id>=1&&Id<=25){
				    showInformation(Id);
					printf("���س�������������ϵͳ����\n\n");
					getchar();getchar();
					system("cls");
					mainView();
					break;
				}else{
					printf("����ı�Ų����ڣ�����������!\n");
					scanf("%d",&Id); 
				}
			}
		}else if(n == 2){
			printf("�����뾰������:\n");
			scanf("%s",name);
			Id = changeToId(name);
			while(1){
				if(Id>=1&&Id<=25){
				    showInformation(Id);
					printf("���س�������������ϵͳ����\n\n");
					getchar();getchar();
					system("cls");
					mainView();
					break;
				}else{
					printf("����ľ��㲻���ڣ�����������!\n");
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
			printf("��������㾰���ţ�\n");
			scanf("%d",&p);
			printf("\n�������յ㾰���ţ�\n");
			scanf("%d",&q);
			while(1){
				if(p>=1&&p<=25&&q>=1&&q<=25&&p!=q){
				    dijkstra(p,q);
					printf("���س�������������ϵͳ����\n\n");
					getchar();getchar();
					system("cls");
					mainView();
					break;
				}else{
					printf("\n���벻�Ϸ������������룡\n\n");
					printf("��������㾰���ţ�\n");
					scanf("%d",&p);
					printf("\n�������յ㾰���ţ�\n");
					scanf("%d",&q);
				}
			}
		}else if(n == 2){
			printf("��������㾰�����ƣ�\n");
			scanf("%s",name);
			p = changeToId(name);
			printf("\n�������յ㾰�����ƣ�\n");
			scanf("%s",name);
			q = changeToId(name);
			while(1){
				if(p>=1&&p<=25&&q>=1&&q<=25&&p!=q){
				    dijkstra(p,q);
					printf("���س�������������ϵͳ����\n\n");
					getchar();getchar();
					system("cls");
					mainView();
					break;
				}else{
					printf("\n���벻�Ϸ������������룡\n\n");
					printf("��������㾰�����ƣ�\n");
					scanf("%s",name);
					p = changeToId(name);
					printf("\n�������յ㾰�����ƣ�\n");
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
		printf("\n\n\n\t\t����������������룡\n\n\n\n");
		scanf("%d",&b); 
	}
	}
}

void schoolView(){
	printf("\n\n\n\n\n");
	printf("\t\t\t\t    ****************************************************\n");
	printf("\t\t\t\t    *                                                  *\n");
	printf("\t\t\t\t    *     ������ѧԺ����ơ��Ϲ�����λ��λ�ڳ��纺�� *\n");
	printf("\t\t\t\t    *                                                  *\n");
	printf("\t\t\t\t    * ����֮������ʥ��󻡢��ʥ�ź⡢ҽʥ���پ������ *\n");
	printf("\t\t\t\t    *                                                  *\n");
	printf("\t\t\t\t    * ���������ء�����ʷ�Ļ����Ǻ���������             *\n");
	printf("\t\t\t\t    *                                                  *\n");
	printf("\t\t\t\t    *    �Ϲ���һ��ȫ���ƹ�����ͨ����ԺУ  ѧУ����1987*\n");
	printf("\t\t\t\t    *                                                  *\n");
	printf("\t\t\t\t    * �꣬ǰ��Ϊ������ѧ,1993�����Ϊ ������ѧԺ��   *\n");
	printf("\t\t\t\t    *                                                  *\n");
	printf("\t\t\t\t    ****************************************************\n");
	printf("\n\n\n\n\n");
	printf("���س�������������\n");
	getchar();getchar();
	system("cls");
	mainView(); 
} 


void exitView(){
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t��ߡ�ߡ�ߡ�ߡ�ߡ�ߡ�ߡ�\n");
	printf("\t\t\t\t\t���                      ���\n");
	printf("\t\t\t\t\t���  �� л �� �� ʹ ��   ���\n");
	printf("\t\t\t\t\t���                      ���\n");
	printf("\t\t\t\t\t���  ף �� �� �� �� ��   ���\n");
	printf("\t\t\t\t\t���                      ���\n");
	printf("\t\t\t\t\t��ߡ�ߡ�ߡ�ߡ�ߡ�ߡ�ߡ�\n");
	printf("\n\n\n"); 
	
}

void authorView(){
	printf("\n\n\n\n\n");
	printf("\t\t\t\t    ****************************************************\n");
	printf("\t\t\t\t    *                     ������                       *\n");
	printf("\t\t\t\t    *                                                  *\n");
	printf("\t\t\t\t    *                  ������ѧԺ                    *\n");
	printf("\t\t\t\t    *                                                  *\n");
	printf("\t\t\t\t    *              19����������ƶ�3��                 *\n");
	printf("\t\t\t\t    *                                                  *\n");
	printf("\t\t\t\t    *                     ���                         *\n");
	printf("\t\t\t\t    *                                                  *\n");
	printf("\t\t\t\t    ****************************************************\n");
	printf("\n\n\n\n\n");
	printf("���س�������������\n");
	getchar();getchar();
	system("cls");
	mainView(); 
}

int searchStyle(){
	int i;
	system("cls");			//���� 
	printf("\n");
	printf("\t\t\t\t                    *�������ѯ��ʽ*\n\n");
	printf("\t\t\t\t                  1�����뾰���Ų�ѯ\n\n");
	printf("\t\t\t\t                  2�����뾰�����Ʋ�ѯ\n\n");
	printf("\t\t\t\t                  0��������ҳ��\n\n\n\n\n\n\n");
	printf("��ѡ���ѯ��ʽ:");
	scanf("%d",&i);
	return i;
}
