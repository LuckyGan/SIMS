#ifndef __DATA_STRUCT_H__
#define __DATA_STRUCT_H__
#include "constInfo.h"

typedef struct userAccountStruct {//�û��˺Žṹ��
	char userName[USER_NAME_LEN];
	char userPwd[USER_PWD_LEN];
	int userRole;
	struct userAccountStruct* next;
}userAccountStruct, *pUserAccountStruct;
typedef struct studentInfoStruct {//ѧ����Ϣ�ṹ��
	int userId;
	char userName[USER_NAME_LEN];
	float userCourse1Score;
	float userCourse2Score;
	float userCourse3Score;
	struct studentInfoStruct* next;
}studentInfoStruct, *pStudentInfoStruct;

#endif // DATA_STRUCT

