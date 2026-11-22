# Anggota 1 - Data & File Handling

Commit milikmu: #11, #12, #13, #14, #15, #16, #17, #18, #31, #32

Kode di bawah adalah isi persis yang ditambahkan pada tiap commit. Ketik sendiri sambil membaca, lalu jalankan `make` sebelum commit.

---

## Commit #11 - `feat(book): struct Book dan BookList`

> Mulai setelah commit #10 (milik Anggota 2) sudah masuk ke `main`.

**`src/book.h`** - Buat berkas baru:

```c
#ifndef BOOK_H
#define BOOK_H

#include <stddef.h>
#include "config.h"

typedef struct {
    char ocaid[LEN_OCAID];
    char title[LEN_TITLE];
    char author[LEN_AUTHOR];
    int  year;
    int  page_count;
    char edition[LEN_OLID];   /* openlibrary_edition */
    char work[LEN_OLID];      /* openlibrary_work    */
    char url[LEN_URL];        /* full_text_url       */
    int  stock;
} Book;

typedef struct {
    Book  *items;
    size_t count;
    size_t capacity;
} BookList;

typedef struct {
    int total_lines;
    int imported;
    int skipped_invalid;
    int skipped_duplicate;
} ImportReport;

void  booklist_init(BookList *bl);
void  booklist_free(BookList *bl);
Book *booklist_find(const BookList *bl, const char *ocaid);
int   booklist_add(BookList *bl, const Book *b);     /* 0 ok, -1 memori, -2 duplikat */
int   booklist_remove(BookList *bl, const char *ocaid);

/* Dataset asli (read-only) -> memori */
int   book_import_master(BookList *bl, ImportReport *report);
int   book_parse_master_line(const char *line, Book *out);

/* Inventaris operasional (dataset + stok) */
int   book_catalog_load(BookList *bl);               /* -1 jika berkas belum ada */
int   book_catalog_save(const BookList *bl);

#endif
```

Cek build lalu commit:

```bash
make clean && make     # harus selesai tanpa error
git add src/book.h
git commit -m "feat(book): struct Book dan BookList"
```

---

## Commit #12 - `feat(book): daftar buku dinamis`

**`src/book.c`** - Buat berkas baru:

```c
#include "book.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

void booklist_init(BookList *bl)
{
    bl->items = NULL;
    bl->count = 0;
    bl->capacity = 0;
}

void booklist_free(BookList *bl)
{
    free(bl->items);
    booklist_init(bl);
}

static int booklist_reserve(BookList *bl, size_t need)
{
    size_t cap;
    Book *p;

    if (need <= bl->capacity) {
        return 0;
    }
    cap = bl->capacity != 0 ? bl->capacity : 256;
    while (cap < need) {
        cap *= 2;
    }
    p = realloc(bl->items, cap * sizeof(Book));
    if (p == NULL) {
        return -1;
    }
    bl->items = p;
    bl->capacity = cap;
    return 0;
}
```

Cek build lalu commit:

```bash
make clean && make     # harus selesai tanpa error
git add src/book.c
git commit -m "feat(book): daftar buku dinamis"
```

---

## Commit #13 - `feat(book): cari, tambah, hapus di memori`

**`src/book.c`** - Tambahkan di **akhir** berkas:

```c
Book *booklist_find(const BookList *bl, const char *ocaid)
{
    size_t i;

    for (i = 0; i < bl->count; i++) {
        if (strcmp(bl->items[i].ocaid, ocaid) == 0) {
            return &bl->items[i];
        }
    }
    return NULL;
}

int booklist_add(BookList *bl, const Book *b)
{
    if (booklist_find(bl, b->ocaid) != NULL) {
        return -2;
    }
    if (booklist_reserve(bl, bl->count + 1) != 0) {
        return -1;
    }
    bl->items[bl->count++] = *b;
    return 0;
}

int booklist_remove(BookList *bl, const char *ocaid)
{
    Book *b = booklist_find(bl, ocaid);
    size_t idx;

    if (b == NULL) {
        return -1;
    }
    idx = (size_t)(b - bl->items);
    memmove(&bl->items[idx], &bl->items[idx + 1], (bl->count - idx - 1) * sizeof(Book));
    bl->count--;
    return 0;
}
```

Cek build lalu commit:

```bash
make clean && make     # harus selesai tanpa error
git add src/book.c
git commit -m "feat(book): cari, tambah, hapus di memori"
```

---

## Commit #14 - `feat(book): pembaca field berpetik dua`

**Catatan:** Ini bagian paling rumit di modul data: judul/pengarang bisa berpetik, bisa memuat "" , dan sebagian satu kata tanpa petik.

**`src/book.c`** - Tambahkan di **akhir** berkas:

