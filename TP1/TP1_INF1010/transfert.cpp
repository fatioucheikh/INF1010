#include "transfert.h"




Transfert::Transfert():donneur_(nullptr),receveur_(nullptr) {
	montant_ = 0.0;
}

Transfert::Transfert(double montant, Utilisateur* de, Utilisateur* pour): donneur_(nullptr), receveur_(nullptr) {
	montant_ = montant;
	donneur_ = de;
	receveur_ = pour;
}

Utilisateur* Transfert::getDonneur()const{
	if (donneur_ != nullptr) {
		return donneur_;
	}
	return nullptr;
}

Utilisateur* Transfert::getReceveur()const{
	if (receveur_ != nullptr) {
		return receveur_;
	}
	return nullptr;
}

double Transfert::getMontant()const {
	return montant_;
}


void Transfert::setDonneur(Utilisateur* donneur) {
	if (donneur_ != nullptr) {
		*donneur_ = *donneur;
	}
}



void Transfert::setMontant(double montant) {
	montant_ = montant;
}
void Transfert::setReceveur(Utilisateur* receveur) {
	if (receveur_ != nullptr) {
		*receveur_ = *receveur;
	}
}




void Transfert::afficherTransfert()const{

	if (receveur_ != nullptr && donneur_ != nullptr) {
		cout << "\nTransfert: " << endl;
		cout << "\tDonneur: " << donneur_->getNom() << endl;;
		cout << "\tReceveur: " << receveur_->getNom() << endl;;
		cout << "\tMontant: " << montant_ << endl;
	}
	else {
		cout << "\tPas de transaction" << endl;
	}

}
