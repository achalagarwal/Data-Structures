#define CURRENCY_H

struct currency;
typedef struct currency* Currency;

struct currency{
    char* key;
};

char* getKey(Currency c);
Currency createCurrency(char* key);