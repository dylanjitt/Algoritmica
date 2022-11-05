#include <bits/stdc++.h>
using namespace std;

struct node
{
    // cada nodo almacena un mapa hacia sus hijos
    unordered_map<char, node*> map;
 
    // true cuando el nodo es un nodo hoja o final
    bool isLeaf = false;
 
    // colecciona y almacena una lista completa de palabras en el nodo hoja
    unordered_set<string> word;
};
 
// Funcion para insertar un string en un trie
void insert(node*& head, string word)
{
    if (head == nullptr) {
        head = new node();
    }
 
    node* curr = head;
    for (char c: word)
    {
        // Insertar unicamente letras mayusculas
        if (isupper(c))
        {
            // crea un nuevo nodo si un camino previo no existe
            if (curr->map.find(c) == curr->map.end()) {
                curr->map[c] = new node();
            }
 
            // va al siguiente nodo
            curr = curr->map[c];
        }
    }
 
    // marca el nodo actual como nodo hoja
    curr->isLeaf = true;
 
    // empuja el nodo actual en un set asociado con un nodo hoja
    (curr->word).insert(word);
}
 
// funcion para imprimir todos los hijos de un trie node asignado
void print(node* root)
{
    // si el nodo actual es hoja, imprime todas las palabras asociadas a este
    if (root->isLeaf)
    {
        unordered_set<string> collection = root->word;
        for (string s: collection) {
            cout << s << endl;
        }
    }
 
    // recurre a todos los hijos del nodo root o principal
    for (auto pair: root->map)
    {
        node* child = pair.second;
        if (child) {
            print(child);
        }
    }
}
 
// funcion para imprimir todas las palabrabras en diccionario CamelCase
void findWord(vector<string> const &diccionario, string patron)
{
    // caso base
    if (diccionario.size() == 0) {
        return;
    }
 
    // nodo cabeza del trie
    node* head = nullptr;
 
    // construye un trie desde un diccionario asignado
    for (string s: diccionario) {
        insert(head, s);
    }
 
    // busca un patron especificado en el trie
    node* curr = head;
    for (char c: patron)
    {
        // va hacia el nodo hijo
        curr = curr->map[c];
 
        // si no se encuentra el patron asignado 
        if (curr == nullptr) {
            return;
        }
    }
 
    // imprimir todas las palabras que coincidan con el patron asignado
    print(curr);
}
 
int main()
{
    vector<string> diccionario {
        "Hi", "HiTech", "HiTechCity", "Techie", "TechieDelight",
        "Hello", "HelloWorld", "HiTechLab"
    };
 
    string patron = "HT";
 
    findWord(diccionario, patron);
 
    return 0;
}
