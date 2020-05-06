// ProjetCpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include <vector>

#include "Test.h"

#include "Article.h"
#include "Date.h"
#include "Transaction.h"
#include "EndowmentTransaction.h"
#include "ExpenseTransaction.h"
#include "Provider.h"


//TODO
/*
GUI / Exporter

do :
On doit pouvoir rajouter d’autre modèles de transactions dotations en demandant à
l’utilisateur d’introduire leurs attributs. Par exemple : rajouter des dotations
location des services de la ville. Dans ce cas-là l’utilisateur introduit les
paramètres suivants : année d’exercice financier, date de l’opération, date rajout,
type de service, montant. (Il est autorisé de limiter le nombre d’attributs pour
une nouvelle dotation a 4 attributs par exemple)."
*/

bool test() {
    Test testing = Test();
    testing.doTests();
    return true;
}

int main()
{
    std::cout << "Hello World!" << std::endl << std::endl;
    
    //test Article
    Article a1("content 1");
    Article a2("content 2", a1);
    Article a3("content 3", a2);
    Article a4("content 4");
    Article a5("content 5", {a3, a4});

    std::cout << std::endl << "~-~ Test Article ~-~" << std::endl
        << a5.toHTMLString() << std::endl;


    //test Date
    Date d1(21, 3, 1999);
    Date d2(20, 10, 2000);
    Date d3(11, 9, 2001);
    Date d4 = Date::today();

    std::cout << std::endl << "~-~ Test Date ~-~" << std::endl
        << "d1 : " << d1.toString() << std::endl
        << "d2 : " << d2.toString() << std::endl
        << "d3 : " << d3.toString() << std::endl
        << "d4 : " << d4.toString() << std::endl
        << "? d1 < d2 " << ((d1 < d2) ? "true" : "false") << std::endl
        << "? d1 == d2 " << ((d1 == d2) ? "true" : "false") << std::endl
        << "? d1 == d1 " << ((d1 == d1) ? "true" : "false") << std::endl
        << "? d3 > d2 " << ((d3 > d2) ? "true" : "false") << std::endl
        << "? d2 > d3 " << ((d2 > d3) ? "true" : "false") << std::endl;


    //test Provider
    Provider p1("Karen", "raison sociale 1", "description 1", "Cosmetique", 2000, 0);
    Provider p2("TomNook", "Besoin d'argent j'ai deux enfants", "un gros radin", "Immobilier", 2020, 100);
    Provider p3("MagohTheGreat","raison social 3", "toujours besoin de thorium, meilleur nain du serveur", "Metalurgie", 2019, 999);


    //test EndowmentTransaction
    EndowmentTransaction ent1(100, d1, a1, true);
    EndowmentTransaction ent2(200, d2, a1, false);
    EndowmentTransaction ent3(500 , d2, a2, false);


    //test ExpenseTransaction
    ExpenseTransaction ext1(100, d1, a1, p3);
    ExpenseTransaction ext2(200, d2, a1, p2);
    ExpenseTransaction ext3(500, d2, a3, p1);


    //test FundTransfer
    Transaction::fundTransfert(500, Date::today(), a5, a1);
    Transaction::fundTransfert(999, Date::today(), a1, a4);


    
    //test sum of article budget
    std::cout << std::endl << "~-~ Test Budget ~-~" << std::endl
        << "a1 : " << Transaction::getBudget(a1, false) << std::endl
        << "a2 : " << Transaction::getBudget(a2, false) << std::endl
        << "a3 : " << Transaction::getBudget(a3, false) << std::endl
        << "a4 : " << Transaction::getBudget(a4, false) << std::endl
        << "a5 : " << Transaction::getBudget(a5, false) << std::endl;
       
    
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
