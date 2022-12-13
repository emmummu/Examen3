#include <iostream>
using namespace std;

class Pet
{
public:
    Pet(int hunger = 0, int boredom = 0, int dirty = 0);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
    void talktoyourpet();
    bool deathcheck(); 
    bool vivo;
    void stats();
    void limpiar(int jabon = 5);
private:
    int m_Hunger;
    int m_Boredom;
    int m_dirty;
    int GetMood() const;
    void PassTime(int time = 1);
   
};


Pet::Pet(int hunger, int boredom, int dirty) :
    m_Hunger(hunger),
    m_Boredom(boredom),
    m_dirty(dirty)
{}

void Pet::talktoyourpet(){
    if (m_Hunger < 10) {
        cout << "humano estoy hambriento\n";
    }
    else {
        cout << "estoy bien de comida\n";
    }
    if (m_Boredom < 10) {
        cout << "humano estoy aburrido\n";
    }
    else {
        cout << "estoy bien de diversion\n";
    }
    if (m_dirty < 10) {
        cout << "me siento sucion\n";
    }
    else {
        cout << "estoy blanco de lo limpio que estoy\n";
    }
    
}
void Pet::stats() {
    cout << "mis stats son: \n";
    cout << "hambre: " << m_Hunger << endl;
    cout << "aburrimiento: " << m_Boredom << endl;
    cout << "limieza: " << m_dirty << endl;
}

void Pet::limpiar(int jabon) {
    cout << "\wash...wass \n";
    m_Hunger -= jabon;

    if (m_dirty < 0)
    {
        m_dirty = 0;
    }

}
bool Pet::deathcheck() {
    if (m_Hunger <= 0 && m_Boredom <= 0 && m_dirty <= 0) {
        cout << "no me cuidaste y por eso mori" << endl;
        return false;

    }
    return true;
}
inline int Pet::GetMood() const
{
    return (m_Hunger + m_Boredom+m_dirty);
}

void Pet::PassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
    m_dirty += time;
}

void Pet::Talk()
{
    cout << "\n\n Humano estoy: ";
    int mood = GetMood();

    if (mood > 20)
    {
        cout << "muriendo. \n";
    }
    else if (mood > 15)
    {
        cout << "mal. \n";
    }
    else if (mood > 10)
    {
        cout << "ok. \n";
    }
    else {
        cout << "feliz. \n";
    }
    talktoyourpet();
    PassTime();
}

void Pet::Eat(int food)
{
    cout << "\Brrup. \n";
    m_Hunger -= food;

    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }

    PassTime();
}

void Pet::Play(int fun)
{
    cout << "\n Wheeee \n";
    m_Boredom -= fun;

    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }

    PassTime();
}


int main()
{

    Pet pet;
    pet.Talk();
    int choice;

    do {
        pet.vivo = pet.deathcheck();
        cout << "\n Mascotas Virtuales\n\n";
        cout << "0 -  Salir\n";
        cout << "1 -  Escucha a tu macota\n";
        cout << "2 -  Alimentar\n";
        cout << "3 -  Jugar con mascota\n";
        cout << "4- limpiar a tu mascota\n";
        cout << "5- stats\n";
        cout << "Elige una opción: \n";

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Vuelve pronto!. \n";
            break;
        case 1:
            pet.Talk();
            break;
        case 2:
            pet.Eat();
            break;
        case 3:
            pet.Play();
            break;
        case 4:
            pet.limpiar();
            break;
        default:
            cout << "\nTu elección se inválida. \n";
        }


    } while (choice != 0|| pet.vivo==true);
}
