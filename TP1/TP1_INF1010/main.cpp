
#include <iostream>
#include "groupe.h"


using namespace std;

int main(int argc, const char * argv[]) {

	///test

	string voiture = "voiture";
	string voiture1 = "voiture1";
	string voiture2 = "voiture2";

	string akimm = "akim";
	string elisee = "elise";

	Depense* maphi = new Depense(voiture, 1500.0);
	Depense* maphi1 = new Depense(voiture1, 150000000001.0 * 0);
	Depense* maphi2 = new Depense(voiture2, 1502.0);

	Utilisateur* akim  = new Utilisateur (akimm);
	Utilisateur* elise = new Utilisateur (elisee);
	akim->ajouterDepense(maphi);
	akim->ajouterDepense(maphi1);
	elise->ajouterDepense(maphi2);

	akim->afficherUtilisateur();
	elise->afficherUtilisateur();

	Transfert trans(5000.0, elise, akim);
	
	trans.setMontant(654125);
	trans.afficherTransfert();





	//// fin test



	cout << "\t \tBienvenue sur PolyCount " << endl << " *****************************************" << endl;
	// Creer un  groupe pour  6 depenses et 4 utilisateurs.



	// Creer 5 utlisateurs.


	//Creer 7 dépenses.



	//ajouter les utilisateurs au groupe


	//ajouter les depenses au groupe



	//calculer le total du grouoe et de chaque utilisateur

	//Afficher  le groupe


	//Equilibrer les comptes

	//Afficher le groupe


	//terminer le programme correctement
	system("pause");

}
