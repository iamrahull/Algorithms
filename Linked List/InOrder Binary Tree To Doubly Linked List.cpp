void helperFunction( Node *root, Node **listHead, Node **listIterator)
{
    if(root==NULL) return;
    
    helperFunction(root->left, listHead, listIterator);
    
    if(*listHead==NULL)
    {
        *listHead=root;
        *listIterator=root;
    }
    else
    {
        root->left=*listIterator;
        (*listIterator)->right=root;
    }
    
    *(listIterator)=root;
    
    helperFunction(root->right, listHead, listIterator);
    
}
Node * binaryTreeToDLL(Node *root)
{
    Node* listHead=NULL, *listIterator;
    
    helperFunction(root,&listHead, &listIterator);
    
    return listHead;
}

// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/

