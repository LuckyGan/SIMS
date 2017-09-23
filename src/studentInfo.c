#include "../include/system.h"
#include "../include/studentInfo.h"
#include "../include/linkedList.h"

/*
 *ѧ��  ͨ��id��ѯѧ����Ϣ
 */
void serachStudentInfoById(pStudentInfoStruct* ppUser_Info) {
	PRINT_BEGIN;
	printf("������ѧ��ѧ��:");
	int user_id;
	scanf("%d", &user_id);
	pStudentInfoStruct pCurrent = *ppUser_Info;
	while (pCurrent != NULL) {
		if (pCurrent->userId == user_id) {
			printf("��ѯ�ɹ�����ѧ����ϢΪ:\n");
			printStudentInfoTitle();
			printf("\t\t%d\t\t%s\t\t%5.2f\t\t%5.2f\t\t%5.2f\n", pCurrent->userId, pCurrent->userName, pCurrent->userCourse1Score, pCurrent->userCourse2Score, pCurrent->userCourse3Score);
			return;
		}
		pCurrent = pCurrent->next;
	}
	printf("------------:��ѯʧ�ܣ���ѧ��������\n");
}

/*
 *ѧ�� ͨ��Name��ѯѧ����Ϣ
 */
void serachStudentInfoByName(pStudentInfoStruct* ppUser_Info) {
	PRINT_BEGIN;
	printf("������ѧ������:");
	char user_name[USER_NAME_LEN];
	scanf("%s", user_name);
	pStudentInfoStruct pCurrent = *ppUser_Info;
	while (pCurrent != NULL) {
		if (strcmp(pCurrent->userName, user_name) == 0) {
			printf("��ѯ�ɹ�����ѧ����ϢΪ:\n");
			printStudentInfoTitle();
			printf("\t\t%d\t\t%s\t\t%5.2f\t\t%5.2f\t\t%5.2f\n", pCurrent->userId, pCurrent->userName, pCurrent->userCourse1Score, pCurrent->userCourse2Score, pCurrent->userCourse3Score);
			return;
		}
		pCurrent = pCurrent->next;
	}
	printf("------------:��ѯʧ�ܣ���ѧ��������\n");
}

/*
 *����Ա ����ѧ����Ϣ
 */
void addStudentInfo(const char* User_Info_File_Name, pStudentInfoStruct* ppUser_Info) {
	PRINT_BEGIN;
	printStudentInfoTitle();
	printf("\t\t");
	studentInfoStruct user_info;
	scanf("%d %s %f %f %f", &user_info.userId, user_info.userName, &user_info.userCourse1Score, &user_info.userCourse2Score, &user_info.userCourse3Score);
	user_info.next = NULL;
	if (!isListContainStudentInfo(ppUser_Info, user_info.userId)) {
		headInsertOfStudentInfo(ppUser_Info, &user_info);
		saveStudentInfoDataToFile(User_Info_File_Name, ppUser_Info);
		printf("�����ɹ�������ѧ����ϢΪ:\n");
		serachStudentInfo(ppUser_Info);
	}
	else
		printf("------------:����ʧ�ܣ���ѧ������\n");
}

/*
 *����Ա ����ѧ����Ϣ
 */
void updateStudentInfo(const char* User_Info_File_Name, pStudentInfoStruct* ppUser_Info) {
	PRINT_BEGIN;
	printStudentInfoTitle();
	printf("\t\t");
	studentInfoStruct user_info;
	scanf("%d %s %f %f %f", &user_info.userId, user_info.userName, &user_info.userCourse1Score, &user_info.userCourse2Score, &user_info.userCourse3Score);
	user_info.next = NULL;
	if (updateListStudentInfo(ppUser_Info, &user_info)) {
		saveStudentInfoDataToFile(User_Info_File_Name, ppUser_Info);
		printf("���³ɹ�������ѧ����ϢΪ:\n");
		serachStudentInfo(ppUser_Info);
	}
	else
		printf("------------:����ʧ�ܣ���ѧ��������\n");
}

/*
 *����Ա ɾ��ѧ����Ϣ
 */
void deleteStudentInfo(const char* User_Info_File_Name, pStudentInfoStruct* ppUser_Info) {
	PRINT_BEGIN;
	printf("������Ҫɾ����ѧ��ѧ��:");
	int userId;
	scanf("%d", &userId);
	if (deleteListStudentInfo(ppUser_Info, userId)) {
		saveStudentInfoDataToFile(User_Info_File_Name, ppUser_Info);
		printf("ɾ���ɹ�������ѧ����ϢΪ:\n");
		serachStudentInfo(ppUser_Info);
	}
	else
		printf("------------:ɾ��ʧ�ܣ���ѧ��������\n");

}

/*
 *����Ա ��ѯѧ����Ϣ
 */
void serachStudentInfo(pStudentInfoStruct* ppUser_Info) {
	PRINT_BEGIN;
	printStudentInfoTitle();
	printStudentInfo(ppUser_Info);
}

/*
 *����ѧ����Ϣ�����ļ���
 */
void saveStudentInfoDataToFile(const char* User_Info_File_Name, pStudentInfoStruct* ppUser_Info) {
	FILE* fp = fopen(User_Info_File_Name, "w+");
	if (NULL == fp) {
		perror("fopen");
		return;
	}
	pStudentInfoStruct pCurrent = *ppUser_Info;
	int ret;
	while (pCurrent != NULL) {
		ret = fprintf(fp, "\t\t%d\t\t%s\t\t%5.2f\t\t%5.2f\t\t%5.2f\n", pCurrent->userId, pCurrent->userName, pCurrent->userCourse1Score, pCurrent->userCourse2Score, pCurrent->userCourse3Score);
		if (ret < 0) {
			perror("fprintf");
			return;
		}
		pCurrent = pCurrent->next;
	}
	fclose(fp);
}

/*
 *��ӡѧ����Ϣ����
 */
void printStudentInfoTitle() {
	printf("\t\tѧ��\t\t����\t\t��Ŀһ\t\t��Ŀ��\t\t��Ŀ��\n");
}
