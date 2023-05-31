#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct evidence {
    int nr_tren;
    char destinatia[50];
    int ora_plecare;
    int minute_plecare;
    int  ora_sosirii;
    int minute_sosirii;
    char zi_circulatie[20];
};

void citire(struct evidence *tren, int n) {

    int s = 0;

    for(int i = 0 ; i < n ; i++) {
        printf("Introduceti nr. tren : ");
        scanf("%d" , &(tren + i)->nr_tren);

        printf("Introduceti Destinatia : ");
        scanf("%s", (tren + i)->destinatia);

        printf("Introduceti Ora de Plecare : \n");
        printf("Ora : ");
        scanf("%d", &(tren + i)->ora_plecare);

        printf("Minute : ");
        scanf("%d", &(tren + i)->minute_plecare);

        printf("Introduceti Ora Sosirii : \n");
        printf("Ora :");
        scanf("%d", &(tren + i)->ora_sosirii);
        printf("Minute :");
        scanf("%d", &(tren + i)->minute_sosirii);

        printf("Introduceti Ziua de Circulatie : ");
        scanf("%s" , (tren + i)->zi_circulatie);

        printf("\n\n");

    }

}

void afisare(struct evidence *tren, int n ) {
    for(int i = 0 ; i  < n; i++) {
        printf("Nr. tren : %d\n", (tren + i)->nr_tren);
        printf("Destinatia : %s\n", (tren + i)->destinatia);
        printf("Ora plecarii : %d %d\n", (tren + i)->ora_plecare, (tren + i)->minute_plecare);
        printf("Ora sosirii : %.d %d\n", (tren+ i)->ora_sosirii, (tren + i)->minute_sosirii);
        printf("Ziua de Circulatie : %s\n", (tren +i)->zi_circulatie);

        printf("------------------------------------------------\n\n");
    };
};

// Ascendent

void countingSort_nr_tren(struct evidence *p, int size) {
  struct evidence output[10];

  // Find the largest element of the array
  int max = p->nr_tren;
  for (int i = 1; i < size; i++) {
    if ((p + i)->nr_tren > max)
      max = (p + i)->nr_tren;
  }
  int count[10] = {0};

  for (int i = 0; i < size; i++) {
    count[(p + i)->nr_tren]++;
  }

  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    output[count[(p + i)->nr_tren] - 1] = p[i];
    count[(p + i)->nr_tren]--;
  }

  for (int i = 0; i < size; i++) {
    p[i] = output[i];
  }
}

