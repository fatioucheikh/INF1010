/********************************************
* Titre: Travail pratique #2 - depense.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>

using namespace std;

class Depense {
public:
	// Constructeurs
	// TODO: Ajouter le attribut objet dans les constructeurs
	Depense();
	Depense(const string& nom, double montant, string* lieu );
	~Depense();

	// TODO: Ajouter un constructeur par copie

	// Methodes d'acces
	string getNom() const;
	double getMontant() const;
	string* getLieu() const;
	// Methodes de modifications
	void setNom(const string& nom);
	void setMontant(double montant);

	// TODO: Ajouter une surcharge de l'operateur =
	Depense&  operator=( const Depense& depense);
	friend ostream&  operator<<(ostream &os, const Depense& depense);
	// TODO: Remplacer par une surcharge de l'operateur <<
	//void afficherDepense() const;

private:
	string nom_;
	double montant_;
	// TODO: Ajouter l'attribut lieu
	string* lieu_;
};
#endif