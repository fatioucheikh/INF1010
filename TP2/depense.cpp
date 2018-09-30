/********************************************
* Titre: Travail pratique #2 - depense.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "depense.h"

// Constucteurs
Depense::Depense() : nom_("inconnu"), montant_(0.0) {
	lieu_ = new string("inconnu");

}

Depense::Depense(const string& nom, double montant, string* lieu) : nom_(nom), montant_(montant) {
	lieu_ = new string(*lieu);
}

// destructeur 
Depense::~Depense() {
	if (lieu_ != nullptr)
		delete lieu_;
}
// Methodes d'acces
string Depense::getNom() const {
	return nom_;
}

double Depense::getMontant() const {
	return montant_;
}

string* Depense::getLieu() const {
	return lieu_;
}
// Methodes de modifications
void Depense::setNom(const string& nom) {
	nom_ = nom;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}

Depense& Depense::operator=(const Depense& depense) {
	nom_ = depense.getNom();
	montant_ = depense.getMontant();

	if (lieu_ != nullptr)
		delete lieu_;
	lieu_ = new string(*(depense.getLieu()));
	return *this;
}


ostream& operator<<(ostream &os, const Depense& depense) {

	os << "Achat : " << depense.getNom() << " Prix : " << depense.getMontant() << "; " << endl;
	return os;
}
// Methode d'affichage
//void Depense::afficherDepense() const {
//	cout << "Achat : " << nom_ << " Prix : " << montant_ << "; " << endl;
//