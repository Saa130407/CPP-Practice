#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
    string email;

    Contact() = default;
    Contact(const Contact&) = default;
    Contact& operator=(const Contact&) = default;
};

int main() {
    Contact contacts[100];
    int count = 0, choice;

    do {
        cout << "\n--- CONTACT MANAGEMENT SYSTEM ---\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Update Contact\n";
        cout << "5. Delete Contact\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            if (count >= 100) {
                cout << "Contact list is full.\n";
                continue;
            }

            cout << "Enter name: ";
            getline(cin, contacts[count].name);
            cout << "Enter phone: ";
            getline(cin, contacts[count].phone);
            cout << "Enter email: ";
            getline(cin, contacts[count].email);

            count++;
            cout << "Contact added successfully.\n";
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "No contacts available.\n";
            } else {
                for (int i = 0; i < count; i++) {
                    cout << "\nContact " << i + 1 << endl;
                    cout << "Name: " << contacts[i].name << endl;
                    cout << "Phone: " << contacts[i].phone << endl;
                    cout << "Email: " << contacts[i].email << endl;
                }
            }
        }

        else if (choice == 3) {
            string searchName;
            bool found = false;

            cout << "Enter name to search: ";
            getline(cin, searchName);

            for (int i = 0; i < count; i++) {
                if (contacts[i].name == searchName) {
                    cout << "\nContact found:\n";
                    cout << "Name: " << contacts[i].name << endl;
                    cout << "Phone: " << contacts[i].phone << endl;
                    cout << "Email: " << contacts[i].email << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Contact not found.\n";
        }

        else if (choice == 4) {
            string searchName;
            bool found = false;

            cout << "Enter name of contact to update: ";
            getline(cin, searchName);

            for (int i = 0; i < count; i++) {
                if (contacts[i].name == searchName) {
                    cout << "Enter new name: ";
                    getline(cin, contacts[i].name);
                    cout << "Enter new phone: ";
                    getline(cin, contacts[i].phone);
                    cout << "Enter new email: ";
                    getline(cin, contacts[i].email);

                    cout << "Contact updated successfully.\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Contact not found.\n";
        }

        else if (choice == 5) {
            string searchName;
            bool found = false;

            cout << "Enter name of contact to delete: ";
            getline(cin, searchName);

            for (int i = 0; i < count; i++) {
                if (contacts[i].name == searchName) {
                    for (int j = i; j < count - 1; j++) {
                        contacts[j] = contacts[j + 1];
                    }

                    count--;
                    cout << "Contact deleted successfully.\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Contact not found.\n";
        }

        else if (choice == 6) {
            cout << "Exiting program. Goodbye!\n";
        }

        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}