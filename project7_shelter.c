#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Name your program project7_shelter.c.
// The input file name is animals.txt Download animals.txt.
// The user will enter the species and gender. For example, “cat” and “female”.
// The data file has the format of name (one word), species (one word), gender (one word), age (int), weight (double), with each animal on a separate line.
// Use fscanf to read data.
// The program should be built around an array of animal structures, with each animal containing information of name, species, gender, age, and weight.
// Your program needs to keep track of the number of animals in the file as it reads from it.
// Assume that there are no more than 200 items in the file. Assume the name, species, and gender of an animal is no more than 100 characters.
// Output file should be named as result.txt.
// Output files should include name, age, weight (2 decimal digits) of the matching animals.

//The data file has the format of name (one word), species (one word), 
//gender (one word), age (int), weight (double), with each animal on a separate line.

struct Animal
{
    char name[101];
    char species[101];
    char gender[101];
    int age;
    double weight;
};

int main(){

    FILE *fp0 = fopen("animals.txt", "r");
    //FILE *fp1 = fopen("intermediate.txt", "w");
    FILE *fp2 = fopen("results.txt", "w");

    struct Animal animals[200];

    int numAnimals = 0, count = 0, index = 1;
    char species[100], gender[100];

    while (!(feof(fp0)) && !(ferror(fp0)))
    {
        fscanf(fp0, "%s %s %s %d %lf", animals[numAnimals].name, animals[numAnimals].species, animals[numAnimals].gender, &animals[numAnimals].age, &animals[numAnimals].weight);
        //fprintf(fp1, "%s %s %s %d %.2f", animals[numAnimals].name, animals[numAnimals].species, animals[numAnimals].gender, animals[numAnimals].age, animals[numAnimals].weight);

        numAnimals++;

    }

    printf("Enter Species: ");
    scanf("%s", species);

    printf("Enter Gender: ");
    scanf("%s", gender);


    while (count < numAnimals)
    {
        if ((strcmp((species), (animals[count].species)) == 0) && ((strcmp((gender), (animals[count].gender)) == 0))) {
            fprintf(fp2, "%d    %s  %d  %.2f \n", index++, animals[count].name, animals[count].age, animals[count].weight);
        }
        count++;
    }
    
    // char c;

    // for (int i = 0; i < 38; i++)
    // {
    //     printf("%s %s %s %d %.2f\n" , animals[i].name, animals[i].species, animals[i].gender, animals[i].age, animals[i].weight);
    // }


    //specifying search parameters




    
}