void countingSort_ora_sosire(struct evidence *tren, int n) {

  struct evidence output[10];

  int x = tren->ora_sosirii;
  for (int i = 1; i < n; i++) {
    if ((tren + i)->ora_sosirii > x)
      x = (tren + i)->ora_sosirii;
  }

   int count_arr[x + 1];

  for (int i = 0; i <= x; ++i) {
    count_arr[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    count_arr[(tren+ i)->ora_sosirii]++;
  }

  for (int i = 1; i <= x; i++) {
    count_arr[i] += count_arr[i - 1];
  }


  for (int i = n-1 ; i >= 0; i--) {
    output[count_arr[(tren + i)->ora_sosirii] - 1] = tren[i];
    count_arr[(tren + i)->ora_sosirii]--;
  }

  for (int i = 0; i < n; i++) {
    tren[i] = output[i];
  }
}


void swap(struct evidence *a, struct evidence *b) {
    struct evidence temp = *a;
    *a = *b;
    *b = temp;
  };

  void heapify_nr_tren(struct evidence *tren, int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && (tren + left)->nr_tren < (tren + largest)->nr_tren)
      largest = left;

    if (right < n && (tren + right)->nr_tren < (tren + largest)->nr_tren)
      largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&tren[i], &tren[largest]);
      heapify_nr_tren(tren, n, largest);
    }
  }

  // Main function to do heap sort
  void heapSort_nr_tren(struct evidence *tren, int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify_nr_tren(tren, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&tren[0], &tren[i]);

      // Heapify root element to get highest element at root again
      heapify_nr_tren(tren, i, 0);
    }
  }


  void heapify_ora_sosire(struct evidence *tren, int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && (tren + left)->ora_sosirii < (tren + largest)->ora_sosirii)
      largest = left;

    if (right < n && (tren + right)->ora_sosirii < (tren + largest)->ora_sosirii)
      largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&tren[i], &tren[largest]);
      heapify_ora_sosire(tren, n, largest);
    }
  }

  // Main function to do heap sort
  void heapSort_ora_sosire(struct evidence *tren, int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify_ora_sosire(tren, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&tren[0], &tren[i]);

      // Heapify root element to get highest element at root again
      heapify_ora_sosire(tren, i, 0);
    }
  }

  void schimbare (int n, struct evidence *tren) {
     int nr = 0;
    printf("Introduceti pozitia trenului la care doriti sa realizati modificari : ");
    scanf("%d" , &nr);
    if(nr > n && nr < 0 ) {
        printf("Asa tren nu este prezent in lista : ");
    }

        printf("Ce doriti sa inlocuiti : \n");
        int sc = 0;
        printf("Nr. Tren - 1: Destinatia - 2 : Ora Plecare : Ora  - 3 : Ora Plecare Minute - 4 : Ora Sosire : Ora - 5\nOra Sosire : Minute  - 6: Zi Circulatie : - 7 \n\n");
        scanf("%d" , &sc);
        switch(sc) {
            case 1 : {
                printf("Nr. Tren : ");
                scanf("%d" , &(tren + (nr - 1))->nr_tren);
                printf("\n");
                        afisare(tren,n);

                    break;
            };

            case 2 : {
                printf("Destinatia : ");
                scanf("%s", (tren + (nr - 1))->destinatia);
                printf("\n");
                        afisare(tren,n);

                    break;
            };

            case 3: {
                printf("Ora Plecare (Ora): ");
                scanf("%d" , &(tren + (nr - 1))->ora_plecare);
                printf("\n");
                        afisare(tren,n);
                    break;
            };

            case 4 : {
                printf("Ora Plecare (Minute) : ");
                scanf("%d" , &(tren + (nr - 1))->minute_plecare);
                printf("\n");
                    afisare(tren,n);
                break;
            };

            case 5 : {
                printf("Ora Sosirii (Ora) : ");
                scanf("%d" ,&(tren + (nr - 1))->ora_sosirii);
                printf("\n");
                    afisare(tren,n);
                break;
            };
             case 6 : {
                printf("Ora Sosirii (Minute) : ");
                scanf("%d" , &(tren + (nr - 1))->minute_sosirii);
                printf("\n");
                    afisare(tren,n);
                break;
            };

            case 7 : {
                printf("Zile de Circulatie : ");
                scanf("%s", (tren + (nr - 1))->zi_circulatie);
                printf("\n");
                    afisare(tren,n);
                break;
            };
        }
}

void afisare_dest(struct evidence tren[],int n , char dest[]) {
   for(int i = 0 ; i < n; i++) {
                if(strcmp(dest,tren[i].destinatia) == 0) {
                    printf("Nr. tren : %d\n", (tren + i)->nr_tren);
                    printf("Destinatia : %s\n", (tren +i)->destinatia);
                    printf("Ora plecarii : %d %d\n", (tren+ i)->ora_plecare, (tren + i)->minute_plecare);
                    printf("Ora sosirii : %.d %d\n", (tren + i)->ora_sosirii, (tren + i)->minute_sosirii);
                    printf("Ziua de Circulatie : %s\n", (tren + i)->zi_circulatie);

        printf("------------------------------------------------\n\n");
                }
}
}



int main() {
    int n = 3;
    struct evidence *tren = (struct evidence*)malloc(n*sizeof(struct evidence));
    struct evidence *p_tren = tren;
    citire(p_tren,n);
    printf("------------------------------------------------\n\n");
    afisare(p_tren,n);

    int checker;
    printf("Daca doriti sa inregistrati careva modificari, introduceti 1, in caz contrar 0 : ");
    scanf("%d", &checker);
    int ver = 1;
    if(checker != 1) {

    } else{
        while(ver == 1) {
            schimbare(n,p_tren);
            printf("Mai doriti sa realizati careva schimbari (1 - DA | 0 - NU) : ");
            scanf("%d", &ver);
        }

    };


    printf("\n\n");
    afisare(p_tren,n);
    char dest[50];
    int h,min;

        printf("Introduceti destinatia :");
        scanf("%s", dest);
            printf("Counting Sort\n\n\n");
            printf("Sortarea dupa numarului de tren : \n\n");
            countingSort_nr_tren(p_tren,n);
            afisare_dest(p_tren,n,dest);

            printf("Sortarea dupa ora sosirii : \n\n");
            countingSort_ora_sosire(p_tren,n);
            afisare_dest(p_tren,n,dest);

            printf("\n\n");

            printf("Heap Sort\n\n\n");
            heapSort_nr_tren(p_tren,n);
            printf("Sortarea dupa numarul de tren : \n\n");
            afisare_dest(p_tren,n,dest);

            heapSort_ora_sosire(p_tren,n);
            printf("Sortarea dupa ora sosirii : \n\n");
            afisare_dest(p_tren,n,dest);

            printf("\n\n");




}
