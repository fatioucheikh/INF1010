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
		Depense** copyTabDepenses;
		copyTabDepenses = nullptr;
		copyTabDepenses = new Depense*[tailleTabDepenses_];
		for (unsigned int i = 0; i < tailleTabDepenses_; i++){
			copyTabDepenses[i] = nullptr;
		}
		for (unsigned int i = 0; i < tailleTabDepenses_; i++) {
			string nom = listeDepenses_[i]->getTitre();
			copyTabDepenses[i] = new Depense(nom, listeDepenses_[i]->getMontant());
		}

		// Suppresion de l'espace memoire
		for (unsigned int i = 0; i < tailleTabDepenses_; i++) {
			if (listeDepenses_[i] != nullptr) {
				delete listeDepenses_[i];
			}
		}
		delete[] listeDepenses_;

		tailleTabDepenses_ *= 2;
		listeDepenses_ = new Depense*[tailleTabDepenses_];
		for (unsigned int i = 0; i < tailleTabDepenses_; i++) {
			listeDepenses_[i] = nullptr;
		}

		for (unsigned int i = 0; i < nombreDepenses_; i++) {
			string nom = copyTabDepenses[i]->getTitre();
			listeDepenses_[i] = new Depense(nom, copyTabDepenses[i]->getMontant());
		}

		// Suppresion de l'espace memoire
		for (unsigned int i = 0; i < tailleTabDepenses_; i++) {
			if (copyTabDepenses[i] != nullptr) {
				delete copyTabDepenses[i];
			}
		}
		delete[] copyTabDepenses;

	}
	listeDepenses_[nombreDepenses_++] = uneDepense;
	
}

void Groupe::ajouterUtilisateur(Utilisateur* unUtilisateur) {
	//todo


	if (tailleTabUtilisateurs_ == nombreUtilisateurs_) {
		

		Utilisateur** copyListeUtilisateur;
		copyListeUtilisateur = new Utilisateur*[tailleTabUtilisateurs_];
		//unsigned int temptailleDepense = tailleTabDepense_;

		for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++) {
			copyListeUtilisateur[i] = nullptr;
		}

		for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
			string nom = listeUtilisateurs_[i]->getNom();
			unsigned int nombreDepense = listeUtilisateurs_[i]->getNombreDepense();
			unsigned int tailleTabDepense = listeUtilisateurs_[i]->getTailleTabDepense();
			double totalDepense = listeUtilisateurs_[i]->getTotal();
			
			if (listeUtilisateurs_[i]->getListeDepense() != nullptr)
					copyListeUtilisateur[i]->setListeDepense(listeUtilisateurs_[i]->getListeDepense);
			
			copyListeUtilisateur[i]->setNom(nom);
			copyListeUtilisateur[i]->setNombreDepense(nombreDepense);
			copyListeUtilisateur[i]->setTailleTabDepense(tailleTabDepense);
			copyListeUtilisateur[i]->setTotalDepense(totalDepense);

		}

		// Suppresion de l'espace memoire
		/*for (unsigned int i = 0; i < tailleTabDepense_; i++) {
			if (listeDepenses_[i] != nullptr) {
				delete listeDepenses_[i];
			}
		}
		delete[] listeDepenses_;

		tailleTabDepense_ *= 2;
		listeDepenses_ = new Depense*[tailleTabDepense_];
		for (unsigned int i = 0; i < tailleTabDepense_; i++) {
			listeDepenses_[i] = nullptr;
		}

		for (unsigned int i = 0; i < nombreDepenses_; i++) {
			string nom = copyListeDepenses[i]->getTitre();
			listeDepenses_[i] = new Depense(nom, copyListeDepenses[i]->getMontant());
		}

		// Suppresion de l'espace memoire
		for (unsigned int i = 0; i < tailleTabDepense_; i++) {
			if (copyListeDepenses[i] != nullptr) {
				delete copyListeDepenses[i];
			}
		}
		delete[] copyListeDepenses;
		*/
	}

	//listeDepenses_[nombreDepenses_++] = uneDepense;
	




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
