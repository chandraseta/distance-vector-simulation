# Distance Vector Simulation


## Anggota Kelompok

- Rionaldi Chandraseta / 13515077
- Holy Lovenia / 13515113
- Agus Gunawan / 13515143


## Spesifikasi Tugas

Pada topologi jaringan, terdapat N _node_ yang diidentifikasikan dari 1 sampai N. Terdapat juga S skenario penyaluran _routing tables_. Pada kondisi asli, setiap _node_ akan mengirim informasi _routing tables_ miliknya ke semua _node_ yang terhubung secara langsung; namun agar _output_ program lebih deterministik, pengiriman informasi akan dilakukan sesuai dengan _input_ program. _Node_ tidak dapat mengirim ke _node_ yang tidak terhubung secara langsung dengannya.

Program akan memberikan _output_ berupa _routing table_ dari setiap _node_ setelah program melakukan skenario simulasi pengiriman pesan.

### Format Masukan

Baris pertama berisi dua  bilangan N dan M, jumlah _node_ pada topologi dan jumlah _edge_ pada topologi.
M baris berikutnya masing-masing berisi 2 bilangan. Baris ke-i berisi u<sub>i</sub> dan v<sub>i</sub>, yang menyatakan bahwa _node_ u<sub>i</sub> terhubung dengan _node_ v<sub>i</sub>.
Baris berikutnya berisi sebuah bilangan S, banyaknya skenario yang terjadi.
S baris berikutnya masing-masing terdiri dari 2 bilangan. Baris ke-i berisi x<sub>i</sub> dan y<sub>i</sub>, yang menyatakan bahwa _node_ x<sub>i</sub> akan mencoba mengirim informasi ke _node_ y<sub>i</sub>.

| Baris ke- | Masukan |
|:---------:|:-------:|
| 1 | **5 4** (Jumlah _node_ dan jumlah _edge_) |
| 2 | **1 2** (_Node_ 1 terhubung dengan _Node_ 2) |
| 3 | **2 3** (_Node_ 2 terhubung dengan _Node_ 3) |
| 4 | **3 4** (_Node_ 3 terhubung dengan _Node_ 4) |
| 5 | **4 5** (_Node_ 4 terhubung dengan _Node_ 5) |
| 6 | **5** (terdapat 5 skenario) |
| 7 | **1 2** (_Node_ 1 mengirim informasi ke _Node_ 2) |
| 8 | **2 3** (_Node_ 2 mengirim informasi ke _Node_ 3) |
| 9 | **2 1** (_Node_ 2 mengirim informasi ke _Node_ 1) |
| 10 | **3 4** (_Node_ 3 mengirim informasi ke _Node_ 4) |
| 11 | **4 5** (_Node_ 4 mengirim informasi ke _Node_ 5) |

### Routing Table

Berikut ini adalah salah satu contoh _routing table_, yaitu _routing table node_ 1 pada saat inisialisasi.

| Node | Distance | NextHop |
|:----:|:--------:|:-------:|
| 1 | 0 | 1 |
| 2 | 1 | 2 |
| 3 | -1 | -1 |
| 4 | -1 | -1 |
| 5 | -1 | -1 |

### Format Keluaran

Keluarkan N<sup>2</sup> baris. N baris pertama berisi informasi _routing table_ pada _node_ 1, N baris berikutnya berisi informasi pada _node_ 2, …., N baris terakhir berisi informasi pada _node_ N.

Untuk setiap N baris pada setiap _node_, baris ke-i berisi 2 buah bilangan di dan h<sub>i</sub>, yang menyatakan _distance_ dan _nextHop node_ ke-i pada _routing table_ yang bersangkutan. Jika ada beberapa kemungkinan h<sub>i</sub>, ambillah h<sub>i</sub> yang terkecil. Kedua bilangan tersebut dipisahkan oleh spasi. 

Penulisan _routing table_ sesuai dengan urutan _node_, mulai dari _routing table_ pada _node_ 1, _node_ 2, dan seterusnya.

Sebagai contoh, berikut adalah keluaran dari masukan diatas.

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

1. Masukan perintah _make_ pada terminal
2. Ubah masukan yang ingin dimasukkan di `data/input.txt` sesuai dengan format masukan.
3. Jalankan dengan memasukkan perintah _make run_ pada terminal
 

## Implementasi Simulasi Node dan Proses Pengiriman Antar Pesan

Tipe data yang digunakan pada tugas ini adalah _array_ 3 dimensi.

`routingTables[selectedNode][nodeOnRoutingTable][columnOnRoutingTable]`

