#ifndef ACCOUNT_INFO
#define ACCOUNT_INFO
#include "dataStruct.h"

void addUserAccount(const char*, pUserAccountStruct*);//����Ա �����û��˺�
void updateUserAccount(const char*, pUserAccountStruct*);//����Ա �����û��˺�
void deleteUserAccount(const char*, pUserAccountStruct*);//����Ա ɾ���û��˺�
void serachUserAccount(pUserAccountStruct*);//����Ա ��ѯ�û��˺�

void saveUserAccountDataToFile(const char*, pUserAccountStruct*);//�����û��˺��������ļ���
void printUserAccountTitle();//��ӡ�û��˺ű���

#endif // ACCOUNT_INFO
