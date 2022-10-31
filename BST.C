#include <Stdio.h>
#include <stdlib.h>
#include <malloc.h>
// NODE FOR A  BINARY SEARCH TREE DECLARED
struct node
{
    int data;
    struct node *left_child;
    struct node *right_child;
};

struct node *insert(struct node *root, int val) // root , q , follow = null , p points to root , so q also points to root.
{
    struct node *q = root;
    struct node *follow = NULL;
    struct node *p = (struct node *)malloc(sizeof(struct node)); // node
    p->data = val;
    p->left_child = NULL;
    p->right_child = NULL;

    if (root == NULL) // case 1 - where the tree is empty , and the first node that will be inserted will become the root of the binary search tree
    {
        root = p;    // node p inserted to root.
        return root; // 10
    }

    while (q != NULL)
    {
        follow = q;            // we ask follow to be in line with pointing to root
        if (p->data > q->data) // 15>10
        {
            q = q->right_child; // traverse to the right // q points to the right child of root 10
        }
        else
        {
            q = q->left_child; // traverse to the left
        }
    }

    if (p->data > follow->data)
    {
        follow->right_child = p; // insert value towards in the right child
    }
    else
    {
        follow->left_child = p; // insert value towards in the left child
    }
    return root;
}
struct node *Delete(struct node *root, int val)
{
    struct node *p = root;
    struct node *follow = NULL;
    struct node *q = p;
    struct node *fp = NULL;
    int y;

    if (p == NULL) // DIRECTLY TERMINATE THE PROGRAM IF P POINTS TO NULL , THAT IS THERE IS NO VALUE IN THE TREE
    {
        printf("ELEMENT NOT FOUND\n");
        return root;
    }

    while (p->data != NULL && p != NULL) // THIS LOOP IS TO SEND THE POINTER P TO THE VALUE WE WANT TO DELETE
    {                                    // AFTER THE VALUE IS FOUND THE LOOP TERMINATES AND THE EXECUTION GOES FURTHUR
        if (val > p->data)
        {
            p = p->right_child;
        }
        else
        {
            p = p->left_child;
        }
    }

    // now we will check the nodes if they have left or right child or not  10,15,8 - 15 needs to be deleted.
    // case 1 where left and right child are null
    if (p->left_child == NULL && p->right_child == NULL)
    {
        if (follow != NULL)
        {
            if (follow->right_child == p)
            {
                follow->right_child = NULL;
            }
            else
            {
                follow->left_child = NULL;
            }
            free(p);
            return root;
        }
        else
            return NULL;
    }

    // case 2 - where there is one child of that particular node
    if (p->left_child == NULL || p->right_child == NULL)
    {
        if (follow->right_child == p) // p lying in the right side of follow
        {
            if (p->right_child != NULL)
            {
                if (follow != NULL)
                    follow->right_child = p->right_child;
                else
                    root = p->right_child;
            }
            else
            {
                if (follow != NULL)
                    follow->left_child = p->left_child;
                else
                    root = p->left_child;
            }
        }
        if (follow->left_child == p)
        {
            if (p->left_child != NULL)
            {
                if (follow != NULL)
                    follow->left_child = p->left_child;
                else
                    root = p->left_child;
            }
            else
            {
                if (follow != NULL)
                    follow->left_child = p->right_child;
                else
                    root = p->right_child;
            }
        }
        free(p);
        return root;
    }

    q = p->left_child;

    // case 3 - when the node to be deleted has two child // TO UNDERSTAND THIS
    while (q->right_child != NULL)
    {
        fp = q;
        q = q->right_child;
    }
    y = p->data;
    p->data = q->data; // EXCHANGE PROCESS
    q->data = y;
    if (q->left_child == NULL && q->right_child == NULL)
    {
        if (fp != NULL)
            fp->right_child = NULL;
        else
            p->left_child = NULL;
    }
    if (q->left_child == NULL || q->right_child == NULL)
    {
        if (fp != NULL)
            fp->right_child = q->left_child;
        else
            p->left_child = q->left_child;
    }
    free(q);
    return root;
}
void display(struct node *root)
{
    if (root != NULL)
    {
        display(root->left_child);
        printf("%d", root->data);
        display(root->right_child);
    }
}
int main()
{
    struct node *root = NULL;
    int c, v;
    while (c != 4)
    {
        printf("ENTER 1 - TO INSERT NODE\n");
        printf("ENTER 2 - TO DELETE NODE\n");
        printf("ENTER 3 - TO DISPLAY TREE\n");
        printf("ENTER 4 - EXIT\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("ENTER THE VALUE TO BE INSERTED\n");
            scanf("%d", &v);
            root = insert(root, v);
            if (root != NULL)
                display(root);
            else
                printf("TREE IS EMPTY\n");
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &v);
            root = Delete(root, v);
            if (root != NULL)
                display(root);
            else
                printf("Tree is empty");
            break;
        case 3:
            if (root != NULL)
                display(root);
            else
                printf("Tree is empty");
            break;
        default:
            printf("INVALID INPUT\n");
            break;
        }
    }
    return 0;
}