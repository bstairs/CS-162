#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <stdlib.h>
using namespace std;


struct user {
   string name;
   int id;
   string password;
};

struct budget {
   int id;
   float balance;
   int num_transactions;
   struct transaction *t;
};

struct transaction {
   string date;
   float amount;
   string description;
   string category;
};


user *create_users(int);

void get_user_data(user*, int, ifstream &);

int check_login (user*, int);

budget *create_budgets(int);

void get_budget_data(budget*, int, ifstream &);

transaction* create_transactions(int);

void get_transaction_data(transaction*, int, ifstream &);

int display_balance (budget *budget_db, int num2, int id); 
    
void delete_info(user**, int, budget**, int);

int sort (budget *budget_db, int row);
    
void swap (transaction *x, transaction *y);
    
void sort_by_amount (budget *budget_db, int row);

void sort_by_cat (budget *budget_db, int row);

void sort_by_date (budget *budget_db, int row);

void commandline (int argc);

void print (budget *budget_db, int row, ofstream &f);

void delete_mem (user *user_db, budget *budget_db, int num2);

void print_screen (budget *budget_db, int row);
