#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nom[50];
    char prenom[50];
} Person;

void writePersonToFile(const char *filename, const Person *person)
{
    FILE *file = fopen(filename, "wb");
    if (file != NULL)
    {
        fwrite(person, sizeof(Person), 1, file);
        fclose(file);
    }
}

void readPersonFromFile(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file != NULL)
    {
        Person person;
        fread(&person, sizeof(Person), 1, file);
        printf("Nom: %s\n", person.nom);
        printf("Prenom: %s\n", person.prenom);
        fclose(file);
    }
}

int main()
{
    Person person = {"John", "Doe"};

    writePersonToFile("person.bin", &person);
    readPersonFromFile("person.bin");

    remove("person.bin"); // supprimer le fichier
    return 0;
}
