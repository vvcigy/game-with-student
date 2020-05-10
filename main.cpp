
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;
class Bar
{
    int value; // значение характеристики
public:
    Bar(int value); // Конструктор, который заполняет значение value
    void set(int& x);      // Установить значение value в x
    int& get();            // Получить значение value
    void add(int x);      // Изменить значение value на x (но так, что оно не становится больше 100 или меньше 0)
    void show();          // Вывести полоску на экран
};
Bar::Bar(int value = 100)
{
    this->value = value;
}
int& Bar::get()
{
    return value;
}
void Bar::add(int x)
{
    if (this->value + x <101 && this->value + x > -1)
    {
        this->value += x;
    }
    if (this->value + x > 100)
        this->value = 100;
    if (this->value + x < 0)
        this->value = 0;
}
void Bar::set(int& x)
{
    x = this->value;
}
void Bar::show()
{
    cout << "[";
    for (int i = 0; i < this->value; ++i)
    {
        cout << "=";
    }
    for (int i = 0; i < 100 - this->value; ++i)
    {
        cout << " ";
    }
    cout << "] " << this->value << "/100" << endl;
}
class Student {
private:
    char name[51];
    char surname[51];
    Bar energy;
    Bar iq;
    Bar sanity;
    Bar exci;
    Bar hp;  // очки здоровья персонажа
    void apply_effect();
    void change_params(int d_hp, int d_energy, int d_iq, int d_sanity, int d_exci);
    void change_field(int& field, int delta);
public:
    bool is_alive();
    void show();
    void eat();
    void wait();
    void study();
    void sleep();
    void watch_tv();
    Student(int hp, int energy, int iq, int sanity, int exci);
    Student(char* name, char* surname, int hp, int energy, int iq, int sanity, int exci);
};
Student::Student(int hp = 100, int energy = 100, int iq = 100, int sanity = 20, int exci = 50)
{
    for (int i = 0; i < 52; ++i) name[i] = 0;
    for (int i = 0; i < 52; ++i) surname[i] = 0;
    char* arr = new char[50]{ 0 };
    cin.getline(arr, 50);
    strncpy(name, arr, strlen(arr));
    char* arr2 = new char[50]{ 0 };
    cin.getline(arr2, 50);
    strncpy(surname, arr2, strlen(arr2));
    cin >> hp >> energy >> iq >> sanity >> exci;
    this->hp = hp;
    this->energy = energy;
    this->iq = iq;
    this->sanity = sanity;
    this->exci = exci;
    delete[] arr;
    delete[] arr2;
}
Student::Student(char* name, char* surname, int hp = 100, int energy = 100, int iq = 100, int sanity = 20, int exci = 50)
{
    for (auto s : this->name) s = '\0';
    for (auto s : this->surname) s = '\0';
    strncpy(this->name, name, strlen(name));
    strncpy(this->surname, surname, strlen(surname));
    cin >> hp >> energy >> iq >> sanity >> exci;
    this->hp = hp;
    this->energy = energy;
    this->iq = iq;
    this->sanity = sanity;
    this->exci = exci;
}
void Student::change_params(int d_hp, int d_energy, int d_iq, int d_sanity, int d_exci)
{
    change_field(hp.get(), d_hp);
    change_field(energy.get(), d_energy);
    change_field(iq.get(), d_iq);
    change_field(sanity.get(), d_sanity);
    change_field(exci.get(), d_exci);
}
bool Student::is_alive()
{
    return (hp.get() > 0 ? 1 : 0);
}
void Student::show()
{
    //cout << name << " " << surname << ": "
    //    << "HP = ";
    ////Здоровье
    //if (hp.get() == 100)
    //    cout << hp.get();
    //else if (hp.get() < 10)
    //{
    //    cout << 0 << 0 << hp.get();
    //}
    //else
    //{
    //    cout << 0 << hp.get();
    //}
    //cout << ", "
    //    << "Energy = ";
    ////Энергия
    //if (energy.get() == 100)
    //    cout << energy.get();
    //else if (energy.get() < 10)
    //{
    //    cout << 0 << 0 << energy.get();
    //}
    //else
    //{
    //    cout << 0 << energy.get();
    //}
    //cout << ", IQ = ";
    ////IQ
    //if (iq.get() == 100) {
    //    cout << iq.get();
    //}
    //else if (iq.get() < 10)
    //{
    //    cout << 0 << 0 << iq.get();
    //}
    //else
    //    cout << 0 << iq.get();
    //cout << ", Sanity = ";
    ////Уровень разума
    //if (sanity.get() == 100)
    //    cout << sanity.get();
    //else if (sanity.get() < 10)
    //{
    //    cout << 0 << 0 << sanity.get();
    //}
    //else
    //{
    //    cout << 0 << sanity.get();
    //}
    //cout << ", "
    //    << "Excitement = ";
    //// Уровень радости
    //if (exci.get() == 100)
    //    cout << exci.get();
    //else if (exci.get() < 10)
    //{
    //    cout << 0 << 0 << exci.get();
    //}
    //else
    //{
    //    cout << 0 << exci.get();
    //}
    //cout << ".";
    ////Проверка на живость и вывод конца игры в случае смерти
    //if (is_alive())
    //    cout << endl;
    //else
    //{
    //    cout << " Game over." << endl;
    //}
    cout << name << " " << surname << endl;
    cout << "        HP: "; hp.show();
    cout << "    Energy: "; energy.show();
    cout << "        IQ: ";  iq.show();
    cout << "    Sanity: ";  sanity.show();
    cout << "Excitement: ";  exci.show();

}
void Student::change_field(int& field, int delta)
{
    if (field + delta > 0 && field + delta < 101) field += delta;
    else if (field + delta <= 0) field = 0;
    else if (field + delta >= 100) field = 100;
}
void Student::eat()
{
    if (!is_alive()) return;
    change_params(1, 7, -1, 0, -2);
    apply_effect();
}
void Student::wait()
{
    if (!is_alive()) return;
    change_params(1, -3, 0, 0, -3);
    apply_effect();
}
void Student::study()
{
    if (!is_alive()) return;
    change_params(-2, -4, 5, -5, -2);
    apply_effect();
}
void Student::sleep()
{
    if (!is_alive()) return;
    change_params(2, -2, 0, 7, 0);
    apply_effect();
}
void Student::watch_tv()
{
    if (!is_alive()) return;
    change_params(-2, -3, -3, 1, 5);
    apply_effect();
}
void Student::apply_effect()
{
    if (energy.get() == 0)
        change_field(hp.get(), -25);
    if (energy.get() == 100)
        change_field(hp.get(), -10);
    if (sanity.get() <= 10)
        change_field(hp.get(), -(15 - sanity.get()));
    if (exci.get() < 25)
        change_field(sanity.get(), -5);
}
int main() {
    Student u1;

    int m;
    cin >> m;
    string s;
    for (int i = 0; i < m + 1; ++i)
    {
        getline(cin, s);
        if (s[0] == 'W')
        {
            if (s[2] == 'i')
            {
                u1.wait();
                u1.show();
            }
            else
            {
                u1.watch_tv();
                u1.show();
            }
        }
        if (s[0] == 'E')
        {
            u1.eat();
            u1.show();
        }
        if (s[0] == 'S')
        {
            if (s[1] == 't')
            {
                u1.study();
                u1.show();
            }
            else
            {
                u1.sleep();
                u1.show();
            }

        }
    }
    return 0;
}