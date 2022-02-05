# SSP Skripta

## Grupa 1

### 1. Promenljive, tipovi podataka, operatori

Osnovni tipovi:
- `char`
- `int`
- `float`
- `double`

Modifikatori:
- ispred `int`:
    + `short`
    + `long`
    + `unsigned`
- ispred `char`:
    + `unsigned`
- ispred `double`:
    + `long`

#### Konstante

- celobrojne: `2`, `2000000L`
- razlomljene: `3.14`
- hex: `0xF`, `0xFF`
- oktalne: `012`
- char: `'a'`, `'\n'`, `'\xxx'` (`xxx` - octalni ASCII kod)
- string: `"ovo je text"`
- `#define PI 3.14`

#### Nabrojivi tipovi

```c
enum naziv {prvi_član[=vrednost], drugi_član[=vrednost] [, ...]};

enum meces { JAN = 1, FEB, MAR, APR, MAJ, JUN, JUL, AVG, SEP, OKT, NOV, DEC };

enum mesec tekući_mesec;

tekući_mesec = JAN;
```

#### Promenljive

```c
int a;
unsigned long int b, c;
int i = 0;
double radius = PI;
const int c = 8;
```

#### Operatori

Aritmetički:
- `+ - * / %`
- Umesto `x = x + 1` može `x += 1`
- `++x`, `x++`

Relacioni i logički:
- Ne postoji boolean
- True je >= 1
- False je < 1
- Relacioni: `< > <= >= == !=`
- Logički: `&& || !`
- Short-circuit:
    + `if (test1() && test2() && test3())`
    + ako `test2()` nije tačan `test3()` se neće ni pozvati
    + kod `||`, ako je prvi izraz tačan, drugi se neće ni pozvati

Bit:
- `& | ^ ~ &= |= ^=`
- Shift:
    + `a >> b` - pomera bitove u `a` za `b` mesta
        - ako je `a` pozitivan, ubacuje 0
        - ako je `a` negativan, ubacuje 1
    + `a << b` - pomera bitove u levo i ubacuje 0

Konverzije tipova:

```c
double d = 3.14;
int i = d;

int i = (int) 3.14 + (int) 2.6;
```

### 2. Funkcije `printf()` i `scanf()`

Biblioteka `stdio.h`

`printf` - Prvi parametar je format, ostali parametri su podaci koji se štampaju

`scanf` - Prvi parameter je format, ostali parametri adrese.

`%[indikator][širina][.preciznost][F|N|h|l|L]tip`

```c
scanf("%\d", &i);
scanf("%d %f", &i, &j); // separator je space, tab, enter
scanf("%d:%f", &i, &j); // custom separator
```

### 3. Naredbe

#### Kontrola toka

```c
if (poeni > 89)
    ocena = 5;
else if (poeni > 74)
    ocena = 4;
else if (poeni > 59)
    ocena = 3;
else if (poeni > 44)
    ocena = 2;
else ocena = 1;

// tenarni
a = (i < 10) ? i * 100 : i * 10;

// switch, izraz mora biti celobrojni
// propadanje bez `break`
// default ne mora `break`
switch (a) {
    case 1:
    case 2: i = j + 6;
            break;
    case 3: i = j + 14;
            break;
    default: i = j + 8;
}

// while, telo ne mora ni jednom da se ivrši
// izlaz kada je false
int r = 0;
while (r < 50) {
    r = random(100);
    printf("%d\n", r);
}

// do while, izvršava uvek bar jednom
int i = 0;
do {
    printf("%d\n", i++);
} while (i < 10);

// for, unapred se zna dužina
for (int i = 0; i < 10; i++)
    printf("%d\n", i);

for (i = 0, j = 1; i < 10 && j != 11; i++, j++)

// može da se ne završi
double x;
for (x = 0; x != 10; x += 0.1)

// `break` prekida i izlazi
// `continue` prekida i nastavlja sledeću iteraciju
```

### 4. Nizovi i stringovi

#### Nizovi

