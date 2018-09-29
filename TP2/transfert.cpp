/********************************************
* Titre: Travail pratique #2 - transfert.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "transfert.h"

// Constructeurs
Transfert::Transfert() : montant_(0), expediteur_(nullptr), receveur_(nullptr) {
}

Transfert::Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur) : 
	montant_(montant), expediteur_(expediteur), receveur_(receveur) {
}

// Methodes d'acces
double Transfert::getMontant() const {
	return montant_;
}

Utilisateur* Transfert::getExpediteur() const {
	return expediteur_;
}

Utilisateur* Transfert::getReceveur() const {
	return receveur_;
}

// Methodes de modifications
void Transfert::setMontant(double montant) {

	montant_= montant;
}

void Transfert::setExpediteur(Utilisateur* donneur) {


	for (unsigned int i = 0; i < expediteur_->getDepense().size(); i++) {
		if (expediteur_->getDepense()[i] != nullptr)
			delete expediteur_->getDepense()[i];
	}


	expediteur_ =new Utilisateur(*donneur);
}

void Transfert::setReceveur(Utilisateur* receveur) {

	for (unsigned int i = 0; i < receveur_->getDepense().size(); i++) {
		if (receveur_->getDepense()[i] != nullptr)
			delete receveur_->getDepense()[i];
	}


	receveur_ = new Utilisateur(*receveur);
}

//Methode affichage
void Transfert::afficherTransfert() const {
	cout<< "Transfert fait par " << expediteur_->getNom() << " vers " << receveur_->getNom() 
		<< " d'un montant de " << montant_ << endl;
}
