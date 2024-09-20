/* class: Person */

#include "includes.h"

Person::Person(std::string_view name): 
    m_name{name} {}

void Person::addExpense(const Expense& expense) { m_paid.push_back(expense); }

void Person::showExpenses() const {
        for ( auto e: m_paid ) {
            std::cout << "\t" << e.getName() << " - " << e.getAmount() << "\n";
            e.showExpense();
        }
}
