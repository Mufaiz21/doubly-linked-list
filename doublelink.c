#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
struct Node* insert_at_head(struct Node* head, int data) {
    struct Node* new_node = create_node(data);
    new_node->next = head;
    if(head != NULL) {
        head->prev = new_node;
    }
    return new_node; // new head
}
struct Node* insert_at_tail(struct Node* head, int data) {
    struct Node* new_node = create_node(data);
    if(head == NULL) return new_node;

    struct Node* temp = head;
    while(temp->next != NULL) temp = temp->next;

    temp->next = new_node;
    new_node->prev = temp;

    return head;
}

struct Node* insert_after_node(struct Node* head, struct Node* prev_node, int data) {
    if(prev_node == NULL) return head;

    struct Node* new_node = create_node(data);
    new_node->next = prev_node->next;
    new_node->prev = prev_node;

    if(prev_node->next != NULL) {
        prev_node->next->prev = new_node;
    }
    prev_node->next = new_node;

    return head;
}


void print_forward(struct Node* head) {
    struct Node* temp = head;
    printf("Forward: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void print_backward(struct Node* head) {
    if(head == NULL) return;

    struct Node* temp = head;
    while(temp->next != NULL) temp = temp->next;

    printf("Backward: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}


int main() {
    struct Node* head = NULL;

    
    head = insert_at_head(head, 10);
    head = insert_at_head(head, 20);
    head = insert_at_head(head, 30);

    head = insert_at_tail(head, 40);
    head = insert_at_tail(head, 50);

   
    struct Node* temp = head;
    while(temp != NULL && temp->data != 20) temp = temp->next;
    head = insert_after_node(head, temp, 99);

    
    print_forward(head);
    print_backward(head);

    return 0;
}
