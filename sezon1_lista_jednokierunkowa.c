#include    <stdio.h>
#include    <stdlib.h>
#define     ABS(X)  (X>0)?(X):(-X)
#define     ROZMIAR 50

/* ########## DEKLRACJE STRUKTUR ########## */

//Struktura do przechowywania danych osobowych
struct datablock
{
    char   name[ROZMIAR];
    char   surname[ROZMIAR];
    int    year;
};
typedef struct datablock datablock;
/* ------------------------------------------ */
//Struktura dla elementow listy jednokierunkowej
struct list
{
    datablock       person;
    struct list*    next;
};
typedef struct list list;

/* ########## DEKLRACJE FUNKCJI ########## */

/*Funkcja zamienia pierwszy napotkany znak nowej lini '\n' w str na '\0'.
//ARGS: char** - wskaznik na przetwarzanego str */
void fixFgets(char*);

/*Funkcja wyswietla na ekranie cala liste
//ARGS: list* - poczatkowy element listy */
void listPrintf(list*);

/*Tworzy nowy element listy i zwraca na niego wskaznik.
//RETURN: Wskaznik na nowy element listy. NULL w przypadku niepowodzenia.*/
list* listNewElem();

/*Dodawanie nowego elementu listy na jej poczatek.
//ARGS: list** - wskaznik na poczatek listy, list** - wskaznik na nowy element*/
void listAddFirst(list**, list**);

/*Dodawanie nowego elementu listy na jej koniec.
//ARGS: list** - wskaznik na poczatek listy, list** - wskaznik na nowy element*/
void listAddLast(list**, list**);

/*Dodawanie nowy element pomiedzy dwoma istniejacymi elementami.
//ARGS: list** - wskaznik na poczatek listy, list** - wskaznik na nowy element,
int - nr ideksu za ktorym ma byc dodawane*/
void listAddBetween(list**, list**, int);

/*Usuwa element z poczatku listy. Zwraca adres nowej glowy
//ARGS: list** - wskaznik na poczatek listy, list** - wskaznik na nowy element
//RETURN: adres nowej glowy*/
list* listDelFirst(list*);

/*Usuwa elment z konca listy. Zwraca adres nowej glowy.
//ARGS: list** - wskaznik na poczatek listy, list** - wskaznik na nowy element
//RETURN: adres nowej glowy*/
list* listDelLast(list*);

/*Usuwa element pomiedzy dwoma innymi elementami.
//ARGS: list** - wskaznik na poczatek listy, list** - wskaznik na nowy element
//RETURN: adres nowej glowy*/
list* listDelBetween(list*, int);

/*Zwalnianie pamie calej listy.
//ARGS: list** - wskaznik na poczatek listy, list** - wskaznik na nowy element*/
list* listDelAll(list*);

/*Wyszukuje na liscie elementy zawierajace podany rok urodzenia.
//ARGS: list** - wskaznik na poczatek listy, list** - wskaznik na nowy element
//RETURN: int - Zwraca pozycje pierwszego wystapienia, -1 w przypadku braku.*/
int  listSearch(list*, int);


