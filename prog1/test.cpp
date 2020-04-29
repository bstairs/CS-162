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






int main (int argc, char **argv) {
	int num, num2, x = 1, y = 0;

	commandline (argc);

	char *userFile = argv[1];
	ifstream f;
	f.open(userFile);
	if (f.fail()){
		cout << "File not found!" << endl;
		exit(0);
	}
	f >> num;

	user *user_db = create_users(num);
	get_user_data(user_db, num, f);

	char *budgetFile = argv[2];
	ifstream f2;
	f2.open(budgetFile);
	if (f2.fail()){
                cout << "File not found!" << endl;
                exit(0);
        }
	f2 >> num2;
	budget *budget_db = create_budgets(num2);
	get_budget_data (budget_db, num2, f2);	
	

	int id = check_login(user_db, num);
	int row = display_balance (budget_db, num2, id);
	sort (budget_db, row);
	
	delete_mem (user_db, budget_db, num2);

}

void commandline (int argc){
	 if (argc != 3){
                cout << "Incorrect # of command line arguments!" << endl;
                exit(0);
        }
}



user* create_users(int num){
	user* user_db = new user[num];
	return user_db;
}




void get_user_data(user *user_db, int num, ifstream &f){
	for (int i = 0; i < num; i++){
		f >> user_db[i].name;
		f >> user_db[i].id;
		f >> user_db[i].password;	
	}
}




int check_login(user *user_db, int num){
	int username, x = 0, y = 0;
	string password;

while (x == 0 && y < 3){
	cout << "User ID: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;

	y++;

	for (int i = 0; i < num; i++){
		if (user_db[i].id == username && user_db[i].password == password){
			cout << user_db[i].name << endl;
			cout << user_db[i].id << endl;
			x = 1;
			return user_db[i].id;
			
		}
	}
	if (x == 0 && y < 3){
		cout << "Incorrect credentials, try again." << endl;
	}
	
	if (x == 0 && y == 3){
		exit(0);
	}
}
}


budget *create_budgets(int num){
	budget *budget_db = new budget[num];
        	return budget_db;
}



void get_budget_data (budget *budget_db, int num2, ifstream &f2){
	for (int i = 0; i < num2; i++){
                f2 >> budget_db[i].id;  
		f2 >> budget_db[i].balance; 
		f2 >> budget_db[i].num_transactions;
		budget_db[i].t = create_transactions (budget_db[i].num_transactions);
		get_transaction_data (budget_db[i].t, budget_db[i].num_transactions, f2);
	}
}	
	

transaction* create_transactions(int num2){
	transaction *transaction_db = new transaction[num2];
                return transaction_db;
}



void get_transaction_data(transaction *transaction_db, int num2, ifstream &f2){
	for (int i = 0; i < num2; i++){
		f2 >> transaction_db[i].date;
		f2 >> transaction_db[i].amount;
		f2 >> transaction_db[i].description;
		f2 >> transaction_db[i].category;
	}

}


int display_balance (budget *budget_db, int num2, int id){

	for (int i = 0; i < num2; i++){
		if (budget_db[i].id == id){
			cout << "Account balance: "<< budget_db[i].balance << endl;
			return i;
                }
        }
}



int sort (budget *budget_db, int row) {
	int x;

	cout << "How would you like your transactions sorted?" << endl;
	cout << "(1) Sort transactions by category" << endl;
        cout << "(2) Sort transactions by date" << endl;
        cout << "(3) Sort transactions by dollar amount" << endl;
        cout << "(4) Quit the program" << endl;
	cout << "Enter a choice (1-4): ";
	cin >> x;
	
	if (x == 1){
		sort_by_cat (budget_db, row);		
	}

	if (x == 2){
		sort_by_date (budget_db, row);	
	}

	if (x == 3){
		sort_by_amount (budget_db, row);
	}

	if (x == 4){
		exit(0);
	}
}



void swap (transaction *x, transaction *y){
	transaction temp = *x;
	*x = *y;
	*y = temp;
}





