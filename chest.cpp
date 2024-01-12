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
bool lockStatus;
vector<Item> content;

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

int chest()
{
    Chest chest;
    chest.show_content();
    chest.add_item(Item{"Sword","A sword made of steel"});
    chest.show_content();
    chest.add_item(Item{"Shield","A shield made of steel"});

    chest.show_content();

    chest.lock();

    chest.show_content();

    chest.unlock();

    chest.show_content();

    return 0;
}

