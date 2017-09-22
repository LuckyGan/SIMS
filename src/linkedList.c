#include "../include/linkedList.h"
/*
�û��˺�����ͷ�巨
*/
void headInsertOfUserAccount(pUserAccountStruct* ppHead, pUserAccountStruct user_account) {
	pUserAccountStruct pNew = (pUserAccountStruct)malloc(sizeof(userAccountStruct));
	strcpy(pNew->userName ,user_account->userName);
	strcpy(pNew->userPwd ,user_account->userPwd);
	pNew->userRole = user_account->userRole;
	pNew->next = NULL;
	if (NULL == *ppHead)
		*ppHead = pNew;
	else {
		pNew->next = *ppHead;
		*ppHead = pNew;
	}
}
/*
��ӡ�û��˺�
*/
void printUserAccount(pUserAccountStruct* ppHead) {
	pUserAccountStruct pCurrent = *ppHead;
	while (pCurrent != NULL) {
		printf("\t\t\t\t%s\t\t%s\t\t%s\n", pCurrent->userName, pCurrent->userPwd, pCurrent->userRole == 0 ? "��ͨ�û�" : "����Ա");
		pCurrent = pCurrent->next;
	}
}
/*
�����û��˺�
���³ɹ�����1������ʧ�ܷ���0
*/
int updateListUserAccount(pUserAccountStruct* ppHead,pUserAccountStruct pUserAccount) {
	pUserAccountStruct pCurrent = *ppHead;
	while (pCurrent != NULL) {
		if (strcmp(pCurrent->userName,pUserAccount->userName)==0) {
			strcpy(pCurrent->userPwd, pUserAccount->userPwd);
			pCurrent->userRole = pUserAccount->userRole;
			return 1;
		}
		pCurrent = pCurrent->next;
	}
	return 0;
}
/*
ɾ���û��˺�
ɾ���ɹ�����1��ɾ��ʧ�ܷ���0
*/
int deleteListUserAccount(pUserAccountStruct* ppHead, char* userName) {
	pUserAccountStruct pCurrent = *ppHead;
	pUserAccountStruct pPrevious = *ppHead;
	if (NULL == pCurrent)
		return 0;
	else if (strcmp(userName, (*ppHead)->userName) == 0) {
		*ppHead = pCurrent->next;
		free(pCurrent);//�ͷŶ�Ӧ�ڵ��ڴ�
		pCurrent = NULL;  //��free�Ժ�û����ΪNULL��ָ���ΪҰָ��
		return 1;
	}
	else {
		while (pCurrent != NULL)//�嵽�м�
		{
			if (strcmp(userName, pCurrent->userName) == 0)
			{
				pPrevious->next = pCurrent->next;
				return 1;
			}
			pPrevious = pCurrent;//����ԭ��λ��
			pCurrent = pCurrent->next;//ָ����һ���ڵ�
		}
		free(pCurrent);//�ͷŶ�Ӧ�ڵ��ڴ�
		pCurrent = NULL;  //��free�Ժ�û����ΪNULL��ָ���ΪҰָ��
	}
	return 0;
}
/*
�����Ƿ�������˺� 
����1������������0
*/
int isListContainUserAccount(pUserAccountStruct* ppHead, char* userName) {
	pUserAccountStruct pCurrent = *ppHead;
	while (pCurrent != NULL) {
		if (strcmp(userName, pCurrent->userName) == 0)
			return 1;
		pCurrent = pCurrent->next;
	}
	return 0;
}
/*
ѧ����Ϣ����ͷ�巨
*/
void headInsertOfStudentInfo(pStudentInfoStruct* ppHead, pStudentInfoStruct user_info) {
	pStudentInfoStruct pNew = (pStudentInfoStruct)malloc(sizeof(studentInfoStruct));
	pNew->userId = user_info->userId;
	strcpy(pNew->userName, user_info->userName);
	pNew->userCourse1Score = user_info->userCourse1Score;
	pNew->userCourse2Score = user_info->userCourse2Score;
	pNew->userCourse3Score = user_info->userCourse3Score;
	pNew->next = NULL;
	if (NULL == *ppHead)
		*ppHead = pNew;
	else {
		pNew->next = *ppHead;
		*ppHead = pNew;
	}
}
/*
��ӡѧ����Ϣ
*/
void printStudentInfo(pStudentInfoStruct* ppHead) {
	pStudentInfoStruct pCurrent = *ppHead;
	while (pCurrent != NULL) {
		printf("\t\t%d\t\t%s\t\t%5.2f\t\t%5.2f\t\t%5.2f\n", pCurrent->userId, pCurrent->userName, pCurrent->userCourse1Score, pCurrent->userCourse2Score, pCurrent->userCourse3Score);
		pCurrent = pCurrent->next;
	}
}
/*
����ѧ����Ϣ
���ڸø����û�����1�������ڷ���0
*/
int updateListStudentInfo(pStudentInfoStruct* ppHead, pStudentInfoStruct pUserInfo) {
	pStudentInfoStruct pCurrent = *ppHead;
	while (pCurrent != NULL) {
		if (pCurrent->userId == pUserInfo->userId) {
			strcpy(pCurrent->userName, pUserInfo->userName);
			pCurrent->userCourse1Score = pUserInfo->userCourse1Score;
			pCurrent->userCourse2Score = pUserInfo->userCourse2Score;
			pCurrent->userCourse3Score = pUserInfo->userCourse3Score;
			return 1;
		}
		pCurrent = pCurrent->next;
	}
	return 0;
}
/*
ɾ��ѧ����Ϣ  
ɾ���ɹ�����1��ɾ��ʧ�ܷ���0
*/
int deleteListStudentInfo(pStudentInfoStruct* ppHead,int userId) {
	pStudentInfoStruct pCurrent = *ppHead;
	pStudentInfoStruct pPrevious = *ppHead;
	if (NULL == pCurrent)
		return 0;
	else if (userId ==(*ppHead)->userId) {
		*ppHead = pCurrent->next;
		free(pCurrent);
		pCurrent = NULL; 
		return 1;
	}
	else {
		while (pCurrent != NULL)//�嵽�м�
		{
			if (userId == pCurrent->userId)
			{
				pPrevious->next = pCurrent->next;
				return 1;
			}
			pPrevious = pCurrent;//����ԭ��λ��
			pCurrent = pCurrent->next;//ָ����һ���ڵ�
		}
		free(pCurrent);
		pCurrent = NULL;  
	}
	return 0;
}
/*
�����Ƿ������ѧ�� 
��������1������������0
*/
int isListContainStudentInfo(pStudentInfoStruct* ppHead, int userId) {
	pStudentInfoStruct pCurrent = *ppHead;
	while (pCurrent != NULL) {
		if (userId==pCurrent->userId)
			return 1;
		pCurrent = pCurrent->next;
	}
	return 0;
}
