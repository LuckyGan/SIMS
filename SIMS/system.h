#ifndef SYSTEM
#define SYSTEM

#include "dataStruct.h"
#define PRINT_BEGIN {system("cls");printSystemTitle();}

void systemInit(const char*, const char*, pUserAccountStruct*, pStudentInfoStruct*);//��ʼ���û���Ϣ������û��˺�����

int isLegalAccount(pUserAccountStruct, char*, char*);//�жϵ�½�Ƿ�Ϸ�
void printSystemTitle();//��ӡ����
void printLogin(char*, char*);//��½

void controlByManager(const char*, const char*, int, pUserAccountStruct* ppUser_Account, pStudentInfoStruct* ppUser_Info);//����Ա�˵���ת����
void controlByStudent(int, pStudentInfoStruct* ppUser_Info);//ѧ���˵���ת����

void printSpace(int);//��ӡ�ո�
void printStudentMenu();//��ӡѧ���˵�
void printManagerMenu();//��ӡ��ʦ�˵�
#endif