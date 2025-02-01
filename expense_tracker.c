#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME 100
#define CATEGORY_NUM 5
#define CATEGORY_NAME 15
typedef enum
{
    FAIL,
    SUCCESS
} status_code;

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
    individual *userIDforexp; // reference to indivial node
    char category[CATEGORY_NUM][CATEGORY_NAME];
    float expense_amt;
    int date_of_expense;
    struct expense_node *nextexp;
} expense;

// create node functions

status_code createindividual_node(individual **indivpptr, int Id, char *name, float income)
{
    individual *nptr;
    status_code sc = SUCCESS;

    nptr = (individual *)malloc(sizeof(individual));

    if (nptr == NULL)
    {
        sc = FAIL;
    }
    else
    {
        nptr->UserID = Id;
        nptr->UserName = name;
        nptr->income = income;
        nptr->nextindiv = indivpptr;
        *indivpptr = nptr;
    }
    return sc;
}

status_code createFamilyNode(family *famptr, int famid, char *famname, float fam_income, float fam_expense_monthly)
{
    family *nptr;
    status_code sc = SUCCESS;

    nptr = (family *)malloc(sizeof(family));

    if (nptr == NULL)
    {
        sc = FAIL;
    }
    else
    {
        nptr->FamilyID = famid;
        nptr->FamilyName = famname;
        nptr->family_income = fam_income;
        nptr->monthly_expense = fam_expense_monthly;
        nptr->nextfam = famptr;
        famptr = nptr;
    }
    return sc;
}

status_code createExpenseNode(expense *exptr)
{
    expense *nptr;
    status_code sc = SUCCESS;

    nptr = (expense *)malloc(sizeof(expense));

    if (nptr == NULL)
    {
        sc = FAIL;
    }
    else
    {
        nptr->nextexp = exptr;
        exptr = nptr;
    }
    return sc;
}

// Adding user

status_code AddUser(individual *individualptr)
{
    printf("Please enter the userID of the individual: ");
    int id;
    scanf("%d", &id);
    printf("\nPlease enter the name of the individual: ");
    char *username;
    scanf("%s", username);
    printf("\nPlease enter the income of the individual: ");
    float income;
    scanf("%f", &income);

    individual *lptr = individualptr;

    status_code sc = createindividual_node(lptr, id, username, income);
    // we need to sort it to uska logic baadme filhal ke liye
    return sc;
}
