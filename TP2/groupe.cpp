/********************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "groupe.h"

// Constructeurs
Groupe::Groupe() :	
	nom_(""),	
	nombreTransferts_(0)
{
}

Groupe::Groupe(const string& nom) :
	nom_(nom),
	nombreTransferts_(0)
{
}


Groupe::~Groupe() {
	

	for (unsigned int i = 0; i < depenses_.size(); i++) {
		if (depenses_[i] != nullptr)
			delete depenses_[i];
	}

	for (unsigned int i = 0; i < utilisateurs_.size(); i++) {
		if (utilisateurs_[i] != nullptr)
			delete utilisateurs_[i];
	}

	for (unsigned int i = 0; i < transferts_.size(); i++) {
		if (transferts_[i] != nullptr)
			delete transferts_[i];
	}

}


// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

//unsigned int Groupe::getNombreDepenses() const {
//	return nombreDepenses_;
//}

double Groupe::getTotalDepenses() const {
	double total = 0.0;
	for (unsigned int i = 0; i < depenses_.size(); i++) {
		if (depenses_[i] != nullptr)
			total += depenses_[i]->getMontant();
	}
	return total;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

bool Groupe::exiteUtilisateur(Utilisateur* u) {
	

	for (unsigned int i = 0; i < utilisateurs_.size(); i++) {
		if (utilisateurs_[i] == u)
			return true;
	}

	return false;
}


// Methodes d'ajout
void Groupe::ajouterDepense(Depense* depense, Utilisateur* utilisateur) {
	
	if (!exiteUtilisateur(utilisateur))
		utilisateurs_.push_back(utilisateur);


	for (unsigned int i = 0; i < utilisateurs_.size(); i++) {
		if (utilisateurs_[i] == utilisateur)
			depenses_[i]->setMontant(depenses_[i]->getMontant()+ depense->getMontant()); // Equivanemt a montant  = montant + new montant
	}

}



//void Groupe::calculerComptes()
//{
//	double moyenne = getTotalDepenses() / nombreUtilisateurs_;
//	for (int i = 0; i < nombreUtilisateurs_; i++) {
//		comptes_[i] = ((utilisateurs_[i]->getTotalDepenses()) - moyenne);
//	}
//}

//void Groupe::equilibrerComptes() {
//	calculerComptes();
//	bool calcul = true;
//	int count = 0;
//	while (calcul) {
//		double max = 0;
//		double min = 0;
//		int indexMax = 0;
//		int indexMin = 0;
//
//		// On cherche le compte le plus eleve et le moins eleve
//		for (int i = 0; i < nombreUtilisateurs_; i++) {
//			if (comptes_[i] > max) {
//				max = comptes_[i];
//				indexMax = i;
//			}
//			if (comptes_[i] < min) {
//				min = comptes_[i];
//				indexMin = i;
//			}
//		}
//
//		// On cherche lequel des deux a la dette la plus grande
//		if (-min <= max) {
//			transferts_[nombreTransferts_++] = new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]);
//			comptes_[indexMax] += min;
//			comptes_[indexMin] = 0;
//		}
//		else {
//			transferts_[nombreTransferts_++] = new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]);
//			comptes_[indexMax] = 0;
//			comptes_[indexMin] += max;
//		}
//
//		// On incremente le nombre de comptes mis a 0
//		count++;
//		if (-min == max) {
//			count++;
//		}
//		if (count >= nombreUtilisateurs_ - 1) {
//			calcul = false;
//		}
//	}
//}


//// Methode d'affichage
//void Groupe::afficherGroupe() const {
//	cout << "L'evenement " << nom_ << " a coute un total de " << getTotalDepenses() << " :  \n\n";
//	for (int i = 0; i < nombreUtilisateurs_; i++) {
//		//		utilisateurs_[i]->afficherUtilisateur();
//	}
//	cout << endl;
//
//	if (nombreTransferts_ != 0) {
//		cout << "Les transferts suivants ont ete realiser pour equilibrer  : " << endl;
//		for (int i = 0; i < nombreTransferts_; i++) {
//			cout << "\t";
//			transferts_[i]->afficherTransfert();
//		}
//	}
//	else {
//		cout << "Les comptes ne sont pas equilibres" << endl << endl;
//	}
//	cout << endl;
//}