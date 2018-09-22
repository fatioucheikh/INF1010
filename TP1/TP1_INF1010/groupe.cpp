#include "groupe.h"


Groupe::Groupe() : listeUtilisateurs_(nullptr), listeDepenses_(nullptr), comptes_(nullptr), listeTransferts_(nullptr) {
	
	totalDepenses_ = 0.0;
	nom_ = "unkoun";
	nombreDepenses_ = 0.0;
	nombreUtilisateurs_ = 0; 
	tailleTabUtilisateurs_ = 5;
	tailleTabDepenses_ = 10;
	nombreTrensferts_ = 0;

	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_];
	for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++){
		listeUtilisateurs_[i] = nullptr;
	}

	listeDepenses_ = new Depense*[tailleTabDepenses_];
	for (unsigned int i = 0; i < tailleTabDepenses_; i++) {
		listeDepenses_[i] = nullptr;
	}

}

Groupe::Groupe(string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs) : listeUtilisateurs_(nullptr), listeDepenses_(nullptr), comptes_(nullptr), listeTransferts_(nullptr) {

	totalDepenses_ = 0.0;
	nom_ = nom;
	nombreDepenses_ = 0.0;
	nombreUtilisateurs_ = 0;
	tailleTabUtilisateurs_ = tailleTabUtilisateurs;
	tailleTabDepenses_ = tailleTabDepenses;
	nombreTrensferts_ = 0;

	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_];
	for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++) {
		listeUtilisateurs_[i] = nullptr;
	}

	listeDepenses_ = new Depense*[tailleTabDepenses_];
	for (unsigned int i = 0; i < tailleTabDepenses_; i++) {
		listeDepenses_[i] = nullptr;
	}
}


//methode d'acces
string Groupe::getNom()const{ return nom_; }
unsigned int Groupe::getNombreDepenses()const{ return nombreDepenses_;}
double Groupe::getTotal()const { return totalDepenses_;}

//Methodes de modification
void Groupe::setNom(string& nom) {
	nom_ = nom;
}

//fonction de verification
//pour etre sur que l'utilisateur fait partie du groupe si non on l'ajoute
bool Groupe::estUnUtilisateurDuGroupe(Utilisateur* utilisateur)const{
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
		if (listeUtilisateurs_[i] != nullptr && listeUtilisateurs_[i]->getNom() == utilisateur->getNom())
			return true;
	}
	return false;
}


//Methodes d'ajout
void Groupe::ajouterDepense(Depense* uneDepense, Utilisateur* payePar) {

	if (!estUnUtilisateurDuGroupe)
		this->ajouterUtilisateur(payePar);
	
	payePar->ajouterDepense(uneDepense);

	if (tailleTabDepenses_ == nombreDepenses_) {

		//Todo

	}
	listeDepenses_[nombreDepenses_++] = uneDepense;
	
}

void Groupe::ajouterUtilisateur(Utilisateur* unUtilisateur) {
	//todo
}



Groupe::~Groupe() {
	if (comptes_ != nullptr)
		delete comptes_;

	for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++) {
		if (listeUtilisateurs_[i] != nullptr) {
			delete listeUtilisateurs_[i];
		}
	}
	delete[] listeUtilisateurs_;
		
	for (unsigned int i = 0; i < tailleTabDepenses_; i++) {

		if (listeDepenses_[i]!=nullptr) {
			delete listeDepenses_[i];
		}
	}
	delete[] listeDepenses_;
}
