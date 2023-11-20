#include "sort.h"


void swap_node_ahead(listint_t **list, listint_t **down, listint_t **up);
void swap_node_behind(listint_t **list, listint_t **down, listint_t **up);
void cocktail_sort_list(listint_t **list);


/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @down: A pointer to the down of the doubly-linked list.
 * @up: A pointer to the current swapping node of the cocktail up algo.
 */
void swap_node_ahead(listint_t **list, listint_t **down, listint_t **up)
{
    listint_t *tmp = (*up)->next;


    if ((*up)->prev != NULL)
        (*up)->prev->next = tmp;
    else
        *list = tmp;
    tmp->prev = (*up)->prev;
    (*up)->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = *up;
    else
        *down = *up;
    (*up)->prev = tmp;
    tmp->next = *up;
    *up = tmp;
}


/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @down: A pointer to the down of the doubly-linked list.
 * @up: A pointer to the current swapping node of the cocktail up algo.
 */
void swap_node_behind(listint_t **list, listint_t **down, listint_t **up)
{
    listint_t *tmp = (*up)->prev;


    if ((*up)->next != NULL)
        (*up)->next->prev = tmp;
    else
        *down = tmp;
    tmp->next = (*up)->next;
    (*up)->prev = tmp->prev;
    if (tmp->prev != NULL)
        tmp->prev->next = *up;
    else
        *list = *up;
    (*up)->next = tmp;
    tmp->prev = *up;
    *up = tmp;
}


/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail up algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *down, *up;
    bool shaken_not_stirred = false;


    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;


    for (down = *list; down->next != NULL;)
        down = down->next;


    while (shaken_not_stirred == false)
    {
        shaken_not_stirred = true;
        for (up = *list; up != down; up = up->next)
        {
            if (up->n > up->next->n)
            {
                swap_node_ahead(list, &down, &up);
                print_list((const listint_t *)*list);
                shaken_not_stirred = false;
            }
        }
        for (up = up->prev; up != *list;
                up = up->prev)
        {
            if (up->n < up->prev->n)
            {
                swap_node_behind(list, &down, &up);
                print_list((const listint_t *)*list);
                shaken_not_stirred = false;
            }
        }
    }
}


