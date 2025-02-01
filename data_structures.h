#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LENGTH 50
#define MAX_DATE 10

typedef enum {rent,utility,grocery,stationary,leisure} ExpenseCategory;

typedef enum{FAILURE,SUCCESS} status_code;

typedef struct individual_node
{
    int UserID;
    char *UserName;
    float income;
    int FamilyID;
    struct individual_node *nextindiv;
} individual;

typedef struct family_node
{
    int FamilyID;
    char *FamilyName;
    individual *familyMember; // pointing towards the forst member of the family
    float monthly_expense;    // sum of expenses of all family members across every category for each month
    float family_income;      // calculated as income of each  family member
    struct family_node *nextfam;
} family;

typedef struct expense_node
{
    int expenseID;
    individual *userID_exp; // reference to indivial node
    ExpenseCategory expense_category;
    float expense_amount;
    int date_of_expense;
    struct expense_node *next_exp;
} expense;

status_code createindividual_node(individual **indivpptr, int Id, char *name, float income);
status_code createFamilyNode(family **fampptr, int famid, char *famname, float fam_income, float fam_expense_monthly);
status_code createExpenseNode(expense **expptr, int expid, ExpenseCategory expensecategory, float expamt, int date);

void sort_individuals(individual *individual_start);
void sort_families(family *family_start);
void sort_expenses(expense *expense_start);

status_code  AddUser(individual* head, int userID, char* userName, float income);
status_code AddExpense(expense* head, int expenseID, int userID, ExpenseCategory category, float amount, int date);
status_code CreateFamily(family* head, int familyID, char* familyName, int* userIDs, int userCount, individual* individualHead);
status_code UpdateOrDeleteIndividualFamilyDetails(family** familyHead, individual** individualHead, int userID, char* newName, float newIncome, int deleteFlag);
status_code UpdateDeleteExpense(family* familyHead, expense** expenseHead, int expenseID, float newAmount, int deleteFlag);
float GetTotalExpense(family* familyHead, int familyID);
float GetCategoricalExpense(family* familyHead, expense* expenseHead, int familyID, ExpenseCategory category);
float GetHighestExpenseDay(family* familyHead, expense* expenseHead, int familyID);
float GetIndividualExpense(expense* expenseHead, int userID);

#endif