```c
tip ime[veličina];

int a[10];

i = a[2];
a[3] = 5;
```

Prvi indeks 0, zadnji veličina - 1

Inicijalizacija:

```c
int dani[12] = {31, 28, 31, 30, 31, 31, 30, 31, 30, 31};
```

Broj elemenata može biti manji od veličine, ostali se init na 0.

Veličina može da se izostavi ako se niz inicijalizuje.

Višedimenzionalni nizovi:

```c
float tabela[5][12];

b = tabela[1][3];
tabela[4][10] = 15.33;

int i[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};

int i[2][3][4] = {
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    },
    {
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}
    }
};
```

#### Stringovi

Nizovi karaktera, završavaju se sa `\0`, znak sa ASCII kodom 0.

```c
char ime1[] = "Mika";
char ime11[] = {'M', 'i', 'k', 'a', '\0'};

char ime2[20] = "Pera";
char ime21[20] = {'P', 'e', 'r', 'a', '\0'};
```

`scanf("%s", s)` učitava string do prvog whitespace, problem ako u rečenici ima razmaka.

`gets(s)` učitava do novog reda

Primer provera palindroma:

```c
int flag = 1;
int len = strlen(s);
for (int j = 0; j < len / 2; j++) {
    if (s[j] != s[len - 1 - j]) {
        flag = 0;
        break;
    }
}
```

### 5. Funkcije

- Sastoje se od zaglavlja i tela
- U zaglavlju modifikatori pristupa, povratni tip, ime i parametri
- Može da primi drugu funkciju kao parametar
- Prenos preko vrednosti ili referenci
    + Default po vrednosti
- Rekurzivne funkcije
- Ako se koristi pre definisanja mora se prvo deklarisati
    + Ako se ne deklariše i ne definiše, prva upotreba će se smatrati deklaracijom
- Vraćaju najviše jednu vrednost
- Ako nema parametara, stavlja se `void` ili prazne zagrade (zastarelo)
- Promenljive deklarisane unutar funkcije su vidljive samo u toj funkciji
    + Ako je `static`, onda se vidi samo unutar trenutnog fajla
- Promenljive deklarisane van funkcije vidljive i u ostalim funkcijama
    + Ako je `static`, vrednost se čuva i pri izlasku (u sledećem pozivu funkcije promenljiva ima istu vrednost kao i pre)

```c
double f(int i);

void main(void) {
    double x;
    x = f(5);
}

double f(int i) {
    return i * 2.0;
}
```

Nizovi kao parametri:

```c
void f(int a[]) { // ne navode se dimenzije, prosleđivanje po referenci
    a[3] = 5;
}

void f(int a[][10]) { // potrebno navesti najmanje n-1 dimenziju
    a[3][3] = 5;
}
```

#### Bibliotečke funkcije

- `math.h`
- `stdlib.h` - korisničke funkcije, konverzije, smeštanje podataka, ...
- `string.h`
- `ctype.h` - testiranje i konverzija karaktera
- `time.h` - rad sa datumom i vremenom
- `conio.h` - rad sa konzolom
- `bios.h` - rutine BIOS-a
- `windows.h` - Windows API

`stdio.h`:
- `fopen`/`fclose`
- `fprintf`/`fscanf`
- `printf`/`scanf`
- `putc`/`getc`
- `puts`/`gets`
- `fread`/`fwrite` - blog bajtova iz fajla

`math.h`:
- `sin cos tan`
- `asin acos atan`
- `sinh cosh tanh`
- `exp(x)`
- `log(x)`
- `log10(x)`
- `pow(x, y)`
- `sqrt`
- `ceil`
- `floor`

`stdlib.h`:
- `atof` - string u float
- `atoi` - string u int
- `atol` - string u long
- `rand`, `random`
- `malloc`, `free`
- `exit`
- `system`
- `abs`
- `qsort`
- `div`

