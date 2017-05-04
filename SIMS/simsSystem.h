#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#define TITLE_LEN 100
#define TITLE_WID 2
#define USER_INFO_TITLE_BEGIN TITLE_LEN / 8
#define USER_ACCOUNT_TITLE_BEGIN TITLE_LEN / 3
#define USER_NAME_LEN 20
#define USER_PWD_LEN 20
#define PRINT_BEGIN {system("cls");printTitle();}

typedef struct user_account_tag {//�û��˺Žṹ��
	char userName[USER_NAME_LEN];
	char userPwd[USER_PWD_LEN];
	int userRole;
	struct user_account_tag* next;
}USER_ACCOUNT, *pUSER_ACCOUNT;

typedef struct user_info_tag {//�û���Ϣ�ṹ��
	int user_id;
	char user_name[USER_NAME_LEN];
	float user_course1_score;
	float user_course2_score;
	float user_course3_score;
	struct user_info_tag* next;
}USER_INFO, *pUSER_INFO;

char* PROJECT_NAME;
char* MANAGER_MENU[9];
char* USER_MENU[3];

void headInsertOfUserAccount(pUSER_ACCOUNT*, pUSER_ACCOUNT);//�û��˺�����ͷ�巨
void printUserAccount(pUSER_ACCOUNT*);//��ӡ�û��˺�
int updateLinkedUserAccount(pUSER_ACCOUNT*, pUSER_ACCOUNT);//�����û��˺�
int deleteLinkedUserAccount(pUSER_ACCOUNT*, char*);//ɾ���û��˺�
int isListContainUserAccount(pUSER_ACCOUNT*, char*);//�����Ƿ�������˺� ��������1������������0


void headInsertOfUserInfo(pUSER_INFO*, pUSER_INFO);//�û���Ϣ����ͷ�巨
void printUserInfo(pUSER_INFO*);//��ӡ�û���Ϣ
int updateLinkedUserInfo(pUSER_INFO*, pUSER_INFO);//�����û���Ϣ
int deleteLinkedUserInfo(pUSER_INFO*, int);//ɾ���û���Ϣ
int isListContainUserInfo(pUSER_INFO*, int);//�����Ƿ�������û� ��������1������������0

void systemInit(const char*, const char*, pUSER_ACCOUNT*, pUSER_INFO*);//��ʼ���û���Ϣ������û��˺�����
void saveUserInfoDataToFile(const char*, pUSER_INFO*);//����ѧ����Ϣ�����ļ���
void saveUserAccountDataToFile(const char*, pUSER_ACCOUNT*);//�����û��˺������ļ���
void printTitle();//��ӡ����
void printUserMenu();//��ӡѧ���˵�
void printManagerMenu();//��ӡ��ʦ�˵�
void printLogin(char*, char*);//��½

int isLegalAccount(pUSER_ACCOUNT, char*, char*);//�жϵ�½�Ƿ�Ϸ�
void controlByManager(const char*, const char*, int, pUSER_ACCOUNT* ppUser_Account, pUSER_INFO* ppUser_Info);//����Ա�˵���ת����
void controlByUser(int, pUSER_ACCOUNT* ppUser_Account, pUSER_INFO* ppUser_Info);//ѧ���˵���ת����
void printUserInfoTitle();//��ӡѧ����Ϣ����
void printUserAccountTitle();//��ӡ�û��˺ű���
void printSpace(int);//��ӡ�ո�

void serachStudentInfoById(pUSER_INFO*);//ѧ��  ͨ��id��ѯѧ����Ϣ
void serachStudentInfoByName(pUSER_INFO*);//ѧ��  ͨ��id��ѯѧ����Ϣ

void addUserInfo(const char*, pUSER_INFO*);//����Ա ����ѧ����Ϣ
void updateUserInfo(const char*, pUSER_INFO*);//����Ա ����ѧ����Ϣ
void deleteUserInfo(const char*, pUSER_INFO*);//����Ա ɾ��ѧ����Ϣ
void serachUserInfo(pUSER_INFO*);//����Ա ��ѯѧ����Ϣ

void addUserAccount(const char*, pUSER_ACCOUNT*);//����Ա �����û��˺�
void updateUserAccount(const char*, pUSER_ACCOUNT*);//����Ա �����û��˺�
void deleteUserAccount(const char*, pUSER_ACCOUNT*);//����Ա ɾ���û��˺�
void serachUserAccount(pUSER_ACCOUNT*);//����Ա ��ѯ�û��˺