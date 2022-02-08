int count(Tree root)
{
    if (root != NULL)
    {
        return 1 + count(root->left) + count(root->right);
    }
    return 0;
}

int isABC(Tree root)
{
    if (root == NULL)
        return 0;
    if (root->left != NULL)
    {
        if (root->left->value < root->value)
            return 1;
        else
            return 0;
    }
    if (root->right != NULL)
    {
        if (root->right->value > root->value)
            return 1;
        else
            return 0;
    }
    return (isABC(root->left)) && (isABC(root->right));
}

Tree cauta_subarbore_maximal(Tree root)
{
    int nr_stanga = count(root->left);
    int nr_dreapta = count(root->right);
    if (nr_stanga < nr_dreapta) //Inseamna ca subarborele drept are mai multe noduri
    {
        if (isABC(root->right))
            return root->right;
        else
            return cauta_subarbore_maximal(root->right);
    }
    else if (nr_stanga > nr_dreapta)
    {
        if (isABC(root->left))
            return root->left;
        else
            return cauta_subarbore_maximal(root->left);
    }
}