`string.h`:
- `strcpy`
- `strncpy` - kopira n karaktera
- `strcat` - concat
- `strncat` - concat n max drugog stringa
- `strcmp`
- `strncmp` - compare n max
- `strchr` - pointer na prvo mesto zadatog slova
- `strstr` - pointer na prvu pojavu stringa
- `strlen`

`ctype.h`:
- `isalpha`
- `isdigit`
- `isalnum`
- `iscntrl`
- `islower`/`isupper`
- `isxdigit` - da li je hex

`time.h`:
- `tm` - struct za podatke o vremenu i datumu
- `time` - trenutno kalendarsko vreme
- `difftime` - razlika dva vremena u sec
- `strftime` - formatirana tekst reprezentacija

#### Modularizacija

- Program se sastoji iz više `*.c` fajlova (moduli)
- Veza između modula preko header-a `*.h`

## Grupa 2

### 1. Pokazivači

- Adresa u memoriji
- Sadržaj pokazivačke promenljive je adresa
- Pokazuju na druge promenljive ili na početak bloka
- `NULL` - ne pokazuje ni na šta
- Neinicijalizovana vrednost nema `NULL`
    + `int* p;` nije `NULL`
- Svaki niz je zapravo pokazivač na prvi element u memoriji

```c
// sabiranje
int* p;
p = p + 10;
p++;

// poređenje
int *p1, *p2;
if (p1 == p2) ...

// dodela
int a = 5;
int *p1, *p2;
p1 = &a;
p2 = p1; // pokazuju na isto

// ---

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int x = 5, y = 6;
swap(&x, &y);

// ---

int a[20];
int* pa;

pa = a; == pa = &a[0];
a + 2; == &a[2]; == pa + 2;
*(a + 3); == a[3]; == *(pa + 3);
```

#### Pokazivači na funkcije

```c
int (*ime)(params); // zagrade oko imena obavezne
(*ime)(params); // poziv
```

#### Alokacija

```c
malloc(num_bytes);
free(pointer);
```

### 2. Strukture i `typedef` operator

- Zauzima onoliko memorije koliko svi elementi zauzimaju zajedno.

```c
struct osoba {
    char ime[50];
    char adresa[100];
    int starost;
};

struct osoba osoba1, osoba2;

osoba1.starost = 15;
strcpy(osoba1.ime, "Petar Petrović");
osoba2.starost = 60;

struct osoba osoba1 = {
    "Petar Petrović",
    "Petrova Ulica 3",
    15
};

osoba2 = osoba1; // kopija

// istovremena deklarazija i definicija
struct osoba {
    char ime[50];
    char adresa[100];
    int starost;
} os;
```

#### Nizovi struktura

```c
struct osoba osobe[3];
osobe[2].ime...

struct osoba osobe[3] = {
    { "ime1", "adr1", 1 },
    { "ime2", "adr2", 2 },
    { "ime3", "adr3", 3 }
};
```

#### Pokazivači na strukturu

```c
struct osoba* pok;
pok->starost...
```

#### Hijerarhijske strukture

```c
struct datum {
    int dan;
    int mesec;
    int godina;
};

struct osoba {
    char ime[50];
    char adresa[100];
    int starost;
    struct datum datum_rodjenja;
};

// ---

struct cvor {
    int info;
    struct cvor* next;
};
```

#### Operator `typedef`

- Definicija imena novog tipa podataka, na osnovu postojećeg ili izvedenog tipa podatka

```c
typedef float real;

real a, b;

typedef char* string;
string a;

typedef struct {
    string ime;
    string adresa;
    int starost;
} osoba;

osoba a, b, *c;
```

### 3. Unije i polja bitova

#### Unije

- Slične strukturama
- Svi elementi zauzimaju isti memorijski prostor
- U jednom trenutno može da se koristi samo jedan element

```c
union union1 {
    int i;
    float f;
};

union union1 u;
u.i = 3;
// ili
u.f = 3.14;
```

```c
struct figura {
    int tip;
    float obim;

    union {
        float r;
        float p[2];
        float t[3];
    } info;
};

struct figura fig1, fig2, fig3;
fig1.tip = KRUG;
fig1.info.r = 10;
fig1.obim = fig1.info.r * 3.14;
```

