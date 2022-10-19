#include <iostream>
#include <conio.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node *tree = nullptr;

void insert(int a, Node **t)
{

    if ((*t) == NULL)
    {
        (*t) = new Node;
        (*t)->data = a;
        (*t)->right = (*t)->left = nullptr;
        return;
    }
    if (a > (*t)->data)
        insert(a, &(*t)->left);

    else
        insert(a, &(*t)->right);
}

void print(Node *t, int u)
{
    if (t == nullptr)
        return;
    else
    {
        print(t->left, ++u);
        for (int i = 0; i < u; ++i)
            cout << "   ";
        cout << t->data << endl;
        u--;
    }
    print(t->right, ++u);
}

int d = 0;

int wrtreelast1(Node *t)
{

    if (t == nullptr)
        return d;
    if (t->data != 0)
    {
        d++;
    }

    wrtreelast1(t->left);
    return d;
}
bool _find(Node *node, int value)
{
    if (node == nullptr)
        return false;

    if (_find(node->right, value))
        return true;

    if (node->data == value)
    {
        return true;
    }
    if (_find(node->left, value))
        return true;

    return false;
}
bool find(Node *t, int el)
{
    return _find(t, el);
}
Node *deltree(Node *t)
{
    if (t == nullptr)
        return nullptr;
    deltree(t->left);
    deltree(t->right);
    delete (t);
    t = nullptr;
    return nullptr;
}

void wrtree(Node *t)
{
    if (t == nullptr)
        return;
    cout << t->data << " ";
    wrtree(t->left);
    wrtree(t->right);
}

void wrtree1(Node *t)
{
    if (t == nullptr)
        return;

    wrtree(t->left);
    cout << t->data << " ";
    wrtree(t->right);
}

void wrtree2(Node *t)
{
    if (t == nullptr)
        return;

    wrtree(t->left);
    wrtree(t->right);
    cout << t->data << " ";
}

int Depth(Node *t)
{
    if (t == nullptr)
        return 0;

    int left = Depth(t->left);
    int right = Depth(t->right);
    if (left > right)
        return left + 1;
    else
        return right + 1;
}

bool IsBalanced(Node *node)
{
    if (node == nullptr)
        return true;
    int left, right;

    if (IsBalanced(node->left) && IsBalanced(node->right))
    {
        left = Depth(node->left);
        right = Depth(node->right);
        if (left - right == 1 || right - left == 1 || left == right)
            return true;
        else
            return false;
    }
    else
        return false;
}

int main()
{
    int k;

    int count, temp;
    cout << "Введите количество элементов  ";
    cin >> count;
    for (int i = 0; i < count; ++i)
    {
        cout << "Введите элемент ";
        cin >> temp;
        if (i == 1)
        {
            k = temp;
        }
        insert(temp, &tree);
    }

    cout << "Дерево\n";
    print(tree, 0);
    if (IsBalanced(tree))
        cout << "Это сбалансированное дерево" << endl;
    else
        cout << "Это НЕ сбалансированное дерево" << endl;
    cout << "Количества узлов правой ветви дерева: " << wrtreelast1(tree) - 1;
    int f;
    cout << "\n\n";
    cout << "\n Введите элемент, который нужно найти ";
    cin >> f;
    if (find(tree, f))
        cout << "элемент есть в дереве\n ";
    else
        cout << "элементa в дереве нет\n";
    cout << "прямой обход: \n";
    wrtree(tree);
    cout << "\n симметричный обход: \n";
    wrtree1(tree);
    cout << "\n обратный обход: \n";
    wrtree2(tree);
}