#include <stdio.h>
#include <stdlib.h>
/*typedef struct _retire_info {
    int months;
    double contribution;
    double rate_of_return;
} retire_info;
*/
/*void calculate_balance(int age_years, int age_months, double initial, retire_info info) {
    double balance = initial;
    double rate = info.rate_of_return / 12.0;
    int total_months = age_years * 12 + age_months + info.months;

    for (int i = 0; i < info.months; i++) {
        printf("Age %3d month %2d you have $%.2lf\n", age_years, age_months, balance);
        balance *= (1 + rate); // adding returns
        balance += info.contribution; // adding contribution
        if (++age_months == 12) {
            age_months = 0;
            age_years++;
        }
    }
}
*/
/*
void calculate_balance(int age_years, int age_months, double initial, _retire_info info) {
    double balance = initial;
    double rate = info.rate_of_return / 12.0;

    for (int i = 0; i < info.months; i++) {
        printf("Age %3d month %2d you have $%.2lf\n", age_years, age_months, balance);
        balance *= (1 + rate); // adding returns
        balance += info.contribution; // adding contribution
        if (++age_months == 12) {
            age_months = 0;
            age_years++;
        }
    }
}

void retirement(int startAge, double initial, _retire_info working, _retire_info retired) {
    int age_years = startAge / 12;
    int age_months = startAge % 12;

    printf("Working:\n");
    printf("--------\n");
    printf("Months: %d\n", working.months);
    printf("Per Month Savings: $%.2lf\n", working.contribution);
    printf("Rate of Return: %.2lf%% per year (%.4lf per month)\n", working.rate_of_return * 100, working.rate_of_return / 12);

    calculate_balance(age_years, age_months, initial, working);

    printf("\nRetired:\n");
    printf("--------\n");
    printf("Months: %d\n", retired.months);
    printf("Per Month Spending: $%.2lf\n", retired.contribution);
    printf("Rate of Return: %.2lf%% per year (%.4lf per month)\n", retired.rate_of_return * 100, retired.rate_of_return / 12);

    calculate_balance(age_years, age_months, initial, retired);
}

int main() {
    retire_info working = {489, 1000, 0.045 / 12};
    retire_info retired = {384, -4000, 0.01 / 12};
    int startAge_months = 27 * 12 + 3; // 27 years and 3 months
    double initial_savings = 21345;

    retirement(startAge_months, initial_savings, working, retired);

    return 0;
}
*/
/*
Grading at Wed 06 Mar 2024 07:29:34 AM UTC
Attempting to compile retirement.c
Checking for struct _retire_info
Found on line 4, column 9
Checking for field int months
Found on line 5, column 5
Checking for field double contribution
Found on line 6, column 5
Checking for field double rate_of_return
Found on line 7, column 5
Checking for typedef of struct _retire_info to retire_info
You have a typedef for retire_info, but it is :
typedef struct _retire_info {
where I instead expected you to define it to struct _retire_info
not found
Checking for void retirement (int startAge, double initial,  retire_info working,  retire_info retired)
Found on line 41, column 1
Checking for int main(void)
Found on line 62, column 1
Your code does not have the right struct, fields, and/or functions
*/
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct _retire_info {
    int months;
    double contribution;
    double rate_of_return;
} retire_info;

void calculate_balance(int age_years, int age_months, double initial, retire_info info) {
    double balance = initial;
    double rate = info.rate_of_return / 12.0;

    for (int i = 0; i < info.months; i++) {
        printf("Age %3d month %2d you have $%.2lf\n", age_years, age_months, balance);
        balance *= (1 + rate); // adding returns
        balance += info.contribution; // adding contribution
        if (++age_months == 12) {
            age_months = 0;
            age_years++;
        }
    }
}

