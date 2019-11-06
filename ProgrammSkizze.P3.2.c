#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>


typedef struct _s
{
	int i;
	struct _s *next;
} TElement;

// TIsLessFunction vergleicht zwei TElement-Typen.
// Rueckgabe:
//	1,  wenn a < b
//  0, sonst
typedef int TIsLessFunction(const TElement*a, const TElement*b);

int meineVergleichsFunktion(const TElement*a, const TElement*b)
{
	// Die Implementierung ist im vorliegenden Fall sehr einfach, da anhang eines integers verglichen wird.
	// Der Vergleich kann aber komplizierter sein, z.b. bei Strings, bei Datumsangaben oder noch komplexeren Datentypen.
	return a->i < b->i;
}

// Diese Funktion sortiert eine Liste.
// Die Sort-FUnktion "sagt" wann ein Listenelement 'kleiner' als ein anderes ist.
// Eingabe: pListe = Zeiger auf den Anfang der Liste.
//			pSortFunc = Die Vergleichsfunktion
// Rueckgabe: ein Zeiger auf den Anfang der sortierten Liste
TElement * sort(TElement *pUnsortierteListe, TIsLessFunction *pVergleichFunc)
{
	// Das Sortieren geht so: Wir suchen in der Quell-Liste das kleinste Element, erzeugen daraus eine Neue Liste und 
	// löschen das Element aus der Quell-Liste.
	// Dann suchen wir wieder das kleinste Element fügen es vorne an die neue Liste an und löschen es aus der alten Liste,
	// so lange bis die Quell-Liste leer ist.
	// Die fertig sortierte Liste ist dann die neue Liste, die wir zurückgeben.
	TElement *pAnfangQuelle = pUnsortierteListe;
	TElement *pAnfangZiel = NULL;

	while (pAnfangQuelle != NULL)
	{
		// kleinsten suchen
		TElement *pAkt = pAnfangQuelle;
		TElement *davor = NULL;
		TElement *aktKleinster = pAkt;
		TElement *kleinsterDavor = NULL;
		while (pAkt != NULL)
		{
			if ((*pVergleichFunc)(pAkt, aktKleinster) > 0)
			{
				aktKleinster = pAkt;		// besseren gefunden
				kleinsterDavor = davor;
			}
			davor = pAkt;
			pAkt = pAkt->next;
		}

		// aus der alten Liste entfernen
		if (kleinsterDavor == NULL) pAnfangQuelle = aktKleinster->next;
		else kleinsterDavor->next = aktKleinster->next;
		
		// vorne an neue Liste anhängen.
		aktKleinster->next = pAnfangZiel;
		pAnfangZiel = aktKleinster;
	}
	return pAnfangZiel;
}


int main()
{
	TElement *pAnfang = NULL;
	for (int i = 1; i < 30; ++i)
	{
		TElement *merker = pAnfang;
		pAnfang = (TElement*)malloc(sizeof(TElement));
		pAnfang->next = merker;
		pAnfang->i = 0 * i + rand()
			;
	}
	
	TElement *pSortierteListe = sort(pAnfang, &meineVergleichsFunktion);

	TElement *pAkt = pSortierteListe;
	while (pAkt)
	{
		printf("%i\n", pAkt->i);
		pAkt = pAkt->next;
	}
}
