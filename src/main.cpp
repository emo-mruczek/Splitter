/* Money Splitter - just a program to make splitting money with my friends easier (excel is kinda boring...) */
/* its a mess rn plz dont yell at me :<< */

// TODO: validation
// TODO: tests
// TODO: folder structure
// TODO: makefile
// TODO: formatter

#include "includes.h"

// TODO: this??

/*const Sheet newSheet() {
    std::cout << "Sheet name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Created a new sheet!";
    return Sheet(name);
}*/

void showOptions(Sheet& sheet, char res);
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
        std::cout << "Show options? (y/N)";
        char res;
        std::cin >> res;
        showOptions(sheet, res);
    }

    return 0;
}

void showOptions(Sheet& sheet, char res) {

    // TODO: firstly, show only a possibility to add a person
    // TODO: deleting stuff, maybe different menu for expenses, people etc.

    if ( res == 'y' ) std::cout << "1. Add a person\n2. Add an expense\n3. Show people\n4. Show expenses\n5. Calculate\n6. Save\n7. Exit\n";

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
            sheet.calculate();
            break;
        }
        case '6': {
            save();
            break;
        }
        case '7': {
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
