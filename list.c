#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bList {
    int val;
    struct bList *prev, *next;
} list;

list *firstList(list *l)
{
    while (l->next != NULL)
        l = l->next;

    return l;
}

list *lastList(list *l)
{
    while (l->prev != NULL)
        l = l->prev;

    return l;
}

list *addList(list *l, int n)
{
    list *newList = malloc(sizeof(list));
    newList->val = n;
    newList->next = NULL;

    if (!l) {
        l = newList;
        l->prev = NULL;
    } else {
        l->next = newList;
        l->next->prev = l;
        l = l->next;
    }
    return l;
}

list *delList(list *l, int n)
{
    if (!l) {
        return l;
    } else {
        list *tmp = l;
        while (tmp != NULL) {
            if (tmp->val == n) {
                if (tmp->prev == NULL) {
                    list *next = tmp->next;
                    next->prev = NULL;
                    free(tmp);
                    return firstList(next);
                } else if (tmp->next == NULL) {
                    list *prev = tmp->prev;
                    prev->next = NULL;
                    free(tmp);
                    return prev;
                } else if (tmp->prev == NULL && tmp->next == NULL) {
                    tmp = NULL;
                    free(l);
                    return tmp;
                } else {
                    list *prev = tmp->prev;
                    prev->next = tmp->next;
                    prev->next->prev = prev;
                    free(tmp);
                    return firstList(prev);
                }
            }
            tmp = tmp->prev;
        }
        free(tmp);
        return l;
    }
}

list *delFirst(list *l)
{
    if (!l) {
        return l;
    } else {
        if (l->prev == NULL) {
            l = NULL;
            return l;
        } else {
            list *prev = l->prev;
            prev->next = NULL;
            free(l);

            return prev;
        }
    }
}

list *delLast(list *l)
{
    if (!l) {
        return l;
    } else {
        l = lastList(l);

        if (l->next == NULL) {
            l = NULL;
            return l;
        } else {
            list *next = l->next;
            next->prev = NULL;
            free(l);
            return firstList(next);
        }
    }
}

void print(list *l) {
    while (l != NULL) {
        if (l->prev == NULL)
            printf("%d\n", l->val);
        else
            printf("%d ", l->val);
        l = l->prev;
    }
}

void delAll(list *l)
{
    while (l->prev != NULL) {
        l = l->prev;
        free(l->next);
    }
    free(l);
}