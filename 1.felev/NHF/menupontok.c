#include <stdio.h>
#include <windows.h>

#include "fajlkezeles.h"
#include "structs.h"

#define YELLOW "\033[0;33m"
#define LIGHT_YELLOW "\033[38;2;255;255;192m"
#define WHITE "\033[0;37m"
#define RED "\033[0;31m"
#define LIGHT_RED "\033[38;2;255;224;224m"
#define GREEN "\033[0;32m"
#define LIGHT_GREEN "\033[38;2;224;255;224m"

// alpontok fuggvenyeinek deklaralasa
int etelcsoportFelvete(Etelcsoport **menu, int **meretek, int *meretekHossz);
int etelFelvetele(Etelcsoport **menu, int **meretek, int *meretekHossz);

// fopontok fuggvenyei
int asztalokMegadasa(Asztal **asztalok, int *asztalokHossz)
{
    system("@cls");
    printf(YELLOW "Asztalok megadasa\n" WHITE);
    printf("Uj asztal megadasahoz add meg a kovetkezoket: x y fo, ahol x es y a koordinatak, a fo pedig az asztal max letszama.\n");
    printf("Kilepeshez ird be hogy -1 -1 -1.\n");

    int x;
    int y;
    int fo;

    if (scanf("%d %d %d", &x, &y, &fo) < 3)
    {
        return 1;
    }

    if (x == -1 && y == -1 && fo == -1)
    {
        return 0;
    }
    if (x < 0 || y < 0 || fo < 1)
    {
        return 1;
    }

    if (*asztalok)
    {
        for (int i = 0; i < *asztalokHossz; i++)
        {
            if ((*asztalok)[i].pozX == x && (*asztalok)[i].pozY == y)
            {
                char valasz;
                printf(LIGHT_RED "Ezen a pozicion mar van asztal, felulirod? (i/n) " WHITE);
                scanf(" %c", &valasz);
                if (valasz == 'i')
                {
                    (*asztalok)[i].pozX = x;
                    (*asztalok)[i].pozY = y;
                    (*asztalok)[i].fo = fo;
                    (*asztalok)[i].foglaltsag = 0;

                    printf("Asztal id: %d felulirva, uj ertekek:\n\tkoordinatak: %d %d\n\tfo: %d\n\tfoglaltsag: szabad\n", i, x, y, fo);
                    if (asztalokMent(*asztalok, *asztalokHossz))
                    {
                        printf(RED "Asztalok mentese sikertelen!" WHITE);
                    }
                    system("pause");
                    return 0;
                }
                else
                {
                    printf(RED "Hibas valasz!" WHITE);
                }
            }
        }
    }
    // nincs ellenorzes de statisztikailag kizart hogy ne legyen ra memoria
    *asztalok = *asztalok ? realloc(*asztalok, (*asztalokHossz + 1) * sizeof(Asztal)) : malloc(sizeof(Asztal));
    (*asztalok)[*asztalokHossz].pozX = x;
    (*asztalok)[*asztalokHossz].pozY = y;
    (*asztalok)[*asztalokHossz].fo = fo;
    (*asztalok)[*asztalokHossz].foglaltsag = 0;
    (*asztalokHossz)++;
    printf("Asztal id: %d felveve, ertekek:\n\tkoordinatak: %d %d\n\tfo: %d\n\tfoglaltsag: szabad\n",
           *asztalokHossz - 1, x, y, fo);

    if (asztalokMent(*asztalok, *asztalokHossz))
    {
        printf(RED "Asztalok mentese sikertelen!" WHITE);
    }
    system("pause");
    return 0;
}

int kajaMenu(Etelcsoport **menu, int **meretek, int *meretekHossz)
{
    system("@cls");
    printf(YELLOW "Menu\n" WHITE);
    printf(LIGHT_YELLOW "1. Menu kiir\n");
    printf("2. Etelcsoport megadasa\n");
    printf("3. Etel megadasa\n");
    printf(LIGHT_RED "4. Kilepes\n" WHITE);

    int valasztas = 0;

    while (!valasztas)
    {
        if (scanf("%d", &valasztas) != 1 || valasztas < 1 || valasztas > 4)
        {
            printf(RED "Helytelen menupont!\n" WHITE);
            printf("Adj meg egy menupontot 1 és 4 kozott: ");
            valasztas = 0;
        }
    }

    switch (valasztas)
    {
    // menu kiir
    case 1:
        if (!*menu)
        {
            printf("Nincsen meg menu!\n");
            system("pause");
            return 0;
        }
        system("@cls");
        printf(YELLOW "MENU\n" WHITE);
        for (int i = 0; i < *meretekHossz; i++)
        {
            printf("\nEtelcsoport: %s\n", (*menu)[i].etelcsoportNev);
            for (int j = 0; j < (*meretek)[i]; j++)
            {
                printf("\tEtel: %s, Ar: %d\n", (*menu)[i].etelek[j].etelNev, (*menu)[i].etelek[j].ar);
            }
        }
        system("pause");
        return 0;

    // Etelcsoport megadasa
    case 2:
        return etelcsoportFelvete(menu, meretek, meretekHossz);

    // Etel megadasa
    case 3:
        return etelFelvetele(menu, meretek, meretekHossz);

    // kilep
    case 4:
        return 0;
    default:
        return 0;
    }
}

