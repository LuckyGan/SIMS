#include "../include/system.h"
#include "../include/accountInfo.h"
#include "../include/linkedList.h"

/*
����Ա �����û��˺�
*/
void addUserAccount(const char* User_Account_File_Name, pUserAccountStruct* ppUser_Account) {
	PRINT_BEGIN;
	printUserAccountTitle();
	printf("\t\t\t\t");
	userAccountStruct user_account;
	scanf("%s %s %d", user_account.userName, user_account.userPwd, &user_account.userRole);
	user_account.next = NULL;
	if (!isListContainUserAccount(ppUser_Account, user_account.userName)) {
		headInsertOfUserAccount(ppUser_Account, &user_account);
		saveUserAccountDataToFile(User_Account_File_Name, ppUser_Account);
		printf("�����ɹ��������˻���ϢΪ:\n");
		serachUserAccount(ppUser_Account);
	}
	else
		printf("------------:����ʧ�ܣ����˻�����\n");
}
/*
����Ա �����û��˺�
*/
void updateUserAccount(const char* User_Account_File_Name, pUserAccountStruct* ppUser_Account) {
	PRINT_BEGIN;
	printUserAccountTitle();
	printf("\t\t\t\t");
	userAccountStruct user_account;
	scanf("%s %s %d", user_account.userName, user_account.userPwd, &user_account.userRole);
	user_account.next = NULL;
	if (updateListUserAccount(ppUser_Account, &user_account)) {
		saveUserAccountDataToFile(User_Account_File_Name, ppUser_Account);
		printf("���³ɹ��������˻���ϢΪ:\n");
		serachUserAccount(ppUser_Account);
	}
	else
		printf("------------:����ʧ�ܣ����˻�������\n");
}
/*
����Ա ɾ���û��˺�
*/
void deleteUserAccount(const char* User_Account_File_Name, pUserAccountStruct* ppUser_Account) {
	PRINT_BEGIN;
	printf("������Ҫɾ�����˻�����:");
	char userName[USER_NAME_LEN];
	scanf("%s", userName);
	if (deleteListUserAccount(ppUser_Account, userName)) {
		saveUserAccountDataToFile(User_Account_File_Name, ppUser_Account);
		printf("ɾ���ɹ��������˻���ϢΪ:\n");
		serachUserAccount(ppUser_Account);
	}
	else
		printf("------------:ɾ��ʧ�ܣ����˻�������\n");

}
/*
����Ա ��ѯ�û��˺�
*/
void serachUserAccount(pUserAccountStruct* ppUser_Account) {
	PRINT_BEGIN;
	printUserAccountTitle();
	printUserAccount(ppUser_Account);
}

/*
��ӡ�û��˺ű���
*/
void printUserAccountTitle() {
	printf("\t\t\t\t����\t\t����\t\t��ɫ\n");
}

/*
�����û��˺������ļ���
*/
void saveUserAccountDataToFile(const char* User_Account_File_Name, pUserAccountStruct* ppUser_Account) {
	FILE* fp = fopen(User_Account_File_Name, "w+");
	if (NULL == fp) {
		perror("fopen");
		return;
	}
	pUserAccountStruct pCurrent = *ppUser_Account;
	int ret;
	while (pCurrent != NULL) {
		ret = fprintf(fp, "\t\t\t\t%s\t\t%s\t\t%d\n", pCurrent->userName, pCurrent->userPwd, pCurrent->userRole);
		if (ret < 0) {
			perror("fprintf");
			return;
		}
		pCurrent = pCurrent->next;
	}
	fclose(fp);
}
