#pragma once
#include <iostream>
#include <string>
using namespace std;

static const int SIZE = 15;

class TABLE {
private:
    class ITEM {
    public:
        string car;
        ITEM* next;
    };
    ITEM* item[SIZE];

public:
    TABLE()
    {
        for (int i = 0; i < SIZE; i++) {
            item[i] = new ITEM;
            item[i]->car = "";
            item[i]->next = NULL;
        }
    }

    ~TABLE() = default;

    int Hash(string key)
    {
        int sum = 0;
        for (int i = 0; i < key.length(); i++) {
            sum += (int)key[i];
        }
        return sum % SIZE;
    }

    int Number(int i)
    {
        int n = 0;
        if (this->item[i]->car == "") {
            return n;
        }
        else {
            n++;
            ITEM* ptr = this->item[i];
            while (ptr->next != NULL) {
                n++;
                ptr = ptr->next;
            }
        }
        return n;
    }

    void Insert(string key)
    {
        int i = Hash(key);
        if (this->item[i]->car == "") {
            this->item[i]->car = key;
        }
        else {
            ITEM* ptr = this->item[i];
            ITEM* n = new ITEM;
            n->car = key;
            n->next = NULL;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = n;
        }
    }

    void Print()
    {
        for (int i = 0; i < SIZE; i++) {
            cout << "i[" << i << "]"
                << " - " << item[i]->car << endl;
        }
    }


    void Delete(string key)
    {
        int i = Hash(key);
        ITEM* del;
        ITEM* p1;
        ITEM* p2;
        if (this->item[i]->car == "") {
            cout << key << " not foud" << endl;
        }
        else if (this->item[i]->car == key && item[i]->next == NULL) {
            this->item[i]->car = "";
            cout << key << " deleted" << endl;
        }
        else if (this->item[i]->car == key) {
            del = this->item[i];
            this->item[i] = this->item[i]->next;
            delete del;
            cout << key << " deleted" << endl;
        }
        else {
            p1 = this->item[i]->next;
            p2 = this->item[i];
            while (p1 != NULL && p1->car != key) {
                p2 = p1;
                p1 = p1->next;
            }
            if (p1 == NULL) {
                cout << key << " not found" << endl;
            }
            else {
                del = p1;
                p1 = p1->next;
                p2->next = p1;
                delete del;
                cout << key << " deleted" << endl;
            }
        }
    }

    void Member(string key)
    {
        int i = Hash(key);
        bool find = false;
        string car;
        ITEM* ptr = this->item[i];
        while (ptr != NULL) {
            if (ptr->car == key) {
                find = true;
                car = ptr->car;
            }
            ptr = ptr->next;
        }
        if (find == true) {
            cout << "Car: " << car << endl;
            cout << "i: " << i << endl;
        }
        else {
            cout << "Not found" << endl;
        }
    }

};

int main()
{
    TABLE hash;
    string car;
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter item in hash-item: ";
        getline(cin, car);
        hash.Insert(car);
        cout << endl;
    }
    system("cls");
    hash.Print();
    cout << "Eneter key for find item: ";
    getline(cin, car);
    hash.Member(car);
    cout << "Enter key for delete item: ";
    getline(cin, car);
    hash.Delete(car);
}
