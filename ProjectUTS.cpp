#include <iostream>
#include <string>

using namespace std;

struct Contact {
    std::string name;
    std::string phone;
    std::string email;
};

struct Node {
    Contact data;
    Node* next;
};

Node* head = nullptr;

void hardline() {
    std::cout << "==========================================================" << endl;
}

void lightline() {
    std::cout << "----------------------------------------------------------" << endl;
}

void addContact() {
    std::string name, address, phone, email;
    std::cout << "\n";
    hardline();
    std::cout << "Add Contact:" << endl;
    lightline();
    std::cout << "Enter name          : ";
    std::cin.ignore();
    std::getline(cin, name);
    lightline();
    std::cout << "Enter phone number  : ";
    std::getline(cin, phone);
    lightline();
    std::cout << "Enter email address : ";
    std::getline(cin, email);
    lightline();

    Contact contact;
    contact.name = name;
    contact.phone = phone;
    contact.email = email;

    Node* newNode = new Node;
    newNode->data = contact;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    std::cout << "\n";
    std::cout << "[!] Contact added successfully!" << endl;
}

void displayContact() {
    if (head == nullptr) {
        std::cout << "\n";
        std::cout << "[!] No contact found." << endl;
        return;
    }
    
    Node* temp = head;
    std::cout << "\n";
    hardline();
    std::cout << "CONTACT LIST" << endl;
    hardline();
    while (temp != nullptr) {
        std::cout << "Name    : " << temp->data.name << endl;
        std::cout << "Phone   : " << temp->data.phone << endl;
        std::cout << "Email   : " << temp->data.email << endl;
        lightline();
        temp = temp->next;
    }
    
}

void editContact() {
    if (head == nullptr) {
        std::cout << "\n";
        std::cout << "[!] No contact found." << endl;
        return;
    }
    
    std::string name;
    std::cout << "\n";
    std::cout << "Enter name of contact to edit : ";
    std::cin.ignore();
    std::getline(cin, name);

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.name == name) {
            std::string newName, newPhone, newEmail;
            std::cout << "\n";
            hardline();
            std::cout << "Edit Contact " << name << ":"<< endl;
            lightline();
            std::cout << "Enter name          : ";
            std::getline(cin, newName);
            lightline();
            std::cout << "Enter phone number  : ";
            std::getline(cin, newPhone);
            lightline();
            std::cout << "Enter email address : ";
            std::getline(cin, newEmail);
            lightline();

            temp->data.name = newName;
            temp->data.phone = newPhone;
            temp->data.email = newEmail;

            std::cout << "\n";
            std::cout << "[!] Contact updated successfully!" << endl;
            return;
        }
        temp = temp->next;
        
    }
    std::cout << "\n";
    std::cout << "[!] Contact not found." << endl;
    
}

void deleteContact() {
    if (head == nullptr) {
        std::cout << "\n";
        std::cout << "[!] No contacts found." << endl;
        return;
    }

    std::string name;
    std::cout << "\n";
    std::cout << "Enter name of contact to delete : ";
    std::cin.ignore();
    std::getline(cin, name);

    Node* temp = head;
    Node* prev = nullptr;
    
    while (temp != nullptr) {
        if (temp->data.name == name) {
            if (prev == nullptr) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            std::cout << "\n";
            std::cout << "[!] Contact deleted successfully!" << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    std::cout << "\n";
    std::cout << "[!] No contacts found." << endl;
}

int main() {
    int choice;
    do {
        std::cout << "\n";
        hardline();
        std::cout << "                  MENU CONTACT MANAGEMENT:" << endl;
        hardline();
        std::cout << "                   1. Add Contact" << endl;
        lightline();
        std::cout << "                   2. Display Contact" << endl;
        lightline();
        std::cout << "                   3. Edit Contact" << endl;
        lightline();
        std::cout << "                   4. Delete Contact" << endl;
        lightline();
        std::cout << "                   5. Exit" << endl;
        hardline();
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                addContact();
                break;
            }
            case 2: {
                displayContact();
                break;
            }
            case 3: {
                editContact();
                break;
            }
            case 4: {
                deleteContact();
                break;
            }
            case 5: {
                std::cout << "\n";
                std::cout << "[!] Exiting program. " << endl;
                break;
            }
            default:
                std::cout << "\n";
                std::cout << "[!] Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);
    
    return 0;
}