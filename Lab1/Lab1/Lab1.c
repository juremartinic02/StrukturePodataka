#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//zakomentiras sa ctrl + K + C
//odkomentiras sa ctrl + K + U

/*
1. Napisati program koji prvo procita koliko redaka ima datoteka, tj.koliko ima studenata
zapisanih u datoteci.Nakon toga potrebno je dinamicki alocirati prostor za niz struktura
studenata(ime, prezime, bodovi) i ucitati iz datoteke sve zapise.Na ekran ispisati ime,
prezime, apsolutni i relativni broj bodova.
Napomena: Svaki redak datoteke sadrži ime i prezime studenta, te broj bodova na kolokviju.
relatvan_br_bodova = br_bodova / max_br_bodova * 100
*/

#define MAXSIZE (50)
#define MAXLINE (1024)

typedef struct _student{
	char name[MAXSIZE];
	char surname[MAXSIZE];
	double points;
}Student;

//no = number of rows
//inicializiraj varijable koje napises

int main() {
	int noRows = 0;

	FILE* filePointer = NULL;
	char buffer[MAXLINE] = { 0 };

	//ako se file ne nalazi u folderu ka i solution moras napisat cijeli path od txt file-a
	// r - read file,
	// w - write(ako ne nadje file stvori ga, ako ima file izbrise sve i pocne pisat),
	// a - append 

	filePointer = fopen("students.txt", "r");
	

	// ! znaci??
	// return 0 = exit success
	// return -1 = exit not successful
	if (!filePointer) {
		printf("File is not open!");
		return -1;
	}

	while (!feof(filePointer)) 
	{
		fgets(buffer, MAXLINE, filePointer);
		noRows++;
	}

	//obavezno moras zatvorit otvoreni file
	fclose(filePointer);

	printf("%d", noRows);
	return 0;
}