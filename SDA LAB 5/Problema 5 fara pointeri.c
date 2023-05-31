#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct stud_rec {
    char prenume[30];
    char nume[30];
    int an_nastere;
    char adresa[50];
    char specialitate[5];
    int prog;
    int filoz;
    int eng;
};

struct stud_rec citire(int i) {
    struct stud_rec student;
    printf("Introduceti Prenumele : ");
    scanf("%s" , student.prenume);

    printf("Introduceti Numele : ");
    scanf("%s", student.nume);

    printf("Introduceti anul nasterii : ");
    scanf("%d", &student.an_nastere);

    printf("Introduceti adresa : ");
    scanf("%s" , student.adresa);

    printf("Introduceti specialitate (ex. IA, SI ,TI etc.) : ");
    scanf("%s" , student.specialitate);

    printf("Introduceti nota la Programare : ");
    scanf("%d" , &student.prog);

    printf("Introduceti nota la Filozofie : ");
    scanf("%d" , &student.filoz);

    printf("Introduceti nota la Limba Engleza : ");
    scanf("%d" , &student.eng);
    printf("\n\n");

    return (student);
};

void afisare(struct stud_rec af[], int i) {

    printf("Prenumele : %s\n", af[i].prenume);
    printf("Numele : %s\n" , af[i].nume);
    printf("An nastere : %d\n" , af[i].an_nastere);
    printf("Adresa : %s\n", af[i].adresa);
    printf("Specialiatea  : %s\n", af[i].specialitate);
    printf("Nota Programare : %d\n", af[i].prog);
    printf("Nota Filozofie : %d\n", af[i].filoz);
    printf("Nota Limba Engleza : %d\n", af[i].eng);
    printf("----------------------------------------\n\n");

};

void calc(int n , struct stud_rec student[n],char spec[5]) {
        float sum_prog = 0, sum_filoz = 0, sum_eng = 0;

    int contor = 0;
    for(int i = 0 ; i  <n; i++) {
        if(strcmp(spec,student[i].specialitate) == 0) {
            afisare(student,i);
            sum_prog += student[i].prog;
            sum_filoz += student[i].filoz;
            sum_eng += student[i].eng;
            contor++;
        }
    }
    printf("Media reusitei pentru obiectul Programare : %.2f \n", (sum_prog / contor));
    printf("Media reusitei pentru obiectul Filozofie : %.2f\n", (sum_filoz / contor));
    printf("Media reusitei pentru obiectul Limba engleza  : %.2f\n\n", (sum_eng / contor));
}

void swap(struct stud_rec *a, struct stud_rec *b)
{
    struct stud_rec t = *a;
    *a = *b;
    *b = t;
}

void Ins_sort_prog(struct stud_rec p[], int n, char spec[]) {
int key;
int j;
    for (int i = 1; i < n; i++) {

                 key = p[i].prog;
                j = i - 1;

                while (j >= 0 && p[j].prog > key) {
                    swap(&p[j+1], &p[j]);

                    j = j - 1;
        }
        p[j + 1].prog = key;

    }
     printf("\n\nNotele aranjate in ordine ascendenta, la Programare, utilizand Insertion Sort : \n");

    for(int i = 0 ; i < n; i++) {
            if(strcmp(spec,p[i].specialitate) == 0) {
                    printf("%s\t\t%d\n" ,p[i].prenume,p[i].prog);
            }
    }
}

void Ins_sort_filoz(struct stud_rec p[], int n, char spec[]) {
int key, j;
    for (int i = 1; i < n; i++) {
        key = p[i].filoz;
        j = i - 1;

        while (j >= 0 && p[j].filoz > key) {
            swap(&p[j+1], &p[j]);
            j = j - 1;
        }
        p[j + 1].filoz = key;
    }
     printf("\n\nNotele aranjate in ordine ascendenta, la Filozofie, utilizand Insertion Sort : \n");

    for(int i = 0 ; i < n; i++) {
            if(strcmp(spec,p[i].specialitate) == 0) {
                    printf("%s\t\t%d\n" ,p[i].prenume,p[i].filoz);
            }
    }
}

void Ins_sort_eng(struct stud_rec p[], int n, char spec[]) {
int key, j;
    for (int i = 1; i < n; i++) {
        key = p[i].eng;
        j = i - 1;

        while (j >= 0 && p[j].eng > key) {
             swap(&p[j+1], &p[j]);
            j = j - 1;
        }
        p[j + 1].eng = key;
    }
     printf("\n\nNotele aranjate in ordine ascendenta, la Limba Engleza, utilizand Insertion Sort : \n");

    for(int i = 0 ; i < n; i++) {
            if(strcmp(spec,p[i].specialitate) == 0) {
                    printf("%s\t\t%d\n" ,p[i].prenume,p[i].eng);
            }
    }
}