/* ########## MAIN ########## */
int main(){

    list*   head=NULL;   //Glowa listy
    list*   wsk;         //Wskaznik pomocniczy na strukture typu list.
    int     tmp;         //Zmienna do przechwytania danych z klawiatury
    int     cnt_i;       //Licznik dla petli

    do
    {
        printf("\033[2J");   //Czyszczenie ekranu
        printf("\033[0;0H"); //Ustawienie kursora w pozycji 0,0
        printf("|##########################|\n");
        printf("|---LISTA JEDNOKIERUNKOWA--|\n");
        printf("|##########################|\n");
        printf("|-----------MENU-----------|\n");
        printf("|[1].Wyswietl cala liste...|\n");
        printf("|[2].Przeszukaj liste......|\n");
        printf("|[3].Nowy el. na POCZATKU..|\n");
        printf("|[4].Nowy el. na KONCU.....|\n");
        printf("|[5].Nowy el. w  SRODKU....|\n");
        printf("|[6].Usun el. na POCZATKU..|\n");
        printf("|[7].Usun el. na KONCU.....|\n");
        printf("|[8].Usun el. w  SRODKU....|\n");
        printf("|[9].Usun cala liste.......|\n");
        printf("|[0].Wyjscie....,........,.|\n");
        printf("|##########################|\n");

        //Pobranie decyzji u¿ytkownika
        printf(">");
        scanf("%i", &tmp); getchar();
        if(tmp<0 || tmp>9){
            printf(">Wybrano niewlasciwa opcje!\n");
            getchar();
            continue;
        }


        //Istnieje mozliwosc zapisania ponizszego kodu za pomoca switch(){};

        //Wyswietl ksiazke
        if(tmp==1){
            printf("\n>[WYSWIETL CALA LISTE]\n");
            listPrintf(head);
            getchar();
        }
        //Szukaj elementu
        else if(tmp==2){
            printf(">[WYSZUKIWANIE PIERW. ELEMENTU]\n");
            printf(">Podaj rok urodzenie:");
            scanf("%i", &tmp); getchar();
            tmp=listSearch(head, ABS(tmp));
            if(tmp < 0) printf(">Nic nie znaleziono.\n>");
            else printf(">Znaleziono rekord o numerze indeksu: %i\n>", tmp);
            getchar();
        }
        //Nowy element na poczatku
        else if(tmp==3){
            wsk=listNewElem();
            if(wsk==NULL){
                printf("\n>Blad alokacji pamieci!\n");
                printf("\n>Czy chcesz usunac cala liste?(t\\n): ");
                do{scanf("%c", &tmp); getchar();}while(tmp!='t'&&tmp!='n');
                if(tmp=='t'){
                    head=listDelAll(head);
                    printf("\n>Usunieto cala liste. Wywolaj zadanie jeszcze raz.\n>");
                }else{printf("\n>Przerwano dodawanie nowego elementu.\n>");}
                getchar();
                continue;
            }
            listAddFirst(&head, &wsk);
            printf("\n>Dodano nowy element na POCZATKU.\n");
            getchar();
        }
        //Nowy element na koncu
        else if(tmp==4){
            wsk=listNewElem();
            if(wsk==NULL){
                printf("\n>Blad alokacji pamieci!\n");
                printf("\n>Czy chcesz usunac cala liste?(t\\n): ");
                do{scanf("%c", &tmp); getchar();}while(tmp!='t'&&tmp!='n');
                if(tmp=='t'){
                    head=listDelAll(head);
                    printf("\n>Usunieto cala liste. Wywolaj zadanie jeszcze raz.\n>");
                }else{printf(">Przerwano dodawanie nowego elementu.\n>");}
                getchar();
                continue;
            }
            listAddLast(&head, &wsk);
            printf("\n>Dodano nowy element na KONCU.\n");
            getchar();
        }
         //Nowy element za ktoryms elementem
        else if(tmp==5){
            wsk=listNewElem();
            if(wsk==NULL){
                printf("\n>Blad alokacji pamieci!\n");
                printf("\n>Czy chcesz usunac cala liste?(t\\n): ");
                do{scanf("%c", &tmp); getchar();}while(tmp!='t'&&tmp!='n');
                if(tmp=='t'){
                    head=listDelAll(head);
                    printf("\n>Usunieto cala liste. Wywolaj zadanie jeszcze raz.\n>");
                }else{printf("\n>Przerwano dodawanie nowego elementu.\n>");}
                getchar();
                continue;
            }
            printf(">Podaj nr elementu ZA KTORYM dodac nowy element:\n>");
            scanf("%i", &tmp); getchar();
            listAddBetween(&head, &wsk, ABS(tmp));
            getchar();
        }
        //Usun element na poczatku
        else if(tmp==6){
            head = listDelFirst(head);
            printf(">Usunieto pierwszy element.\n>");
            getchar();
        }
        //Usun element na koncu
        else if(tmp==7){
            head = listDelLast(head);
            getchar();
        }
        //Usun wybrany element
        else if(tmp==8){
            printf(">Podaj nr elementu do usuniecia:\n>");
            scanf("%i", &tmp); getchar();
            head = listDelBetween(head, ABS(tmp));
            getchar();
        }
        //Usun cala liste
        else if(tmp==9){
            head = listDelAll(head);
                printf(">Usunieto cala liste.\n>");
            getchar();
        }
        else if(tmp==0){

            head = listDelAll(head);
            return 1;
        }

    }while(1);

    //Zakonczenie programu
    printf("\n\n");
    return 0;
}
/* ------------------------------------------ */

/* ########## DEFINICJE FUNKCJI ########## */

void fixFgets(char *str){

    int     i;      //Licznik dla petli

    for(i=0; str[i] != '\0'; i++)
        if(str[i] == '\n') {
                str[i]='\0';
                return;
        }
    return;

}
/* ------------------------------------------ */

void listPrintf(list *wsk){

    list    *p;         //Zmienna pomocnicza
    int     cnt=0;      //Licznik petli

    if(wsk==NULL){
        printf(">Lista jest pusta!\n");
        return;
    }

    p=wsk;
    while(1){
        printf(">\n>\n");
        printf(">Numer elementu: %i\n",  cnt++);
        printf(">Imie..........: %s\n",  p->person.name);
        printf(">Nazwisko......: %s\n",  p->person.surname);
        printf(">Rok urodzin...: %i\n",  p->person.year);
        printf(">\n");
        if(p->next == NULL) break;
        p=p->next;
    }
    return;


}
/* ------------------------------------------ */

