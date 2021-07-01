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

int global_array[25];
Task_List *task_list;

void job1(void* argument); // square
void job2(void* argument); // minus
void job3(void* argument); // double
void initTask(Task* task, void(*func)(void*),void* argument);
void executeTasks(Task_List *task_list);

int main(void){
    int n,i,upper, lower, method;
    // initial global_array
    for(i=0; i<25; ++i){
        global_array[i] = i+1;
    }
    scanf("%d", &n);	//n個task 
    task_list = (Task_List*)malloc(sizeof(Task_List));
    task_list->tasks = (Task**)malloc(sizeof(Task*)*n);	//挖一個一維task總表 
    task_list->size = n;
    for(i=0; i<n; ++i){
        scanf("%d%d%d",&method, &lower, &upper);
        Task *task = (Task*)malloc(sizeof(Task));
        Data *data = (Data*)malloc(sizeof(Data));
        data->arr = global_array;
        data->lower = lower;
        data->upper = upper;
        switch(method){
            case 0:
                initTask(task, job1, data);
                break;
            case 1:
                initTask(task, job2, data);
                break;
            case 2:
                initTask(task, job3, data);
                break;
            default:
                break;
        }
        task_list->tasks[i] = task;	//讓task_list底下的tasks記住這塊task的位址 
    }
    // execute job
    executeTasks(task_list);

    // print out result
    for(i=0; i<24; ++i){
        printf("%d ", global_array[i]);
    }printf("%d\n",global_array[24]);

    for(i=0; i<n; ++i){
        free(task_list->tasks[i]->argument);
        free(task_list->tasks[i]);
    }free(task_list);
    return 0;
}
void job1(void* argument) //reverse
{
	int i;
	Data* data=(Data*)argument;	//記得先將argument轉型 
	int low=data->lower;
	int up=data->upper;
	int mid=(low+up)/2;
	for(i=low;i<=mid;i++){
		int temp=data->arr[i];
		data->arr[i]=data->arr[low+up-i];
		data->arr[low+up-i]=temp;
	}
}
void job2(void* argument) //minus
{
	int i;
	Data* data=(Data*)argument;	//記得先將argument轉型 
	int low=data->lower;
	int up=data->upper;
	for(i=low;i<=up;i++){
		data->arr[i]*=-1;
	}
} 
void job3(void* argument) //double
{
	int i;
	Data* data=(Data*)argument;	//記得先將argument轉型 
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
void executeTasks(Task_List *task_list)	//執行task_list總表中的所有task
{
	int i;
	int size=task_list->size;
	for(i=0;i<size;i++){
		void(*func)(void*)=task_list->tasks[i]->func;
		void *argument=task_list->tasks[i]->argument;
		func(argument);
	}
}
