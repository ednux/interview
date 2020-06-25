#include <iostream>
#include <string>

using namespace std;

typedef struct node
{
    string data;
    struct node *next;
} NODE;


NODE *list_create(void);
void list_insert(NODE node);
void list_remove_duplicates();
void list_free(NODE *node);

int main(int argc, char **argv)
{
    return 0;
}