int asztalFoglalasok(Asztal *asztalok, int asztalokHossz)
{
    if (!asztalok)
    {
        printf(RED "Nincsenek meg asztalok!" WHITE);
        system("pause");
        return 0;
    }

    system("@cls");
    printf(YELLOW "Asztal foglalasok\n" WHITE);
    printf("A kovetkezokeppen adjad meg a parametereket:");
    printf("asztalid foglaltsag (szokozzel elvalasztva!)\nHa a foglaltsag 1 akkor foglalt ha 0 akkor szabad.");
    printf("\nA foglaltsag mindig az uj megadott lesz, meg ha meg is egyezik a regivel.\n");

    int asztalId = -1;
    int foglaltsag = -1;

    int input = scanf("%d %d", &asztalId, &foglaltsag);

    if (input == 2 && asztalId >= 0 && (foglaltsag == 0 || foglaltsag == 1) && asztalId < asztalokHossz)
    {
        asztalok[asztalId].foglaltsag = foglaltsag;

        printf("Asztal id: " WHITE "%d"
               ", uj foglaltsaga: " WHITE "%s"
               ".\n" WHITE,
               asztalId, foglaltsag ? "foglalt" : "szabad");
        system("pause");
        return 0;
    }
    else
    {
        return 1;
    }
}

int rendelesFelvetel(Rendeles **rendelesek, int *rendelesekHossz, Etelcsoport *menu, int *meretek, int meretekHossz)
{
    system("@cls");
    printf(YELLOW "Rendelesek\n" WHITE);

    if (!menu)
    {
        printf(RED "Nincsen meg menu!\n" WHITE);
        system("pause");
        return 0;
    }

    printf("Add meg az asztal ID-t: ");
    int asztalId;
    scanf("%d", &asztalId);

    if (asztalId < 0)
    {
        printf(RED "Ervenytelen asztal ID!\n" WHITE);
        system("pause");
        return 1;
    }

    int osszEtelSzam = 0;
    for (int i = 0; i < meretekHossz; i++)
    {
        osszEtelSzam += meretek[i];
    }

    Rendeles ujRendeles;
    ujRendeles.asztalId = asztalId;
    ujRendeles.etelek = malloc((osszEtelSzam + 1) * sizeof(int));
    ujRendeles.db = malloc((osszEtelSzam + 1) * sizeof(int));

    for (int i = 0; i < osszEtelSzam + 1; i++)
    {
        ujRendeles.etelek[i] = -1;
        ujRendeles.db[i] = 0;
    }

    int etelIndex = 0;
    int valasztottEtel;

    do
    {
        system("@cls");
        printf(YELLOW "MENU\n" WHITE);

        int etelSorszam = 1;
        for (int i = 0; i < meretekHossz; i++)
        {
            printf("\n%s:\n", menu[i].etelcsoportNev);
            for (int j = 0; j < meretek[i]; j++)
            {
                printf("%d. %s - %d Ft\n", etelSorszam, menu[i].etelek[j].etelNev, menu[i].etelek[j].ar);
                etelSorszam++;
            }
        }

        printf("\nJelenlegi rendeles:\n");
        int vanRendeles = 0;
        for (int i = 0; ujRendeles.etelek[i] != -1; i++)
        {
            if (ujRendeles.db[i] > 0)
            {
                int tempSorszam = 0;
                for (int j = 0; j < meretekHossz; j++)
                {
                    for (int k = 0; k < meretek[j]; k++)
                    {
                        if (tempSorszam == ujRendeles.etelek[i])
                        {
                            printf("\t%s - %dx\n", menu[j].etelek[k].etelNev, ujRendeles.db[i]);
                            vanRendeles = 1;
                        }
                        tempSorszam++;
                    }
                }
            }
        }
        if (!vanRendeles)
        {
            printf("(meg ures)\n");
        }

        printf("\nValassz etelt (1-%d), vagy -1 a befejezeshez: ", etelSorszam - 1);
        scanf("%d", &valasztottEtel);

        if (valasztottEtel >= 1 && valasztottEtel < etelSorszam)
        {
            int letezo = -1;
            for (int i = 0; ujRendeles.etelek[i] != -1; i++)
            {
                if (ujRendeles.etelek[i] == valasztottEtel - 1)
                {
                    letezo = i;
                    break;
                }
            }

            if (letezo >= 0)
            {
                ujRendeles.db[letezo]++;
                printf(GREEN "Etel hozzaadva!\n" WHITE);
            }
            else
            {
                ujRendeles.etelek[etelIndex] = valasztottEtel - 1;
                ujRendeles.db[etelIndex] = 1;
                etelIndex++;
                printf(GREEN "Etel hozzaadva!\n" WHITE);
            }
            system("pause");
        }
        else if (valasztottEtel != -1)
        {
            printf(RED "Hibas etel sorszam!\n" WHITE);
            system("pause");
        }

    } while (valasztottEtel != -1);

    if (etelIndex > 0)
    {
        *rendelesek = *rendelesek ? realloc(*rendelesek, (*rendelesekHossz + 1) * sizeof(Rendeles)) : malloc(sizeof(Rendeles));
        (*rendelesek)[*rendelesekHossz] = ujRendeles;
        (*rendelesekHossz)++;
        printf(GREEN "Rendeles rogzitve!\n" WHITE);
    }
    else
    {
        free(ujRendeles.etelek);
        free(ujRendeles.db);
    }

    system("pause");
    return 0;
}

