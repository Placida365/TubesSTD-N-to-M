#include "REKRUTMEN.h"

/**==============================CREATE LIST==============================*/
void create2List(listPelamar &L1, listPekerjaan &L2){
    first(L1) = NIL;
    first(L2) = NIL;
}

/**==============================ALOKASI==============================*/
addr1 createNewPelamar(infotype X){
    addr1 P = new elmtPelamar;
    info(P) = X;
    nextI(P) = NIL;
    firstR(P) = NIL;
    return P;
}

addr2 createNewCouse(infotype X){
    addr2 P = new elmtPekerjaan;
    info(P) = X;
    nextC(P) = NIL;
    return P;
}

addr3 createNewRelasi(){
    addr3 P = new elmtRelasi;
    nextR(P) = NIL;
    nextC(P) = NIL;
    return P;
}

/**==============================INSERT FIRST ==============================*/
void insertfirstPelamar(listPelamar &L1, addr1 P){
    if (first(L1) != NULL){
        nextI(P) = first(L1);
        first(L1) = P;
    } else {
        first(L1) = P;
    }
}

void insertFirstPekerjaan(listPekerjaan &L2,addr2 P){
    if (first(L2) != NULL){
        nextC(P) = first(L2);
        first(L2) = P;
    } else {
        first(L2) = P;
    }
}

void insertFirstRelasi(listPelamar L1, listPekerjaan L2, infotype X, infotype Y){
    addr1 P = searchPelamar(L1,X);
    addr2 Q = searchPekerjaan(L2,Y);
    if (P != NIL && Q!=NIL){
        addr3 R = createNewRelasi();
        if (firstR(P) == NIL){
            firstR(P) = R;
            nextC(R) = Q;
        }else{
            nextR(R) = firstR(P);
            firstR(P) = R;
            nextC(R) = Q;
        }
        cout << "\nRelasi berhasil ditambahkan" << endl;
    }else{
        cout << "\nTidak bisa menambahkan relasi" << endl;
        cout << "Karena data yang dimasukkan tidak ada dalam list" << endl;
    }
}


/**==============================INSERT LAST==============================*/
void insertLastPelamar(listPelamar &L1, addr1 P){

    addr1 Q = first(L1);

    if (first(L1) != NULL){
        while(nextI(Q) != NULL){
            Q = nextI(Q);
        }
        nextI(Q) = P;
    } else{
        insertfirstPelamar(L1,P);
    }
}

void insertLastPekerjaan(listPekerjaan &L2, addr2 P){

    addr2 Q = first(L2);

    if (first(L2) != NULL){
        while(nextC(Q) != NULL){
            Q = nextC(Q);
        }
        nextC(Q) = P;
    }else{
        insertFirstPekerjaan(L2,P);
    }
}

/**==============================DELETE FIRST==============================*/
void deleteFirstPelamar(listPelamar &L1){
    if (first(L1) != NULL){
        addr1 P = first(L1);

            if(nextI(first(L1)) == NULL){
                if (firstR(P) != NIL){
                    firstR(P) = NIL;
                }
                first(L1) = NULL;
            }else{
                if (firstR(P) != NIL){
                    firstR(P) = NIL;
                }
                first(L1) = nextI(first(L1));
                nextI(P) = NULL;
        }
    }else{
        cout<<"DAFTAR PELAMAR KOSONG"<<endl;
    }
}

void deleteFirstPekerjaan(listPelamar L1, listPekerjaan &L2){
    addr2 P = first(L2);
    addr1 Q = first(L1);
    addr3 R;

    while (Q != NIL){
        R = firstR(Q);
            while (R != NIL){
                if (nextC(R) == P){
                    nextC(R) = NIL;
                }
                R = nextR(R);
            }
        Q = nextI(Q);
    }

    if (first(L2) != NULL){
        if(nextC(first(L2)) == NULL){
            first(L2) = NULL;
        }else{
            first(L2) = nextC(first(L2));
            nextC(P) = NULL;
        }
    }
    else{
        cout<<"DAFTAR PEKERJAAN KOSONG"<<endl;
    }
}



/**==============================PRINT==============================*/
void printPelamar(listPelamar L1){
    addr1 P = first(L1);
    int i = 1;
    cout << "\nDAFTAR PELAMAR" << endl;
    if (first(L1) != NIL){
        while (P != NIL){
            cout << i << ". " << info(P) << endl;
            P = nextI(P);
            i++;
        }
    }else{
        cout << "DAFTAR PELAMAR KOSONG" << endl;
    }
}

void printPekerjaan(listPekerjaan L2){
    addr2 P = first(L2);
    int i = 1;
    cout << "\nDAFTAR PEKERJAAN" << endl;
    if (first(L2) != NIL){
        while (P != NIL){
            cout << i << ". " << info(P) << endl;
            P = nextC(P);
            i++;
        }
    }else{
        cout << "DAFTAR PEKERJAAN KOSONG" << endl;
    }
}

