#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void afisare_orig(char a[]) {
        puts(a);
}

void afisare_changed(char a[]) {
        puts(a);
}

void aranjare(char a[]) {
    char temp;
    int step;
    printf("\nIntroduceti pasul : ");
    scanf("%d", &step);

    printf("\n\nSirul pina la schimbare :\n");
    afisare_orig(a);

    for(int i=0;i<strlen(a) - 3;i++)
    {
        if (i==(strlen(a)-3))
        {
            temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
            break;
        }
        temp = a[i];
        a[i] = a[i+(step - 1)];
        a[i+(step - 1)] = temp;
        i=i+(step - 1);
    }

    printf("\nSirul schimbat :\n");
    afisare_changed(a);
}



int main() {
    char s[100], temp;
    printf("Introduceti sirul : \n");
    gets(s);

    FILE *pFile = fopen("lucru.txt", "w");

    fprintf(pFile,"%s", s);
    fclose(pFile);

    FILE *pFileRead = fopen("lucru.txt" , "r");
    char a[100];

    fgets(a,100,pFileRead);

    fclose(pFileRead);

    aranjare(a);

    return 0;
}