```c
static int read_text_field(const char **pp, char *dst, size_t size)
{
    const char *p = *pp;
    size_t n = 0;

    while (*p != '\0' && isspace((unsigned char)*p)) {
        p++;
    }
    if (*p == '\0') {
        return 0;
    }
    if (*p == '"') {
        p++;
        for (;;) {
            if (*p == '\0') {
                return 0; /* tanda petik penutup tidak ada */
            }
            if (*p == '"') {
                if (p[1] == '"') {
                    if (n + 1 < size) {
                        dst[n++] = '"';
                    }
                    p += 2;
                    continue;
                }
                p++;
                break;
            }
            if (n + 1 < size) {
                dst[n++] = *p;
            }
            p++;
        }
    } else {
        while (*p != '\0' && !isspace((unsigned char)*p)) {
            if (n + 1 < size) {
                dst[n++] = *p;
            }
            p++;
        }
    }
    dst[n] = '\0';
    *pp = p;
    return 1;
}
```

Cek build lalu commit:

```bash
make clean && make     # harus selesai tanpa error
git add src/book.c
git commit -m "feat(book): pembaca field berpetik dua"
```

---

## Commit #15 - `feat(book): parser satu baris Books.txt`

**`src/book.c`** - Tambahkan di **akhir** berkas:

```c
int book_parse_master_line(const char *line, Book *out)
{
    const char *p = line;
    Book b;

    memset(&b, 0, sizeof(b));
    if (!read_text_field(&p, b.ocaid, sizeof(b.ocaid)) ||
        !read_text_field(&p, b.title, sizeof(b.title)) ||
        !read_text_field(&p, b.author, sizeof(b.author))) {
        return 0;
    }
    if (sscanf(p, " %d %d %31s %31s %127s", &b.year, &b.page_count,
               b.edition, b.work, b.url) != 5) {
        return 0;
    }
    if (b.year <= 0 || b.page_count <= 0 || !util_is_token(b.ocaid)) {
        return 0;
    }
    util_sanitize_field(b.title);
    util_sanitize_field(b.author);
    b.stock = DEFAULT_STOCK;
    *out = b;
    return 1;
}
```

Cek build lalu commit:

```bash
make clean && make     # harus selesai tanpa error
git add src/book.c
git commit -m "feat(book): parser satu baris Books.txt"
```

---

## Commit #16 - `feat(book): impor dataset asli (read-only)`

**`src/book.c`** - Tambahkan di **akhir** berkas:

```c
int book_import_master(BookList *bl, ImportReport *report)
{
    FILE *f = fopen(FILE_BOOKS_MASTER, "r");
    char line[LINE_BUFFER];
    Book b;
    int first = 1;
    int rc;

    memset(report, 0, sizeof(*report));
    if (f == NULL) {
        return -1;
    }
    while (fgets(line, sizeof(line), f) != NULL) {
        size_t len = strlen(line);

        while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) {
            line[--len] = '\0';
        }
        if (first) {            /* baris header */
            first = 0;
            continue;
        }
        if (len == 0) {
            continue;
        }
        report->total_lines++;
        if (!book_parse_master_line(line, &b)) {
            report->skipped_invalid++;
            continue;
        }
        rc = booklist_add(bl, &b);
        if (rc == 0) {
            report->imported++;
        } else if (rc == -2) {
            report->skipped_duplicate++;
        } else {
            fclose(f);
            return -1;
        }
    }
    fclose(f);
    return 0;
}
```

Cek build lalu commit:

```bash
make clean && make     # harus selesai tanpa error
git add src/book.c
git commit -m "feat(book): impor dataset asli (read-only)"
```

---

## Commit #17 - `feat(book): simpan katalog (tulis .tmp lalu rename)`

**`src/book.c`** - Tambahkan di **akhir** berkas:

```c
int book_catalog_save(const BookList *bl)
{
    char tmp[256];
    FILE *f;
    size_t i;

    snprintf(tmp, sizeof(tmp), "%s.tmp", FILE_CATALOG);
    f = fopen(tmp, "w");
    if (f == NULL) {
        return -1;
    }
    for (i = 0; i < bl->count; i++) {
        const Book *b = &bl->items[i];
        fprintf(f, "%s|%s|%s|%d|%d|%s|%s|%s|%d\n", b->ocaid, b->title, b->author,
                b->year, b->page_count, b->edition, b->work, b->url, b->stock);
    }
    if (fclose(f) != 0) {
        remove(tmp);
        return -1;
    }
    return util_replace_file(tmp, FILE_CATALOG);
}
```

Cek build lalu commit:

```bash
make clean && make     # harus selesai tanpa error
git add src/book.c
git commit -m "feat(book): simpan katalog (tulis .tmp lalu rename)"
```

---

## Commit #18 - `feat(book): muat katalog operasional`

**`src/book.c`** - Tambahkan di **akhir** berkas:

