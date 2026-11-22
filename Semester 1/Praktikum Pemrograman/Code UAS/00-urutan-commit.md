# Urutan Commit Global (50 commit)

Urutan ini sudah diuji: **setiap commit bisa di-`make` tanpa error**. Satu-satunya peringatan yang mungkin muncul adalah `defined but not used` untuk fungsi `static` yang baru dipakai di commit berikutnya - itu normal.

## Alur Kerja Git

- Anggota 4 membuat repo dan mengerjakan commit #1-#3 langsung di `main`, lalu mengundang anggota lain.
- Tiap anggota membuat branch sendiri (`git checkout -b <nama-branch>`) dan mengerjakan commit bagiannya **sesuai urutan nomor**.
- Untuk setiap blok commit berurutan milik satu anggota, buat Pull Request ke `main`, minta direview anggota lain, lalu merge sebelum anggota berikutnya mulai.
- Review silang: 1 mengecek 2, 2 mengecek 3, 3 mengecek 4, 4 mengecek 1.
- Setelah merge, anggota lain menjalankan `git pull` sebelum mulai bagiannya.

Branch yang disarankan: Anggota 1: `feat/book-data`, Anggota 2: `feat/util-sorting`, Anggota 3: `feat/auth-loan`, Anggota 4: `feat/ui-admin` (boleh dibuat ulang per blok, misalnya `feat/book-data-2`).

## Daftar Commit

| # | Anggota | Pesan commit |
|---|---------|--------------|
| 1 | 4 | `chore: inisialisasi repo` |
| 2 | 4 | `feat: kerangka program dan Makefile` |
| 3 | 4 | `feat: tambah config.h` |
| 4 | 2 | `feat(util): trim dan copy string aman` |
| 5 | 2 | `feat(util): baca satu baris input` |
| 6 | 2 | `feat(util): parsing dan prompt angka` |
| 7 | 2 | `feat(util): perbandingan string tanpa case` |
| 8 | 2 | `feat(util): validasi dan prompt teks` |
| 9 | 2 | `feat(util): konfirmasi y/n dan pause` |
| 10 | 2 | `feat(util): tanggal hari ini dan ganti berkas` |
| 11 | 1 | `feat(book): struct Book dan BookList` |
| 12 | 1 | `feat(book): daftar buku dinamis` |
| 13 | 1 | `feat(book): cari, tambah, hapus di memori` |
| 14 | 1 | `feat(book): pembaca field berpetik dua` |
| 15 | 1 | `feat(book): parser satu baris Books.txt` |
| 16 | 1 | `feat(book): impor dataset asli (read-only)` |
| 17 | 1 | `feat(book): simpan katalog (tulis .tmp lalu rename)` |
| 18 | 1 | `feat(book): muat katalog operasional` |
| 19 | 2 | `feat(sort): kerangka dan Bubble Sort` |
| 20 | 2 | `feat(sort): Insertion Sort` |
| 21 | 2 | `feat(sort): Selection Sort dan dispatcher` |
| 22 | 2 | `feat(sort): nama algoritma, atribut, dan arah` |
| 23 | 3 | `feat(user): struct dan daftar akun` |
| 24 | 3 | `feat(user): simpan dan muat akun (+akun bawaan)` |
| 25 | 3 | `feat(user): autentikasi dan cek role` |
| 26 | 3 | `feat(loan): struct dan daftar transaksi` |
| 27 | 3 | `feat(loan): simpan dan muat transaksi` |
| 28 | 3 | `feat(loan): cari peminjaman aktif` |
| 29 | 3 | `feat(loan): peminjaman buku` |
| 30 | 3 | `feat(loan): pengembalian buku` |
| 31 | 1 | `feat(app): struct App dan app_free` |
| 32 | 1 | `feat(app): app_init (impor otomatis + muat semua berkas)` |
| 33 | 3 | `feat(auth): login interaktif dan lewat argumen` |
| 34 | 3 | `feat(auth): registrasi anggota baru` |
| 35 | 4 | `feat(ui): pencetak sel tabel aman UTF-8` |
| 36 | 4 | `feat(ui): tabel buku berhalaman` |
| 37 | 4 | `feat(ui): detail satu buku` |
| 38 | 4 | `feat(ui): tabel transaksi peminjaman` |
| 39 | 2 | `feat(ui): menu pilihan algoritma dan atribut sorting` |
| 40 | 4 | `feat(ui): katalog dengan sorting dan waktu eksekusi` |
| 41 | 4 | `feat(ui): pencarian buku (ID / judul)` |
| 42 | 3 | `feat(menu-user): tampilan pinjaman milik user` |
| 43 | 3 | `feat(menu-user): pinjam dan kembalikan buku` |
| 44 | 3 | `feat(menu-user): menu utama anggota` |
| 45 | 4 | `feat(menu-admin): tambah buku` |
| 46 | 4 | `feat(menu-admin): ubah data buku` |
| 47 | 4 | `feat(menu-admin): hapus buku (cek peminjaman aktif)` |
| 48 | 4 | `feat(menu-admin): laporan transaksi dan menu admin` |
| 49 | 4 | `feat(main): alur login, sesi per role, dan logout` |
| 50 | 4 | `docs: lengkapi README` |

## Jumlah Commit per Anggota

- Anggota 1 - Data & File Handling: 10 commit
- Anggota 2 - Sorting & Utilitas: 12 commit
- Anggota 3 - Akun & Sirkulasi: 13 commit
- Anggota 4 - Tampilan, Admin & Rilis: 15 commit

## Peringatan

Jangan menyalin semua kode lalu membuat commit palsu dengan tanggal/penulis yang diatur. Ketik dan pahami kode bagianmu sendiri per commit, karena kontribusi dinilai dari commit history dan setiap anggota diuji individual saat demo 25 November.
