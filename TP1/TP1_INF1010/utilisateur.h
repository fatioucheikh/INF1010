
#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>

#include "depense.h"

using namespace std;

class Utilisateur {
public:
	// constructeurs
	Utilisateur();
	Utilisateur(string& nom);

	//Destructeur
	~Utilisateur();

	//Methodes d'accès
	string getNom() const;
	unsigned int getNombreDepense() const;
	double getTotal()const;
	Depense** getListeDepense()const;
	unsigned int getTailleTabDepense()const;

	//Methode de modification
	void setNom(string& nom);
	void setListeDepense(Depense** depense) {
		listeDepenses_ = depense;
	}
	void setTailleTabDepense(unsigned int taille) {
		tailleTabDepense_ = taille;
	}

	void setNombreDepense(unsigned int nbDepense) {
		nombreDepenses_ = nbDepense;
	}

	void setTotalDepense(double total) {
		totalDepense_ = total;
	}
    
    // Methode ajout de dépense
    void ajouterDepense(Depense* uneDepense);
    
    //Methode de calcul total
    void calculerTotal();
    
    //Methode d'affichage
    void afficherUtilisateur() const;
    
    private :
        string nom_;
        unsigned int tailleTabDepense_;
        unsigned int nombreDepenses_;
        double totalDepense_;
        Depense ** listeDepenses_;
    
    
};
#endif /* utilisateur_hpp */
