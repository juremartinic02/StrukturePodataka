//digresija profesora: "Direktiva "#define _CRT_SECURE_NO_WARNINGS" se koristi kako bi se isključila upozorenja vezana za korištenje 
// nesigurnih funkcija za rad sa stringovima i datotekama, kao što su scanf, gets, fopen, itd."
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// zakomentiras sa ctrl + K + C
//odkomentiras sa ctrl + K + U

/*
1. Napisati program koji prvo procita koliko redaka ima datoteka, tj.koliko ima studenata
zapisanih u datoteci.Nakon toga potrebno je dinamicki alocirati prostor za niz struktura
studenata(ime, prezime, bodovi) i ucitati iz datoteke sve zapise.Na ekran ispisati ime,
prezime, apsolutni i relativni broj bodova.
Napomena: Svaki redak datoteke sadrži ime i prezime studenta, te broj bodova na kolokviju.
relatvan_br_bodova = br_bodova / max_br_bodova * 100
*/

#define MAX_SIZE (50)
#define MAX_LINE (1024)
#define MAX_POINTS (50)

typedef struct _student {
    char name[MAX_SIZE];
    char surname[MAX_SIZE];
    double points;
} Student;

//no = number of
//inicializiraj sve varijable koje napises u kodu

//funckija koja sluzi za brojanje redova u file-u "students.txt"
int rowCounter(char* fileName) {
    int noRows = 0;

    //char buffer pohranjuje niz char-ova
    //u ovom slucaju on moze maksimalno primit 1024 char-a jer je to maksimalni broj znakova u jednom redu
    char buffer[MAX_LINE];

    //ako se file ne nalazi u folderu ka i solution moras napisat cijeli path od txt file-a
    // r - read file,
    // w - write(ako ne nadje file stvori ga, ako ima file izbrise sve i pocne pisat),
    // a - append

    FILE* filePointer = NULL;
    filePointer = fopen(fileName, "r");

    //!filePointer, tj. negacijom filePointera ako je datoteka neuspjesno otvorena izbacujemo poruku koju smo napisali,
    //a ako je uspjesno otvorena datoteka program nastavlja sa radom
    // return 0 = exit success
    // return -1 = exit not successful
    if (!filePointer) {
        printf("file is not open!");
        return -1;
    }
    
    while (fgets(buffer, MAX_LINE, filePointer)) {
        noRows++;
    }

    fclose(filePointer);

    printf("There is %d rows in this document (number of rows = number of students).\n", noRows);
    return noRows;
}

//funkcija koja iscitava informacije o studentima iz datotete "students.txt" i pohranjuje ih u strukturu Student
void readStudents(Student* stud, int noStud, char* fileName) {
    FILE* filePointer = NULL;
    filePointer = fopen(fileName, "r");

    if (!filePointer) {
        printf("File is not open!");
        return;
    }

    for (int i = 0; i < noStud; i++) {
        fscanf(filePointer, "%s %s %lf\n", (stud + i)->name, (stud + i)->surname, &((stud + i)->points));
    }

    fclose(filePointer);
}

//funckija koja ispisuje studente sa izracunatim postotkom(relativni broj bodova)
void printStudents(Student* stud, int noStud) {
    for (int i = 0; i < noStud; i++) {
        double average = ((stud + i)->points / MAX_POINTS) * 100;
        printf("Student %s %s scored %.2lf points, which is equal to %.2lf percentage.\n",
            (stud + i)->name, (stud + i)->surname, (stud + i)->points, average);
    }
}

int main() {

    //stvaramo pokazivac na string "students.txt" u memoriji
    char* filePointer = "students.txt";
    int noStudents = rowCounter(filePointer);

    //ako u datoteci nema studenata program se nece izvrsiti
    if (noStudents < 0) {
        return -1;
    }

    //dinamicki alociramo memoriju za studente
    Student* stud = NULL;
    stud = (Student*)malloc(noStudents * sizeof(Student));

    readStudents(stud, noStudents, filePointer);
    printStudents(stud, noStudents);

    return 0;
}
