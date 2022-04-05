#include <iostream>
#include <conio.h>

struct OldTree 
{
    std::string eng_word; // Английское слово
    std::string rus_word; // Русское слово
    int count; // Счётчик
    bool active;
    OldTree *l, *r;
};

OldTree *oTree = NULL;

struct NewTree
{
    std::string eng_word; // Английское слово
    std::string rus_word; // Русское слово
    int count; // Счётчик
    NewTree *l, *r;
};

NewTree *nTree = NULL;

void push(std::string eng, std::string rus, int count, OldTree **t)
{
    if((*t) == NULL)
    {
        (*t) = new OldTree;
        (*t)->eng_word = eng;
        (*t)->rus_word = rus;
        (*t)->count = count;
        (*t)->active = true;
        (*t)->l = (*t)->r = NULL;
        return;
    }
    if (eng.compare((*t)->eng_word) == 1) 
        push(eng, rus, count, &(*t)->r);
    else 
        push(eng, rus, count, &(*t)->l);
}

void print (OldTree *t, int u)
{
    if (t == NULL) return;
    else
    {
        print(t->l, ++u);
        // for (int i=0; i<u; ++i) std::cout << "\n";
        std::cout << std::endl << t->eng_word << std::endl << t->rus_word << std::endl << t->count << std::endl;
        u--;
    }
    print(t->r, ++u);
}





int main()
{
    setlocale(LC_ALL, "Russian");
    // OldTree tmp_tree = {"apple", "яблоко", 23, true};
        // "big", "большой", 10. true;
        // "cian", "голубой", 12, true;
        // "door", "дверь", 35, true;

    push("apple", "яблоко", 23, &oTree);
    push("big", "большой", 10, &oTree);
    push("door", "дверь", 35, &oTree);
    push("cian", "голубой", 12, &oTree);
    
    
    print(oTree, 0);
    

    return 0;
}