int partion_prog(struct stud_rec arr[], int low, int high)
{
    int pivot = arr[high].prog;

    int i = (low - 1);

    for(int j = low; j <= high - 1; j++)
    {
        if(arr[j].prog > pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort_prog(struct stud_rec arr[], int low, int high,char spec[])
{
    if(low < high)
    {
        int pi = partion_prog(arr, low, high);

        quickSort_prog(arr, low, pi - 1,spec);
        quickSort_prog(arr, pi + 1, high,spec);
    }
}

int partion_filoz(struct stud_rec arr[], int low, int high)
{
    int pivot = arr[high].filoz;

    int i = (low - 1);

    for(int j = low; j <= high - 1; j++)
    {
        if(arr[j].filoz > pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort_filoz(struct stud_rec arr[], int low, int high,char spec[])
{
    if(low < high)
    {
        int pi = partion_filoz(arr, low, high);

        quickSort_filoz(arr, low, pi - 1,spec);
        quickSort_filoz(arr, pi + 1, high,spec);
    }
}

int partion_eng(struct stud_rec arr[], int low, int high)
{
    int pivot = arr[high].eng;

    int i = (low - 1);

    for(int j = low; j <= high - 1; j++)
    {
        if(arr[j].eng > pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort_eng(struct stud_rec arr[], int low, int high,char spec[])
{
    if(low < high)
    {
        int pi = partion_eng(arr, low, high);

        quickSort_eng(arr, low, pi - 1,spec);
        quickSort_eng(arr, pi + 1, high,spec);
    }
}



void schimbare (int n, struct stud_rec student[n]) {
     int nr_stud = 0;
    printf("Introduceti numarul studentului la care doriti sa realizati modificari : ");
    scanf("%d" , &nr_stud);
    if(nr_stud > n && nr_stud < 0) {
        printf("Asa elev nu este prezent in lista : ");
    }

        printf("Ce doriti sa inlocuiti : \n");
        int sc = 0;
        printf("Numele - 1 : Prenumele  - 2 : Anul Nasterii - 3 : Adresa - 4\nSpecialitatea - 5: Nota Programare : - 6 : Nota Filozofie - 7 : Nota Engleza - 8 \n\n");
        scanf("%d" , &sc);
        switch(sc) {
            case 1 : {
                printf("Numele : ");
                scanf("%s" , student[nr_stud - 1].nume);
                printf("\n");
                      for(int i = 0 ; i < n; i++) {
                        afisare(student,i);
                        }
                    break;
            };

            case 2 : {
                printf("Prenumele : ");
                scanf("%s", student[nr_stud - 1].prenume);
                printf("\n");
                     for(int i = 0 ; i < n; i++) {
                        afisare(student,i);
                        }
                    break;
            };

            case 3: {
                printf("Anul Nasterii : ");
                scanf("%d" , &student[nr_stud - 1].an_nastere);
                printf("\n");
                    for(int i = 0 ; i < n; i++) {
                        afisare(student,i);
                        }
                    break;
            };

            case 4 : {
                printf("Adresa : ");
                scanf("%s" , student[nr_stud - 1].adresa);
                printf("\n");
                    for(int i = 0 ; i < n; i++) {
                    afisare(student,i);
                    }
                break;
            };

            case 5 : {
                printf("Specialitatea : ");
                scanf("%s" , student[nr_stud - 1].specialitate);
                printf("\n");
                    for(int i = 0 ; i < n; i++) {
                    afisare(student,i);
                    }
                break;
            };

            case 6 : {
                printf("Nota Programare : ");
                scanf("%d", &student[nr_stud - 1].prog);
                printf("\n");
                    for(int i = 0 ; i < n; i++) {
                    afisare(student,i);
                    }
                break;
            };

            case 7 : {
                printf("Nota Filozofie : ");
                scanf("%d", &student[nr_stud - 1].filoz);
                printf("\n");
                    for(int i = 0 ; i < n; i++) {
                    afisare(student,i);
                    }
                break;
            };

            case 8 : {
                printf("Nota Engleza : ");
                scanf("%d" , &student[nr_stud - 1].eng);
                printf("\n");
                    for(int i = 0 ; i < n; i++) {
                    afisare(student,i);
                    }
                break;
            }
        }
}


int main() {
    int n = 4;
    struct stud_rec *student = (struct stud_rec*)malloc(sizeof(struct stud_rec) * n);

    for(int i = 0 ; i < n ;i++) {
        student[i] = citire(i);
    }

    for(int i = 0 ; i < n; i++) {
        afisare(student,i);
    }


    int checker;
    printf("Daca doriti sa inregistrati careva modificari, introduceti 1, in caz contrar 0 : ");
    scanf("%d", &checker);
    int ver = 1;
    if(checker != 1) {

    } else{
        while(ver == 1) {
            schimbare(n,student);
            printf("Mai doriti sa realizati careva schimbari (1 - DA | 0 - NU) : ");
            scanf("%d", &ver);
        }

    }
        char spec[5];
        printf("Introduceti specialitatea : ");
        scanf("%s", spec);
        printf("\n");
        calc(n, student,spec);

        Ins_sort_prog(student,n,spec);
        Ins_sort_filoz(student,n,spec);
        Ins_sort_eng(student,n,spec);

        printf("\n\n------------------------------------------------------------------------------\n");

        quickSort_prog(student, 0, n - 1,spec);

        printf("\n\nNotele aranjate in ordine descendenta, la Programare, utilizand Quick Sort : \n");

        for(int i = 0; i < n; i++)
        {

            if(strcmp(spec,student[i].specialitate) == 0) {
                printf("%s\t\t%d\n" ,student[i].prenume,student[i].prog);
            }
        }

        quickSort_filoz(student,0,n-1,spec);

        printf("\n\nNotele aranjate in ordine descendenta, la Filozofie, utilizand Quick Sort : \n");

        for(int i = 0; i < n; i++)
        {

            if(strcmp(spec,student[i].specialitate) == 0) {
                printf("%s\t\t%d\n" ,student[i].prenume,student[i].filoz);
            }
        }

        quickSort_eng(student,0,n-1,spec);

        printf("\n\nNotele aranjate in ordine descendenta, la Engleza, utilizand Quick Sort : \n");

        for(int i = 0; i < n; i++)
        {

            if(strcmp(spec,student[i].specialitate) == 0) {
                printf("%s\t\t%d\n" ,student[i].prenume,student[i].eng);
            }
        }

        free(student);

    return 0;
}