void retirement(int startAge, double initial, retire_info working, retire_info retired) {
    int age_years = startAge / 12;
    int age_months = startAge % 12;

    printf("Working:\n");
    printf("--------\n");
    printf("Months: %d\n", working.months);
    printf("Per Month Savings: $%.2lf\n", working.contribution);
    printf("Rate of Return: %.2lf%% per year (%.4lf per month)\n", working.rate_of_return * 100, working.rate_of_return / 12);

    calculate_balance(age_years, age_months, initial, working);

    printf("\nRetired:\n");
    printf("--------\n");
    printf("Months: %d\n", retired.months);
    printf("Per Month Spending: $%.2lf\n", retired.contribution);
    printf("Rate of Return: %.2lf%% per year (%.4lf per month)\n", retired.rate_of_return * 100, retired.rate_of_return / 12);

    calculate_balance(age_years, age_months, initial, retired);
}

int main() {
    retire_info working = {489, 1000, 0.045 / 12};
    retire_info retired = {384, -4000, 0.01 / 12};
    int startAge_months = 27 * 12 + 3; // 27 years and 3 months
    double initial_savings = 21345;

    retirement(startAge_months, initial_savings, working, retired);

    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>

/*struct _retire_info {
    int months;

    double contribution;
    double rate_of_return;
};
typedef struct _retire_info retire_info;

void calculate_balance(int age_years, int age_months, double initial, retire_info info) {
    double balance = initial;
    double rate = info.rate_of_return / 12.0;

    for (int i = 0; i < info.months; i++) {
        printf("Age %3d month %2d you have $%.2lf\n", age_years, age_months, balance);
        balance *= (1 + rate); // adding returns
        balance += info.contribution; // adding contribution
        if (++age_months == 12) {
            age_months = 0;
            age_years++;
        }
    }
}

void retirement(int startAge, double initial, retire_info working, retire_info retired) {
    int age_years = startAge / 12;
    int age_months = startAge % 12;

    printf("Working:\n");
    printf("--------\n");
    printf("Months: %d\n", working.months);
    printf("Per Month Savings: $%.2lf\n", working.contribution);
    printf("Rate of Return: %.2lf%% per year (%.4lf per month)\n", working.rate_of_return * 100, working.rate_of_return / 12);

    calculate_balance(age_years, age_months, initial, working);

    printf("\nRetired:\n");
    printf("--------\n");
    printf("Months: %d\n", retired.months);
    printf("Per Month Spending: $%.2lf\n", retired.contribution);
    printf("Rate of Return: %.2lf%% per year (%.4lf per month)\n", retired.rate_of_return * 100, retired.rate_of_return / 12);

    calculate_balance(age_years, age_months, initial, retired);
}

int main() {
    retire_info working = {489, 1000, 0.045 / 12};
    retire_info retired = {384, -4000, 0.01 / 12};
    int startAge_months = 27 * 12 + 3; // 27 years and 3 months
    double initial_savings = 21345;

    retirement(startAge_months, initial_savings, working, retired);

    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

double next_balance(double balance, retire_info ri) {

  return balance * ( 1 + ri.rate_of_return ) + ri.contribution;

}

void calc_year_month(int months, int *year, int *month) {

  *year = months / 12;
  *month = months % 12;

}

void print_balance_info(int months, double balance) {

  int age, month;

  calc_year_month(months, &age, &month);
  printf("Age %3d month %2d you have $%.2lf\n", age, month, balance);

}

void retirement(int startAge, // in months
		double initial, // initial savings in dollar
		retire_info working,
		retire_info retired) {

  int m;
  int age_months = startAge;
  double balance = initial;

  for (m=0; m<working.months; m++) {
    print_balance_info(age_months, balance);
    age_months++;
    balance = next_balance(balance, working);
  }

  for (m=0; m<retired.months; m++) {
    print_balance_info(age_months, balance);
    age_months++;
    balance = next_balance(balance, retired);
  }

}

int main(void) {

  retire_info working = {
    489, 1000.0, 0.045 / 12
  };

  retire_info retired = {
    384, -4000.0, 0.01 / 12
  };

  int start_age_months = 327;
  double savings = 21345;

  retirement(start_age_months,
	     savings,
	     working,
	     retired);

  return EXIT_SUCCESS;

}

