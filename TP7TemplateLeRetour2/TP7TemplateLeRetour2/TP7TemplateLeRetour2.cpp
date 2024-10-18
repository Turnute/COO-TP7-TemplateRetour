
#include <iostream>
#include "coopointer.h"

using namespace std;

void testCoopointer();

int main()
{
    testCoopointer();

    return 0;
}


void testCoopointer()
{
    // Pointeurs alloués dynamiquement
    int* test = new int(2);
    int* test2 = new int(3);

    // Déclaration de coopointers
    coo::coopointer<int> c1;        // Par défaut
    coo::coopointer<int> c2(test);  // Par paramètre
    coo::coopointer<int> c3(c2);    // Par copie sur la même zone mémoire
    coo::coopointer<int> c4(test2); // Par paramètre sur une autre zone mémoire
    coo::coopointer<int> c5(c4);    // Par copie sur cette autre zone mémoire

    // Affichage Console
    cout << "c1 count : " << c1.count() << endl;
    cout << "c2 count : " << c2.count() << ", c2 value : " << *c2 << endl;
    cout << "c3 count : " << c3.count() << ", c3 value : " << *c3 << endl;
    cout << "c4 count : " << c4.count() << ", c4 value : " << *c4 << endl;
    cout << "c5 count : " << c5.count() << ", c5 value : " << *c5 << endl << endl;

	c2 = c3;                // Affectation de deux coopointers sur la même zone mémoire
	c1 = c2;                // Affectation de deux coopointers provenants de zones mémoires différentes
    c4 = c2;                // Affectation de deux coopointers provenants de zones mémoires différentes

	// Affichage Console
    cout << "c1 count : " << c1.count() << ", c1 value : " << *c1 << endl;
    cout << "c2 count : " << c2.count() << ", c2 value : " << *c2 << endl;
    cout << "c3 count : " << c3.count() << ", c3 value : " << *c3 << endl;
    cout << "c4 count : " << c4.count() << ", c4 value : " << *c4 << endl;
    cout << "c5 count : " << c5.count() << ", c5 value : " << *c5 << endl << endl;

    c5 = c2;               // Affectation de deux coopointers provenants de zone mémoire différente

	// Affichage Console
	cout << "c5 count : " << c5.count() << ", c5 value : " << *c5 << endl;
    cout << "test2 : " << *test2 << endl << endl;       // Vérification de la destruction du pointeur
}
