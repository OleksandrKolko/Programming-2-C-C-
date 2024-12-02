#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Person {
private:
    string name;
    unsigned byear;

public:
    Person() : name(""), byear(0) {}

    virtual int input() {
        cout << "Enter surname: ";
        cin >> name;
        cout << "Enter year of birth: ";
        cin >> byear;
        return 0;
    }

    virtual void show() const {
        cout << "Surname: " << name << ", Year of Birth: " << byear << endl;
    }

    string getName() const { return name; }
    void setName(const string& n) { name = n; }

    unsigned getYear() const { return byear; }
    void setYear(unsigned year) { byear = year; }
};

class Friend : public Person {
private:
    string phoneNumber;

public:
    Friend() : Person(), phoneNumber("") {}

    int input() override {
        Person::input();
        cout << "Enter phone number: ";
        cin >> phoneNumber;
        return 0;
    }

    void show() const override {
        Person::show();
        cout << "Phone Number: " << phoneNumber << endl;
    }

    string getPhoneNumber() const { return phoneNumber; }
    void setPhoneNumber(const string& number) { phoneNumber = number; }

    void setDetails(const string& name, const string& phone, unsigned year) {
        setName(name);
        setPhoneNumber(phone);
        setYear(year);
    }
};

class PhoneBook {
private:
    vector<Friend> friends;
    const size_t maxSize = 100;

public:
    void addFriend() {
        if (friends.size() >= maxSize) {
            cout << "Phone book is full!" << endl;
            return;
        }
        Friend newFriend;
        newFriend.input();
        friends.push_back(newFriend);
        cout << "Entry successfully added!" << endl;
    }

    void findPhoneNumber(const string& surname) const {
        for (const auto& fr : friends) {
            if (fr.getName() == surname) {
                cout << "Phone number for " << surname << ": " << fr.getPhoneNumber() << endl;
                return;
            }
        }
        cout << "Entry with surname \"" << surname << "\" not found." << endl;
    }

    void updatePhoneNumber(const string& surname, const string& newNumber) {
        for (auto& fr : friends) {
            if (fr.getName() == surname) {
                fr.setPhoneNumber(newNumber);
                cout << "Phone number updated!" << endl;
                return;
            }
        }
        cout << "Entry with surname \"" << surname << "\" not found." << endl;
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (!file) {
            cout << "Error opening file for writing!" << endl;
            return;
        }
        for (const auto& fr : friends) {
            file << fr.getName() << " " << fr.getPhoneNumber() << " " << fr.getYear() << endl;
        }
        file.close();
        cout << "Data saved to file \"" << filename << "\"!" << endl;
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error opening file for reading!" << endl;
            return;
        }
        friends.clear();
        string name, phone;
        unsigned byear;
        while (file >> name >> phone >> byear) {
            Friend fr;
            fr.setDetails(name, phone, byear);
            friends.push_back(fr);
        }
        file.close();
        cout << "Data loaded from file \"" << filename << "\"!" << endl;
    }

    void showAll() const {
        if (friends.empty()) {
            cout << "Phone book is empty." << endl;
            return;
        }
        for (const auto& fr : friends) {
            fr.show();
        }
    }
};

int main() {
    PhoneBook phoneBook;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add an entry\n";
        cout << "2. Search phone number by surname\n";
        cout << "3. Update phone number\n";
        cout << "4. Save phone book to file\n";
        cout << "5. Load phone book from file\n";
        cout << "6. Show all entries\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                phoneBook.addFriend();
                break;
            case 2: {
                string surname;
                cout << "Enter surname to search: ";
                cin >> surname;
                phoneBook.findPhoneNumber(surname);
                break;
            }
            case 3: {
                string surname, newNumber;
                cout << "Enter surname: ";
                cin >> surname;
                cout << "Enter new phone number: ";
                cin >> newNumber;
                phoneBook.updatePhoneNumber(surname, newNumber);
                break;
            }
            case 4: {
                string filename;
                cout << "Enter filename to save: ";
                cin >> filename;
                phoneBook.saveToFile(filename);
                break;
            }
            case 5: {
                string filename;
                cout << "Enter filename to load: ";
                cin >> filename;
                phoneBook.loadFromFile(filename);
                break;
            }
            case 6:
                phoneBook.showAll();
                break;
            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}