```c
static int split_fields(char *line, char **fields, int max)
{
    int n = 0;
    char *p = line;

    fields[n++] = p;
    while (*p != '\0' && n < max) {
        if (*p == '|') {
            *p = '\0';
            fields[n++] = p + 1;
        }
        p++;
    }
    return n;
}

static int parse_catalog_line(char *line, Book *out)
{
    char *f[9];
    Book b;
    int year, pages, stock;

    if (split_fields(line, f, 9) != 9) {
        return 0;
    }
    if (!util_parse_int(f[3], 1, 9999, &year) ||
        !util_parse_int(f[4], 1, 1000000, &pages) ||
        !util_parse_int(f[8], 0, 1000000, &stock) || !util_is_token(f[0])) {
        return 0;
    }
    memset(&b, 0, sizeof(b));
    util_copy(b.ocaid, sizeof(b.ocaid), f[0]);
    util_copy(b.title, sizeof(b.title), f[1]);
    util_copy(b.author, sizeof(b.author), f[2]);
    b.year = year;
    b.page_count = pages;
    util_copy(b.edition, sizeof(b.edition), f[5]);
    util_copy(b.work, sizeof(b.work), f[6]);
    util_copy(b.url, sizeof(b.url), f[7]);
    b.stock = stock;
    *out = b;
    return 1;
}

int book_catalog_load(BookList *bl)
{
    FILE *f = fopen(FILE_CATALOG, "r");
    char line[LINE_BUFFER];
    Book b;

    if (f == NULL) {
        return -1;
    }
    while (fgets(line, sizeof(line), f) != NULL) {
        size_t len = strlen(line);

        while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) {
            line[--len] = '\0';
        }
        if (len == 0) {
            continue;
        }
        if (parse_catalog_line(line, &b)) {
            if (booklist_add(bl, &b) == -1) {
                fclose(f);
                return -1;
            }
        }
    }
    fclose(f);
    return 0;
}
```

Cek build lalu commit:

```bash
make clean && make     # harus selesai tanpa error
git add src/book.c
git commit -m "feat(book): muat katalog operasional"
```

---

## Commit #31 - `feat(app): struct App dan app_free`

> Mulai setelah commit #30 (milik Anggota 3) sudah masuk ke `main`.

**`src/app.h`** - Buat berkas baru:

```c
#ifndef APP_H
#define APP_H

#include "book.h"
#include "loan.h"
#include "user.h"

typedef struct {
    BookList books;
    UserList users;
    LoanList loans;
} App;

int  app_init(App *app);   /* muat/ bootstrap semua berkas data; 0 = sukses */
void app_free(App *app);   /* bebaskan seluruh memori dinamis               */

#endif
```

**`src/app.c`** - Buat berkas baru:

```c
#include "app.h"

#include <stdio.h>

void app_free(App *app)
{
    booklist_free(&app->books);
    userlist_free(&app->users);
    loanlist_free(&app->loans);
}
```

Cek build lalu commit:

```bash
make clean && make     # harus selesai tanpa error
git add src/app.h src/app.c
git commit -m "feat(app): struct App dan app_free"
```

---

## Commit #32 - `feat(app): app_init (impor otomatis + muat semua berkas)`

**`src/app.c`** - Tambahkan di **akhir** berkas:

```c
int app_init(App *app)
{
    ImportReport rep;

    booklist_init(&app->books);
    userlist_init(&app->users);
    loanlist_init(&app->loans);

    if (book_catalog_load(&app->books) != 0) {
        /* Pertama kali dijalankan: impor dataset asli (read-only) + stok awal */
        printf("Menyiapkan inventaris dari %s ...\n", FILE_BOOKS_MASTER);
        if (book_import_master(&app->books, &rep) != 0) {
            fprintf(stderr, "Gagal membuka dataset '%s'.\n", FILE_BOOKS_MASTER);
            return -1;
        }
        printf("  Baris data      : %d\n", rep.total_lines);
        printf("  Berhasil diimpor: %d buku (stok awal %d/judul)\n", rep.imported, DEFAULT_STOCK);
        if (rep.skipped_duplicate > 0) {
            printf("  Dilewati (ID ganda): %d\n", rep.skipped_duplicate);
        }
        if (rep.skipped_invalid > 0) {
            printf("  Dilewati (format tidak valid): %d\n", rep.skipped_invalid);
        }
        if (book_catalog_save(&app->books) != 0) {
            fprintf(stderr, "Gagal menulis '%s'.\n", FILE_CATALOG);
            return -1;
        }
    }
    if (users_load(&app->users) != 0) {
        fprintf(stderr, "Gagal memuat/membuat '%s'.\n", FILE_USERS);
        return -1;
    }
    if (loans_load(&app->loans) != 0) {
        fprintf(stderr, "Gagal memuat/membuat '%s'.\n", FILE_LOANS);
        return -1;
    }
    return 0;
}
```

Cek build lalu commit:

```bash
make clean && make     # harus selesai tanpa error
git add src/app.c
git commit -m "feat(app): app_init (impor otomatis + muat semua berkas)"
```

---