list* listNewElem(){

    list* buffor;
    buffor=(list*)malloc(sizeof(list));
    if(buffor==NULL) return NULL;
    printf(">[TWORZENIE NOWEGO ELEMENTU]\n");
    printf(">[1] Podaj imie:\n>");
    fgets(buffor->person.name, ROZMIAR, stdin);
    fixFgets(buffor->person.name);
    printf(">[2] Podaj nazwisko:\n>");
    fgets(buffor->person.surname, ROZMIAR, stdin);
    fixFgets(buffor->person.surname);
    printf(">[3] Podaj rok urodzenia:\n>");
    scanf("%i", &(buffor->person.year)); getchar();
    buffor->next = NULL;

    return buffor;

}
/* ------------------------------------------ */

void listAddFirst(list **wsk, list **element){

    //Pierwszy element
    if((*wsk) == NULL){
        *wsk = *element;
        return;
    }
    //Przepinanie glowy
    (*element)->next = *wsk;
    *wsk = *element;
    return;
}
/* ------------------------------------------ */

void listAddLast(list **wsk, list **element){

    list* p;    //Wskaznik na kolejny element
    //Pierwszy element
    if((*wsk) == NULL){
        *wsk = *element;
        return;
    }
    p=*wsk;
    while(p->next != NULL)
        p=p->next;
    p->next = *element;
    return;

}
/* ------------------------------------------ */

void listAddBetween(list **wsk, list **element, int n){

    list* p;    //Wskaznik na kolejny element
    list* w;    //Wskaznik na element nastêpny po kolejnym

    int   i=0;  //Licznik

    //Pierwszy element
    if(*wsk == NULL){
        *wsk = *element;
        printf(">Element sta³ sie nowa glowa.\n>");
        return;
    }
    for(p=*wsk; p->next != NULL && i<n; i++)
        p=p->next;

    if(p->next == NULL){
        p->next = *element;
        printf(">Element zostal wstawiony na koncu listy.\n>");
    }
    else{
        (*element)->next = p->next;
        p->next = *element;
        printf(">Element zostal wstawiony za elementem nr %i.\n>", i);
    }
    return;

}
/* ------------------------------------------ */

list* listDelFirst(list *wsk){

    list    *p;         //Zmienna pomocnicza
    
    //Pierwszy element
    if(wsk == NULL){
        printf(">Lista jest pusta.\n>");
        return NULL;
    }

    p=(wsk)->next;
    free(wsk);

    return p;
}
/* ------------------------------------------ */

list* listDelLast(list *wsk){

    list* p;        //Wskaznik na kolejne elementy
    list* w;        //Wskaznik na kolejne elementy
    
    //Pierwszy element
    if(wsk == NULL){
        printf(">Lista jest pusta.\n>");
        return NULL;
    }
    
    p=wsk;
    w=NULL;
    while(p->next != NULL){
        w=p;
        p=p->next;
    }
    //Przedostatni element ustawiamy na NULL
    if(w!=NULL)
        w->next = NULL;

    printf(">Usunieto ostatni element.\n>");
    if(p!=wsk){
        free(p);
        return wsk;
    }
    else{
        free(p);
        return NULL;
    }
}
/* ------------------------------------------ */

list* listDelBetween(list *wsk, int n){

    list* p;        //Wskaznik na element do usuniecia
    list* w=NULL;   //Wskaznik na element poprzedzajacy el. do usuniecia

    int   i=0;  //Licznik

    //Pierwszy element
    if(wsk == NULL){
        printf(">Lista jest pusta.\n>");
        return NULL;
    }
    for(p=wsk; p->next != NULL && i<n; i++){
        w=p;
        p=p->next;
    }

    //Czy trafiono na dany blad
    if(i==n){
        if(p == wsk){  //Usuwanie glowy
            w=p->next;
            free(p);
            printf(">Element nr %i zostal usuniety.\n>", n);
            return w;
        }
        w->next = p->next;
        free(p);
        printf(">Element nr %i zostal usuniety.\n>", n);
    }
    else
        printf(">Element o nr %i nie istnieje.\n>", i);

    return wsk;
}
/* ------------------------------------------ */

list* listDelAll(list *wsk){

    list* p;        //Wskaznik na kolejne elementy
    list* w;        //Wskaznik na kolejne elementy

    //Pierwszy element
    if(wsk == NULL)
        return NULL;
    for(p=wsk; p->next != NULL; p=w){
        w=p->next;
        free(p);
    }
    return NULL;
}
/* ------------------------------------------ */

int  listSearch(list *wsk, int y){

    list* p;    //Wskaznik na kolejny element
    int i=0;        //Licznik

    //Pierwszy element
    if(wsk == NULL){
        return -1;
    }
    for(p=wsk; p->person.year != y && p->next != NULL; p=p->next)
        i++;
    //Brak wystapien
    if(p->next == NULL)
        return 0;
    return i;
}
/* ------------------------------------------ */