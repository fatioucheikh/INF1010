#include "depense.h"

Depense::Depense():titre_("unknow"),montant_(0.0){
}

Depense::Depense(string& titre, double montant)   {
	titre_ = titre; 
	montant_ = montant;
}

void Depense::setTitre(string& titre) {
	titre_ = titre;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}

string Depense::getTitre()const { 
	return titre_; 
};

double Depense::getMontant()const {
	return montant_;
}

void Depense::afficherDepense() const{
	cout << "\ttitre: " << titre_;;
	cout << "\tMontant: " << montant_;
}