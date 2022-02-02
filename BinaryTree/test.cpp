#include<iostream>

using namespace std;

struct node
{
        int data;
        int height;
        
        node* left;
        node* right;
};

class AVL
{


    node* root;

    void makeEmpty(node* t)
    {
        if(t == NULL)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }

    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->height = 0;
            t->left = NULL;
            t->right = NULL;
        }
        else if(x < t->data)
        {
            t->left = insert(x, t->left);
            if(height(t->left) - height(t->right) == 2)
            {
                if(x < t->left->data)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if(x > t->data)
        {
            t->right = insert(x, t->right);
            if(height(t->right) - height(t->left) == 2)
            {
                if(x > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }

        t->height = max(height(t->left), height(t->right))+1;
        return t;
    }

       node* singleRightRotate(node* &t)
	{
		if (t->left != NULL) {
			node* u = t->left;
			t->left = u->right;
			u->right = t;
			t->height = max(height(t->left), height(t->right)) + 1;
			u->height = max(height(u->left), t->height) + 1;
			return u;
		}
		return t;
	}
	node* singleLeftRotate(node* &t)
	{
            if (t->right != NULL) {
		    node* u = t->right;
		    t->right = u->left;
		    u->left = t;
		    t->height = max(height(t->left), height(t->right)) + 1;
		    u->height = max(height(t->right), t->height) + 1;
		    return u;
            }
            return t;
	}

    node* doubleLeftRotate(node* &t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    node* doubleRightRotate(node* &t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    /*node* remove(int x, node* t)
    {
        node* temp;

        // Element not found
        if(t == NULL)
            return NULL;

        // Searching for element
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);

        // Element found
        // With 2 children
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        // With one or zero child
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        if(t == NULL)
            return t;

        t->height = max(height(t->left), height(t->right))+1;

        // If node is unbalanced
        // If left node is deleted, right case
        if(height(t->left) - height(t->right) == -2)
        {
            // right right case
            if(height(t->right->right) - height(t->right->left) == 1)
                return singleLeftRotate(t);
            // right left case
            else
                return doubleLeftRotate(t);
        }
        // If right node is deleted, left case
        else if(height(t->right) - height(t->left) == 2)
        {
            // left left case
            if(height(t->left->left) - height(t->left->right) == 1){
                return singleRightRotate(t);
            }
            // left right case
            else
                return doubleRightRotate(t);
        }
        return t;
    }*/

    int height(node* t)
    {
        return (t == NULL ? -1 : t->height);
    }

    int getBalance(node* t)
    {
        if(t == NULL)
            return 0;
        else
            return height(t->left) - height(t->right);
    }

    void inorder(node* t)
    {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

public:
    AVL()
    {
        root = NULL;
    }

    void insert(int x)
    {
        root = insert(x, root);
    }

  /*  void remove(int x)
    {
        root = remove(x, root);
    }*/

    void display()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    AVL t;
    int array[]={100,55,50,45,47,70,80,78,77,79,82,81,83,150,140,
    135,142,143,180,170,165,160,175,173,200,190,195,500,1000,1500,2000,3000,4000,5000,6000,7000,8000,9000};

    for(int i=0;i<38;i++){
          t.insert(array[i]);
    }
    cout << "insertion done" << endl;

   /* t.remove(45);
    t.remove(47);
    t.remove(50);
    t.remove(55);
    t.remove(70);
    t.remove(77);
    t.remove(78);
    t.remove(79);
    t.remove(80);
    t.remove(81);
    t.remove(82);
    t.remove(83);
    t.remove(100);
    t.remove(135);
    //cout << "Now I remove 140" << endl;
    t.remove(142);*/

    t.display();
}