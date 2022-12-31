#include"REKRUTMEN.h"


int main()
{
    listPelamar L1;
    listPekerjaan L2;
    addr1 P;
    addr2 Q;
    int pil;

    create2List(L1,L2);
    {
    /**==============================MENU==============================*/
    cout << "==========SELAMAT DATANG DI PENERIMAAN PEGAWAI==========" << endl;
    cout << "Silakan pilih menu yang ingin Anda lakukan : " << endl;
    cout << "\n---MENAMBAH Pelamar / Pekerjaan---" << endl;
    cout << "1. Insert First Pelamar" << endl;
    cout << "2. Insert First Pekerjaan" << endl;
    cout << "3. Insert Last Pelamar" << endl;
    cout << "4. Insert Last Pekerjaan" << endl;
    cout << "\n---MENAMBAH RELASI ANTARA KEDUANYA---" << endl;
    cout << "5. Insert First Relasi" << endl;
    cout << "\n---PRINT---" << endl;
    cout << "6. Print Pelamar" << endl;
    cout << "7. Print Pekerjaan" << endl;
    cout << "8. Print Pekerjaan with Pelamar" << endl;
    cout << "9. Find Pelamar" << endl;
    cout << "\n---MENGHAPUS Pelamar / Pekerjaan---" << endl;
    cout << "10. Delete First Pelamar" << endl;
    cout << "11. Delete First Pekerjaan" << endl;
    cout << "\n---SEARCHING---" << endl;
    cout << "12. Search Pelamar" << endl;
    cout << "13. Search Pekerjaan" << endl;
    cout << "14. Keluar" << endl;
    cout << "\nPilihan Anda : ";

        cin >> pil;
        menuPilihan(pil,L1,L2);
        system("PAUSE");
        system("CLS");
    }while(pil != 16);
    cout << "\n=============================END OF PROGRAM===============================" << endl;

    return 0;
}
