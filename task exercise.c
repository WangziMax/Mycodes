/*任务分为运行结束任务和无线循环任务
/*void Run_to_end_Task(void)
{
	Step 1: Initialize application
	Step 2: Create endless loop tasks
	Step 3: Create kernel objects
	Step 4: Delete or suspend this task
}
 我们一般使用return来使函数返回就可以删除调用的任务，一遍其他任务能够得到cpu */

/*void ContinuousLoopTask(void)
{
	Initialization code

	Loop Forever
	{
		main loop
		make one or more blocking calls
	}
} 
在循环代码中，至少需要一处代码可以使任务暂时放弃CPU，只有这样才有可能使低优先级的任务能够得到CPU，
然后开始执行，信号量的使用就是完成这个功能 */

/* 多任务应用例程 
该任务穿件两个任务模拟一个数据同步收集系统， 
Send Task 每两秒释放一次信号量dataSemId，用来模拟收到数据，
Receive Task 接受信号量datdaSemId，然后做相应的处理。 */

/* 头文件 */ 
#include "vxworks.h"
#include "stdio.h"
#include "stdlib.h"
#include "taskLib.h"
#include "sysLib.h"

/* 宏定义 */
#define STACK_SIZE 2000			/* 任务堆栈大小为2000bytes */

/* 全局变量 */
SEM_ID dataSemId;				/* 同步信号量 */
int tidSend;					/* Send Task任务id */
int tidReceive;					/* Receive Task任务id */

/* 函数声明 */
void progStart(void);
void taskSend(void);
void raskReceive(void);
void SendInit(void);
void ReceiveInit(void);
void progStop(void);

/**********************************************************************************************
* progStart - start 程序
* 负责创建Send Task和Recieve Task，并开始运行
* RETURNS： N/A
*/
void progStart(void)
{
	/* 创建信号量 */
	dataSemId = semBCreate(SEM_QFIFO, SEM_EMPTY);

	/* 创建任务*/
	tidSend = taskSpawn ("tSend", 200, 0 ,STACK_SIZE,
							(FUNCPTER)taskSend,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	tidReceive = taskSpawn ("tReceive", 220, 0 ,STACK_SIZE,
							(FUNCPTER)taskReceive,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	return;
}

/**********************************************************************************
* taskSend - 发送数据任务
* 每两秒钟释放一次信号量dataSemId，用来模拟收到的数据
*/
void taskSend(void)
{
	/* Send Task的初始化 */
	SendInit（）；

	/* 主循环 */
	while(1)
	{
		/* 任务延时两秒 */
		taskDelay(sysClkRateGet() * 2);
		/* 释放信号量用来表示收到数据 */
		semGive(dataSemId);
	}

	return;
}

/**********************************************************************************
* taskReceive - 接受数据任务
* 等待信号量 dataSemId，用来判断是否收到数据 
*/
void taskReceive(void)
{
	/* Receive Task的初始化 */
	ReceiveInit();

	/* 主循环 */
	while(1)
	{
		/* 等待信号量（收数据） */
		semTake(dataSemId, WAIT_FOREVER);
		printf("\nReceive a data");
	}

	return;
}

/************************************************************************************
* SendInit - 初始化 Send Task
* 初始化Send Task
*/
void SendInit(void)
{
	/* 初始化代码 */
	printf("\nInitial Send Task");
	return;
}

/************************************************************************************
* ReceiveInit - 初始化 Receive Task
* 初始化Receive Task
*/
void ReceiveInit(void)
{
	/* 初始化代码 */
	printf("\nInitial Receive Task");
	return;
}

/************************************************************************************
* progStop - 终止程序运行
* 删除信号量，删除所有任务，终止程序运行。
*/
void progStop(void)
{
	/* 删除信号量 */
	semDelete(dataSemId);

	/* 删除所有信号量 */
	taskDelete(tidSend);
	taskDelete(tidReceive);

	printf("The End\n");

	return;
}