#ifndef INCLUDES_H
#define INCLUDES_H

#include <iostream>
#include <vector>
#include <cinttypes>
#include <string_view>

class Person;

class Expense {
private:
    const std::string m_name {"???"};
    uint32_t m_amount;
    std::vector<Person> m_with;

public:
    Expense(std::string_view name, uint32_t amount, std::vector<Person>& with);

    void showExpense() const;

    const std::string& getName() const { return m_name; }

    uint32_t getAmount() const { return m_amount; }
};

class Person {
private:
    std::string m_name {"???"};
    std::vector<Expense> m_paid;

public:
    Person(std::string_view name);

    void addExpense(const Expense& expense);

    void showExpenses() const;

    const std::string& getName() const { return m_name; }
};

class Sheet {
private:
    std::string m_name {"???"};
    std::string m_about {"???"};
    std::vector<Person> m_people;
public:
    Sheet(std::string_view name); 

    void addPerson();

    void showPeople() const;

    void addExpense();

    void showExpenses() const; 

    void setName(std::string_view name) {
        m_name = name;
    }

    const std::string& getName() const { return m_name; }

    void setAbout(std::string_view about) {
        m_about = about;
    }

    const std::string& getAbout() const { return m_about; }
};

#endif