void printPekerjaanWithInst(listPelamar L1, listPekerjaan L2){
    addr1 P;
    addr2 Q = first(L2);
    addr3 R;

    cout << "\n===============PRINT PEKERJAAN DENGAN PELAMAR===============" << endl;

    while (Q!= NIL){
        cout << "\nPekerjaan " << info(Q) << " Dipilih oleh : " << endl;
        P = first(L1);
        while (P != NIL){
            R = firstR(P);
                while (R != NIL){
                    if (nextC(R) == Q){
                        cout << info(P) << endl;
                    }
                    R = nextR(R);
                }
            P = nextI(P);
        }
        Q = nextC(Q);
    }
}

void findPelamar(listPelamar L1, listPekerjaan L2, infotype X){
    addr1 P;
    addr2 Q = searchPekerjaan(L2,X);
    addr3 R;

    if (Q != NIL){
        cout << "\nPekerjaan " << info(Q) << " diajarkan oleh : " << endl;
        P = first(L1);
        while (P != NIL){
            R = firstR(P);
                while (R != NIL){
                    if (nextC(R) == Q){
                        cout << info(P) << endl;
                    }
                    R = nextR(R);
                }
            P = nextI(P);
        }
    }else{
        cout << "\nTIDAK DAPAT MENAMPILKAN HASIL KARENA Pekerjaan TIDAK ADA" << endl;
    }
}



/**==============================SEARCHING==============================*/
addr1 searchPelamar(listPelamar L1, infotype X){
    addr1 P = first(L1);
    while (P != NIL){
        if (info(P) == X){
            return P;
            break;
        }else{
            P = nextI(P);
        }
    }
    if (P == NIL){
        return P;
    }
}

addr2 searchPekerjaan(listPekerjaan L2, infotype X){
    addr2 P = first(L2);
    while (P != NIL){
        if (info(P) == X){
            return P;
            break;
        }else{
            P = nextC(P);
        }
    }
    if (P == NIL){
        return P;
    }
}


/**==============================MENU==============================*/


void menuPilihan(int pil, listPelamar &L1, listPekerjaan&L2){
    infotype namaPelamar, namaPekerjaan;
    addr1 P;
    addr2 Q;
    switch(pil){
        case 1 : cout << "\nMasukkan Nama Pelamar yang ingin ditambahkan : ";
                 cin >> namaPelamar;
                 P = createNewPelamar(namaPelamar);
                 insertfirstPelamar(L1,P);
                 break;
        case 2 : cout << "\nMasukkan Nama Pekerjaan yang ingin ditambahkan : ";
                 cin >> namaPekerjaan;
                 Q = createNewCouse(namaPekerjaan);
                 insertFirstPekerjaan(L2,Q);
                 break;
        case 3 : cout << "\nMasukkan Nama Pelamar yang ingin ditambahkan : ";
                 cin >> namaPelamar;
                 P = createNewPelamar(namaPelamar);
                 insertLastPelamar(L1,P);
                 break;
        case 4 : cout << "\nMasukkan Nama Pekerjaan yang ingin ditambahkan : ";
                 cin >> namaPekerjaan;
                 Q = createNewCouse(namaPekerjaan);
                 insertLastPekerjaan(L2,Q);
                 break;
        case 5 : cout << "Masukkan Nama Pelamar dan Pekerjaan yang mau dipasangkan : " << endl;
                 cout << "Nama Pelamar : ";
                 cin >> namaPelamar;
                 cout << "Nama Pekerjaan : ";
                 cin >> namaPekerjaan;
                 insertFirstRelasi(L1,L2,namaPelamar,namaPekerjaan);
                 break;
        case 6 : printPelamar(L1);
                 break;
        case 7 : printPekerjaan(L2);
                 break;
        case 8 : printPekerjaanWithInst(L1,L2);
                 break;
        case 9 : cout << "\nMasukkan Nama Pelamar yang ingin dicari Pekerjaan yang diajarnya : ";
                 cin >> namaPelamar;
                 findPelamar(L1,L2,namaPelamar);
                 break;
        case 10 : deleteFirstPelamar(L1);
                  break;
        case 11 : deleteFirstPekerjaan(L1,L2);
                  break;
        case 12 : cout << "Masukkan Nama Pelamar yang mau dicari : ";
                  cin >> namaPelamar;
                  P = searchPelamar(L1,namaPelamar);
                  if (P != NIL){
                    cout << "Pelamar bernama " << namaPelamar << " ditemukan" << endl;
                  }else{
                    cout << "Pelamar tidak ditemukan" << endl;
                  }
                  break;
        case 13 : cout << "Masukkan Nama Pekerjaan yang mau dicari : ";
                  cin >> namaPekerjaan;
                  Q = searchPekerjaan(L2,namaPekerjaan);
                  if (Q != NIL){
                    cout << "Pekerjaan " << namaPekerjaan << " ditemukan" << endl;
                  }else{
                    cout << "Pekerjaan tidak ditemukan" << endl;
                  }
                  break;

        case 14 : break;
        default : cout << "Tolong masukkan angka yang valid! " << endl;
                  break;
    }
}
