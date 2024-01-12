#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Block {
private: 
    float hp;
    float modifier = 1;

public:
    string name;
    string texture;
    float hardness;
    float x, y, z;

    // Constructor
    Block(string n, string t, float h, float x, float y, float z) 
    : name(n), texture(t), hardness(h), x(x), y(y), z(z), hp(100) {}

    float get_hp() {
        return hp;
    }

    void apply_dmg(int val) {
        hp -= val * modifier + 12;
    }

    void print_properties() {
        cout << "Block: " << name 
             << ", Texture: " << texture 
             << ", Hardness: " << hardness 
             << ", HP: " << get_hp() << endl;
    }
};

class Chest {
public:
    string content;
    bool lockStatus;

    Chest() : lockStatus(true) {}

    void lock() { lockStatus = true; cout << "Chest is locked." << endl; }

    void unlock() { lockStatus = false; cout << "Chest is unlocked." << endl; }

    void addItem(const string& item) {
        if (!lockStatus) {
            content += item + "\n";
            cout << "Added " << item << " to the chest." << endl;
        } else {
            cout << "Chest is locked!" << endl;
        }
    }

    // Corrected deleteItem method
    void deleteItem(const string& item) {
        if (!lockStatus) {
            size_t pos = content.find(item);
            if (pos != string::npos) {
                content.erase(pos, item.length() + 1); // +1 for newline
                cout << "Item " << item << " is removed." << endl;
            } else {
                cout << "Item not found." << endl;
            }
        } else {
            cout << "Chest is locked!" << endl;
        }
    }

    void printChestItem() { cout << "Chest Content:" << endl << content << endl; }
};

int main() {
    Block dirt("Dirt", "Brown", 0.5, 10, 10, 10);
    Block stone("Stone", "Grey", 1.5, 10, 10, 10);
    Chest chest;

    int choice;

    while (true) {
        cout << "1 - Print Chest Content\n";
        cout << "2 - Add Item to Chest\n";
        cout << "3 - Delete Item from Chest\n";
        cout << "4 - Lock/Unlock Chest\n";
        cout << "5 - Print Block Properties\n";
        cout << "6 - Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline character from previous input

        switch (choice) {
            case 1:
                chest.printChestItem();
                break;

            case 2: {
                string item;
                cout << "Enter item to add: ";
                getline(cin, item);
                chest.addItem(item);
                break;
            }

            case 3: {
                string item;
                cout << "Enter item to delete: ";
                getline(cin, item);
                chest.deleteItem(item);
                break;
            }

            case 4:
                if (chest.lockStatus) {
                    chest.unlock();
                } else {
                    chest.lock();
                }
                break;

            case 5:
                cout << "Properties of Dirt Block:" << endl;
                dirt.print_properties();
                cout << "\nProperties of Stone Block:" << endl;
                stone.print_properties();
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}

// gcc main.cpp -o main.o -lstdc++
// ./main.o