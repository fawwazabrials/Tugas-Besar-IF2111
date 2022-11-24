# Tugas Besar IF2111 - Algoritma dan Struktur Data STI

## Deskripsi

> Repository ini ditujukan untuk memenuhi Tugas Besar Algoritma dan Struktur Data STI IF2111 tahun ajaran 2022/2023

BNMO (dibaca: Binomo) adalah sebuah robot game milik Indra dan Doni yang membantu mereka melepas stress ketika mendapatkan tugas selama di Institut Teknologi Bandung. Ketika sedang bermain game gacha, Indra marah dan membanting BNMO sampai rusak. Karena seorang programmer handal, BNMO berhasil diperbaiki. Sayangnya, setelah diperbaiki BNMO justru tambah rusak karena banyak bug. Oleh karena itu, Indra dan Doni ingin mencari programmer yang lebih handal untuk memrogram ulang robot kesayangan mereka.

## Anggota Kelompok

**Kelompok 7 Kelas K01 :**

| NIM          | Nama                       |
| ---          | ---                        |
| 18221063     | Aufar Ramadhan             |
| 18221067     | Fawwaz Abrial Saffa        |
| 18221069     | Gibran Fasha Ghazanfar     |
| 18221087     | Willy Frans Farel Sijabat  |
| 18221101     | Ilmagita Nariswari         |

## Setup program
Pastikan di komputer anda dapat menjalankan fungsi ```make```. Untuk OS Unix tidak perlu men-setup apapun. Untuk OS Windows dapat menonton video dibawah :
https://www.youtube.com/watch?v=a3ejgWLqelQ

## Cara Menjalankan Program
- Pindah ke directory /bin
    ``` 
    cd bin
    ```
- Jalankan Makefile
    ```
    make # %config_name%

    # Tersedia beberapa konfigurasi Makefile :
    # 1. Program utama : main
    # 2. Program tests : game, array, matriks, mesinkarakter, mesinkata, queue
    ```
    
- Jalankan program yang telah tercompile
    ``` 
    BNMO.exe        # bila anda menggunakan windows 
    ./BNMO          # bila anda menggunakan non-Windows (MacOS, Ubuntu)  

    # Untuk program driver, dapat menjalankan sesuai nama file executable yang telah dibuat
    ```