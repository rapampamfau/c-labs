#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void add_first(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);

    new_node->next = *head_ref;
    *head_ref = new_node;
}

int pop(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Lista jest pusta, nie można usunąć elementu.\n");
        return -1;
    }

    struct Node* temp = *head_ref;
    int popped_data = temp->data;
    *head_ref = temp->next;
    free(temp);

    return popped_data;
}

int remove_last(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Lista jest pusta, nie można usunąć elementu.\n");
        return -1;
    }

    if ((*head_ref)->next == NULL) {
        int data = (*head_ref)->data;
        free(*head_ref);
        *head_ref = NULL;
        return data;
    }

    struct Node* temp = *head_ref;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    int data = temp->next->data;

    free(temp->next);
    temp->next = NULL;

    return data;
}

int remove_by_index(struct Node** head_ref, int index) {
    if (*head_ref == NULL) {
        printf("Lista jest pusta, nie można usunąć elementu.\n");
        return -1;
    }

    struct Node* temp = *head_ref;

    if (index == 0) {
        *head_ref = temp->next;
        int data = temp->data;
        free(temp);
        return data;
    }

    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Indeks jest poza zakresem.\n");
        return -1;
    }

    struct Node* next = temp->next->next;
    int data = temp->next->data;
    free(temp->next);

    temp->next = next;

    return data;
}

int remove_by_value(struct Node** head_ref, int value) {
    if (*head_ref == NULL) {
        printf("Lista jest pusta, nie można usunąć elementu.\n");
        return -1;
    }

    struct Node* temp = *head_ref;

    if (temp->data == value) {
        *head_ref = temp->next;
        int data = temp->data;
        free(temp);
        return data;
    }

    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Element o wartości %d nie został znaleziony w liście.\n", value);
        return -1;
    }

    struct Node* next = temp->next->next;
    int data = temp->next->data;
    free(temp->next);

    temp->next = next;

    return data;
}

void add_at_index(struct Node** head_ref, int index, int data) {
    struct Node* new_node = createNode(data);

    if (index < 0) {
        printf("Indeks nie może być mniejszy niż 0.\n");
        return;
    }

    if (index == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    struct Node* temp = *head_ref;
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Indeks jest poza zakresem.\n");
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    add_first(&head, 10);
    add_first(&head, 20);
    add_first(&head, 30);
    add_first(&head, 40);
    add_first(&head, 50);
    add_first(&head, 60);

    printf("Lista przed usunięciem pierwszego elementu:\n");
    printList(head);

    int removed_first_data = pop(&head);

    if (removed_first_data != -1) {
        printf("Usunięto element o wartości: %d\n", removed_first_data);
    }

    printf("Lista po usunięciu pierwszego elementu:\n");
    printList(head);

    printf("Lista przed usunięciem ostatniego elementu:\n");
    printList(head);

    int removed_last_data = remove_last(&head);

    if (removed_last_data != -1) {
        printf("Usunięto ostatni element o wartości: %d\n", removed_last_data);
    }

    printf("Lista po usunięciu ostatniego elementu:\n");
    printList(head);

    printf("Lista przed usunięciem elementu:\n");
    printList(head);

    int removed_data_by_index = remove_by_index(&head, 2);

    if (removed_data_by_index != -1) {
        printf("Usunięto element o wartości: %d\n", removed_data_by_index);
    }

    printf("Lista po usunięciu elementu:\n");
    printList(head);

    printf("Lista przed operacją:\n");
    printList(head);

    int removed_data = remove_by_value(&head, 20);

    if (removed_data != -1) {
        printf("Usunięto element o wartości: %d\n", removed_data);
    }

    printf("Lista po usunięciu elementu:\n");
    printList(head);

    add_at_index(&head, 2, 70);

    printf("Lista po dodaniu elementu:\n");
    printList(head);
    return 0;
}
