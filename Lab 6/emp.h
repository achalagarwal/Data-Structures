struct employee{
char* name;
long long empID;
};
typedef struct employee* Employee;

struct pair{
	int start;
	int end;
	struct pair* next;
};
typedef struct pair* Pair;

struct stack{
Pair head;
};
typedef struct stack* Stack;
int compareEmployees(Employee a, Employee b);
Employee createEmployee(char * name, long long id);
Stack push(Stack s,int start,int end);
Stack createStack();
Pair pop(Stack s);
