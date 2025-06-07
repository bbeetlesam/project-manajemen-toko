# Manajemen Toko

Program **Manajemen Toko** adalah program yang dibuat untuk mempermudah **pebisnis** (atau spesifiknya, **pemilik/akuntan toko**) untuk memanajemen barang yang dimiliki pada toko saat itu,
karena perhitungan secara manual cenderung melelahkan dan dapat terjadi **human error**, seperti kesalahan perhitungan kuantitas, dan lain sebagainya.

Program ini dibuat sebagai proyek akhir pada mata kuliah **Struktur Data**, dengan menggunakan bahasa **C++** dan implementasi konsep seperti _single linked list_, _sorting algorithm_,
_dynamic memory allocation_, serta _modular programming_ untuk mempermudah maintenance kode.

## Fitur-fitur

Program ini memiliki `6` fitur utama, yaitu:

- **Tampilkan Barang**: Menampilkan barang yang sedang ada dalam 'gudang' atau rak program.
- **Input Barang**: Memasukkan barang baru ke dalam rak.
- **Hapus Barang**: Menghapus barang yang ada dalam rak dengan `idBarang`.
- **Edit Barang**: Mengubah _atribut_ barang (seperti letak rak, nama barang, harga barang, dsb) yang ada dalam rak.
- **Sort Barang**: Melakukan pengurutan barang sesuai berdasarkan `kodeRak`, `idBarang`, dan `stok`, dan keduanya bisa dilakukan baik secara
_ascending_ maupun _descending_.
- **Cari Barang**: Mencari barang dengan `idBarang`, lalu menampilkan semua _atribut_ barang tersebut.

## Implementasi Konsep

Dalam fitur-fitur diatas, digunakan beberapa konsep dalam programnya, yaitu:

- Dalam penggunaan `idBarang` untuk tiap barang, digunakan konsep _single linked list_, dimana elemen barang diletakkan **persis** di samping elemen barang sebelumnya secara berurutan,
sehingga proses pengubahan seperti **Input**, **Hapus**, dan **Edit** bisa dilakukan dengan lebih cepat, efisien, dan mudah. Di sini, konsep tersebut diimplementasikan
menggunakan jenis data **struct** yang ada dalam **C++**.
- Dalam fitur **Sort**, digunakan _sorting algorithm_, yaitu algoritma untuk mengurutkan kumpulan elemen dalam konteks tertentu. Di sini, digunakan algoritma **_Bubble Sort_**,
salah satu _sorting algorithm_ paling simpel dan cukup terkenal dalam kalangan pemula.
- Untuk keseluruhan kode, konsep _modular programming_ digunakan, yaitu konsep memisahkan kode dalam blok fungsi sesuai fungsinya masing-masing, yang nantinya akan dipanggil pada
waktu yang tepat, sehingga kode lebih 'modular', rapi, dan mudah dipahami.

## Menjalankan Program

Untuk menjalankan program **Manajemen Toko** ini, dibutuhkan **compiler C++** seperti _MinGw_, _Clang_, atau _LLVM_ untuk menjalankan program ini
(kecuali menggunakan _**IDE**_, seperti _CLion_ atau _Code::Blocks_). Lalu, pastikan bahwa compiler tersebut telah ditambahkan dalam _Environment Variables_.\
Apabila compiler telah terinstall, ketik command:

#### MinGW:

`g++ manajemen-toko.cpp -o manajemen-toko.exe` lalu `.\manajemen-toko`, atau\
`g++ manajemen-toko.cpp -o manajemen-toko.exe ; if ($?) { .\manajemen-toko }`

#### CLang

`clang++ manajemen-toko.cpp -o manajemen-toko.exe` lalu `.\manajemen-toko`, atau\
`clang++ manajemen-toko.cpp -o manajemen-toko.exe ; if ($?) { .\manajemen-toko }`

Dalam _code-editor_ **VSCode**, cukup tekan `Run Code` atau shortcut `Ctrl`+`Alt`+`N` untuk menjalankan program (dengan syarat compiler telah terinstall).

## About

Program ini dibuat oleh `4` orang, termasuk pemilik repo ini.\
That's it. I don't have anything to be texted again, I'm fvkg dried.

Thanks for reading this useless README, try to take a tour on my GitHub profile (you'll be wasting your time).

Sincerely, Sam.
