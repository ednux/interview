#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

typedef struct node
{
    char data;
    struct node *next;
} **NODE;

NODE list_create(void);
int list_insert(NODE node, struct node data);
int list_remove_duplicates(NODE node);
void list_free(NODE node);
int list_print(NODE node);

int main(int argc, char **argv)
{
    NODE email_thread = NULL;

    email_thread = list_create();

    srand (time(NULL));

    struct node data = {{0x00}, NULL};

    /* Insert 100 nodes to email_thread using numbers as messages */
    for (int i = 0; i < 10; i++)
    {
        data.data = (char) (rand() % 10 + 48);
        if (!list_insert(email_thread, data))
        {
            cout << "Failed to insert" << endl;
        }
    }

    cout << "Before remove duplicates: ";
    list_print(email_thread);

    cout << "\nRemoved " << list_remove_duplicates(email_thread) << " duplicates" << endl;

    cout << "\nAfter remove duplicates: ";
    list_print(email_thread);

    list_free(email_thread);

    return 0;
}

NODE list_create(void)
{
    NODE node = (NODE) malloc(sizeof(struct node*));
	if (node != NULL)
    {
        *node = NULL;
    }
	return node;
}

void list_free(NODE node)
{
    if (node != NULL)
    {
		struct node *tmp;
		while ((*node) != NULL)
        {
			tmp = *node;
			*node = (*node)->next;
			free(tmp);
		}
		free(node);
        node = NULL;
	}
}

int list_insert(NODE node, struct node data)
{
	if (node == NULL)
    {
        return 0;
    }
	struct node *tmp = (struct node*) malloc(sizeof(struct node));
	if (tmp == NULL)
    {
        return 0;
    } 
	*tmp = data;
	if ((*node) == NULL)
    {
        *node = tmp;
    }
	else
    {
		struct node *current = *node;
		while (current->next != NULL)
        {
            current = current->next;
        }
		current->next = tmp;
	}
	return 1;
}

int list_remove_duplicates(NODE node)
{
    if (node == NULL || *node == NULL)
    {
        return 0;
    }
    int duplicates = 0;
	struct node *tmp = *node;
    struct node *next = NULL;
    struct node *prev = NULL;
    while (tmp != NULL)
    {
        prev = tmp;
        next = tmp->next;
        while (next != NULL)
        {
            if (tmp->data == next->data)
            {
                /* remove duplicate */
                prev->next = next->next;
                free(next);
                next = prev;
                duplicates++;
            }
            prev = next;
            next = next->next;
        }
        tmp = tmp->next;
    }
	return duplicates;
}

int list_print(NODE node)
{
	if (node == NULL || *node == NULL)
    {
        return 0;
    }
	struct node *tmp = *node;
    cout << endl;
	while (tmp != NULL)
    {
        cout << tmp->data;
        if ((tmp = tmp->next) != NULL)
        {
            cout << ", ";
        }
        else
        {
            cout << ".";
        }
	}
    cout << endl;
	return 1;
}