int szamlaKiir(Rendeles *rendelesek, int rendelesekHossz, Etelcsoport *menu, int *meretek, int meretekHossz)
{
    system("@cls");
    printf(YELLOW "Szamla kiirasa\n" WHITE);

    if (!rendelesek || !menu)
    {
        printf(RED "Nincsenek rendelesek vagy nincs menu!\n" WHITE);
        system("pause");
        return 0;
    }

    printf("Add meg az asztal ID-t: ");
    int asztalId;
    scanf("%d", &asztalId);

    if (asztalId < 0)
    {
        printf(RED "Ervenytelen asztal ID!\n" WHITE);
        system("pause");
        return 1;
    }

    system("@cls");
    printf(YELLOW "SZAMLA - Asztal %d\n\n" WHITE, asztalId);

    int osszeg = 0;
    int vanRendeles = 0;

    for (int i = 0; i < rendelesekHossz; i++)
    {
        if (rendelesek[i].asztalId == asztalId)
        {
            vanRendeles = 1;
            for (int j = 0; rendelesek[i].etelek[j] != -1; j++)
            {
                if (rendelesek[i].db[j] > 0)
                {
                    int etelIndex = rendelesek[i].etelek[j];
                    int tempIndex = 0;

                    for (int m = 0; m < meretekHossz; m++)
                    {
                        for (int n = 0; n < meretek[m]; n++)
                        {
                            if (tempIndex == etelIndex)
                            {
                                int etelAr = menu[m].etelek[n].ar * rendelesek[i].db[j];
                                printf("%dx %s", rendelesek[i].db[j], menu[m].etelek[n].etelNev);

                                int pontok = 40 - strlen(menu[m].etelek[n].etelNev) - 3;
                                for (int p = 0; p < pontok; p++)
                                {
                                    printf(".");
                                }
                                printf("%d Ft\n", etelAr);
                                osszeg += etelAr;
                            }
                            tempIndex++;
                        }
                    }
                }
            }
        }
    }

    if (!vanRendeles)
    {
        printf(RED "Nincs rendeles ehhez az asztalhoz!\n" WHITE);
        system("pause");
        return 0;
    }

    printf("________________________________________\n");
    printf(LIGHT_YELLOW "Vegosszeg:");
    int pontok = 30;
    for (int i = 0; i < pontok; i++)
    {
        printf(".");
    }
    printf("%d Ft\n" WHITE, osszeg);

    system("pause");
    return 0;
}

int foglaltsagiTerkepKiir(Asztal *asztalok, int asztalokHossz)
{
    system("@cls");
    printf(YELLOW "Foglaltsagi terkep\n" WHITE);
    if (!asztalok)
    {
        printf(RED "Nincsenek meg asztalok!\n" WHITE);
        system("pause");
        return 0;
    }

    int xMax = 0;
    int yMax = 0;
    for (int i = 0; i < asztalokHossz; i++)
    {
        xMax = asztalok[i].pozX > xMax ? asztalok[i].pozX : xMax;
        yMax = asztalok[i].pozY > yMax ? asztalok[i].pozY : yMax;
    }

    for (int sor = 0; sor <= yMax; sor++)
    {
        for (int oszlop = 0; oszlop <= xMax; oszlop++)
        {
            int printed = 0;
            for (int i = 0; i < asztalokHossz; i++)
            {
                if (asztalok[i].pozX == oszlop && asztalok[i].pozY == sor)
                {
                    if (asztalok[i].foglaltsag == 1)
                    {
                        printf(RED "%d ", i);
                    }
                    else
                    {
                        printf(GREEN "%d ", i);
                    }

                    printed = 1;
                    break;
                }
            }
            if (!printed)
            {
                printf("  ");
            }
            printed = 0;
        }
        printf(WHITE "\n\n");
    }

    system("pause");
    return 0;
}

