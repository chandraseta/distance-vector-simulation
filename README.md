# Distance Vector Simulation


## Anggota Kelompok

- Rionaldi Chandraseta / 13515077
- Holy Lovenia / 13515113
- Agus Gunawan / 13515143


## Spesifikasi Tugas

Pada topologi jaringan, terdapat N node yang diidentifikasikan dari 1 sampai N. Terdapat juga S skenario penyaluran routing tables. Pada kondisi asli, setiap node akan mengirim informasi routing tables miliknya ke semua node yang terhubung secara langsung; namun agar output program lebih deterministik, pengiriman informasi akan dilakukan sesuai dengan input program. Node tidak dapat mengirim ke node yang tidak terhubung secara langsung dengannya.

Program akan memberikan output berupa routing table dari setiap node setelah program melakukan skenario simulasi pengiriman vector.

### Format Masukan

Baris pertama berisi dua  bilangan N dan M, jumlah node pada topologi dan jumlah edge pada topologi.
M baris berikutnya masing-masing berisi 2 bilangan. Baris ke-i berisi u<sub>i</sub> dan v<sub>i</sub>, yang menyatakan bahwa node u<sub>i</sub> terhubung dengan node v<sub>i</sub>.
Baris berikutnya berisi sebuah bilangan S, banyaknya skenario yang terjadi.
S baris berikutnya masing-masing terdiri dari 2 bilangan. Baris ke-i berisi x<sub>i</sub> dan y<sub>i</sub>, yang menyatakan bahwa node x<sub>i</sub> akan mencoba mengirim informasi ke node y<sub>i</sub>.

| Baris ke- | Masukan |
|:---------:|:-------:|
| 1 | **5 4** (Jumlah node dan jumlah edge) |
| 2 | **1 2** (Node 1 terhubung dengan Node 2) |
| 3 | **2 3** (Node 2 terhubung dengan Node 3) |
| 4 | **3 4** (Node 3 terhubung dengan Node 4) |
| 5 | **4 5** (Node 4 terhubung dengan Node 5) |
| 6 | **5** (terdapat 5 skenario) |
| 7 | **1 2** (Node 1 mengirim informasi ke Node 2) |
| 8 | **2 3** (Node 2 mengirim informasi ke Node 3) |
| 9 | **2 1** (Node 2 mengirim informasi ke Node 1) |
| 10 | **3 4** (Node 3 mengirim informasi ke Node 4) |
| 11 | **4 5** (Node 4 mengirim informasi ke Node 5) |

### Format Keluaran

Keluarkan N2 baris. N baris pertama berisi informasi routing table pada node 1, N baris berikutnya berisi informasi pada node 2, …., N baris terakhir berisi informasi pada node N.

Untuk setiap N baris pada setiap node, baris ke-i berisi 2 buah bilangan di dan hi, yang menyatakan distance dan nextHop node ke-i pada routing table yang bersangkutan. JIka ada beberapa kemungkinan hi, ambillah hi yang terkecil. Kedua bilangan tersebut dipisahkan oleh spasi. 

Penulisan routing table sesuai dengan urutan node, mulai dari routing table pada node 1, node 2, dan seterusnya.

Sebagai contoh, berikut adalah keluaran dari input diatas.

```
0 1 (Routing table Node 1)
1 2
2 2
-1 -1
-1 -1
1 1 (Routing table Node 2)
0 2
1 3
-1 -1
-1 -1
2 2 (Routing table Node 3)
1 2
0 3
1 4
-1 -1
3 3 (Routing table Node 4)
2 3
1 3
0 4
1 5
4 4 (Routing table Node 5)
3 4
2 4
1 4
0 5
```


## Petunjuk Penggunaan Program

1. Masukan perintah *make* pada terminal
2. Ubah masukan yang ingin dimasukkan di `data/input.txt` sesuai dengan [format masukan](###Format Masukan).
3. Jalankan dengan memasukan perintah *make run* pada terminal dan akan otomatis keluar outputnya pada layar
 

## Implementasi Simulasi Node dan Proses Pengiriman Antar Pesan

Belum diisi.


## Pembagian Tugas
13515077 - Inisialisasi, Proses, Output
13515113 - Inisialisasi, Proses, Output
13515143 - Inisialisasi, Proses, Output


## Jawaban Pertanyaan

### Perbedaan Routing Protocol Distance-Vector dan Link State

Belum diisi.

### Routing Protocol yang Sering Digunakan dan Alasannya

Belum diisi.