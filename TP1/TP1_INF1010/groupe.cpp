#include "groupe.h"


Groupe::Groupe() : listeUtilisateurs_(nullptr), listeDepenses_(nullptr), comptes_(nullptr), listeTransferts_(nullptr) {
	
	totalDepenses_ = 0.0;
	nom_ = "unkoun";
	nombreDepenses_ = 0;
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
	nombreDepenses_ = 0;
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

	//Si l'utilisateur n'existe pa son l'ajoute au groupe
	//if (!estUnUtilisateurDuGroupe(payePar))
		//this->ajouterUtilisateur(payePar);
	
	//On ajoute une depense a l'utilisateur
	payePar->ajouterDepense(uneDepense);


	//On ajoute aussi la depense au groupe on verfie si le tableau n'est pas plein
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
		for (unsigned int i = 0; i < nombreDepenses_; i++) {
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

		for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++) {
			copyListeUtilisateur[i] = new Utilisateur;
		}

		for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
			string nom = listeUtilisateurs_[i]->getNom();
			unsigned int nombreDepense = listeUtilisateurs_[i]->getNombreDepense();
			unsigned int tailleTabDepense = listeUtilisateurs_[i]->getTailleTabDepense();
			double totalDepense = listeUtilisateurs_[i]->getTotal();
			
			if (listeUtilisateurs_[i]->getListeDepense() != nullptr) {
				for (unsigned int k = 0; k < listeUtilisateurs_[i]->getTailleTabDepense(); k++) {
					if (listeUtilisateurs_[i]->getListeDepense()[k] != nullptr)
						copyListeUtilisateur[i]->ajouterDepense(listeUtilisateurs_[i]->getListeDepense()[k]);
				}
			}
			
			if (copyListeUtilisateur[i] != nullptr) {
				copyListeUtilisateur[i]->setNom(nom);
				copyListeUtilisateur[i]->setNombreDepense(nombreDepense);
				copyListeUtilisateur[i]->setTailleTabDepense(tailleTabDepense);
				copyListeUtilisateur[i]->setTotalDepense(totalDepense);
			}

		}

		// Suppresion de l'espace memoire
		for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++) {
			if (listeUtilisateurs_[i] != nullptr) {
				for (unsigned int j = 0; j < listeUtilisateurs_[i]->getNombreDepense(); j++) {
					if (listeUtilisateurs_[i]->getListeDepense()[j] != nullptr) {
						delete listeUtilisateurs_[i]->getListeDepense()[j];
						listeUtilisateurs_[i]->getListeDepense()[j] = nullptr;
					}
					delete[] listeUtilisateurs_[i]->getListeDepense();

				}
				delete listeUtilisateurs_[i];
			}
		}
		delete[] listeUtilisateurs_;


		//On Double la liste des utilissateur
		tailleTabUtilisateurs_ *= 2;
		listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_];
		for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++) {
			listeUtilisateurs_[i] = new Utilisateur;;
		}
		

		//On fait la copie
		for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
			string nom = copyListeUtilisateur[i]->getNom();
			unsigned int nombreDepense = copyListeUtilisateur[i]->getNombreDepense();
			unsigned int tailleTabDepense = copyListeUtilisateur[i]->getTailleTabDepense();
			double totalDepense = copyListeUtilisateur[i]->getTotal();

			if (copyListeUtilisateur[i]->getListeDepense() != nullptr) {
				for (unsigned int k = 0; k < copyListeUtilisateur[i]->getTailleTabDepense(); k++) {
					if (copyListeUtilisateur[i]->getListeDepense()[k] != nullptr)
						listeUtilisateurs_[i]->ajouterDepense(copyListeUtilisateur[i]->getListeDepense()[k]);
				}
			}

			listeUtilisateurs_[i]->setNom(nom);
			listeUtilisateurs_[i]->setNombreDepense(nombreDepense);
			listeUtilisateurs_[i]->setTailleTabDepense(tailleTabDepense);
			listeUtilisateurs_[i]->setTotalDepense(totalDepense);

		}

		// Suppresion de l'espace memoire
		for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
			if (copyListeUtilisateur[i] != nullptr) {
				for (unsigned int j = 0; j < copyListeUtilisateur[i]->getNombreDepense(); j++) {
					if (copyListeUtilisateur[i]->getListeDepense()[j] != nullptr) {
						delete copyListeUtilisateur[i]->getListeDepense()[j];
					}
					delete[] copyListeUtilisateur[i]->getListeDepense();

				}
				delete copyListeUtilisateur[i];
			}
		}
		delete[] copyListeUtilisateur;
	}

	listeUtilisateurs_[nombreUtilisateurs_++] = unUtilisateur;
	

}

