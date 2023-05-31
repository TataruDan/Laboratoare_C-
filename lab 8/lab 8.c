#include <stdio.h>
#include <string.h>
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

void citire(struct stud_rec student[],int n) {
    for(int i = 0; i < n; i++) {
    printf("Introduceti Prenumele : ");
    scanf("%[^\n]", student[i].prenume);
    fflush(stdin);

    printf("Introduceti Numele : ");
    scanf("%[^\n]", student[i].nume);
    fflush(stdin);

    printf("Introduceti anul nasterii : ");
    scanf("%d", &student[i].an_nastere);

    printf("Introduceti adresa : ");
    fflush(stdin);
    scanf("%[^\n]", student[i].adresa);
    fflush(stdin);

    printf("Introduceti specialitate (ex. IA, SI ,TI etc.) : ");
    scanf("%s" , student[i].specialitate);

    printf("Introduceti nota la Programare : ");
    scanf("%d" , &student[i].prog);

    printf("Introduceti nota la Filozofie : ");
    scanf("%d" , &student[i].filoz);

    printf("Introduceti nota la Limba Engleza : ");
    scanf("%d" , &student[i].eng);
    printf("\n\n");

    fflush(stdin);
    }

};

void afisare(struct stud_rec af[], int n) {

    for(int i = 0 ; i  < n; i++) {
        printf("Prenumele : %s\n", af[i].prenume);
        printf("Numele : %s\n" , af[i].nume);
        printf("An nastere : %d\n" , af[i].an_nastere);
        printf("Adresa : %s\n", af[i].adresa);
        printf("Specialiatea  : %s\n", af[i].specialitate);
        printf("Nota Programare : %d\n", af[i].prog);
        printf("Nota Filozofie : %d\n", af[i].filoz);
        printf("Nota Limba Engleza : %d\n", af[i].eng);
        printf("----------------------------------------\n\n");
    }
};

