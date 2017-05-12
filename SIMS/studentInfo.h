#ifndef STUDENT_INFO
#define STUDENT_INFO
#include "dataStruct.h"

void addStudentInfo(const char*, pStudentInfoStruct*);//����Ա ����ѧ����Ϣ
void updateStudentInfo(const char*, pStudentInfoStruct*);//����Ա ����ѧ����Ϣ
void deleteStudentInfo(const char*, pStudentInfoStruct*);//����Ա ɾ��ѧ����Ϣ
void serachStudentInfo(pStudentInfoStruct*);//����Ա ��ѯѧ����Ϣ
void serachStudentInfoById(pStudentInfoStruct*);//ѧ��  ͨ��id��ѯѧ����Ϣ
void serachStudentInfoByName(pStudentInfoStruct*);//ѧ��  ͨ��id��ѯѧ����Ϣ

void saveStudentInfoDataToFile(const char*, pStudentInfoStruct*);//����ѧ����Ϣ�����ļ���
void printStudentInfoTitle();//��ӡѧ����Ϣ����

#endif
