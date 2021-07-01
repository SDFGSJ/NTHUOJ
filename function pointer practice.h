#include <stdio.h>
#include <stdlib.h>

typedef struct{
    void (*func)(void *);
    void *argument;
}Task;
typedef struct{
    int* arr;
    int lower;
    int upper;
}Data;
typedef struct{
    Task **tasks;
    int size;
}Task_List;

void job1(void* argument); // square
void job2(void* argument); // minus
void job3(void* argument); // double
void initTask(Task* task, void(*func)(void*),void* argument);
void executeTasks(Task_List *task_list);
void job1(void* argument) // reverse
{
	int i;
	Data* data=(Data*)argument;
	int low=data->lower;
	int up=data->upper;
	int mid=(low+up)/2;
	for(i=low;i<=mid;i++){
		int temp=data->arr[i];
		data->arr[i]=data->arr[low+up-i];
		data->arr[low+up-i]=temp;
	}
}
void job2(void* argument) // minus
{
	int i;
	Data* data=(Data*)argument;
	int low=data->lower;
	int up=data->upper;
	for(i=low;i<=up;i++){
		data->arr[i]*=-1;
	}
} 
void job3(void* argument) // double
{
	int i;
	Data* data=(Data*)argument;
	int low=data->lower;
	int up=data->upper;
	for(i=low;i<=up;i++){
		data->arr[i]*=2;
	}
}
void initTask(Task* task, void(*func)(void*),void* argument)
{
	task->argument=argument;
	task->func=func;
}
void executeTasks(Task_List *task_list)
{
	int i;
	int size=task_list->size;
	for(i=0;i<size;i++){
		void(*func)(void*)=task_list->tasks[i]->func;
		void *argument=task_list->tasks[i]->argument;
		func(argument);
	}
}