Indeks pertama _array_ tersebut merepresentasikan _node_ yang memiliki sebuah _routing table_. Indeks kedua dan ketiga _array_ tersebut mendefinisikan _routing table_ yang dimiliki. Indeks kedua _array_ digunakan untuk merepresentasikan _node_ yang ada pada _routing table_. Indeks ketiga _array_ dipakai untuk merepresentasikan kolom yang ada pada _routing table_, yaitu _distance_ dan _next hop_.

1. Menerima masukan berupa jumlah _node_ dan jumlah _edge_ (hubungan ketetanggaan).
2. Melakukan inisialisasi awal seluruh _routing table_.
  - _Node_ lain pada _routing table_: _Distance_ dan _next hop_-nya diinisialisasi dengan nilai `UNKNOWN` (-1 pada contoh).
  - _Node_ diri sendiri pada _routing table_: _Distance_ diinisialisasi dengan nilai `MYSELF` (0 pada contoh) dan _next hop_-nya diinisialisasi dengan _node_ itu sendiri.
3. Menerima masukan (sejumlah _edge_ yang tadi sudah dimasukkan) berupa hubungan ketetanggaan dua _node_.
  - Mengganti nilai pada _routing table_ milik kedua _node_ terkait dengan nilai _distance_ dan _next hop_ yang sesuai pada setiap iterasinya.
4. Menerima masukan berupa jumlah skenario pengiriman pesan.
5. Menerima masukan (sejumlah skenario) berupa skenario pengiriman pesan antara dua _node_.
  - Melakukan _update_ pada _routing table_ milik _node_ tujuan berdasarkan skenario dan _routing table_ milik _node_ pengirim pada setiap iterasinya.
6. Menuliskan hasil akhir seluruh _routing table_ di layar.


## Pembagian Tugas
13515077 - Inisialisasi, Proses, _Output_
13515113 - Inisialisasi, Proses, _Output_
13515143 - Inisialisasi, Proses, _Output_


## Jawaban Pertanyaan

### Perbedaan Routing Protocol Distance-Vector dan Link State

**Distance-Vector Protocol** menghitung jarak antara _routers_ yang berada di dalam _network_-nya. Biasanya, jarak adalah jumlah _router_ yang dilewati untuk mencapai _router_ tujuan. Jarak yang disimpan pada _routing table_ adalah jarak terpendek. Selain itu, pada _routing table_ juga menyimpan rute berupa vektor. Disebut vektor karena memiliki arah, dari _router_ satu ke _router_ lainnya.

**Link State Protocol** memiliki cara berbeda dengan _distance-vector_. Setiap _router_ mengirimkan data mengenai dirinya dan _router_ lain yang terhubung secara langsung dengannya. Informasi ini disimpan oleh setiap _router_ yang membaca dan kemudian diteruskan dari satu _router_ ke seluruh _router_ lainnya. Pada akhirnya, semua _router_ tahu mengenai semua _router_ yang berada dalam network yang sama, termasuk alamat IP. Penentuan jarak terpendek menggunakan algoritma sendiri, karena tidak hanya dicatat yang terpendek saja.

Perbedaan utama _distance-vector_ dengan _link state_ adalah pengetahuan mengenai _router_ lain. Suatu _router_ dalam _distance-vector_ hanya bisa mendapatkan informasi dari tetangganya yang berhubungan langsung. Sedangkan _router_ dalam _link state_ mendapatkan informasi mengenai semua _router_ yang ada di dalam _network_ tersebut. Selain itu, _update_ pada _link state_ juga hanya terjadi ketika ada perubahan (penambahan/pengurangan _router_), sedangkan _distance-vector_ secara periodik.

### Routing Protocol yang Sering Digunakan dan Alasannya

**Routing Protocol** yang implementasinya sering digunakan pada saat ini adalah _Link State Routing Protocol_. Salah satu _Link State Protocol_ yang paling sering digunakan saat ini adalah _Open Shortest Path First_ (OSPF). Alasan _Link State Routing Protocol_ lebih sering digunakan adalah:
- Didesain untuk beroperasi pada _large, enterprise-level network_.
- Mengatasi banyak kekurangan yang dimiliki protokol _distance vector_.
- Mencapai titik konvergen lebih cepat dibandingkan _distance vector_, karena _link state_ hanya berbagi informasi _routing_ dengan tetangganya jika ada perubahan pada topologi jaringan.
- Mengirim informasi yang ter-_update_ ke _router_ tetangga, tidak seperti _distance vector_ yang mengirim seluruh _routing table_-nya.
- Lebih efisien.