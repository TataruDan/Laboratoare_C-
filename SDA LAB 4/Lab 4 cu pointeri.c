#include <stdio.h>
#include <string.h>
#include <stdbool.h>


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

void afisare(struct stud_rec *af,int i ) {

    printf("Prenumele : %s\n", (af + i)->prenume);
    printf("Numele : %s\n" , (af + i)->nume);
    printf("An nastere : %d\n" , (af + i)->an_nastere);
    printf("Adresa : %s\n", (af + i)->adresa);
    printf("Specialiatea  : %s\n", (af + i)->specialitate);
    printf("Nota Programare : %d\n", (af + i)->prog);
    printf("Nota Filozofie : %d\n", (af + i)->filoz);
    printf("Nota Limba Engleza : %d\n", (af + i)->eng);
    printf("----------------------------------------\n\n");

};

void calc(int n , struct stud_rec *student,char spec[5]) {
        float sum_prog = 0, sum_filoz = 0, sum_eng = 0;

    int contor = 0;
    for(int i = 0 ; i  <n; i++) {
        if(strcmp(spec,(student+i)->specialitate) == 0) {
            afisare(student,i);
            sum_prog += (student + i)->prog;
            sum_filoz += (student + i)->filoz;
            sum_eng += (student + i)->eng;
            contor++;

        }
    }
    printf("Media reusitei pentru obiectul Programare : %.2f \n", (sum_prog / contor));
    printf("Media reusitei pentru obiectul Filozofie : %.2f\n", (sum_filoz / contor));
    printf("Media reusitei pentru obiectul Limba engleza  : %.2f\n\n", (sum_eng / contor));
}

void Bsort_prog(struct stud_rec *p, int n,char spec[]) {
    struct stud_rec temp;
    for(int k = 0 ; k < n; k++) {
        if(strcmp(spec,(p + k)->specialitate) == 0){
            for(int i =  k ; i < n - 1; i++) {
              for(int j = 0 ; j < n - 1 - i; j++) {
                if((p + j)->prog > (p + (j + 1))->prog) {
                temp = *(p + j);
                *(p + j)= *(p + (j + 1));
                *(p + (j + 1))= temp;
            }
        }
    }
        }
    }

     printf("\n\nNotele aranjate in ordine ascendenta, la Programare, utilizand Bubble Sort : \n");

    for(int i = 0 ; i < n; i++) {
            if(strcmp(spec,(p + i)->specialitate) == 0) {
                printf("%s\t\t%d\n" ,(p + i)->prenume,(p + i)->prog);
            }
    }
}

void Bsort_filoz(struct stud_rec *p, int n,char spec[]) {
    struct stud_rec temp;
    for(int k = 0 ; k < n; k++) {
        if(strcmp(spec,(p + k)->specialitate) == 0) {
                for(int i = k; i < n - 1; i++) {
                for(int j = 0 ; j < n - i - 1; j++) {
                if((p + j)->filoz > (p + (j + 1))->filoz) {
                temp = *(p + j);
                *(p + j) = *(p + (j + 1));
                *(p + (j + 1)) = temp;
            }
        }
    }
        }
    }

     printf("\n\nNotele aranjate in ordine ascendenta, la Filozofie, utilizand Bubble Sort : \n");

    for(int i = 0 ; i < n; i++) {
            if(strcmp(spec,(p + i)->specialitate) == 0) {
                printf("%s\t\t%d\n" ,(p + i)->prenume,(p + i)->filoz);
            }

    }
}

void Bsort_eng(struct stud_rec *p, int n, char spec[]) {
    struct stud_rec temp;
    for(int k = 0 ; k < n; k++) {
        if(strcmp(spec,(p + k)->specialitate) == 0) {
                for(int i = k ; i < n - 1; i++) {
                for(int j = 0 ; j < n - i - 1; j++) {
                if((p + j)->eng > (p + (j + 1))->eng) {
                temp = *(p + j);
                *(p + j) = *(p + (j + 1));
                *(p + (j + 1)) = temp;
            }
        }
    }
        }
    }


     printf("\n\nNotele aranjate in ordine ascendenta, la Limba Engleza, utilizand Bubble Sort : \n");

    for(int i = 0 ; i < n; i++) {
            if(strcmp(spec,(p + i)->specialitate) == 0) {
                    printf("%s\t\t%d\n" ,(p + i)->prenume,(p + i)->eng);
            }

    }
}

void selection_sort_prog(int n , struct stud_rec *p,int length, char spec[]){
    struct stud_rec temp;
        for(int k = 0  ; k  < n ; k++) {
            if(strcmp(spec,(p+k)->specialitate) == 0) {
            for(int i = k ;i < length - 1; i++) {
                int min = i;
                for(int j = i+1 ; j < length; j++) {
                    if((p + j)->prog > (p + min)->prog) {
                        min = j;
                }
            }
            if(min != i) {
                temp = *(p + i);
                *(p + i) = *(p + min);
                *(p + min) = temp;
            }
            }
        }
        }


         printf("\n\nNotele aranjate in ordine ascendenta, la Programare, utilizand Selection Sort : \n");
        for(int k = 0; k < n; k++) {
                if(strcmp(spec,(p + k)->specialitate) == 0) {
                    printf("%s\t\t%d\n" ,(p + k)->prenume,(p + k)->prog);
                }

        }
}

