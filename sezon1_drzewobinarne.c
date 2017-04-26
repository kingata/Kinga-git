#include    <stdio.h>
#include    <stdlib.h>
#include    <time.h>
#define     SIZE    20
#define     RND_MIN     0
#define     RND_MAX     100
#define     RND_ROLL    rand()%(RND_MAX+1-RND_MIN)+RND_MIN


/* ########## DEKLRACJE STRUKTUR ########## */

//Struktura dla drzewa binarnego
struct _S_DRZEWO{
    int                 val;
    struct _S_DRZEWO*   lewy;
    struct _S_DRZEWO*   prawy;
};
typedef struct _S_DRZEWO DRZEWO;

/* ########## DEKLRACJE FUNKCJI ########## */

/*Funkcja wyswietlajaca drzewo binarne metoda PREORDER (najpierw rodzic, pozniej dzieci)
//ARGS: DRZEWO* - wskaznik na korzen drzewa*/
void drzewoPreorder(DRZEWO*);

/*Funkcja wyswietlajaca drzewo binarne metoda INORDER (najpierw dzieci, pozniej rodzic)
//ARGS: DRZEWO* - wskaznik na korzen drzewa*/
void drzewoPostorder(DRZEWO*);

/*Funkcja wyswietlajaca drzewo binarne metoda OSTORDER (dziecko, rodzic, drugie dziecko)
//ARGS: DRZEWO* - wskaznik na korzen drzewa*/
void drzewoInorder(DRZEWO*);


/* ########## MAIN ########## */
int main(){
    //Sprawdzenie warunków pocz¹tkowych (kompilator usunie ten kod, jesli warunek nie bedzie spelniony)
    #if RND_MIN>=RND_MAX
        printf("Uwaga: niepoprawnie skonfiugrowany modul losujacy (MIN>=MAX)!\n");
        return -1;
    #endif // RND_MIN

    int i, j=1;      //Liczniki dla petli

    srand(time(NULL));

    printf("Tworzenie drzewa binarnego skladajacego sie z %i elementow...\n", SIZE);

    //Tworzymy SIZE iloœæ liœci, by je nastepnie poprzepinaæ miedzy sob¹.
    DRZEWO  table[SIZE];
    for(i=0; i<SIZE; i++){
        table[i].val=RND_ROLL;
        table[i].lewy=NULL;
        table[i].prawy=NULL;
        //Podpinanie kolejnych lisci
        //Uwaga, ++ po zmiennej inkrementuje zmienna dopiero PO jej uzyciu.
        if(j<SIZE) table[i].lewy  = table+j++;
        if(j<SIZE) table[i].prawy = table+j++;
    }

    //Wyswietlanie
    printf("Wyswietlanie roznymi sposobami drzewa binarnego:\n\n");
    printf(">PREORDER:\n");
    drzewoPreorder(table);
    printf("\n>POSTORDER:\n");
    drzewoPostorder(table);
    printf("\n>INORDER:\n");
    drzewoInorder(table);

    printf("\n\n");
    return 0;
}
/* ------------------------------------------ */

/* ########## DEFINICJE FUNKCJI ########## */

void drzewoPreorder(DRZEWO* leaf){
    if(leaf==NULL) return;
    printf("%3i ", leaf->val);
    drzewoPreorder(leaf->lewy);
    drzewoPreorder(leaf->prawy);
    return;
}
/* ------------------------------------------ */

void drzewoPostorder(DRZEWO* leaf){
    if(leaf==NULL) return;
    drzewoPostorder(leaf->lewy);
    drzewoPostorder(leaf->prawy);
    printf("%3i ", leaf->val);
    return;
}
/* ------------------------------------------ */

void drzewoInorder(DRZEWO* leaf){
    if(leaf==NULL) return;
    drzewoInorder(leaf->lewy);
    printf("%3i ", leaf->val);
    drzewoInorder(leaf->prawy);
    return;
}
/* ------------------------------------------ */