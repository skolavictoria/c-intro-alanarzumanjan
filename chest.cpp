#include <iostream>
#include <string>
#include <vector>

#include "main.cpp"

using namespace std;

class Item
{
public:
    string name;
    string description;

};

class Chest: public Block
{
int size;
vector<Item> content;

protected:
    bool lockStatus;

public:
    Chest():lockStatus(false),Block("Chest","Chest",0.5,1,1,1){}

    void lock(){lockStatus = true;}
    void unlock(){lockStatus = false;}

    void add_item(Item item){content.push_back(item);}

    void show_content()
    {
        if(!lockStatus)
        {
            for(const Item& elem: content)
            {
                cout << elem.name << endl;
            }
        }
        else
        {
            cout << "Chest is locked" << endl;
        }
    }

};

class EnderChest: public Chest
{
    static vector<Item> static_content;
public:
    EnderChest():Chest(){name = "Ender Chest"; texture = "Ender Chest"; hardness = 0.5;}
    void add_item(const Item& item){static_content.push_back(item);}
    void show_content()
    {
        if(!lockStatus)
        {
            for(const Item& elem: static_content)
            {
                cout << elem.name << endl;
            }
        }
        else
        {
            cout << "Chest is locked" << endl;
        }
    }
};


vector<Item> EnderChest::static_content;
int a = 0;


int main()
{
    Chest chest0;
    Chest chest1;
    EnderChest e_chest0;
    EnderChest e_chest1;
    EnderChest e_chest2;

    cout << "Chest 0 content: ";
    chest0.show_content();
    chest0.add_item(Item{"Sword","A sword made of steel"});
    cout << "\nChest 0 content: ";
    chest0.show_content();
    chest0.add_item(Item{"Shield","A shield made of steel"});
    cout << "\nChest 0 content: ";
    chest0.show_content();
    chest0.lock();
    cout << "\nChest 0 content: ";
    chest0.show_content();
    chest0.unlock();
    cout << "\nChest 0 content: ";
    chest0.show_content();
    chest1.add_item(Item{"wand","magic puff"});
    cout << "\nChest 1 content: ";
    chest1.show_content();

    cout << "\nEnder Chest" << endl;
    e_chest0.add_item(Item{"wand","magic puff"});
    cout << "\nEnder Chest 1 content: ";
    e_chest1.show_content();
    e_chest0.add_item(Item{"bow","weee"});
    cout << "\nEnder Chest 2 content: ";
    e_chest2.show_content();
    


    return 0;
}
