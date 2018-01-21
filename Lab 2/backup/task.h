typedef struct taskid{
	long value;
}TaskID;
typedef struct priority{
	int value;
}Priority;
typedef struct task{
	Priority* p;
	TaskID* tid;
}Task;

	
