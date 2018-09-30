/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur() : nom_("") {

}

Utilisateur::Utilisateur(const string& nom)
	: nom_(nom) {
}




//Destructeur
Utilisateur::~Utilisateur() {
	for (unsigned int i = 0; i < depenses_.size(); i++) {
		if (depenses_[i] != nullptr)
			delete depenses_[i];
	}
}



// Methodes d'acces
string Utilisateur::getNom() const {
	return nom_;
}

vector<Depense*> Utilisateur::getDepense() const {

	return depenses_;
}
//
//unsigned int Utilisateur::getNombreDepense() const {
//	return nombreDepenses_;
//}

double Utilisateur::getTotalDepenses() const {
	double total = 0.0;

	for (unsigned int i = 0; i < depenses_.size(); i++) {

		total += depenses_[i]->getMontant();
	}
	return total;
}

//
Utilisateur::Utilisateur(const Utilisateur& U1) {
	nom_ = U1.getNom();


	for (unsigned int i = 0; i < U1.getDepense().size(); i++) {
		depenses_.push_back(new Depense(U1.getDepense()[i]->getNom(), U1.getDepense()[i]->getMontant(), U1.getDepense()[i]->getLieu()));
	}

}


//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}



void Utilisateur::ajouterDepense(const Depense* depense) {


	/*if (nombreDepenses_ == tailleTabDepense_) {
		tailleTabDepense_ *= 2;

		Depense** listeTemp = new Depense*[tailleTabDepense_];
		for (unsigned int i = 0; i < nombreDepenses_; i++) {
			listeTemp[i] = depenses_[i];
		}
		delete[] depenses_;

		depenses_ = listeTemp;
	}
	depenses_[nombreDepenses_++] = depense;*/

	//depenses_.push_back(new Depense(*depense));

	depenses_.push_back(new Depense(depense->getNom(), depense->getMontant(), depense->getLieu()));


}
// surcharge de  l'operateur de += 
Utilisateur& Utilisateur::operator+=(const Depense*  depense){
	 ajouterDepense(depense);
	 return *this;
}




Utilisateur& Utilisateur::operator=( const Depense* depense) {

	depenses_.clear();
	depenses_.push_back(new Depense(depense->getNom(), depense->getMontant(), depense->getLieu()));	
	
	return *this;
}






// Methode d'affichage
ostream&  operator<<(ostream &os, const Utilisateur& utilisateur) {

	os << "Utilisateur : " << utilisateur.getNom() << " a depense pour un total de : " << utilisateur.getTotalDepenses() << endl;
	cout << "\t Liste de depenses : " << endl;
	for (int i = 0; i < utilisateur.getDepense().size(); i++) {
		if (utilisateur.getDepense()[i] != nullptr)
			cout << "\t\t" << *utilisateur.getDepense()[i];

	}
	return os;
}