void Groupe::calculerTotalDepenses() {
	totalDepenses_ = 0.0;
	unsigned int nb = 0;

	for (unsigned int i = 0; i < nombreDepenses_; i++) {
		if (listeDepenses_[i] != nullptr) {
			totalDepenses_ += listeDepenses_[i]->getMontant();
			nb++;
		}
	}

	double moy = totalDepenses_ / nb;

	if (comptes_ != nullptr) {
		delete comptes_;
	}

	comptes_ = new double[nb];

	for (unsigned int i = 0; i < nb; i++) {
		if (comptes_ != nullptr && listeDepenses_[i] != nullptr) {
			comptes_[i] = listeDepenses_[i]->getMontant() - moy;
		}
	}



}




void Groupe::equilibrerComptes() {
	double rembourse = 0.0;
	listeTransferts_ = new Transfert*[nombreDepenses_];
	
	for (unsigned int i = 0; i < nombreDepenses_; i++) {
		for (unsigned int j = 0; j < nombreDepenses_; j++)
			if (comptes_[i] < 0 && comptes_[j] > 0) {
				//On calcule le minium pour verifier si le donneur a suufisament les myen pour rembouseer 
				if (abs(comptes_[i]) < abs(comptes_[j]))
					rembourse = abs(comptes_[i]);
				else
					rembourse = abs(comptes_[j]);

				listeTransferts_[nombreTrensferts_++] = new Transfert(rembourse, listeUtilisateurs_[i], listeUtilisateurs_[j]);
				//listeTransferts_[nombreTrensferts_++]->tranferer();
				comptes_[i] = +rembourse;
				comptes_[j] = -rembourse;
				
		}
	}

}


void Groupe::afficherGroupe()const {
	bool ifCompteNull = false;
	unsigned int comp = 0;
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
		if (listeUtilisateurs_[i] != nullptr) {
			listeUtilisateurs_[i]->afficherUtilisateur();
		}
	}

	for (unsigned int i = 0; i < nombreDepenses_; i++) {
		if (comptes_[i] == 0)
			comp++;
	}
	if (nombreDepenses_ == comp)
		ifCompteNull = true;

	if (!ifCompteNull) {
		cout << "\n\tComptes: " << endl;
		for (unsigned int i = 0; i < nombreDepenses_; i++) {
			cout << "|" << comptes_[i];
		}
	}

	if (ifCompteNull) {
		for (unsigned int i = 0; i < nombreTrensferts_; i++) {
			if (listeTransferts_[i] != nullptr) {
				listeTransferts_[i]->afficherTransfert();
			}
		}
	}

}





Groupe::~Groupe() {
	if (comptes_ != nullptr)
		delete comptes_;
		
	for (unsigned int i = 0; i < tailleTabDepenses_; i++) {

		if (listeDepenses_[i]!=nullptr) {
			delete listeDepenses_[i];
		}
	}
	delete[] listeDepenses_;

	for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++) {
		if (listeUtilisateurs_[i] != nullptr) {
			for (unsigned int j = 0; j < listeUtilisateurs_[i]->getTailleTabDepense(); j++) {
				if (listeUtilisateurs_[i]->getListeDepense()[j] != nullptr) {
					delete listeUtilisateurs_[i]->getListeDepense()[j];
				}
				delete[] listeUtilisateurs_[i]->getListeDepense();

			}
			delete listeUtilisateurs_[i];
		}
	}
	delete[] listeUtilisateurs_;
}
