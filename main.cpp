#include <iostream>
#include <string>
#include <vector>

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

    Block(string n, string t, float h, float x, float y, float z)
        : name(n), texture(t), hardness(h), x(x), y(y), z(z), hp(100) {}

    float get_hp() const { return hp; }

    void apply_dmg(int val) { hp -= val * modifier + 12; }

    void print_properties() const {
        cout << "Block: " << name
            << ", Texture: " << texture
            << ", Hardness: " << hardness
            << ", HP: " << hp << endl;
    }

};

class Item {
public:
    string name;
    string description;

    Item(string n, string d) : name(n), description(d) {}
};


class Chest : public Block
{   
private:
    vector<Item> content;

protected:
    bool lockStatus;

public:
    Chest() : lockStatus(false), Block("Chest", "Chest", 0.5, 1, 1, 1) {}
    
    void lock() { lockStatus = true; cout << "Chest is locked" << endl;}
    void unlock() { lockStatus = false; cout << "Chest is unlocked" << endl;}
    bool isLocked() const { return lockStatus; }
    void add_item(string item_n, string item_d) {
        Item item(item_n, item_d);
        content.push_back(item);
    }
    void delete_item(string item_name) {

    }

    void show_content() {
        if (!lockStatus) {
            for (const Item& elem : content) {
                cout << elem.name << endl;
            }
        }
        else {
            cout << "Chest is locked!" << endl;
        }
    }
};

class EnderChest : public Chest
{
    static vector<Item> static_content;

public:
    EnderChest() : Chest() { name = "Ender Chest"; texture = "Ender Chest"; hardness = 0.5; }

    void add_item(const Item& item) { static_content.push_back(item); }

    void show_content() {
        if (!lockStatus) {
            for (const Item& elem : static_content) {
                cout << elem.name << endl;
            }
        }
        else {
            cout << "Chest is locked" << endl;
        }
    }
};

vector<Item> EnderChest::static_content;

int main() {
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
        cout << "\n";

        switch (choice) {
        case 1:
            chest.show_content();
            break;
        
        case 2: {
            string item_name;
            string item_description;
            cout << "Enter item name: ";
            cin >> item_name;
            cout << "Enter item description: ";
            cin >> item_description;
            chest.add_item(item_name, item_description);

            break;
        }


        case 3: {
            string item_name;
            cout << "Enter item name to delete: ";
            cin >> item_name;
            chest.delete_item(item_name);

            break;
        }

        case 4: {
            if (chest.isLocked()) {
                chest.unlock();
            }
            else {
                chest.lock();
            }

            break;
        }
        case 5: {
            string block_name;
            cout << "Enter block name: ";
            cin >> block_name;
            Block block("Name", "Texture", 0.0, 0.0, 0.0, 0.0);
            block.name = block_name; 
            block.print_properties();

            break;
        }

        case 6: 

            return 0;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
}
// gcc main.cpp -o main.o -lstdc++
// ./main.o