// alpontok fuggvenyei
int etelcsoportFelvete(Etelcsoport **menu, int **meretek, int *meretekHossz)
{
    system("@cls");
    printf(YELLOW "Etelcsoportok megadasa\n" WHITE);
    printf("(ird be hogy \"kilep\" a kilepeshez)\n");
    char beolvasottCsop[50 + 1];

    int safetyGuard = 0;
    while (safetyGuard < 500)
    {
        fflush(stdin);
        printf("\nAdd meg az etelcsoport nevet: ");

        if (fgets(beolvasottCsop, sizeof(beolvasottCsop), stdin) != NULL)
        {
            if (beolvasottCsop[strlen(beolvasottCsop) - 1] == '\n')
            {
                beolvasottCsop[strlen(beolvasottCsop) - 1] = '\0';
            }

            if (strcmp(beolvasottCsop, "kilep") == 0)
            {
                return 0;
            }

            int letezik = 0;
            for (int i = 0; i < *meretekHossz; i++)
            {
                if (strcmp((*menu)[i].etelcsoportNev, beolvasottCsop) == 0)
                {
                    printf(RED "Ez az etelcsoport mar letezik!\n" WHITE);
                    letezik = 1;
                    system("pause");
                    break;
                }
            }
            if (letezik)
            {
                continue;
            }

            *menu = *menu ? realloc(*menu, (*meretekHossz + 1) * sizeof(Etelcsoport)) : malloc(sizeof(Etelcsoport));
            *meretek = *meretek ? realloc(*meretek, (*meretekHossz + 1) * sizeof(int)) : malloc(sizeof(int));

            strcpy((*menu)[*meretekHossz].etelcsoportNev, beolvasottCsop);
            (*menu)[*meretekHossz].etelek = NULL;
            (*meretek)[*meretekHossz] = 0;
            (*meretekHossz)++;

            printf(GREEN "Etelcsoport sikeresen hozzaadva!\n" WHITE);
            if (kajamenuMent(*menu, *meretek, *meretekHossz))
            {
                printf(RED "Menu mentese sikertelen!" WHITE);
            }
        }
        safetyGuard++;
    }
    return 0;
}

int etelFelvetele(Etelcsoport **menu, int **meretek, int *meretekHossz)
{
    if (!*menu)
    {
        printf(RED "Nincsen meg menu!\n" WHITE);
        system("pause");
        return 0;
    }
    system("@cls");
    printf(YELLOW "Etelcsoportok:\n" WHITE);
    for (int i = 0; i < *meretekHossz; i++)
    {
        printf("%d. %s\n" WHITE, i + 1, (*menu)[i].etelcsoportNev);
    }
    printf("\nValaszd ki az etelcsoportot (-1 a kilepeshez): ");

    int csopId;
    scanf("%d", &csopId);
    csopId--;
    fflush(stdin);

    if (csopId < 0 || csopId >= *meretekHossz)
    {
        printf(RED "Ervenytelen valasztas!\n" WHITE);
        system("pause");
        return 0;
    }

    char etelNev[50 + 1];
    int ar = 0;
    printf("Add meg az etel nevet: ");

    if (fgets(etelNev, sizeof(etelNev), stdin) != NULL)
    {
        if (etelNev[strlen(etelNev) - 1] == '\n')
        {
            etelNev[strlen(etelNev) - 1] = '\0';
        }

        printf("Add meg az etel arat: ");
        scanf("%d", &ar);
        if (ar <= 0)
        {
            return 1;
        }

        (*menu)[csopId].etelek = (*menu)[csopId].etelek ? realloc((*menu)[csopId].etelek, ((*meretek)[csopId] + 1) * sizeof(Etel)) : malloc(sizeof(Etel));

        strcpy((*menu)[csopId].etelek[(*meretek)[csopId]].etelNev, etelNev);
        (*menu)[csopId].etelek[(*meretek)[csopId]].ar = ar;
        (*meretek)[csopId]++;

        printf(GREEN "Etel sikeresen hozzaadva!\n" WHITE);
        fflush(stdin);
        if (kajamenuMent(*menu, *meretek, *meretekHossz))
        {
            printf(RED "Menu mentese sikertelen!" WHITE);
        }
        system("pause");
    }
    else
    {
        return 1;
    }
    return 0;
}
