#include <iostream>

using std::cout;

struct TreeNode
{
    int key;
    short a, b, c;
    int sum;
    TreeNode *left = nullptr, *right = nullptr;

    TreeNode(int key, int a, int b, int c)
    {
        this->key = key;
        this->a = a;
        this->b = b;
        this->c = c;
        this->sum = a + b + c;
    }

    TreeNode()
    {
        this->a = 0;
        this->b = 0;
        this->c = 0;
        this->sum = 0;
    };
};

class Tree
{
private:
    TreeNode *root = nullptr;

    void show(TreeNode *node, int deep)
    {
        if (node == nullptr)
            return;

        show(node->left, deep + 1);
        for (int i = 0; i < deep; i++)
            cout << "  ";
        cout << node->key << "\n";
        show(node->right, deep + 1);
    }

public:
    int size = 0;

    void DeleteElement(int key)
    {
        auto node = findNode(key);
        DeleteElement(node, findParent(node));
    }

    void DeleteElement(TreeNode *node, TreeNode *parent)
    {
        if (node->right == nullptr && node->left == nullptr)
        {
            delete node;
            if (parent->left == node)
                parent->left = nullptr;
            else
                parent->right = nullptr;
        }
        else if (node->right != nullptr)
            DeleteElement(node->right, node);
        else
            DeleteElement(node->left, node);
    }

    TreeNode *findParent(TreeNode *child)
    {
        return findParent(child, root);
    }

    TreeNode *findParent(TreeNode *child, TreeNode *main)
    {
        if (main->right == child || main->left == child)
            return main;
        else if (child->key > main->key)
            return findParent(child, main->right);
        else
            return findParent(child, main->left);
    }

    TreeNode *findNode(int key)
    {
        return findNode(key, root);
    }

    TreeNode *findNode(int key, TreeNode *now)
    {
        if (key == now->key)
            return now;
        else if (key > now->key)
            return findNode(key, now->right);
        else
            return findNode(key, now->left);
    }

    TreeNode *findPlace(int key, TreeNode *now)
    {
        if (key == now->key)
        {
            cout << "уже занятый ключ";
            exit(1);
        }
        if (key > now->key)
        {
            if (now->right == nullptr)
            {
                now->right = new TreeNode;
                return now->right;
            }
            else
                return findPlace(key, now->right);
        }
        else
        {
            if (now->left == nullptr)
            {
                now->left = new TreeNode;
                return now->left;
            }
            else
                return findPlace(key, now->left);
        }
    }

    void addElement(int key, int a, int b, int c)
    {
        TreeNode *place = findPlace(key, root);
        place->key = key;
        place->a = a;
        place->b = b;
        place->c = c;
        place->sum = a + b + c;
        size += 1;
    }
    Tree(int key, int a, int b, int c)
    {
        root = new TreeNode;
        root->key = key;
        root->a = a;
        root->b = b;
        root->c = c;
        size = 1;
    }

    void show()
    {
        if (root == nullptr)
            return;
        show(root->left, 0);
        std::cout << root->key << " root\n";
        show(root->right, 0);
    }
};

int main()
{
    Tree test(10, 1, 2, 3);
    test.addElement(13, 2, 4, 5);
    test.addElement(15, 2, 5, 6);
    test.addElement(8, 3, 2, 1);
    test.addElement(7, 3, 2, 1);
    test.addElement(11, 3, 2, 1);
    test.addElement(12, 3, 2, 1);

    test.show();

    test.DeleteElement(12);
    cout << "\n";
    test.show();
}