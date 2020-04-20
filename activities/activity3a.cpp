/****************************************************************************
 *
 * Activity 3: Example Linked List
 *
 * File Name:  activity3a.cpp
 * Course:     CPTR 242
 *
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct nodeTag Node;

/* similar to the textbook -- a Node represents one node in the linked list */
struct nodeTag {
  int num;    // value stored in node
  Node *next; // pointer to next node in list
};

/* function prototypes on linked lists */
Node *makeNode(int n, Node *nextItem);
int length(Node *list);
void print(Node *list);
void insertTail(int n, Node **list);
Node *find(int n, Node *list);
int remove(Node *toRemove, Node **listPtr);

/* main function */
int main(void) {
  // create linked list
  Node *top = NULL;
  top = makeNode(6, top);
  top = makeNode(10, top);
  top = makeNode(-3, top);
  top = makeNode(2, top);
  print(top);

  // q1: What does the picture of top look like now?
  int len = length(top);
  printf("Length of list: %d\n", len);

  // q2: What is the value of len?
  insertTail(25, &top);
  print(top);

  // q3: What does the picture of top look like now?
  Node *ten = find(10, top);
  if (ten == NULL) {
    printf("Not found: 10\n");
  } else {
    printf("Found: 10, memory location: %p\n", ten);
  }
  printf("removing 10:\n");
  int ret = remove(ten, &top);
  print(top);

  // q4: What does the picture of top look like now?
  printf("removing 2:\n");
  Node *two = find(2, top);
  ret = remove(two, &top);
  print(top);

  // q5: What does the picture of top look like now?
  printf("removing 15:\n");
  Node *fifteen = find(15, top);
  ret = remove(fifteen, &top);
  print(top);
  return EXIT_SUCCESS;
}

/********************* function definitions *****************/
/**
 *  makeNode
 * parameters -- n (the number to store in the node)
 *            -- nextItem (the next link of the node)
 * slightly different than textbook version */
Node *makeNode(int n, Node *nextItem) {
  Node *ret = (Node *)malloc(sizeof(Node));
  ret->num = n;
  ret->next = nextItem;
  return ret;
}

/**
 * length
 * parameter -- list (the linked list)
 * returns the length (# nodes) in the linked list
 * implemented iteratively */
int length(Node *list) {
  int len = 0;
  while (list != NULL) {
    len++;
    list = list->next;
  }
  return len;
}

/**
 * print
 * parameter -- list (the linked list)
 * prints the values of the nodes (in order) of the list
 */
void print(Node *list) {
  printf("Linked list contents: ");
  while (list != NULL) {
    printf("%d ", list->num);
    list = list->next;
  }
  printf("\n");
}

/**
 * insertTail
 * parameters -- n (the value of the node to insert)
 *            -- list (the linked list)
 * inserts new node at the end with value n
 * note: this is done by passing the pointer to list, so
 * when the function returns, the list object that was
 * passed to this function has been altered
 */
void insertTail(int n, Node **listPtr) {
  Node *list = *listPtr;
  if (list == NULL) {
    // create a 1-node list
    *listPtr = makeNode(n, NULL);
    return;
  }
  while (list != NULL) {
    if (list->next == NULL) {
      // insert new node here since we found the last node
      list->next = makeNode(n, NULL);
      return;
    }
    list = list->next;
  }
}

/**
 *  find
 * parameters -- n (the value to search for)
 *            -- list (the linked list)
 * returns a pointer to the first node found with value n
 * if no such value is found, returns NULL
 */
Node *find(int n, Node *list) {
  while (list != NULL) {
    if (list->num == n) {
      return list;
    }
    list = list->next;
  }
  // no node with value n found
  return NULL; // or could return list, since list has value NULL
}

/**
 * remove
 * parameters -- toRemove (the node to find and remove)
 *            -- listPtr (pointer to the list)
 * note: must pass listPtr in case the first element of the list
 * is removed -- passing the list by reference, so the address
 * to the first item in the list can get updated if necessary
 *
 * returns 0 if no item found and removed
 * returns 1 if a node is removed
 */
int remove(Node *toRemove, Node **listPtr) {
  Node *list = *listPtr; // list is the linked list
  // case: either toRemove or list is null -- will not be removing
  if (toRemove == NULL || list == NULL) {
    return 0; // indicates no change to the list
  }
  // special case: toRemove is first node in list
  if (toRemove == list) {
    *listPtr = list->next;
    // now list->next becomes first node in list
    // returning new first address via pointer
    free(toRemove);
    return 1; // indicates that a node was removed
  }
  // case: need to find toRemove somewhere other than first node in list
  Node *before = list;
  list = list->next;
  while (list != NULL) {
    if (toRemove == list) {
      // redo pointers and then free memory
      before->next = list->next;
      free(list);
      return 1;
    }
    before = list; // update for next iteration
    list = list->next;
  }
  return 0;
  // toRemove not found
}