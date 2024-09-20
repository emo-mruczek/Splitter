/* class: Expense */

#include "includes.h"

Expense::Expense(std::string_view name, uint32_t amount, std::vector<Person>& with):
    m_name {name}, m_amount {amount}, m_with {with} {}

void Expense::showExpense() const {
    for ( auto w: m_with ) {
        std::cout << "\t\t" << w.getName() << "\n";
    } 
}
