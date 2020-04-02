// ProjetCpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include <vector>
#include "Article.h"

#include "Test.h"


//TODO
/*
Article toHTMLString print son of son
Test all classes
Calculate budget of an article
GUI / Exporter

do :
On doit pouvoir rajouter d’autre modèles de transactions dotations en demandant à
l’utilisateur d’introduire leurs attributs. Par exemple : rajouter des dotations
location des services de la ville. Dans ce cas-là l’utilisateur introduit les
paramètres suivants : année d’exercice financier, date de l’opération, date rajout,
type de service, montant. (Il est autorisé de limiter le nombre d’attributs pour
une nouvelle dotation a 4 attributs par exemple)."
*/

int main()
{
    std::cout << "Hello World!" << std::endl << std::endl;
    Test testing = Test();
    testing.doTests();
    std::cout << std::endl << "End!" << std::endl;
}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
