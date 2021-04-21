#include "Expense.h"

void Expense :: setupExpenseId (int newExpenseId) {
    if (newExpenseId >= 0)
        expenseId = newExpenseId;
}
