/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 3 (Structures and Dynamic Arrays)
 *   Hari dan Tanggal    : Selasa, 28 April 2026
 *   Nama (NIM)          : Rafif Hilman Muhammad (13224073)
 *   Nama File           : soal1.c
 *   Deskripsi           : input data-data pekerja, output pekerja ranking terbaik
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct data {
    char nama[50];
    int id;
    char shift[50];
    int skor;
} data;

int main(void){
    int n; //jumlah inputan
    scanf("%d", &n);
    char inputnama[50];
    int inputid;
    char inputshift[50];
    int inputskor;
    data daftarPekerja[n];
    data highdatapagi;
    data highdatasiang;
    data highdatamalam;

    //INPUTAN
    for (int i = 0; i < n ; i++){
        scanf("%s", inputnama);
        scanf("%d", &inputid);
        scanf("%s", inputshift);
        scanf("%d", &inputskor);
        
        int j = 0;
        while (daftarPekerja[i].nama[j] != 0){
            daftarPekerja[i].nama[j] = inputnama[j];            
        }
        daftarPekerja[i].nama[i] = inputnama[i];
        daftarPekerja[i].id = inputid;
        int k = 0;
        while (daftarPekerja[i].shift[k] != 0){
            daftarPekerja[i].shift[k] = inputshift[k];            
        }
        daftarPekerja[i].skor = inputskor;
    }
    
    // PENGOLAHAN
    if (n == 0){
        printf("-");
    }
    else if (n != 0){
        //PAGI
        for (int i = 0; i < n; i++){
            if (daftarPekerja[i].shift == 'PAGI'){
                highdatapagi = daftarPekerja[0];
                for (int j = i + 1; j < n; j++){
                    if (daftarPekerja[j].shift == 'PAGI'){
                        if (daftarPekerja[j].skor > daftarPekerja[i].skor){
                            highdatapagi = daftarPekerja[j];
                        }
                        else if (daftarPekerja[j].skor < daftarPekerja[i].skor){
                            highdatapagi = daftarPekerja[j];
                        }
                        else if (daftarPekerja[j].skor == daftarPekerja[i].skor){
                            if (daftarPekerja[j].id < daftarPekerja[i].id){
                                highdatapagi = daftarPekerja[j];
                            }
                            else if (daftarPekerja[j].skor >= daftarPekerja[i].skor){
                                highdatapagi = daftarPekerja[i];
                            }
                        }
                    }
                }
            }
        }        

        //SIANG
        for (int i = 0; i < n; i++){
            if (daftarPekerja[i].shift == 'SIANG'){
                highdatasiang = daftarPekerja[0];
                for (int j = i + 1; j < n; j++){
                    if (daftarPekerja[j].shift == 'SIANG'){
                        if (daftarPekerja[j].skor > daftarPekerja[i].skor){
                            highdatasiang = daftarPekerja[j];
                        }
                        else if (daftarPekerja[j].skor < daftarPekerja[i].skor){
                            highdatasiang = daftarPekerja[j];
                        }
                        else if (daftarPekerja[j].skor == daftarPekerja[i].skor){
                            if (daftarPekerja[j].id < daftarPekerja[i].id){
                                highdatasiang = daftarPekerja[j];
                            }
                            else if (daftarPekerja[j].skor >= daftarPekerja[i].skor){
                                highdatasiang = daftarPekerja[i];
                            }
                        }
                    }
                }
            }
        }  
        
        //MALAM
        for (int i = 0; i < n; i++){
            if (daftarPekerja[i].shift == 'MALAM'){
                highdatamalam = daftarPekerja[0];
                for (int j = i + 1; j < n; j++){
                    if (daftarPekerja[j].shift == 'MALAM'){
                        if (daftarPekerja[j].skor > daftarPekerja[i].skor){
                            highdatamalam = daftarPekerja[j];
                        }
                        else if (daftarPekerja[j].skor < daftarPekerja[i].skor){
                            highdatamalam = daftarPekerja[j];
                        }
                        else if (daftarPekerja[j].skor == daftarPekerja[i].skor){
                            if (daftarPekerja[j].id < daftarPekerja[i].id){
                                highdatamalam = daftarPekerja[j];
                            }
                            else if (daftarPekerja[j].skor >= daftarPekerja[i].skor){
                                highdatamalam = daftarPekerja[i];
                            }
                        }
                    }
                }
            }
        }
    }

    //OUTPUTAN
    printf("PAGI ");
    printf("%s ", highdatapagi.nama);
    printf("%d ", highdatapagi.id);
    printf("%d\n", highdatapagi.skor);

    printf("SIANG ");
    printf("%s ", highdatasiang.nama);
    printf("%d ", highdatasiang.id);
    printf("%d\n", highdatasiang.skor);
    
    printf("MALAM ");
    printf("%s ", highdatamalam.nama);
    printf("%d ", highdatamalam.id);
    printf("%d\n", highdatamalam.skor);

    return 0;
}

