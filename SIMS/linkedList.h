#ifndef LINKED_LIST
#define LINKED_LIST
#include "dataStruct.h"
void headInsertOfUserAccount(pUserAccountStruct*, pUserAccountStruct);//�û��˺�����ͷ�巨
void printUserAccount(pUserAccountStruct*);//��ӡ�û��˺�
int updateListUserAccount(pUserAccountStruct*, pUserAccountStruct);//�����û��˺�
int deleteListUserAccount(pUserAccountStruct*, char*);//ɾ���û��˺�
int isListContainUserAccount(pUserAccountStruct*, char*);//�����Ƿ�������˺� ��������1������������0


void headInsertOfStudentInfo(pStudentInfoStruct*, pStudentInfoStruct);//�û���Ϣ����ͷ�巨
void printStudentInfo(pStudentInfoStruct*);//��ӡ�û���Ϣ
int updateListStudentInfo(pStudentInfoStruct*, pStudentInfoStruct);//�����û���Ϣ
int deleteListStudentInfo(pStudentInfoStruct*, int);//ɾ���û���Ϣ
int isListContainStudentInfo(pStudentInfoStruct*, int);//�����Ƿ�������û� ��������1������������0
#endif