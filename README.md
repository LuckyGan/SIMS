# Student Information Management System(学生信息管理系统)

1. 系统功能描述	
  系统管理学生的课程信息，提供账户管理和学生信息管理两大功能	
  提供的功能有:	
	1）学生信息的查询、修改、增加、删除	
	2）账户信息的查询、修改、增加、删除	
  登录系统的账户分为管理员账户和普通用户	
  	1）普通用户只具有查询学生信息的功能	
  	2）管理员用户具有系统的所有功能	
  主要的数据结构有：链表(存储账户链表、学生信息链表)	
  系统数据存储在文件中：	
  	1）USER_ACCOUNT.txt  存放用户账户信息	
  	2）USER_INFO.txt     存放学生信息	
2. 系统模块设计	
  1) 预处理模块	
	系统在启动时自动到USER_ACCOUNT.txt加载账户信息，到USER_INFO.txt加载学生信息	
  2）登陆模块	
	用户登录时，需要输入用户名和密码，输入密码时，用*代表用户当前输入的内容	
	用户输完用户名和密码后，系统自动拿这些输入信息和内存中的用户名和密码匹配。匹配成功，则进入系统菜单界面；匹配不成功，则重新进入登陆模块	
  3）系统功能菜单显示	
    根据用户名的权限不同（0：普通用户 1：管理员用户）显示不同的功能界面	
    普通用户只能查询学生信息，可以按姓名查询（按1）和按学号查询（按2）	
    管理员用户能对学生信息进行查询（按1）、增加（按2）、更新（按3）、删除（按4）	
                对用户账号进行查询（按5）、增加（按6）、更新（按7）、删除（按8）	
	
	
	

