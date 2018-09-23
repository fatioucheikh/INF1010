#include "utilisateur.h"

// constructeurs par defaut et par parametre 

Utilisateur::Utilisateur():listeDepenses_(nullptr){
	nom_ = "unknown";
	tailleTabDepense_ = 5;
	nombreDepenses_ = 0;
	totalDepense_ = 0.0;

	listeDepenses_ = new Depense*[tailleTabDepense_];
	for ( unsigned int i = 0; i < tailleTabDepense_;i++) {
		listeDepenses_[i] = nullptr;
	}
}
Utilisateur::Utilisateur(string& nom): listeDepenses_(nullptr) {
	nom_ = nom;
	tailleTabDepense_ = 5;
	nombreDepenses_ = 0;
	totalDepense_ = 0.0;

	listeDepenses_ = new Depense*[tailleTabDepense_];
	for (unsigned int i = 0; i < tailleTabDepense_;i++) {
		listeDepenses_[i] = nullptr;
	}
}
// Destructeurs




// methode d'accès

string Utilisateur::getNom() const
{
	return nom_;
}

unsigned int Utilisateur::getNombreDepense() const
{
	return nombreDepenses_;
}

unsigned int Utilisateur::getTailleTabDepense()const{
	return tailleTabDepense_;
}

double Utilisateur::getTotal()const{
	return totalDepense_;
}

Depense** Utilisateur::getListeDepense()const {
	return listeDepenses_;
}

// methode de modification 
void Utilisateur::setNom(string& nom)
{
	nom_ = nom;
}

// Methode ajout de dépense
void Utilisateur::ajouterDepense(Depense* uneDepense)
{
	if (tailleTabDepense_ == nombreDepenses_){
		//int anciennetaille = tailleTabDepense_;
		//tailleTabDepense_ = tailleTabDepense_ * 2;


		Depense** copyListeDepenses;
		copyListeDepenses = new Depense*[tailleTabDepense_];
		//unsigned int temptailleDepense = tailleTabDepense_;

		for (unsigned int i = 0; i < tailleTabDepense_;i++) {
			copyListeDepenses[i] = nullptr;
		}

		for (unsigned int i = 0; i < nombreDepenses_;i++) {
			string nom = listeDepenses_[i]->getTitre();
			copyListeDepenses[i] = new Depense(nom, listeDepenses_[i]->getMontant());
		}
		
		// Suppresion de l'espace memoire
		for (unsigned int i = 0; i < tailleTabDepense_;i++) {
			if (listeDepenses_[i] != nullptr) {
				delete listeDepenses_[i];
			}
		}
		delete[] listeDepenses_;

		tailleTabDepense_ *= 2;
		listeDepenses_ = new Depense*[tailleTabDepense_];
		for (unsigned int i = 0; i < tailleTabDepense_;i++) {
			listeDepenses_[i] = nullptr;
		}

		for (unsigned int i = 0; i < nombreDepenses_;i++) {
			string nom = copyListeDepenses[i]->getTitre();
			listeDepenses_[i] = new Depense(nom,copyListeDepenses[i]->getMontant());
		}

		// Suppresion de l'espace memoire
		for (unsigned int i = 0; i < tailleTabDepense_;i++) {
			if (copyListeDepenses[i] != nullptr) {
				delete copyListeDepenses[i];
			}
		}
		delete[] copyListeDepenses;

	}

	listeDepenses_[nombreDepenses_++] = uneDepense;

}
//Methode d'affichage
void Utilisateur::afficherUtilisateur()const
{
	cout << "\nNom : " << nom_ << endl;
	cout << "\tTaille du tableau de depenses : " << tailleTabDepense_ << endl;
	cout << "\tNombre de depenses : " << nombreDepenses_ << endl;
	cout << "\tTotal de depense : " << totalDepense_ << endl;
	for (unsigned int i = 0; i < nombreDepenses_; i++)
	{

		cout << "\tDepense: " << i << endl; 
		listeDepenses_[i]->afficherDepense();
		
	}
}

Utilisateur::~Utilisateur() {
	// Suppresion de l'espace memoire
	for (unsigned int i = 0; i < tailleTabDepense_;i++) {
		if (listeDepenses_[i] != nullptr) {
			delete listeDepenses_[i];
		}
	}
	delete[] listeDepenses_;
}