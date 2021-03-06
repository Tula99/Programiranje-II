#include <stdio.h>
#include <stdlib.h>
#pragma pack (1)

char slova[27];

void pomjeri(int n)
{
    int i = 0;
    int j = 0;

    for (i=n;i<26;i++)
        slova[j++] = i + 'A';
    for (i=0;i<n;i++)
        slova[j++] = i + 'A';
}

void unos_podataka(char *argv[])
{
    FILE *fp = fopen(argv[1], "ab");

    char tekst[100];
    scanf("%s", tekst);int i = 0;

    while ( tekst[i] )
    {
        int j = 0;

        for (j=0;j<26;j++)
            if ( (char)(j + 'A') == tekst[i] )
                { tekst[i++] = slova[j]; break; }
            else if ( (char)(j + 'a') == tekst[i] )
                { tekst[i++] = slova[j] - 'A' + 'a'; break; }
    }

    fwrite(tekst, sizeof(tekst), 1, fp);
    fclose(fp);
}

void prikaz(char *argv[])
{
    char fajl[100];
    printf("Citanje: \n");
    scanf("%s", fajl);

    FILE *fp;
    if(fajl[0] == '#')
    fp= fopen(argv[1], "rb");
    else fp= fopen(fajl, "rb");

    char tekst[100];
    while (fread(&tekst, sizeof(tekst), 1, fp) )
        printf("%s\n", tekst);

    fclose(fp);
}

int main(int argc, char *argv[])
{
    pomjeri(3); int vrsta;

    printf("Unos podataka: 1\n");
    printf("Prikaz: 2\n");

    scanf("%d", &vrsta);

    if ( vrsta == 1 ) unos_podataka(argv);
    else prikaz(argv);
    return 0;
}

/*

POMJERI - vrsi iplementaciju pomjeranja slova za odgovarajuci broj mjesta ( n < 26 )
PRIKAZ - sluzi za prikazivanje elemenata
    - receno je ako je prvi argument komandne linije # onda koristiti prvi argument komandne linije za datoteku za citanje
    - ukoliko nije citati iz datoteke koju ste vi naveli
UNOS_PODATAKA - sluzi za unos podataka
    - upisuje se u onu datoteku koja je prvi argument komandne linije 
PRAGMA PACK (1) - ukoliko imamo strukturu onda ce sizeof(struktura) biti bukvalna velicina 
    - nece biti padding-a

*/
