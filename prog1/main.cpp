#include <iostream>
#include "prog1.h"

using namespace std;



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


