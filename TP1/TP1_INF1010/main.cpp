
#include <iostream>
#include "groupe.h"


using namespace std;

int main(int argc, const char * argv[]) {

	///test

	/*string voiture = "voiture";
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

	Groupe* Gr1 = new Groupe();

	Gr1->ajouterDepense(maphi1,akim);
	Gr1->ajouterDepense(maphi1, akim);
	Gr1->ajouterUtilisateur(elise);*/





	//// fin test



	cout << "\t \tBienvenue sur PolyCount " << endl << " *****************************************" << endl;
	// Creer un  groupe pour  6 depenses et 4 utilisateurs.
	string nomGroupe = "INF1010";
	Groupe* monGroupe = new Groupe (nomGroupe,6,4);


	// Creer 5 utlisateurs.
	string nomUtilisateur1 = "nomUtilisateur1";
	string nomUtilisateur2 = "nomUtilisateur2";
	string nomUtilisateur3 = "nomUtilisateur3";
	string nomUtilisateur4 = "nomUtilisateur4";
	string nomUtilisateur5 = "nomUtilisateur5";

	Utilisateur* utilisateur1 = new Utilisateur(nomUtilisateur1);
	Utilisateur* utilisateur2 = new Utilisateur(nomUtilisateur2);
	Utilisateur* utilisateur3 = new Utilisateur(nomUtilisateur3);
	Utilisateur* utilisateur4 = new Utilisateur(nomUtilisateur4);
	Utilisateur* utilisateur5 = new Utilisateur(nomUtilisateur5);
	
	

	//Creer 7 dépenses.
	string nomDepense1 = "nomDepense1";
	string nomDepense2 = "nomDepense2";
	string nomDepense3 = "nomDepense3";
	string nomDepense4 = "nomDepense4";
	string nomDepense5 = "nomDepense5";
	string nomDepense6 = "nomDepense6";
	string nomDepense7 = "nomDepense7";

	Depense* depense1 = new Depense(nomDepense1,100.0);
	Depense* depense2 = new Depense(nomDepense2,200.0);
	Depense* depense3 = new Depense(nomDepense3,300.0);
	Depense* depense4 = new Depense(nomDepense4,400.0);
	Depense* depense5 = new Depense(nomDepense5,500.0);
	Depense* depense6 = new Depense(nomDepense1,600.0);
	Depense* depense7 = new Depense(nomDepense1,700.0);
	
	


	//ajouter les utilisateurs au groupe
	monGroupe->ajouterUtilisateur(utilisateur1);
	monGroupe->ajouterUtilisateur(utilisateur2);
	monGroupe->ajouterUtilisateur(utilisateur3);
	monGroupe->ajouterUtilisateur(utilisateur4);
	monGroupe->ajouterUtilisateur(utilisateur5);
	
	//Afficher les depenses
	monGroupe->afficherGroupe();

	//ajouter les depenses au groupe
	monGroupe->ajouterDepense(depense1, utilisateur1);
	monGroupe->ajouterDepense(depense2, utilisateur2);
	monGroupe->ajouterDepense(depense3, utilisateur3);
	monGroupe->ajouterDepense(depense4, utilisateur4);
	monGroupe->ajouterDepense(depense5, utilisateur5);
	monGroupe->ajouterDepense(depense6, utilisateur5);
	monGroupe->ajouterDepense(depense7, utilisateur5);

	


	//calculer le total du grouoe et de chaque utilisateur
	monGroupe->calculerTotalDepenses();
	double totalDepenses = monGroupe->getTotal();

	//Afficher  le groupe
	monGroupe->afficherGroupe();

	//Equilibrer les comptes
	monGroupe->equilibrerComptes();

	//Afficher le groupe
	monGroupe->afficherGroupe();

	//terminer le programme correctement
/*	delete utilisateur1 ;
	delete utilisateur2 ;
	delete utilisateur3 ;
	delete utilisateur4 ;
	delete utilisateur5 ;
	utilisateur1 = nullptr;
	utilisateur2 = nullptr;
	utilisateur3 = nullptr;
	//utilisateur4 = nullptr;
	//utilisateur5 = nullptr;

	delete depense1;
	delete depense2;
	delete depense3;
	delete depense4;
	delete depense5;
	delete depense6;
	delete depense7;
	depense1 = nullptr;
	depense2 = nullptr;
    depense3 = nullptr;
	depense4 = nullptr;
	depense5 = nullptr;
	depense6 = nullptr;
	depense7 = nullptr;
	*/

	system("pause");


}
