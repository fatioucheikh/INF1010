
#ifndef TRANSFERT_H
#define TRANSFERT_H
#include "utilisateur.h"
#include <iostream>

#include <stdio.h>

class Transfert {
    public :
    
    // Constructeurs
    Transfert();
    Transfert(double montant, Utilisateur* de, Utilisateur* pour);
	~Transfert();
    
    // Méthodes d'accès
    
    Utilisateur* getDonneur()const ;
    Utilisateur* getReceveur()const ;
    double getMontant()const ;
	void tranferer(){
	/*	if (donneur_ != nullptr && receveur_ != nullptr) {
			donneur_->setTotalDepense(donneur_->getTotal() + montant_);
			receveur_->setTotalDepense(receveur_->getTotal() - montant_);
		}*/
	}
    
    
    //Méthode d'affichage
    void setDonneur(Utilisateur* donneur);
    void setMontant(double montant);
    void setReceveur(Utilisateur* receveur);
    
    void afficherTransfert()const;
    
    private :
        double montant_;
        Utilisateur* donneur_;
        Utilisateur* receveur_;
    

};
#endif
