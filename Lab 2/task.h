typedef struct taskid{
	int value;
}TaskID;
typedef struct priority{
	int value;
}Priority;
typedef struct task{
	Priority* p;
	TaskID* tid;
}Task;

	
