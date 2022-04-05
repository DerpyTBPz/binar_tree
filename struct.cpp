// #include "stdafx.h"
#include "windows.h"
#include <cstdlib> 
#include <math.h>
#include <iostream> 
#include <string> 
using namespace std;
#pragma hdrstop 
 
using std::string;
using std::cout;
using std::endl;
using std::cin;


struct tree
{
    string eng;            //английское слово 
    string rus;            //русский перевод 
    int count;             //количество обращений 
    tree *left;
    tree *right;
};
string temp_eng;
string temp_rus;
int temp_count;
int level = 0;
 

tree *first(string eng, string rus, int count);

tree *search_insert(tree *root, string eng, string rus, int count);
 

void print_tree(tree *p, int level);
 
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
 
    int vibor;
    tree *root = NULL;
    do {
        cout << "Select: " << endl;
        cout << "1| Add to vocabulary" << endl; //Добавить в словарь
        cout << "2| Exit" << endl; //Выйти
        cout << "3| Output tree on screen" << endl; //вывести дерево на экран
        cout << "4) Write ENG word and find RU translation" << endl; //Ввести англ. слово на экран и найти его перевод
        cout << "5) Delete word from vocabulary" << endl; // Удалить слово из словоря
        cin >> vibor;
        switch (vibor)
        {
        case 1: 
        {cout << "Write eng word: " << endl;
            cin >> temp_eng;
            cout << "Write translation for this word: " << endl;
            cin >> temp_rus;
            cout << "Write counter value: " << endl;
            cin >> temp_count;
            //создание первого элемента дерева 
            if (!root) root = first(temp_eng, temp_rus, temp_count);
            //создание элементо-потомков дерева 
            else root = search_insert(root, temp_eng, temp_rus, temp_count);
 
        }; break;
        case 2: return 0; break;
        case 3: print_tree(root, 0); break;
        default: cout << "You have to push key from 1 to 5" << endl;
            break;
        }
    }
 
    while (vibor != 3);
    system("pause");
    return 0;
}
 
//--------------------------------------------------------------------------- 
// Функции программы: 

// Функция фрмирования первого элемента дерева: 
tree *first(string temp_eng, string temp_rus, int count)
{
    tree *pv = new tree;
    pv->eng = temp_eng;
    pv->rus = temp_rus;
    pv->count = temp_count;
    pv->left = 0;
    pv->right = 0;
    return pv;
}

// Функция поиска и добавления элемента в дерево: 
tree *search_insert(tree *root, string temp_eng, string temp_rus, int temp_count)
{
    
    tree *pv = root, *prev;
    bool found = false;
    //поиск по дереву 
    prev = pv;
    while (pv && !found) {
    
        if (temp_eng == pv->eng) found = true;
        else if (temp_count < pv->count) pv = pv->left;
        else pv = pv->right;
    }
    if (found) return pv;
    //создание нового узла 
    tree *pnew = new tree;
    pnew->eng = temp_eng;
    pnew->rus = temp_rus;
    pnew->count = temp_count;
    pnew->left = 0;
    pnew->right = 0;
    if (temp_count < prev->count) prev->left = pnew; //присоединение к левому поддереву предка 
    else prev->right = pnew;                    //присоединение к правому поддереву предка 
    return pnew;
}

// Функция показа дерева 
void print_tree(tree *p, int level)
{
    if (p)
    {
        print_tree(p->left, level + 1);
        for (int i = 0; i<level; i++)
            cout << "   ";
        cout << p->eng;
        for (int i = 0; i<level; i++)
            cout << "   ";
        cout << p->rus;
        for (int i = 0; i<level; i++)
            cout << "   ";
        cout << p->count;
        print_tree(p->right, level + 1);
    }
}