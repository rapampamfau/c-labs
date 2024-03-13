#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

// Struktura przechowująca kontakt
typedef struct {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_LENGTH];
} Contact;

// Tablica kontaktów
Contact contacts[MAX_CONTACTS];
int numContacts = 0;

// Funkcja dodająca nowy kontakt
void addContact(char *firstName, char *lastName, char *phoneNumber) {
    if (numContacts < MAX_CONTACTS) {
        strcpy(contacts[numContacts].firstName, firstName);
        strcpy(contacts[numContacts].lastName, lastName);
        strcpy(contacts[numContacts].phoneNumber, phoneNumber);
        numContacts++;
        printf("Kontakt został dodany.\n");
    } else {
        printf("Książka adresowa jest pełna.\n");
    }
}

// Funkcja wyszukująca kontakt po nazwisku
void findContact(char *lastName) {
    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].lastName, lastName) == 0) {
            printf("Imię: %s\n", contacts[i].firstName);
            printf("Nazwisko: %s\n", contacts[i].lastName);
            printf("Numer telefonu: %s\n", contacts[i].phoneNumber);
            found = 1;
        }
    }
    if (!found) {
        printf("Brak kontaktu o podanym nazwisku.\n");
    }
}

// Funkcja usuwająca kontakt po nazwisku
void deleteContact(char *lastName) {
    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].lastName, lastName) == 0) {
            for (int j = i; j < numContacts - 1; j++) {
                strcpy(contacts[j].firstName, contacts[j + 1].firstName);
                strcpy(contacts[j].lastName, contacts[j + 1].lastName);
                strcpy(contacts[j].phoneNumber, contacts[j + 1].phoneNumber);
            }
            numContacts--;
            printf("Kontakt został usunięty.\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Brak kontaktu o podanym nazwisku.\n");
    }
}

// Funkcja wypisująca wszystkie kontakty
void displayAllContacts() {
    if (numContacts == 0) {
        printf("Książka adresowa jest pusta.\n");
    } else {
        printf("Wszystkie kontakty w książce adresowej:\n");
        for (int i = 0; i < numContacts; i++) {
            printf("%d. Imię: %s, Nazwisko: %s, Numer telefonu: %s\n", i + 1, contacts[i].firstName, contacts[i].lastName, contacts[i].phoneNumber);
        }
    }
}

// Funkcja main - prosty interfejs użytkownika
int main() {
    int choice;
    char firstName[MAX_NAME_LENGTH], lastName[MAX_NAME_LENGTH], phoneNumber[MAX_PHONE_LENGTH];

    while (1) {
        printf("\nWybierz opcję:\n");
        printf("1. Dodaj kontakt\n");
        printf("2. Znajdź kontakt\n");
        printf("3. Usuń kontakt\n");
        printf("4. Wyświetl wszystkie kontakty\n");
        printf("5. Wyjdź\n");
        printf("Wybór: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Podaj imię: ");
                scanf("%s", firstName);
                printf("Podaj nazwisko: ");
                scanf("%s", lastName);
                printf("Podaj numer telefonu: ");
                scanf("%s", phoneNumber);
                addContact(firstName, lastName, phoneNumber);
                break;
            case 2:
                printf("Podaj nazwisko: ");
                scanf("%s", lastName);
                findContact(lastName);
                break;
            case 3:
                printf("Podaj nazwisko: ");
                scanf("%s", lastName);
                deleteContact(lastName);
                break;
            case 4:
                displayAllContacts();
                break;
            case 5:
                printf("Dziękujemy! Do widzenia.\n");
                return 0;
            default:
                printf("Niepoprawny wybór.\n");
        }
    }

    return 0;
}
