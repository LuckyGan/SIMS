#include "simsSystem.h"

char* PROJECT_NAME = { "ѧ����Ϣ����ϵͳ" };
char* MANAGER_MENU[9] = { "1. ��ѯѧ����Ϣ" ,"5. ��ѯ�û��˺�","2. ����ѧ����Ϣ" ,"6. �����û��˺�" ,"3. ����ѧ����Ϣ" ,"7. �����û��˺�" ,"4. ɾ��ѧ����Ϣ","8. ɾ���û��˺�",
"9. �˳�" };
char* USER_MENU[3] = { "1. ������ѯ" ,"2. ѧ�Ų�ѯ" ,"3. �˳�" };
/*
��ʼ���˻������ѧ����Ϣ����
*/
void systemInit(const char* User_Account_File_Name,const char* User_Info_File_Name, pUSER_ACCOUNT* ppUser_Account, pUSER_INFO* ppUser_Info) {
	FILE* fp1 = fopen(User_Account_File_Name,"r");
	FILE* fp2 = fopen(User_Info_File_Name, "r");
	if (NULL == fp1 || NULL==fp2) {
		perror("fopen");
		return ;
	}
	USER_ACCOUNT user_account;
	while (fscanf(fp1, "%s %s %d", user_account.userName, user_account.userPwd,&user_account.userRole) != EOF) {
		headInsertOfUserAccount(ppUser_Account, &user_account);
	}
	USER_INFO user_info;
	while (fscanf(fp2, "%d %s %f %f %f", &user_info.user_id, user_info.user_name,&user_info.user_course1_score, &user_info.user_course2_score, &user_info.user_course3_score) != EOF) {
		headInsertOfUserInfo(ppUser_Info, &user_info);
	}
	fclose(fp1);
	fclose(fp2);
}
/*
����ѧ����Ϣ�����ļ���
*/
void saveUserInfoDataToFile(const char* User_Info_File_Name, pUSER_INFO* ppUser_Info) {
	FILE* fp = fopen(User_Info_File_Name, "w+");
	if (NULL == fp) {
		perror("fopen");
		return;
	}
	pUSER_INFO pCurrent = *ppUser_Info;
	int ret;
	while (pCurrent != NULL) {
		ret = fprintf(fp, "\t\t%d\t\t%s\t\t%5.2f\t\t%5.2f\t\t%5.2f\n", pCurrent->user_id, pCurrent->user_name, pCurrent->user_course1_score, pCurrent->user_course2_score, pCurrent->user_course3_score);
		if (ret < 0) {
			perror("fprintf");
			return;
		}
		pCurrent = pCurrent->next;
	}
	fclose(fp);
}
/*
�����û��˺������ļ���
*/
void saveUserAccountDataToFile(const char* User_Account_File_Name,pUSER_ACCOUNT* ppUser_Account) {
	FILE* fp = fopen(User_Account_File_Name, "w+");
	if (NULL == fp) {
		perror("fopen");
		return;
	}
	pUSER_ACCOUNT pCurrent = *ppUser_Account;
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
/*
�жϵ�½�Ƿ�Ϸ�
*/
int isLegalAccount(pUSER_ACCOUNT pUser_Account, char* user_name,char* user_pwd) {
	while (pUser_Account != NULL) {
		if (strcmp(pUser_Account->userName, user_name) == 0 && strcmp(pUser_Account->userPwd, user_pwd) == 0)
			return pUser_Account->userRole;
		pUser_Account = pUser_Account->next;
	}
	return -1;
}
/*
����Ա�˵���ת����
*/
void controlByManager(const char* User_Account_File_Name, const char* User_Info_File_Name, int select, pUSER_ACCOUNT* ppUser_Account, pUSER_INFO* ppUser_Info ) {
	switch (select) {
	case 1:
		//printf("------------:��ѯ�ɹ�������ѧ����ϢΪ:\n");
		serachUserInfo(ppUser_Info);
		break;
	case 2:addUserInfo(User_Info_File_Name,ppUser_Info);
		break;
	case 3:updateUserInfo(User_Info_File_Name,ppUser_Info);
		break;
	case 4:deleteUserInfo(User_Info_File_Name,ppUser_Info);
		break;
	case 5:
		//printf("------------:��ѯ�ɹ��������˻���ϢΪ:\n");
		serachUserAccount(ppUser_Account);
		break;
	case 6:addUserAccount(User_Account_File_Name,ppUser_Account);
		break;
	case 7:updateUserAccount(User_Account_File_Name,ppUser_Account);
		break;
	case 8:deleteUserAccount(User_Account_File_Name,ppUser_Account);
		break;
	case 9:
		break;
	default:
		break;
	}
}
/*
ѧ���˵���ת����
*/
void controlByUser(int select, pUSER_ACCOUNT* ppUser_Account, pUSER_INFO* ppUser_Info) {
	switch (select) {
	case 1:serachStudentInfoByName(ppUser_Info); 
		break;
	case 2:serachStudentInfoById(ppUser_Info);
		break;
	case 3:
		break;
	default:
		break;
	}
}
/*
ѧ��  ͨ��id��ѯѧ����Ϣ
*/
void serachStudentInfoById(pUSER_INFO* ppUser_Info) {
	PRINT_BEGIN;
	printf("������ѧ��ѧ��:");
	int user_id;
	scanf("%d", &user_id);
	pUSER_INFO pCurrent = *ppUser_Info;
	while (pCurrent != NULL) {
		if (pCurrent->user_id == user_id) {
			printf("��ѯ�ɹ�����ѧ����ϢΪ:\n");
			printUserInfoTitle();
			printf("%\t\t%d\t\t%s\t\t%5.2f\t\t%5.2f\t\t%5.2f\n", pCurrent->user_id, pCurrent->user_name, pCurrent->user_course1_score, pCurrent->user_course2_score, pCurrent->user_course3_score);
			return ;
		}
		pCurrent = pCurrent->next;
	}
	printf("------------:��ѯʧ�ܣ���ѧ��������\n");
}
/*
ѧ�� ͨ��Name��ѯѧ����Ϣ
*/
void serachStudentInfoByName(pUSER_INFO* ppUser_Info) {
	PRINT_BEGIN;
	printf("������ѧ������:");
	char user_name[USER_NAME_LEN];
	scanf("%s", user_name);
	pUSER_INFO pCurrent = *ppUser_Info;
	while (pCurrent != NULL) {
		if (strcmp(pCurrent->user_name, user_name)==0) {
			printf("��ѯ�ɹ�����ѧ����ϢΪ:\n");
			printUserInfoTitle();
			printf("\t\t%d\t\t%s\t\t%5.2f\t\t%5.2f\t\t%5.2f\n", pCurrent->user_id, pCurrent->user_name, pCurrent->user_course1_score, pCurrent->user_course2_score, pCurrent->user_course3_score);
			return;
		}
		pCurrent = pCurrent->next;
	}
	printf("------------:��ѯʧ�ܣ���ѧ��������\n");
}
/*
����Ա �����û���Ϣ
*/
void addUserInfo(const char* User_Info_File_Name, pUSER_INFO* ppUser_Info) {
	PRINT_BEGIN;
	printUserInfoTitle();
	printf("\t\t");
	USER_INFO user_info;
	scanf("%d %s %f %f %f", &user_info.user_id, user_info.user_name, &user_info.user_course1_score, &user_info.user_course2_score, &user_info.user_course3_score);
	user_info.next = NULL;
	if (!isListContainUserInfo(ppUser_Info, user_info.user_id)) {
		headInsertOfUserInfo(ppUser_Info, &user_info);
		saveUserInfoDataToFile(User_Info_File_Name, ppUser_Info);
		printf("�����ɹ�������ѧ����ϢΪ:\n");
		serachUserInfo(ppUser_Info);
	}
	else
		printf("------------:����ʧ�ܣ���ѧ������\n");
}
/*
����Ա �����û���Ϣ
*/
void updateUserInfo(const char* User_Info_File_Name,pUSER_INFO* ppUser_Info) {
	PRINT_BEGIN;
	printUserInfoTitle();
	printf("\t\t");
	USER_INFO user_info;
	scanf("%d %s %f %f %f", &user_info.user_id, user_info.user_name, &user_info.user_course1_score,&user_info.user_course2_score,&user_info.user_course3_score);
	user_info.next = NULL;
	if (updateLinkedUserInfo(ppUser_Info, &user_info)) {
		saveUserInfoDataToFile(User_Info_File_Name, ppUser_Info);
		printf("���³ɹ�������ѧ����ϢΪ:\n");
		serachUserInfo(ppUser_Info);
	}
	else
		printf("------------:����ʧ�ܣ���ѧ��������\n");
}
/*
����Ա ɾ���û���Ϣ
*/
void deleteUserInfo(const char* User_Info_File_Name, pUSER_INFO* ppUser_Info) {
	PRINT_BEGIN;
	printf("������Ҫɾ����ѧ��ѧ��:");
	int userId;
	scanf("%d", &userId);
	if (deleteLinkedUserInfo(ppUser_Info, userId)) {
		saveUserInfoDataToFile(User_Info_File_Name, ppUser_Info);
		printf("ɾ���ɹ�������ѧ����ϢΪ:\n");
		serachUserInfo(ppUser_Info);
	}else
		printf("------------:ɾ��ʧ�ܣ���ѧ��������\n");

}
/*
����Ա ��ѯ�û���Ϣ
*/
void serachUserInfo(pUSER_INFO* ppUser_Info) {
	PRINT_BEGIN;
	printUserInfoTitle();
	printUserInfo(ppUser_Info);
}
/*
����Ա �����û��˺�
*/
void addUserAccount(const char* User_Account_File_Name, pUSER_ACCOUNT* ppUser_Account) {
	PRINT_BEGIN;
	printUserAccountTitle();
	printf("\t\t\t\t");
	USER_ACCOUNT user_account;
	scanf("%s %s %d", user_account.userName, user_account.userPwd, &user_account.userRole);
	user_account.next = NULL;
	if (!isListContainUserAccount(ppUser_Account, user_account.userName)) {
		headInsertOfUserAccount(ppUser_Account, &user_account);
		saveUserAccountDataToFile(User_Account_File_Name, ppUser_Account);
		printf("�����ɹ��������˻���ϢΪ:\n");
		serachUserAccount(ppUser_Account);
	}else
		printf("------------:����ʧ�ܣ����˻�����\n");
}
/*
����Ա �����û��˺�
*/
void updateUserAccount(const char* User_Account_File_Name, pUSER_ACCOUNT* ppUser_Account) {
	PRINT_BEGIN;
	printUserAccountTitle();
	printf("\t\t\t\t");
	USER_ACCOUNT user_account;
	scanf("%s %s %d", user_account.userName, user_account.userPwd, &user_account.userRole);
	user_account.next = NULL;
	if (updateLinkedUserAccount(ppUser_Account, &user_account)) {
		saveUserAccountDataToFile(User_Account_File_Name, ppUser_Account);
		printf("���³ɹ��������˻���ϢΪ:\n");
		serachUserAccount(ppUser_Account);
	}else
		printf("------------:����ʧ�ܣ����˻�������\n");
}
/*
����Ա ɾ���û��˺�
*/
void deleteUserAccount(const char* User_Account_File_Name, pUSER_ACCOUNT* ppUser_Account) {
	PRINT_BEGIN;
	printf("������Ҫɾ�����˻�����:");
	char userName[USER_NAME_LEN];
	scanf("%s", userName);
	if (deleteLinkedUserAccount(ppUser_Account, userName)) {
		saveUserAccountDataToFile(User_Account_File_Name, ppUser_Account);
		printf("ɾ���ɹ��������˻���ϢΪ:\n");
		serachUserAccount(ppUser_Account);
	}else
		printf("------------:ɾ��ʧ�ܣ����˻�������\n");

}
/*
����Ա ��ѯ�û��˺�
*/
void serachUserAccount(pUSER_ACCOUNT* ppUser_Account) {
	PRINT_BEGIN;
	printUserAccountTitle();
	printUserAccount(ppUser_Account);
}
/*
��ӡ����
*/
void printTitle() {
	for (int k = 0; k < TITLE_WID * 2 + 3; ++k) {
		if (k == 0 || k == TITLE_WID * 2 + 2) {
			for (int i = 0; i < TITLE_LEN; ++i)
				printf("-");
		}
		else if (k >= 1 && k < 1 + TITLE_WID || k >= TITLE_WID + 2 && k <TITLE_WID * 2 + 2) {
			for (int j = 0; j < TITLE_LEN; ++j) {
				if (j == 0 || j == 1 || j == 2 || j == TITLE_LEN - 1 || j == TITLE_LEN - 2 || j == TITLE_LEN - 3)
					printf("-");
				else
					printf(" ");
			}
		}
		else {
			for (int j = 0; j < TITLE_LEN; ++j) {
				if (j == 0 || j == 1 || j == 2 || j == TITLE_LEN - 1 || j == TITLE_LEN - 2 || j == TITLE_LEN - 3)
					printf("-");
				else if (j<TITLE_LEN / 2 - 7 || j>TITLE_LEN / 2 + 8)
					printf(" ");
				else
					printf("%c", PROJECT_NAME[j - (TITLE_LEN / 2 - 7)]);
			}
		}
		printf("\n");
	}
}
/*
��ӡѧ���˵�
*/
void printUserMenu() {
	for (int i = 0; i < 3; ++i) {
		printSpace(TITLE_LEN / 2-6);
		printf(USER_MENU[i]);
		printf("\n");
	}
}
/*
��ӡ��ʦ�˵�
*/
void printManagerMenu() {
	for (int i = 0; i < 8;) {
		printSpace(TITLE_LEN / 4);
		printf(MANAGER_MENU[i]);
		printSpace(TITLE_LEN / 4);
		++i;
		printf(MANAGER_MENU[i]);
		printf("\n");
		++i;
	}
	printSpace(TITLE_LEN / 2-3);
	printf(MANAGER_MENU[8]);
	printf("\n");
}
/*
��½
*/
void printLogin(char* user_name, char* user_pwd) {
	printSpace(TITLE_LEN / 2 - 4);
	printf("�û���:");
	scanf("%s", user_name);
	rewind(stdin);
	printSpace(TITLE_LEN / 2 - 6);
	printf("�û�����:");
	char c;
	int index = 0;
	while ((c = getch()) != '\r') {
		if (c == '\b')
		{
			if (index > 0) {//���ֻ��ɾ��û���ַ�  
				putchar('\b');
				putchar(' ');
				putchar('\b');
				index--;
			}
		}
		if (!(c>='a'&&c<='z'||c>='A'&&c<='Z'||c>='0'&&c<='9'||c=='_'))//����ֻ֧�ִ�Сд��ĸ�����ֺ��»���    ��bug 
			continue;
		putchar('*');
		user_pwd[index++] = c;
	}
	user_pwd[index] = '\0';
	printf("\n");
}
/*
��ӡ�ո�
*/
void printSpace(int length) {
	for (int j = 0; j < length; ++j)
		printf(" ");
}
/*
��ӡѧ����Ϣ����
*/
void printUserInfoTitle() {
	printf("\t\tѧ��\t\t����\t\t��Ŀһ\t\t��Ŀ��\t\t��Ŀ��\n");
}
/*
��ӡ�û��˺ű���
*/
void printUserAccountTitle() {
	printf("\t\t\t\t����\t\t����\t\t��ɫ\n");
}