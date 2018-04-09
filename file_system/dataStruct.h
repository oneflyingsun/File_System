#pragma once
#include "define.h"
struct supblock
{
	//unsigned int blockNum;				//the number of the block
	unsigned int size;				//文件系统的盘块数
	unsigned int freeBlock[BLOCKNUM];	//空闲盘块号栈，即用于记录当前可用的空闲盘块编号的栈。
	unsigned int nextFreeBlock;		//当前空闲盘块号数，即在空闲盘块号栈中保存的空闲盘块号的数目。他也可以被视为空闲盘块号栈的指针。
	unsigned int freeBlockNum;			//空闲磁盘i结点编号栈，即记录了当前可用的空闲结点编号的栈。
	unsigned int freeInode[INODENUM];	//空闲磁盘i结点数目，指在磁盘i结点栈中保存的空闲i结点编号的数目，也可以视为当前空闲i结点栈顶的指针。
	unsigned int freeInodeNum;			//空闲盘块数，用于记录整个文件系统中未被分配的盘块个数。
	unsigned int nextFreeInode;		//空闲i结点个数，用于记录整个文件系统中未被分配的节点个数。
	unsigned int lastLogin;	//上次登录时间
	/**注意：
	*如果有新的元素添加，请追加，不要插在数据之间
	**/
};

//node structure in the disk磁盘索引结点
struct finode
{
	int			mode;//文件类型及属性
	long		int	fileSize;
	int			fileLink;//文件连接数 
	char			owner[MAXNAME];//所属用户名
	char			group[GROUPNAME];//所属用户组
	long		int	modifyTime;//修改时间 
	long		int	createTime;//创建时间 
	int			addr[6];//盘块地址数组
	char			black[45];				//凑整，也防止以后数据结构中又有新的东西加入影响程序
};

//node structure in the memory内存索引结点
struct inode
{
	struct					finode finode;//磁盘索引结点结构，保存从磁盘读出的索引结点信息
	struct					inode *parent;//父级内存索引结点指针
	unsigned short int		inodeID;				//the node id
	int						userCount;			//the number of process using the inode
};
//direct structure文件目录项
struct direct
{
	char					directName[DIRECTNAME];
	unsigned short int	inodeID;
};
//the structure of dir目录数据结构
struct dir
{
	int		dirNum;//目录数目 
	struct	direct direct[DIRNUM];//目录项数组
};
//the structure of file
struct file
{
	struct	inode *fInode;
	int		f_curpos;
};
//the structure of user
struct user
{
	char		userName[MAXNAME];
	char		userPwd[MAXPWD];
	char		userGroup[MAXNAME];
};