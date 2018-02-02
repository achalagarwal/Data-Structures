struct card{
	long long card_number;
	char bank_code[5];
	int  expiry_month;
	int expiry_year;
	char first_name[5];
	char last_name[5];
};
typedef struct card* Card;

