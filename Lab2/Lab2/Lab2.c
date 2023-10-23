/*2. definirati strukturu osoba(ime, prezime, godina rođenja) i napisati program koji :
a.dinamički dodaje novi element na početak liste,
b.ispisuje listu,
c.dinamički dodaje novi element na kraj liste,
d.pronalazi element u listi(po prezimenu),
e.briše određeni element iz liste,
u zadatku se ne smiju koristiti globalne varijable.*/#define _CRT_SECURE_NO_WARNINGS#include <stdio.h>#include <stdlib.h>#include <string.h>#include <malloc.h>#define MAX_LINE (50)#define PROGRAM_SUCCESS (0)typedef struct person* Position;typedef struct person{	char name[MAX_LINE];	char surname[MAX_LINE];	int birthyear;	Position next;} Person;void Add_Element(Position P) {

	Position q;

	q = (Position)malloc(sizeof(struct person));

	printf("\nInsert information about the person: ");
	scanf(" %s %s %d", q->name, q->surname, &q->birthyear);

	q->next = P->next;
	P->next = q;
}void PrintList(Position P) {

	if (NULL == P)
		printf("\nThe list is empty!\n");

	else {

		printf("\nList: \n");

		while (P != NULL) {

			printf("\n\t %s %s %d", P->name, P->surname, P->birthyear);
			P = P->next;

		}
	}
}Position FindLast(Position P) {

	while (NULL != P)
		P = P->next;

	return P;
}Position FindPrevious(Position P) {

	char lastnm[50] = { 0 };

	if (NULL == P->next)
		P = NULL;

	else {

		printf("Please insert persons surname: ");
		scanf(" %s", lastnm);

		while (strcmp(P->next->surname, lastnm) != 0 && P->next->next != NULL)
			P = P->next;

		while (strcmp(P->next->surname, lastnm) != 0)
			P = NULL;
	}

	return P;
}Position Find(Position P) {

	char lastnm[50] = { 0 };

	printf("\nPlease insert persons, who you want to find, surname: ");
	scanf(" %s", lastnm);

	while (P != NULL && strcmp(P->surname, lastnm) != 0)
		P = P->next;

	return P;
}

void Delete(Position P) {

	Position prev;

	prev = FindPrevious(P);

	if (NULL != prev) {

		P = prev->next;
		prev->next = P->next;

		printf("\nPerson: %s %s %d is deleted", P->name, P->surname, P->birthyear);

		free(P);
	}
	else
		printf("\nThe person do not exist in the list.");

}int main(int argc, char** argv) {

	char Lastname[MAX_LINE] = { 0 };
	struct person* q;
	int NumofFuc;

	Person head = {
		.name = { 0 },
		.surname = { 0 },
		.birthyear = 0,
		.next = NULL
	};

	printf("Please insert number of function which you what to execute: \n1.Add person\n2.Print list\n3.Add person on the end of the list\n4.Find person by lastname\n5.Delete person\nAnswear: ");
	scanf("%d", &NumofFuc);

	if (NumofFuc == 1)
		Add_Element(&head);

	else if (NumofFuc == 2)
		PrintList(&head);

	else if (NumofFuc == 3) {
		q = FindLast(&head);
		Add_Element(q);
	}

	else if (NumofFuc == 4) {
		q = Find(head.next);
		if (NULL == q)
			printf("\n The person does not exist!");
		else
			printf("\n\tPerson is: %s %s, %d", q->name, q->surname, q->birthyear);
	}

	else if (NumofFuc == 5)
		Delete(&head);

	else
		printf("\nWrong input!\n");

	return PROGRAM_SUCCESS;
}