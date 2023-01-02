#ifndef REKRUTMEN_H_INCLUDED
#define REKRUTMEN_H_INCLUDED

#include <iostream>
#define info(P) P->info
#define first(L) L.first
#define nextC(P) P->nextC
#define nextI(P) P->nextI
#define nextR(P) P->nextR
#define firstR(P) P->firstR
#define NIL NULL

using namespace std;

typedef string infotype;
typedef struct elmtPelamar *addr1;
typedef struct elmtPekerjaan *addr2;
typedef struct elmtRelasi *addr3;

struct elmtPelamar{
    infotype info;
    addr1 nextI;
    addr3 firstR;
};

struct elmtPekerjaan{
    infotype info;
    addr2 nextC;
};

struct elmtRelasi{
    addr2 nextC;
    addr3 nextR;
};

struct listPelamar{
    addr1 first;
};

struct listPekerjaan{
    addr2 first;
};


/**Create List*/
void create2List(listPelamar &L1, listPekerjaan &L2);
/**Alokasi*/
addr1 createNewPelamar(infotype X);
addr2 createNewCouse(infotype X);
addr3 createNewRelasi();
/**Insert First*/
void insertfirstPelamar(listPelamar &L1,addr1 P);
void insertFirstPekerjaan(listPekerjaan &L2,addr2 P);
void insertFirstRelasi(listPelamar L1, listPekerjaan L2, infotype X, infotype Y);
/**Insert Last*/
void insertLastPelamar(listPelamar &L1, addr1 P);
void insertLastPekerjaan(listPekerjaan &L2, addr2 P);
/**Delete First*/
void deleteFirstPelamar(listPelamar &L1);
void deleteFirstPekerjaan(listPelamar, listPekerjaan &L2);
/**Print List*/
void printPelamar(listPelamar L1);
void printPekerjaan(listPekerjaan L2);
void printPekerjaandenganPelamar(listPelamar L1, listPekerjaan L2);
void findPelamar(listPelamar L1, listPekerjaan L2, infotype X);
/**Searching*/
addr1 searchPelamar(listPelamar L1, infotype X);
addr2 searchPekerjaan(listPekerjaan L2, infotype X);
/**Menu*/
void menuPilihan(int pil, listPelamar &L1, listPekerjaan &L2);

#endif // REKRUTMEN_H_INCLUDED
