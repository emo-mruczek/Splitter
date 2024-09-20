/* class: Sheet */
#include "includes.h"

Sheet::Sheet(std::string_view name):
    m_name{name} {}


/* people manipulation */
void Sheet::addPerson() {
    std::cout << "Person's name: ";
    std::string name;
    std::cin >> name;
    m_people.push_back(Person {name});
    std::cout << "Created a new person!\n";
}

//TODO: show numbers
void Sheet::showPeople() const {
    for ( auto p : m_people ) {
        std::cout << p.getName() << "\n";
    }
}

/* expenses manipulation */
void Sheet::addExpense() {
    std::cout << "Expense's name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Amount: ";
    uint32_t amount;
    std::cin >> amount;
    std::cout << "Payer (choose a number):\n";
    showPeople();
    uint16_t num;
    std::cin >> num;

    //TODO: bug with infinity loop
    char res;
    std::vector<Person> with;
    do {
        std::cout << "For who did you pay?";
        showPeople();
        uint16_t som;
        std::cin >> som;
        with.push_back(m_people[som]);
        std::cout << "Is that all? (y/N)";
        std::cin >> res;
     } while ( res != 'y' );

    m_people[num].addExpense(Expense {name, amount, with});
}

void Sheet::showExpenses() const {
    for ( auto p : m_people ) {
        std::cout << p.getName() << ":\n";
        p.showExpenses();
        std::cout << "\n";
    }
}

void Sheet::calculate() const {
    
}
