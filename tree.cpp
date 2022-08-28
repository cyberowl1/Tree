TRee implementation and almost all tree queries .
------------------------------------------------


#include <bits/stdc++.h>

using namespace std;

 struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    int hd;
}Node;

struct Node* newNode(int data)
{
    struct Node* node= (struct Node*)malloc(sizeof(Node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}
int height(struct Node* node);
void traverse(struct Node* root)
{
   if(root==NULL)
   {
       return;
   }
   traverse(root->left);
   cout<<root->data<<" ";
   traverse(root->right);
}
// void insert(struct Node* temp, int key)
// {
//     queue<struct Node*> q;
//     q.push(temp);
//     while (!q.empty()) {
//         struct Node* temp = q.front();
//         q.pop();
//         if (!temp->left) {
//             temp->left = newNode(key);
//             break;
//         } else
//             q.push(temp->left);
//         if (!temp->right) {
//             temp->right = newNode(key);
//             break;
//         } else
//             q.push(temp->right);
//     }
// }
// void insert(struct Node* root, int data)
// {
//     queue<struct Node*> q;
//     q.push(root);
//     while(!q.empty())
//     {
//         struct Node* temp=q.front();
//         q.pop();
//         if(temp->left==NULL)
//         {
//             temp->left=newNode(data);
//             break;
//         }

//         else
//         {
//                      q.push(temp->left);

//         }
//         if(temp->right==NULL)
//         {
//             temp->right=newNode(data);
//             break;
//         }
//         else
//         {
//          q.push(temp->right);
// }
//     }
// }
void insert(struct Node* root,int data) {
   struct Node *tempNode = root;
   struct Node *current;
   struct Node *parent;

   tempNode->data = data;
   tempNode->left = NULL;
   tempNode->right = NULL;

   //if tree is empty
   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent = NULL;

      while(1) {
         parent = current;

         //go to left of the tree
         if(data < parent->data) {
            current = current->left;
            //insert to the left

            if(current == NULL) {
               parent->left = tempNode;
               return;
            }
         }//go to right of the tree
         else {
            current = current->right;

            //insert to the right
            if(current == NULL) {
               parent->right = tempNode;
               return;
            }
         }
      }
   }
}
void levelOrderTraverse(struct Node* root)
{
    if (root==NULL)return;

    queue<struct Node*> q;
    q.push(root);
    while(!q.empty())
    {
        struct Node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
}
void topview(struct Node* root)
{
    if(root==NULL)return;
    queue<struct Node*> q;
    map<int,int>mp;
    int hd=0;
    root->hd=hd;
    q.push(root);

    while(q.size())
    {
        hd=root->hd;
        if(mp.count(hd)==0)
        {
            mp[hd]=root->data;
}
        if(root->left)
        {
            root->left->hd=hd-1;
            q.push(root->left);
        }
        if(root->right)
        {
            root->right->hd=hd+1;
            q.push(root->right);
        }
        q.pop();
        root=q.front();
    }

    for(auto u:mp)
    {
        cout<<u.second<<" ";
    }
}
void bottomview(struct Node* root)
{
    if(root==NULL)return;
    queue<struct Node*> q;
    map<int,int> mp;
    int hd=0;
    root->hd=hd;
    q.push(root);
    while(!q.empty())
    {
     struct Node* temp=q.front();
        hd=temp->hd;
        mp[hd]=temp->data;
        q.pop();
        if(temp->left!=NULL)
        {
            temp->left->hd=hd-1;
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            temp->right->hd=hd+1;
            q.push(temp->right);
        }

    }

    for(auto u:mp){
        cout<<u.second<<" ";
    }
}
void bottomView(struct Node *root)
{
    if (root == NULL)
        return;

    // Initialize a variable 'hd' with 0
    // for the root element.
    int hd = 0;

    // TreeMap which stores key value pair
    // sorted on key value
    map<int, int> m;

    // Queue to store tree nodes in level
    // order traversal
    queue<struct Node *> q;

    // Assign initialized horizontal distance
    // value to root node and add it to the queue.
    root->hd = hd;
    q.push(root);  // In STL, push() is used enqueue an item

    // Loop until the queue is empty (standard
    // level order loop)
    while (!q.empty())
    {
        struct Node *temp = q.front();
        q.pop();   // In STL, pop() is used dequeue an item

        // Extract the horizontal distance value
        // from the dequeued tree node.
        hd = temp->hd;

        // Put the dequeued tree node to TreeMap
        // having key as horizontal distance. Every
        // time we find a node having same horizontal
        // distance we need to replace the data in
        // the map.
        m[hd] = temp->data;

        // If the dequeued node has a left child, add
        // it to the queue with a horizontal distance hd-1.
        if (temp->left != NULL)
        {
            temp->left->hd = hd-1;
            q.push(temp->left);
        }

        // If the dequeued node has a right child, add
        // it to the queue with a horizontal distance
        // hd+1.
        if (temp->right != NULL)
        {
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }

    // Traverse the map elements using the iterator.
    for (auto i = m.begin(); i != m.end(); ++i)
        cout << i->second << " ";
}
void leftview(struct Node* root)
{
    queue<struct Node*> q;
    if(root==NULL)
    {
        return;
    }
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        struct Node* temp=q.front();
        if(temp)
        {
            cout<<temp->data<<" "<<endl;

        while(q.front()!=NULL)
        {
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
            q.pop();
            temp=q.front();
        }
        q.push(NULL);
        }
        q.pop();
    }
}
void rightview(struct Node* root)
{
    queue<struct Node*> q;
    if(root==NULL)
    {
        return;
    }
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        struct Node* temp=q.front();
        if(temp)
        {
            cout<<temp->data<<" "<<endl;

        while(q.front()!=NULL)
        {
            if(temp->right)
            {
                q.push(temp->right);
            }
            if(temp->left)
            {
                q.push(temp->left);
            }
            q.pop();
            temp=q.front();
        }
        q.push(NULL);
        }
        q.pop();
    }
}

int diameter(struct Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lheight=height(root->left);
    int rheight= height(root->right);
    int ldiam= diameter(root->left);
    int rdiam= diameter(root->right);
    return max(lheight+rheight+1,max(ldiam,rdiam));
}
int height(struct Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left),height(root->right));
}

int main (){
    struct Node *root;
    // insert(root,2);
    // insert(root,3);
    // insert(root,4);
    // insert(root,5);
    // insert(root,6);
    // insert(root,7);
    insert(root,1);
      insert(root,2);
        insert(root,3);
          insert(root,4);  insert(root,5);
            insert(root,5);
              insert(root,6);  insert(root,7);

    // root->left=newNode(2);
    // root->right=newNode(4);
    // root->left->left=newNode(6);
    // root->right->right=newNode(9);
    // insert(root,8);
    traverse(root);
cout<<"height of tree:"<<height(root)<<endl;
cout<<"diameter of tree:"<<diameter(root)<<endl;
cout<<"leftView:";leftview(root);
rightview(root);
cout<<"topview:";
topview(root);
cout<<endl;
cout<<"level order:-";
levelOrderTraverse(root);
cout<<endl;
cout<<"bottom:";
bottomView(root);
}
