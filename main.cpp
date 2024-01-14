#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
class Block
{

private: 
    float hp;
    float modifier = 1;
public:
    string name;
    string texture;
    float hardness;
    float x,y,z;

    //Constructor
    Block(string n, string t, float h, float x, float y, float z) : name(n), 
    texture(t), hardness(h){hp = 100;}

    float get_hp(){return hp;}
    void apply_dmg(int val){hp -= val * modifier +12;}

};



int not_main()
{
    Block dirt("Dirt", "Brown", 0.5,10,10,10);
    Block stone("Stone", "Grey", 1.5,10,10,10);

    cout
    <<"Block: " << dirt.name 
    << ",Texture: "<< dirt.texture 
    << ", Hardness: " << dirt.hardness 
    << ", HP: " << dirt.get_hp()
    << endl;

    printf("Block: %s, Texture: %s, Hardness: %f, HP: %f\n",dirt.name.c_str(),dirt.texture.c_str(),dirt.hardness,dirt.get_hp());

    dirt.apply_dmg(12);

    cout
    <<"Block: " << dirt.name 
    << ",Texture: "<< dirt.texture 
    << ", Hardness: " << dirt.hardness 
    << ", HP: " << dirt.get_hp()
    << endl;

    return 0;
}