#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <string>

using namespace std;

#define PAUSE {cout << ("\n"); system("pause");}

int compare(char *str1, char *str2) {
    int len = strlen(str1);
    int beda = 0;

    for (int i=0; i<len; i++) {
        if (str1[i] >= 'A' && str1[i] <= 'Z') str1[i] += 32;
        if (str2[i] >= 'A' && str2[i] <= 'Z') str2[i] += 32;

        if (str1[i] != str2[i]) beda++;
        if (str2[i] == 'beda') {
            beda++;
                return beda;
        }
    }
    if (strlen(str2) < len) {
        beda += strlen(str2) - len;
    }
    return beda;
}


    int main()
{
    struct data_barang {
        char kode_barang[10];
        char judul_barang[50];
        int stock;
        struct data_barang *next;
    };
    struct data_barang *awal, *akhir, *p, *Psbl, *baru,*njut,*akhir1;

    awal = akhir = NULL;

    int pilihan ,posisi, posisi_sekarang,posisi_data;
    char cari[50], konfirmasi;

     cout << "***********************************************************" << endl;
     cout << "\t\t*Inventaris Kantor*" << endl;
     cout << "***********************************************************" << endl;

    do {
            cout << "\n\t\|================================|";
            cout << "\n\t\|Menu Inventaris                 |";
            cout << "\n\t\|                                |";
            cout << "\n\t\|1. Tambah Data Inventaris       |"
                    "\n\t\|2. Hapus Data Inventaris        |"
                    "\n\t\|3. Cari Barang Inventaris       |"
                    "\n\t\|4. Tampilkan Data Inventaris    |"
                    "\n\t\|5. Edit Data Inventaris         |"
                    "\n\t\|0. EXIT                         |"
                    "\n\t\|--------------------------------|";
            cout << "\n\nMasukkan pilihan anda : ";
            cin >> pilihan;
            system("cls");

        switch (pilihan) {
            case 1: // tambah data kedalam list

                baru = (struct data_barang *) malloc(sizeof(struct data_barang)); // alokasikan list baru di memori
                if (baru == NULL) {
                    cout << "\nMemori tidak cukup.";
                    PAUSE;
                    break;
                }
                cout << "=========================================="<< endl;
                cout << "1. Kode Barang  : ";
                cin >> baru -> kode_barang;
//              getchar();
                cout << "2. Judul Barang : ";
                cin >> baru -> judul_barang;
                cout << "3. Stock        : ";
                cin >> baru -> stock;
                cout << "==========================================";

                if (awal == NULL) {
                    awal = baru;
                    awal -> next = NULL;
                    akhir = baru;
                } else {
                    cout << "\nTambahkan Data di (Default = akhir) : \n";
                    cout << "1. Awal\n2. Tengah\n3. Akhir\n\nPilihan Anda : ";
                    cin >> posisi;
                    switch(posisi) {
                        case 1:
                            // tambah data di awal list
                            baru->next = awal;
                            awal= baru;
                            ;
                            PAUSE;
                            break;
                            system("cls");

                        case 2:
                            if (awal != NULL){
                            cout << "Masukan posisi data : ";
                            cin >> posisi_data;
                            p = awal;
                            Psbl = NULL;
                            posisi_sekarang = 1;
                            while (p != NULL && posisi_sekarang < posisi_data-1) {
                                //Psbl = p;
                                p = p->next;
                                posisi_sekarang++;
                            }
                            if (p != NULL) {
                                // tambahkan data di tengah (posisi_data)
                                Psbl = p;
                                baru->next = p->next;
                                Psbl->next = baru;
                            }
                            }
                            PAUSE;
                            break;
                        case 3:
                        default:
                            // tambah data di akhir list

                            if (awal == NULL){
                                 baru->next = awal;
                                 awal= baru;
                            }
                            else
                            {
//                                akhir -> next = baru;
//                                akhir = awal;
//                                baru->next = NULL;
//                            } else if (akhir1 != NULL ){
                               akhir = awal;
                               while (akhir->next != NULL)
                               {
                                   akhir = akhir -> next;
                               }
                               akhir->next= baru;
                            }
                            break;
                    }
                }
                PAUSE;
                break;

        case 2:
                p = awal;
                    cout << "==============================================";
                if (p == NULL) {
                    cout << "\n List Kosong!!!!!!!!!!!!!!\n";
                    cout << "\n----------------------------------------------\n";
                    break;
                } else {
                    while (p != NULL) {
                        cout << "\n============================================\n";
                        cout << "\nKode Barang   : " << p->kode_barang;
                        cout << "\nJudul Barang  : " << p->judul_barang;
                        cout << "\nStock         : " << p->stock;
                        cout << "\n============================================\n";
                        p = p->next;
                    }
                }
                cout << "\nMasukkan Judul barang dari data yang ingin dihapus : ";
                cin >> cari;
                Psbl = NULL;
                p = awal;
                while (p != NULL) {
                    if (compare(p->judul_barang, cari) == 0) {
                        cout << "\n==========================================\n";
                        cout << "\nKode Barang   : " << p->kode_barang;
                        cout << "\nJudul Barang  : " << p->judul_barang;
                        cout << "\nStock         : " << p->stock;
                        cout << "\n==========================================\n";
                        cout << "\nIngin menghapus data di atas (y/n) : ";
                        cin >> &konfirmasi;
                        if (konfirmasi == 'y' || konfirmasi == 'Y') {
                            if (awal->next == NULL) {
                                awal = NULL;
                                akhir = awal;
                            } else if (p == awal) {
                                // hapus di awal
                                Psbl = awal;
                                awal = Psbl->next;
                            } else if (p == akhir) {
                                // hapus di akhir
                                Psbl->next = NULL;
                                akhir = Psbl;
                            }
                            else {
                                // hapus di tengah
                                Psbl->next = p->next;
                            }
                            cout << "\nData berhasil dihapus.\n\n";
                        } else {
                            cout << "\nData tidak jadi dihapus.\n\n";
                        }
                        break;
                    }
                    Psbl = p;
                    p = p->next;
                }

                if (p == NULL) {
                    cout << "\n\nJudul Barang tidak ditemukan !\n\n";
                }
                PAUSE;
                system("cls");
                break;
            case 3:
                p = awal;
                cout << "==========================================";
                if (p == NULL) {
                    cout << "\n List Kosong\n";
                    cout << "\n------------------------------------------\n";
                } else {
                    while (p != NULL) {
                        cout << "\nKode Barang   : " << p->kode_barang;
                        cout << "\nJudul Barang  : " << p->judul_barang;
                        cout << "\nStock         : " << p->stock;
                        cout << "\n==========================================\n";
                        p = p->next;
                    }
                }
                cout << "\ningin cari barang? (y/n) : ";
                cin >> &konfirmasi;
                        if (konfirmasi == 'y' || konfirmasi == 'Y') {
                cout << "\n";
                cout << "\nMasukan Judul Barang yang di cari : ";
                cin >> cari;
                p = awal;
                while (p != NULL) {
                    if (compare(p->judul_barang, cari) == 0) {
                        cout << "\n==========================================";
                        cout << "\nKode Barang   : " << p->kode_barang;
                        cout << "\nJudul Barang  : " << p->judul_barang;
                        cout << "\nStock         : " << p->stock;
                        cout << "\n==========================================\n";
                        PAUSE;
                        break;
                    }
                    p = p->next;
                }
                if (p == NULL) {
                    cout << "\nData tidak ditemukan ! \n\n";
                    PAUSE;
                }
                else {
                    system("cls");
                    break;
                }
            }

                system("cls");
                break;

        case 4: // tampilkan list
                p = awal;
                cout << "==========================================";
                if (p == NULL) {
                    cout << "\n List Kosong\n";
                    cout << "\n------------------------------------------\n";
                } else {
                    while (p != NULL) {
                        cout << "\nKode Barang   : " << p->kode_barang;
                        cout << "\nJudul Barang  : " << p->judul_barang;
                        cout << "\nStock         : " << p->stock;
                        cout << "\n==========================================\n";
                        p = p->next;
                    }

                }
                cout << "ingin mengurutkan data berdasarkan Huruf depan ? (y/n) : ";
                cin >> &konfirmasi;
                        if (konfirmasi == 'y' || konfirmasi == 'Y') {
                cout << "\n";

                p = awal;
                while (p != NULL) {
                    if (compare(p->judul_barang, cari) == 0) {
                        cout << "\n==========================================";
                        cout << "\nJudul Barang  : " << p->judul_barang;
                        cout << "\n==========================================\n";
                        PAUSE;
                        break;
                    }
                    p = p->next;
                }
                if (p == NULL) {
                    cout << "\nData tidak ditemukan ! \n\n";
                    PAUSE;
                }

            }


                PAUSE;
                system("cls");
                break;

        case 5: // Edit data
                p = awal;
                cout << "==========================================";
                if (p == NULL) {
                    cout << "\n Tidak Ada Data \n";
                    cout << "\n------------------------------------------\n";
                    break;
                } else {
                    while (p != NULL) {
                        cout << "==========================================";
                        cout << "\nKode Barang   : " << p->kode_barang;
                        cout << "\nJudul Barang  : " << p->judul_barang;
                        cout << "\nStock         : " << p->stock;
                        cout << "\n==========================================\n";
                        p = p->next;
                    }
                }
                cout << "\nMasukkan Judul barang dari data yang ingin diupdate : ";
                cin >> cari;
                Psbl = NULL;
                p = awal;
                while (p != NULL) {
                    if (compare(p->judul_barang, cari) == 0) {
                        cout << "\n==========================================";
                        cout << "\nKode Barang   : " << p->kode_barang;
                        cout << "\nJudul Barang  : " << p->judul_barang;
                        cout << "\nStock         : " << p->stock;
                        cout << "\n==========================================\n";
                        cout << "\nIngin Edit data di atas (y/n) : ";
                        cin >> &konfirmasi;
                        if (konfirmasi == 'y' || konfirmasi == 'Y') {
                                if (awal->next == NULL) {
                                awal = NULL;
                                akhir = awal;
                            } else if (p == awal) {
                                // hapus di awal
                                Psbl = awal;
                                awal = Psbl->next;
                            } else if (p == akhir) {
                                // hapus di akhir
                                Psbl->next = NULL;
                                akhir = Psbl;
                            }
                            else {
                                // hapus di tengah
                                Psbl->next = p->next;
                            }

                baru = (struct data_barang *) malloc(sizeof(struct data_barang)); // alokasikan list baru di memori
                if (baru == NULL) {
                    cout << "\nMemori tidak cukup.";
                    PAUSE;
                    break;
                }
                cout << "=========================================="<< endl;
                cout << "1. Kode Barang  : ";
                cin >> baru -> kode_barang;
//              getchar();
                cout << "2. Judul Barang : ";
                cin >> baru -> judul_barang;
                cout << "3. Stock        : ";
                cin >> baru -> stock;
                cout << "==========================================";

                if (awal == NULL) {
                    awal = baru;
                    awal -> next = NULL;

                    akhir = baru;
                } else {
                    cout << "\nTambahkan Data di (Default = akhir) : \n";
                    cout << "1. Awal\n2. Tengah\n3. Akhir\n\nPilihan Anda : ";
                    cin >> posisi;
                    switch(posisi) {
                        case 1:
                            // tambah data di awal list
                            baru->next = awal;
                            awal= baru;
                            ;
                            PAUSE;
                            break;
                        case 2:
                            if (awal != NULL){
                            cout << "Masukan posisi data : ";
                            cin >> posisi_data;
                            p = awal;
                            Psbl = NULL;
                            posisi_sekarang = 1;
                            while (p != NULL && posisi_sekarang < posisi_data-1) {
                                //Psbl = p;
                                p = p->next;
                                posisi_sekarang++;
                            }
                            if (p != NULL) {
                                // tambahkan data di tengah (posisi_data)
                                Psbl = p;
                                baru->next = p->next;
                                Psbl->next = baru;
                            }
                            }
                            break;
                        case 3:
                        default:
                            // tambah data di akhir list

                            akhir->next = baru;
                            akhir = baru;
                            baru->next = NULL;
                            PAUSE;
                            break;
                    }
                }
                            cout << "\nData berhasil diUpdate.\n\n";
                        } else {
                            cout << "\nData tidak jadi diupdate.\n\n";
                        }
                        break;
                    }
                    Psbl = p;
                    p = p->next;
                }

                if (p == NULL) {
                    cout << "\n\nJudul Barang tidak ditemukan !\n\n";
                }

                PAUSE;
                system("cls");
                break;

            case 0: break;
            default:
                cout << "\nPilihan salah !\n";
                break;
        }
    } while (pilihan > 0);

    return 0;
}
