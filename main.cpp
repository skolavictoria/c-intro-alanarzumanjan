#include <iostream>
#include <string>

using namespace std;

class Chest {
public:
    string content;
    bool lockStatus;

    Chest() : lockStatus(true) {}

    void lock() {
        lockStatus = true;
        cout << "Chest is locked." << endl;
    }

    void unlock() {
        lockStatus = false;
        cout << "Chest is unlocked." << endl;
    }

    void addItem(string item) {
        if (!lockStatus) {
            content += item + "\n";
            cout << "Added " << item << " to the chest." << endl;
        }
        else {
            cout << "Chest is locked!" << endl;
        }
    }

    void deleteItem(string *item){
        if(!lockStatus){
            for(int i=0;i != '/0';i++){
                if(content[i] == *item){
                    delete &content[i];
                    cout << "Item " << *item << "is removed" << endl;
                }
            }
        } 
        else{
            cout << "Chest is locked!" << endl;
        }   
    }
    void printChestItem(){
        cout << "Chest Content:" << endl << content << endl;
    }
};

    void printChestItem() {
        cout << "Chest Content:" << endl << content << endl;
    }
};

class Block {
public:
    string name;
    string texture;
    float hardness;

    Block(string n, string t, float h) : name(n), texture(t), hardness(h) {}

    void print_properties() {
        cout << "Name: " << name << endl;
        cout << "Texture: " << texture << endl;
        cout << "Hardness: " << hardness << endl;
    }
};

int main() {
    Block dirt("Dirt", "Brown", 0.5);
    Block stone("Stone", "Grey", 1.5);
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

        switch (choice) {
            case 1:
                chest.printChestItem();
                break;

            case 2: {
                string item;
                cout << "Enter item to add: ";
                cin.ignore(); // Clear newline character from previous input
                getline(cin, item);
                chest.addItem(item);
                break;
            }

            case 3: {
                string item;
                cout << "Enter item to delete: ";
                cin.ignore(); // Clear newline character from previous input
                getline(cin, item);
                chest.deleteItem(item);
                break;
            }

            case 4:
                if (chest.lockStatus) {
                    chest.unlock();
                }
                else {
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

    return 0;
}

// gcc main.cpp -o main.o -lstdc++
// ./main.o