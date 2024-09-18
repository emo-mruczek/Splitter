/* Money Splitter - just a program to make splitting money with my friends easier (excel is kinda boring...) */
/* its a mess rn plz dont yell at me :<< */

// TODO: every class in a separate file, duh
// TODO: validation

#include <iostream>
#include <vector>
#include <cinttypes>


class Expense {
private:
    const std::string m_name {"???"};
    uint32_t m_amount;
 //   const Person &m_payer;
public:
    Expense(std::string_view name, uint32_t amount):
    m_name {name}, m_amount {amount} {}

    const std::string& getName() const { return m_name; }

    uint32_t getAmount() const { return m_amount; }

  //  const Person& getPayer() const { return m_payer; }

};

class Person {
private:
    std::string m_name {"???"};
    std::vector<Expense> m_paid;
public:
    Person(std::string_view name): 
    m_name{name} {}

    const std::string& getName() const { return m_name; }

    void addExpense(const Expense& expense) { m_paid.push_back(expense); }

    void showExpenses() const {
        for ( auto e: m_paid ) {
            std::cout << "\t" << e.getName() << " - " << e.getAmount() << "\n";
        }
    }
};

class Sheet {
private:
    std::string m_name {"???"};
    std::string m_about {"???"};
    std::vector<Person> m_people;
public:
    Sheet(std::string_view name):
    m_name{name} {}
    
    /* setters and getters */
    void setName(std::string_view name) {
        m_name = name;
    }

    const std::string& getName() const { return m_name; }

    void setAbout(std::string_view about) {
        m_about = about;
    }

    const std::string& getAbout() const { return m_about; }

    /* people manipulation */
    void addPerson() {
        std::cout << "Person's name: ";
        std::string name;
        std::cin >> name;
        m_people.push_back(Person {name});
        std::cout << "Created a new person!\n";
    }

    //TODO: show numbers
    void showPeople() {
        for ( auto p : m_people ) {
            std::cout << p.getName() << "\n";
        }
    }

    /* expenses manipulation */
    void addExpense() {
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
        m_people[num].addExpense(Expense {name, amount});
    }

    void showExpenses() {
        for ( auto p : m_people ) {
            std::cout << p.getName() << ":\n";
            p.showExpenses();
            std::cout << "\n";
        }
    }
};

// TODO: this??
const Sheet newSheet() {
    std::cout << "Sheet name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Created a new sheet!";
    return Sheet(name);
}

void showOptions(Sheet& sheet);
void showResults(void) {};
void save(void) {};
void exitProgram(void);
const Sheet newSheet(void);
void loadSheet(void) {};

int main() {

    // TODO: make this a loop??

    std::cout << "Welcome to the splitter! What do you want to do?\n";
    /* std::cout << "1. New sheet\n2. Load sheet\n";

    // TODO: can i do this in one line??
    char command;
    std::cin >> command;

    switch ( command ) {
        case '1': {
            Sheet sheet = newSheet();
            break;
        }
        case '2': {
            loadSheet();
            break;
        }
    }*/

    std::cout << "Sheet name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Created a new sheet!\n";

    Sheet sheet {name};

    std::cout << "Using sheet: " << sheet.getName() << "\n";

    while (1) {
        showOptions(sheet);
    }

    return 0;
}

void showOptions(Sheet& sheet) {

    // TODO: firstly, show only a possibility to add a person
    // TODO: make this show only when wrong command was typed
    std::cout << "1. Add a person\n2. Add an expense\n3. Show people\n4. Show expenses\n5. Save\n6. Exit\n";

    char command;
    std::cin >> command;

    switch ( command) {
        case '1': {
            sheet.addPerson();
            break;
        }
        case '2': {
            sheet.addExpense();
            break;
        }
        case '3': {
            sheet.showPeople();
            break;
        }
        case '4': {
            sheet.showExpenses();
            break;
        }
        case '5': {
            save();
            break;
        }
        case '6': {
            exitProgram();
        }
        default: {
            std::cout << "Unrecognized command!\n";
        }
    }
}


// TODO: make it also ask for save
void exitProgram() {
    exit(0);
}