#### Polja bitova

- Definisanje struktura koje imaju zadati broj bitova
- Redosled polja bitova u memoriji zavisi od implementacije

```c
struct oznaka {
    [unsigned] int ime1 : br_bitova;
    [unsigned] int ime2 : br_bitova;
};

struct char_attribute {
    unsigned int chR : 1;
    unsigned int chG : 1;
    unsigned int chB : 1;
    unsigned int intensity : 1;
    unsigned int backR : 1;
    unsigned int backG : 1;
    unsigned int backB : 1;
    unsigned int flash : 1;
};

struct char_attribute {
    unsigned int boja : 3;
    unsigned int intensity : 1;
    unsigned int pozadina : 3;
    unsigned int flash : 1;
};
```

### 4. Datoteke

- `stdio.h`
- `FILE` struktura
- datoteka se otvara, dobija se pokazivač na `FILE` strukturu, vraća `NULL` ako ne može da se otvori
- sve funkcije za rad sa datotekama primaju kao parametar i pokazivač na `FILE` strukturu
- datoteka se zatvara

```c
FILE* fopen(char* ime, char* mod);

fclose(FILE* f);
```

Modovi:
- `r` - read
- `w` - write
- `a` - append
- `b` - binarno otvaranje

Funkcije:
- `getc(FILE* f)`/`putc(char c, FILE* f)` - čitanje/pisanje jednog karaktera
    + Ako se kao rezultat dobije konstanta `EOF`, stigli smo do kraja
- `fprintf(FILE* f, ...)`/`fscanf(FILE* f, ...)` - isto kao i `printf`/`scanf`
- `fgets(char* s, int max, FILE* f)`/`fputs(char*, FILE* f)` - čitanje/pisanje jednog stringa
    + `fgets`
        - čita ili do zadate dužine ili do kraja reda
        - vraća `NULL` ako dođe do kraja fajla
        - učitani string sadrži i znak za novi red
    + `fputs`
        - snima string bez znaka za novi red
- `feof(FILE* f)` - 1 ako smo stigli do kraja fajla
    - vraća 1 na kraju tek nakon što je kraj fajla detektovan pri pokušaju čitanja
- `ferror(FILE* f)` - 1 ako je bila greška
    - `clearerr(FILE* f)` - briše status greške
- `fread(void* ptr, size_t size, size_t n, FILE* stream)` - čitanje blokova memorije
- `fwrite(const void* ptr, size_t size, size_t n, FILE* stream)` - pisanje blokova memorije

### 5. Liste

#### SLL - Singly Linked List

- Skup čvorova povezanih u jednom smeru
- Svaki čvor se stastoji od informacije koju čvor nosi, i pokazivača na sledeći čvor

```c
typedef struct node {
    char info;
    struct node* next;
} node;

node* root;
```

Stanja:
- Prazna lista - `root == NULL`
- Jedan čvor - `root -> first_element -> NULL`
- Više čvorova - `root -> first_element -> ... -> last_element -> NULL`

Dodavanje na početak

```cs
new = (node*) malloc(sizeof(node));
new->next = root;
root = new;
```

Dodavanje na kraj

```cs
new = (node*) malloc(sizeof(node));
node* curr = root;
while (curr != NULL) {
    prev = curr;
    curr = curr->next;
}
new->next = NULL;
prev->next = new;
```

Pronalaženje čvora

```cs
while (curr != NULL) {
    if (curr->info == search_info) {
        return curr;
    }

    curr = curr->next;
}
```

Brisanje čvora

```c
// ako je prvi
node* curr = root;
node* prev;
if (curr != NULL && curr.info == search_info) {
    first = curr->next;
    free(curr);
    return;
}

// nadji
while (curr != NULL && curr->info != search_info) {
    prev = curr;
    curr = curr->next;
}

if (curr == NULL) return;

prev->next = curr->next;

free(curr);
```

