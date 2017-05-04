#include"simsSystem.h"
/*
�û��˺�����ͷ�巨
*/
void headInsertOfUserAccount(pUSER_ACCOUNT* ppHead, pUSER_ACCOUNT user_account) {
	pUSER_ACCOUNT pNew = (pUSER_ACCOUNT)malloc(sizeof(USER_ACCOUNT));
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
void printUserAccount(pUSER_ACCOUNT* ppHead) {
	pUSER_ACCOUNT pCurrent = *ppHead;
	while (pCurrent != NULL) {
		printf("\t\t\t\t%s\t\t%s\t\t%s\n", pCurrent->userName, pCurrent->userPwd, pCurrent->userRole == 0 ? "��ͨ�û�" : "����Ա");
		pCurrent = pCurrent->next;
	}
}
/*
�����û��˺�
���³ɹ�����1������ʧ�ܷ���0
*/
int updateLinkedUserAccount(pUSER_ACCOUNT* ppHead,pUSER_ACCOUNT pUserAccount) {
	pUSER_ACCOUNT pCurrent = *ppHead;
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
int deleteLinkedUserAccount(pUSER_ACCOUNT* ppHead, char* userName) {
	pUSER_ACCOUNT pCurrent = *ppHead;
	pUSER_ACCOUNT pPrevious = *ppHead;
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
�����Ƿ�������˺� ����1������������0
*/
int isListContainUserAccount(pUSER_ACCOUNT* ppHead, char* userName) {
	pUSER_ACCOUNT pCurrent = *ppHead;
	while (pCurrent != NULL) {
		if (strcmp(userName, pCurrent->userName) == 0)
			return 1;
		pCurrent = pCurrent->next;
	}
	return 0;
}
/*
�û���Ϣ����ͷ�巨
*/
void headInsertOfUserInfo(pUSER_INFO* ppHead, pUSER_INFO user_info) {
	pUSER_INFO pNew = (pUSER_INFO)malloc(sizeof(USER_INFO));
	pNew->user_id = user_info->user_id;
	strcpy(pNew->user_name, user_info->user_name);
	pNew->user_course1_score = user_info->user_course1_score;
	pNew->user_course2_score = user_info->user_course2_score;
	pNew->user_course3_score = user_info->user_course3_score;
	pNew->next = NULL;
	if (NULL == *ppHead)
		*ppHead = pNew;
	else {
		pNew->next = *ppHead;
		*ppHead = pNew;
	}
}
/*
��ӡ�û���Ϣ
*/
void printUserInfo(pUSER_INFO* ppHead) {
	pUSER_INFO pCurrent = *ppHead;
	while (pCurrent != NULL) {
		printf("\t\t%d\t\t%s\t\t%5.2f\t\t%5.2f\t\t%5.2f\n", pCurrent->user_id, pCurrent->user_name, pCurrent->user_course1_score, pCurrent->user_course2_score, pCurrent->user_course3_score);
		pCurrent = pCurrent->next;
	}
}
/*
�����û���Ϣ
���ڸø����û�����1�������ڷ���0
*/
int updateLinkedUserInfo(pUSER_INFO* ppHead, pUSER_INFO pUserInfo) {
	pUSER_INFO pCurrent = *ppHead;
	while (pCurrent != NULL) {
		if (pCurrent->user_id == pUserInfo->user_id) {
			strcpy(pCurrent->user_name, pUserInfo->user_name);
			pCurrent->user_course1_score = pUserInfo->user_course1_score;
			pCurrent->user_course2_score = pUserInfo->user_course2_score;
			pCurrent->user_course3_score = pUserInfo->user_course3_score;
			return 1;
		}
		pCurrent = pCurrent->next;
	}
	return 0;
}
/*
ɾ���û���Ϣ  
ɾ���ɹ�����1��ɾ��ʧ�ܷ���0
*/
int deleteLinkedUserInfo(pUSER_INFO* ppHead,int userId) {
	pUSER_INFO pCurrent = *ppHead;
	pUSER_INFO pPrevious = *ppHead;
	if (NULL == pCurrent)
		return 0;
	else if (userId ==(*ppHead)->user_id) {
		*ppHead = pCurrent->next;
		free(pCurrent);
		pCurrent = NULL; 
		return 1;
	}
	else {
		while (pCurrent != NULL)//�嵽�м�
		{
			if (userId == pCurrent->user_id)
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
�����Ƿ�������û� ��������1������������0
*/
int isListContainUserInfo(pUSER_INFO* ppHead, int userId) {
	pUSER_INFO pCurrent = *ppHead;
	while (pCurrent != NULL) {
		if (userId==pCurrent->user_id)
			return 1;
		pCurrent = pCurrent->next;
	}
	return 0;
}