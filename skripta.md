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
- Rekurzivne funkcije
- Ako se koristi pre definisanja mora se prvo deklarisati

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

## Grupa 2

### 1. Pokazivači

### 2. Strukture i `typedef` operator

### 3. Unije i polja bitova

### 4. Datoteke

### 5. Liste

### 6. Stabla