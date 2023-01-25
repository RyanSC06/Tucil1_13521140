# 24-GAME SOLVER
## Identitas
Nama: Ryan Samuel Chandra<br />
NIM: 13521140<br />
Angkatan: 2021<br />
Kelas: K2<br />
Semester: 4<br />
Mata Kuliah: IF2211 Strategi Algoritma

## Deskripsi
Permainan kartu 24 (_24_-_game_) adalah salah satu permainan aritmatika kartu remi sederhana dapat mengasah otak dan melatih kecepatan berhitung seseorang. Peraturannya pun amat mudah; setiap pemain cukup berlomba mengoperasikan 4 kartu teratas dari tumpukan sehingga dapat menghasilkan 24, hanya dengan operator kali (×), bagi (/), tambah (+), kurang (−), serta tanda kurung ( ( ) ) sebagai tambahan.

<p align="center">
  <img width="1000" src="https://1.bp.blogspot.com/-e_OgNQXnntQ/Xob-RfKhAGI/AAAAAAAABaI/lIOuyli7sL87hC8bYWWLfn1HqRZ33BESACLcBGAsYHQ/s640/make%2Bit%2B24.png" alt="Ilustrasi Permainan Kartu 24">
</p>
  
Solusi dari permainan tersebut dapat ditemukan dengan program komputer. Meskipun dalam praktiknya, para pemain tentu akan dengan cepat memikirkan cara yang paling mungkin untuk menyusun keempat kartu sedemikian rupa, namun komputer berbeda. Ia akan mencoba satu per satu susunan yang mungkin dari kartu dan operator. Algoritme seperti itu dinamakan _brute force_, yaitu pendekatan yang lempang (_straightforward_), jelas, langsung, dan sederhana untuk memecahkan suatu persoalan.

Dengan bantuan konstruksi tipe data matriks, beberapa fungsi pendukung, serta konsep permutasi, program 24-game solver berhasil dibuat dalam bahasa pemrograman C. Silakan menikmati program lengkap yang telah saya buat. Terima kasih sudah berkunjung.


## Penggunaan
Tidak ada instalasi tambahan yang diperlukan untuk menjalankan program ini, melainkan cukup dengan komputer yang bisa mengeksekusi bahasa pemrograman C.
1. Memasukkan input: pada saat program dijalankan ketikkan angka '1' pada pertanyaan "Apakah Anda ingin memasukkan angka sendiri?", lalu tekan ENTER. Setelah itu, silakan masukkan keempat kartu yang Anda ingin cari solusinya. Tenang, program akan memvalidasi semua masukan Anda.
2. Membangkitkan masukan acak: pada saat program dijalankan ketikkan angka '0' pada pertanyaan "Apakah Anda ingin memasukkan angka sendiri?", lalu tekan ENTER.
3. Menyimpan solusi ke fail: pada saat masukan selesai diproses, dan keluaran sudah ditampilkan, ketikkan '1' pada pertanyaan "Apakah Anda ingin menyimpan solusi ke dalam fail", lalu tekan ENTER. Setelah itu, program akan meminta masukan nama fail (maksimal 15 karakter). Jangan lupa akhiri nama dengan ".txt" sebagai format default.
4. Jika tidak ingin menyimpan solusi, silakan ketikkan '0' pada pertanyaan "Apakah Anda ingin menyimpan solusi ke dalam fail", lalu tekan ENTER.