Brisanje liste

```c
node* curr = root;
node* tmp;
while (curr != NULL) {
    tmp = curr;
    curr = curr->next;
    free(tmp);
}
root = NULL;
```

#### Uređena lista

- Dodavanje novih čvorova tako da lista ostane uređena
    + Sadržaj novog čvora se poredi sa tekućim, i ako je manji ili jednak, dodaje se ispred tekućeg
    + Inače se pomerimo na sledeći čvor

```c
if (root == NULL || new->info < root->info) {
    new->next = root;
    root = new;
} else {
    node* curr = root;
    while (curr->next != NULL && new->info > curr->next->info) {
        curr = curr->next;
    }

    new->next = curr->next;
    curr->next = new;
}
```

### 6. Stabla

- Svaki čvor sadrži info i dva pokazivača
    + Levi pokazuje na podstablo koje se sastoji iz čvorova manjih od tekućeg
    + Desni pokazuje na podstablo koje se sastoji iz čvorova većih od tekućeg
- Postoji koren
- Čvor bez podčvorova je list
- Sortirano čuvanje elemenata
- Brza pretraga

```c
typedef struct node {
    char info;
    struct node* left;
    struct node* right;
} node;

node* root;
```

Ubacivanje u stablo

- Kreira se novi čvor
- Prođe se kroz stablo, i kada se stigne do kraja stabla, umetne se ispod njega

```c
void add(node** root, node* new) {
    if (*root == NULL) {
        *root = new;
        new->left = NULL;
        new->right = NULL;
    } else {
        if (new->info > (*root)->info) {
            add(&(*root)->right, new);
        } else {
            add(&(*root)->left, new);
        }
    }
}
```

Pronalaženje čvora

- Krene se od korena, i gleda da li je sadržaj traženog čvora manji ili veći od tekućeg
- Ako je manji ide se u levo podstablo
- Ako je veći ide se u desno podstablo
- Ako je jednak vrati se pokazivač na tekući

```c
node* search(node* root, char search_info) {
    if (root == NULL || root->info == search_info) {
        return root;
    } else if (search_info > root->info) {
        return search(root->right, search_info);
    } else {
        return search(root->left, search_info);
    }
}
```

Brisanje čvora

- Krene se od korena i gleda se da li je sadržaj traženog čvora manji ili veći od tekućeg
- Ako je manji ide se u levo podstablo
- Ako je veći ide se u desno podstablo
- Ako je jednak, briše se čvor i obavi se prevezivanje
    + Ako je čvor koji se briše list, samo se obriše, a onaj koji je pokazivao na njega se ažurira (`NULL`)
    + Ako čvor koji se briše ima samo jedan podčvor, samo se obriše, a onaj koji je pokazivao na njega preveže na podčvor
    + Ako čvor koji se briše ima oba podčvora, on se obriše, a na njegovo mesto se uveže najmanji element u njegovom podstablu
        - Najmanji element koji je uvezan umesto izbrisanog se uklanja sa originalne lokacije i radi se isto prevezivanje

```c
node* delete(node *root, char search_info) {
    // searching for the item to be deleted
    if (root == NULL) {
        return NULL;
    } if (search_info > root->info) {
        root->right = delete(root->right, search_info);
    } else if(search_info < root->info) {
        root->left = delete(root->left, search_info);
    } else {
        // no Children
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // one Child
        else if(root->left == NULL || root->right == NULL) {
            node *temp;
            if(root->left == NULL) {
                temp = root->right;
            } else {
                temp = root->left;
            }
            free(root);
            return temp;
        }
        // two Children
        else {
            node *temp = find_minimum(root->right);
            root->info = temp->info;
            root->right = delete(root->right, temp->info);
        }
    }

    return root;
}
```

Brisanje stabla

- Krene se od korena i briše se levo i desno podstablo, pa onda koren

```c
void free_tree(node* root) {
    if (root == NULL) return;

    free_tree(root->left);
    free_tree(root->right);

    free(root);
}
```