void countingSort_an_nastere(struct stud_rec stud[], int n) {

  struct stud_rec output[10];

  int x = stud[0].an_nastere;
  for (int i = 1; i < n; i++) {
    if (stud[i].an_nastere > x)
      x = stud[i].an_nastere;
  }

   int count_arr[x + 1];

  for (int i = 0; i <= x; ++i) {
    count_arr[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    count_arr[stud[i].an_nastere]++;
  }

  for (int i = 1; i <= x; i++) {
    count_arr[i] += count_arr[i - 1];
  }


  for (int i = n-1 ; i >= 0; i--) {
    output[count_arr[stud[i].an_nastere] - 1] = stud[i];
    count_arr[stud[i].an_nastere]--;
  }

  for (int i = 0; i < n; i++) {
    stud[i] = output[i];
  }
}

void countingSort_prog(struct stud_rec stud[], int n) {

  struct stud_rec output[10];

  int x = stud[0].prog;
  for (int i = 1; i < n; i++) {
    if (stud[i].prog > x)
      x = stud[i].prog;
  }

   int count_arr[x + 1];

  for (int i = 0; i <= x; ++i) {
    count_arr[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    count_arr[stud[i].prog]++;
  }

  for (int i = 1; i <= x; i++) {
    count_arr[i] += count_arr[i - 1];
  }


  for (int i = n-1 ; i >= 0; i--) {
    output[count_arr[stud[i].prog] - 1] = stud[i];
    count_arr[stud[i].prog]--;
  }

  for (int i = 0; i < n; i++) {
    stud[i] = output[i];
  }
}

void counting_insert(struct stud_rec af[], int n, FILE *sf) {
    for(int i = 0 ; i  < n; i++) {
        fprintf(sf, "Prenumele : %s\n", af[i].prenume);
        fprintf(sf, "Numele : %s\n" , af[i].nume);
        fprintf(sf, "An nastere : %d\n" , af[i].an_nastere);
        fprintf(sf, "Adresa : %s\n", af[i].adresa);
        fprintf(sf, "Specialiatea  : %s\n", af[i].specialitate);
        fprintf(sf, "Nota Programare : %d\n", af[i].prog);
        fprintf(sf, "Nota Filozofie : %d\n", af[i].filoz);
        fprintf(sf, "Nota Limba Engleza : %d\n", af[i].eng);
        fprintf(sf, "\n\n");
    }
};

void swap(struct stud_rec *a, struct stud_rec *b)
{
    struct stud_rec t = *a;
    *a = *b;
    *b = t;
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

void quickSort_prog(struct stud_rec arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partion_prog(arr, low, high);

        quickSort_prog(arr, low, pi - 1);
        quickSort_prog(arr, pi + 1, high);
    }
}


int partion_an_nastere(struct stud_rec arr[], int low, int high)
{
   int pivot = arr[high].an_nastere;

    int i = (low - 1);

    for(int j = low; j <= high - 1; j++)
    {
        if(arr[j].an_nastere > pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort_an_nastere(struct stud_rec arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partion_an_nastere(arr, low, high);

        quickSort_an_nastere(arr, low, pi - 1);
        quickSort_an_nastere(arr, pi + 1, high);
    }
}

void quick_insert(struct stud_rec af[], int n, FILE *tf) {
    for(int i = 0 ; i  < n; i++) {
        fprintf(tf, "Prenumele : %s\n", af[i].prenume);
        fprintf(tf, "Numele : %s\n" , af[i].nume);
        fprintf(tf, "An nastere : %d\n" , af[i].an_nastere);
        fprintf(tf, "Adresa : %s\n", af[i].adresa);
        fprintf(tf, "Specialiatea  : %s\n", af[i].specialitate);
        fprintf(tf, "Nota Programare : %d\n", af[i].prog);
        fprintf(tf, "Nota Filozofie : %d\n", af[i].filoz);
        fprintf(tf, "Nota Limba Engleza : %d\n", af[i].eng);
        fprintf(tf, "\n\n");
    }
};

void calc(int n , struct stud_rec student[n],char spec[20]) {
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

    printf("Media pe obiecte de la specialitatea %s\n\n", spec);

     for(int i = 0 ; i  < n; i++) {
        if(strcmp(spec, student[i].specialitate) == 0) {
             printf("Prenumele : %s\n", student[i].prenume);
             printf("Numele : %s\n" , student[i].nume);
             printf("An nastere : %d\n" , student[i].an_nastere);
             printf("Adresa : %s\n", student[i].adresa);
             printf("Specialiatea  : %s\n", student[i].specialitate);
             printf("Nota Programare : %d\n", student[i].prog);
             printf("Nota Filozofie : %d\n", student[i].filoz);
             printf("Nota Limba Engleza : %d\n", student[i].eng);
             printf("----------------------------------------\n\n");
        }

    }

    printf("Media reusitei pentru obiectul Programare : %.2f \n", (sum_prog / contor));
    printf("Media reusitei pentru obiectul Filozofie : %.2f\n", (sum_filoz / contor));
    printf("Media reusitei pentru obiectul Limba engleza  : %.2f\n\n", (sum_eng / contor));
}

int main() {
    char spec[20];
    FILE *pf,*sf, *tf;
    int n = 3;
     struct stud_rec *student = (struct stud_rec*)malloc(sizeof(struct stud_rec) * n);



    citire(student,n);

     pf = fopen("experiment.txt" , "w");

        for(int i = 0 ; i < n; i++) {
        fprintf(pf, "Prenume : %s\n", student[i].prenume);
        fprintf(pf, "Nume : %s\n", student[i].nume);
        fprintf(pf, "An nastere : %d\n", student[i].an_nastere);
        fprintf(pf, "Adresa : %s\n", student[i].adresa);
        fprintf(pf, "Specialitatea : %s\n", student[i].specialitate);
        fprintf(pf, "Nota Programare : %d\n", student[i].prog);
        fprintf(pf, "Nota Filozofie : %d\n", student[i].filoz);
        fprintf(pf, "Nota Engleza : %d\n\n", student[i].eng);
    }

    fclose(pf);

    afisare(student,n);

    printf("Introduceti specialitatea : ");
    scanf("%s", spec);

    calc(n,student,spec);

    countingSort_an_nastere(student,n);
    printf("Sortarea ascendenta dupa anul de nastere\n\n");
    for(int i = 0 ; i  < n; i++) {
            if(strcmp(spec,student[i].specialitate) == 0) {
                printf("Prenumele : %s\n", student[i].prenume);
                printf("Numele : %s\n" , student[i].nume);
                printf("An nastere : %d\n" , student[i].an_nastere);
                printf("Adresa : %s\n", student[i].adresa);
                printf("Specialiatea  : %s\n", student[i].specialitate);
                printf("Nota Programare : %d\n", student[i].prog);
                printf("Nota Filozofie : %d\n", student[i].filoz);
                printf("Nota Limba Engleza : %d\n", student[i].eng);
                printf("----------------------------------------\n\n");
        }

    }
    sf = fopen("Counting-exp.txt", "w");

    fprintf(sf, "Sortarea ascendenta dupa anul de nastere\n\n");
    counting_insert(student,n,sf);

    countingSort_prog(student,n);
    printf("Sortarea ascendenta a notelor la programare\n\n");
     for(int i = 0 ; i  < n; i++) {
            if(strcmp(spec,student[i].specialitate) == 0) {
                printf("Prenumele : %s\n", student[i].prenume);
                printf("Numele : %s\n" , student[i].nume);
                printf("An nastere : %d\n" , student[i].an_nastere);
                printf("Adresa : %s\n", student[i].adresa);
                printf("Specialiatea  : %s\n", student[i].specialitate);
                printf("Nota Programare : %d\n", student[i].prog);
                printf("Nota Filozofie : %d\n", student[i].filoz);
                printf("Nota Limba Engleza : %d\n", student[i].eng);
                printf("----------------------------------------\n\n");
        }

    }

    fprintf(sf, "Sortarea ascendenta a notelor la programare\n\n");
    counting_insert(student,n,sf);

    fclose(sf);

    tf = fopen("Quick-exp.txt", "w");


    quickSort_an_nastere(student, 0, n - 1);
    fprintf(tf, "Sortarea descendenta dupa anul de nastere\n\n");
    quick_insert(student,n,tf);

     printf("Sortarea descendenta dupa anul de nastere\n\n");

    for(int i = 0 ; i  < n; i++) {
            if(strcmp(spec,student[i].specialitate) == 0) {
                printf("Prenumele : %s\n", student[i].prenume);
                printf("Numele : %s\n" , student[i].nume);
                printf("An nastere : %d\n" , student[i].an_nastere);
                printf("Adresa : %s\n", student[i].adresa);
                printf("Specialiatea  : %s\n", student[i].specialitate);
                printf("Nota Programare : %d\n", student[i].prog);
                printf("Nota Filozofie : %d\n", student[i].filoz);
                printf("Nota Limba Engleza : %d\n", student[i].eng);
                printf("----------------------------------------\n\n");
        }

    }


    quickSort_prog(student, 0, n - 1);

    fprintf(tf,"\n\n");
    fprintf(tf, "Sortarea descendenta a notelor la programare\n\n");
    quick_insert(student,n,tf);

    printf("Sortarea descendenta a notelor la programare\n\n");
     for(int i = 0 ; i  < n; i++) {
            if(strcmp(spec,student[i].specialitate) == 0) {
                printf("Prenumele : %s\n", student[i].prenume);
                printf("Numele : %s\n" , student[i].nume);
                printf("An nastere : %d\n" , student[i].an_nastere);
                printf("Adresa : %s\n", student[i].adresa);
                printf("Specialiatea  : %s\n", student[i].specialitate);
                printf("Nota Programare : %d\n", student[i].prog);
                printf("Nota Filozofie : %d\n", student[i].filoz);
                printf("Nota Limba Engleza : %d\n", student[i].eng);
                printf("----------------------------------------\n\n");
        }

    }


    return 0;
}