void selection_sort_filoz(int n , struct stud_rec *p,int length, char spec[]){
    struct stud_rec temp;
    for(int k = 0 ; k < n ;k++) {
        if(strcmp(spec,(p + k)->specialitate) == 0){
            for(int i = k ;i < length - 1; i++) {
            int min = i;
            for(int j = i+1 ; j < length; j++) {
                if((p + j)->filoz > (p + min)->filoz) {
                    min = j;
                }
            }
            if(min != i) {
                temp =  *(p + i);
                *(p + i) = *(p + min);
               *(p + min) = temp;
            }
        }

        }
    }

         printf("\n\nNotele aranjate in ordine ascendenta, la Filozofie, utilizand Selection Sort : \n");
        for(int k = 0; k < n; k++) {
                if(strcmp(spec,(p + k)->specialitate) == 0) {
                    printf("%s\t\t%d\n" ,(p + k)->prenume,(p + k)->filoz);
                }

        }
}

void selection_sort_eng(int n , struct stud_rec *p,int length, char spec[]){
    struct stud_rec temp;
      for(int k = 0 ; k < n ; k++) {
        if(strcmp(spec,(p + k)->specialitate) == 0) {
            for(int i = k ;i < length - 1; i++) {
            int min = i;
            for(int j = i+1 ; j < length; j++) {
                if((p + j)->eng > (p + min)->eng) {
                    min = j;
                }
            }
            if(min != i) {
                temp = *(p + i);
                *(p + i) = *(p + min);
                *(p + min) = temp;
            }
        }
        }
      }


         printf("\n\nNotele aranjate in ordine ascendenta, la Limba Engleza, utilizand Selection Sort : \n");
        for(int k = 0; k < n; k++) {
                if(strcmp(spec,(p + k)->specialitate) == 0) {
                    printf("%s\t\t%d\n" ,(p + k)->prenume,(p + k)->eng);
                }

        }
}


void schimbare (int n, struct stud_rec *student) {
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
                scanf("%s" , (student + (nr_stud - 1) )->nume);
                printf("\n");
                      for(int i = 0 ; i < n; i++) {
                        afisare(student,i);
                        }
                    break;
            };

            case 2 : {
                printf("Prenumele : ");
                scanf("%s", (student + (nr_stud - 1) )->prenume);
                printf("\n");
                     for(int i = 0 ; i < n; i++) {
                        afisare(student,i);
                        }
                    break;
            };

            case 3: {
                printf("Anul Nasterii : ");
                scanf("%d" , &(student + (nr_stud - 1) )->an_nastere);
                printf("\n");
                    for(int i = 0 ; i < n; i++) {
                        afisare(student,i);
                        }
                    break;
            };

            case 4 : {
                printf("Adresa : ");
                scanf("%s" , (student + (nr_stud - 1) )->adresa);
                printf("\n");
                    for(int i = 0 ; i < n; i++) {
                    afisare(student,i);
                    }
                break;
            };

            case 5 : {
                printf("Specialitatea : ");
                scanf("%s" , (student + (nr_stud - 1) )->specialitate);
                printf("\n");
                    for(int i = 0 ; i < n; i++) {
                    afisare(student,i);
                    }
                break;
            };

            case 6 : {
                printf("Nota Programare : ");
                scanf("%d", &(student + (nr_stud - 1) )->prog);
                printf("\n");
                    for(int i = 0 ; i < n; i++) {
                    afisare(student,i);
                    }
                break;
            };

            case 7 : {
                printf("Nota Filozofie : ");
                scanf("%d", &(student + (nr_stud - 1) )->filoz);
                printf("\n");
                    for(int i = 0 ; i < n; i++) {
                    afisare(student,i);
                    }
                break;
            };

            case 8 : {
                printf("Nota Engleza : ");
                scanf("%d" , &(student + (nr_stud - 1) )->eng);
                printf("\n");
                    for(int i = 0 ; i < n; i++) {
                    afisare(student,i);
                    }
                break;
            }
        }
}


int main() {
    int n = 2;
    struct stud_rec student[n];
    struct stud_rec *p_student = student;

    for(int i = 0 ; i < n ;i++) {
        student[i] = citire(i);
    }

    for(int i = 0 ; i < n; i++) {
        afisare(p_student,i);
    }


    int checker;
    printf("Daca doriti sa inregistrati careva modificari, introduceti 1, in caz contrar 0 : ");
    scanf("%d", &checker);
    int ver = 1;
    if(checker != 1) {

    } else{
        while(ver == 1) {
            schimbare(n,p_student);
            printf("Mai doriti sa realizati careva schimbari (1 - DA | 0 - NU) : ");
            scanf("%d", &ver);
        }

    };
        char spec[5];
        printf("Introduceti specialitatea : ");
        scanf("%s", spec);
        printf("\n");
        calc(n, p_student,spec);
        Bsort_prog(p_student,n,spec);
        Bsort_filoz(p_student,n,spec);
        Bsort_eng(p_student,n,spec);

        printf("\n\n------------------------------------------------------------------------------\n");

        selection_sort_prog(n,p_student,n,spec);
        selection_sort_filoz(n,p_student,n,spec);
        selection_sort_eng(n,p_student,n,spec);

    return 0;
}