void sort_by_cat (budget *budget_db, int row){
        int choice;
	for(int j = 0; j < budget_db[row].num_transactions - 1; j++){
		for(int i = 0; i < budget_db[row].num_transactions - 1; i++){		
			if(budget_db[row].t[i].category.at(0) > budget_db[row].t[i+1].category.at(0)){
				swap(&budget_db[row].t[i], &budget_db[row].t[i+1]);
			}
		}
	}	

	cout << "Enter 0 to print to screen OR enter 1 to make file: ";
	cin >> choice;
	
	if (choice == 0){
		print_screen (budget_db, row);

	}

	if (choice == 1){
        string filename;
        cout << "Enter filename: ";
        cin.ignore();
        getline (cin, filename);

        ofstream fout;
        fout.open(filename.c_str());
        if(!fout.is_open()){
                cout << "Error, unable to open file for output" << endl;
        }

        fout << "Sorted by category: " << endl;
        print(budget_db, row, fout);
        fout << endl;
	}
	
	sort (budget_db, row);
}





void sort_by_date (budget *budget_db, int row){
        int choice;
	for(int i = 0; i < budget_db[row].num_transactions - 1; i++){
		string str = budget_db[row].t[i].date;
		string year = str.substr (6, 4);
		string month = str.substr (0, 2);
		string day = str.substr (3, 2);


		string str2 = budget_db[row].t[i+1].date;
		string year2 = str2.substr (6, 4);
		string month2 = str2.substr (0, 2);
                string day2 = str2.substr (3, 2);

		if (year2 > year){
			swap(&budget_db[row].t[i], &budget_db[row].t[i+1]);
		}

		if (year2 == year){
			if (month2 > month){
				swap(&budget_db[row].t[i], &budget_db[row].t[i+1]);
			}
			if (month2 == month){
				if (day2 > day){
					swap(&budget_db[row].t[i], &budget_db[row].t[i+1]);
				}
			}
		}
	}        
        cout << "Enter 0 to print to screen OR enter 1 to make file: ";
        cin >> choice;
        if (choice == 0){
                print_screen (budget_db, row);
        }
        if (choice == 1){
        string filename;
        cout << "Enter filename: ";
        cin.ignore();
        getline (cin, filename);

        ofstream fout;
        fout.open(filename.c_str());
        fout << "Sorted by date: " << endl;
        print(budget_db, row, fout);
        fout << endl;
	}
        sort (budget_db, row);

}




void sort_by_amount (budget *budget_db, int row){
        int choice;
	for (int i = 0; i < budget_db[row].num_transactions - 1; i++){
                if (budget_db[row].t[i].amount > budget_db[row].t[i+1].amount){
                        swap(&budget_db[row].t[i], &budget_db[row].t[i+1]);
                } 
        }


        cout << "Enter 0 to print to screen OR enter 1 to make file: ";
        cin >> choice;

        if (choice == 0){
                print_screen (budget_db, row);
        }

        if (choice == 1){

	string filename;
	cout << "Enter filename: ";
	cin.ignore();
	getline (cin, filename);

        ofstream fout;
        fout.open(filename.c_str());
        if(!fout.is_open()){
                cout << "Error, unable to open file for output" << endl;
        }

        fout << "Sorted by amount: " << endl;
        print(budget_db, row, fout);
        fout << endl;
	}
        sort (budget_db, row);
}    


void print_screen (budget *budget_db, int row){
	for (int i = 0; i < budget_db[row].num_transactions; i++){
                cout << budget_db[row].t[i].date << " " << budget_db[row].t[i].amount << " " << budget_db[row].t[i].description << " " << budget_db[row].t[i].category << endl;
        }


}



void print (budget *budget_db, int row, ofstream &fout){
	for (int i = 0; i < budget_db[row].num_transactions; i++){
		fout << budget_db[row].t[i].date << " " << budget_db[row].t[i].amount << " " << budget_db[row].t[i].description << " " << budget_db[row].t[i].category << endl;
	}
}



void delete_mem (user *user_db, budget *budget_db, int num2){
	delete [] user_db;
	for (int i = 0; i < num2; i++){
		delete [] budget_db[i].t;
	}
	delete [] budget_db;

}














