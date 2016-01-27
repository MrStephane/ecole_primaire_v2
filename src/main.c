#include <stdio.h>
#include <stdlib.h>

#include "fichier.h"




struct tm dateJ, rentreeScolaire;

int main(int argc, char* argv[])
{	
	Ecole_t ecole;
	
	Classe_t *ptr_classe;
	
	Eleve_t *ptr_eleve;
	
	char nom[TAILLECHAINE];
	char prenom[TAILLECHAINE];
	char nomFichier[100] = {0};
	
	char choixC;
	
	int choix = 0;
	int fin_prog = 0;
	int i;
	
	
	
	// On récupère la date du jour
	RecupererDate(&dateJ);
	// On calcule la date de rentré scolaire
	CalculRentreeScolaire(dateJ, &rentreeScolaire);
	
	InitEcole(&ecole);
	
	// Si l'utilisateur n'a pas passé le bon nombre d'arguments alors on sort du programme
	if (argc > 2)
		exit(EXIT_FAILURE);
	// Si l'utilisateur a passé un argument, alors il s'agit du nom de l'école
	else if (argc == 2)
		strcpy(ecole.nomEcole, argv[1]);
	// Si il n'y a aucun argument alors on demande le nom de l'école
	else if (argc == 1)
		SaisieChaineControle("Nom de l'ecole : ", ecole.nomEcole);
	
	// On formate le nom du fichier d'enregistrement et de lecture
	strcpy(nomFichier, ecole.nomEcole);
	strcat(nomFichier, ".csv");
	
	// Si il y a deja une base enregistré, alors on la récupère.
	lireBaseEleve(nomFichier, &ecole);
	
	do
	{
		printf("Menu :\n");
		RetourLigne(1);
		printf("1 - Ajouter un eleve.\n");
		printf("2 - Afficher un eleve.\n");
		printf("3 - Modifier un eleve.\n");
		printf("4 - Rechercher un eleve dans une classe.\n");
		printf("5 - Rechercher un eleve dans l'ecole.\n");
		printf("6 - Supprimer un eleve.\n");
		printf("7 - Afficher une classe\n");
		printf("8 - Afficher l'ecole.\n");
		printf("9 - Quitter.\n");
		RetourLigne(1);
		printf("Votre choix : ");
		scanf("%d", &choix);
		ViderBuffer();
		
		switch (choix)
		{
			case 1:
				SaisieChaineControle("Nom : ", nom);
				SaisieChaineControle("Prenom : ", prenom);
				NormaliserNomPrenom(NULL, nom, prenom);
				AjouterEleveDansEcole(&ecole, nom, prenom);
				break;
				
			case 2:
				SaisieChaineControle("Nom : ", nom);
				SaisieChaineControle("Prenom : ", prenom);
				NormaliserNomPrenom(NULL, nom, prenom);
				
				ptr_eleve = RechercherEleveDansEcole(&ecole, nom, prenom);
				
				if (ptr_eleve != NULL)
					AfficherEleve(*ptr_eleve);
				else
					printf("Cet eleve n'existe pas.\n");
				break;
				
			case 3:
				SaisieChaineControle("Nom : ", nom);
				SaisieChaineControle("Prenom : ", prenom);
				NormaliserNomPrenom(NULL, nom, prenom);
				
				ptr_eleve = RechercherEleveDansEcole(&ecole, nom, prenom);
				
				if (ptr_eleve != NULL)
					ModificationEleve(&ecole, ptr_eleve);
				break;
				
			case 4:
				// Si il n'y a pas de classe alors on ne peut pas rechercher l'élève
				if (ecole.nbClasse == 0)
				{
					printf("Il n'y a aucun eleve dans l'ecole.\n");
				}
				else
				{
					SaisieChaineControle("Nom : ", nom);
					SaisieChaineControle("Prenom : ", prenom);
					NormaliserNomPrenom(NULL, nom, prenom);
					
					printf("Dans quelle classe recherchez-vous l'eleve :\n");
					RetourLigne(1);
					AfficherListeClasse(ecole.premiereClasse);
					RetourLigne(1);
					printf("Votre choix : ");
					scanf("%d", &choix);
					ViderBuffer();
					
					// Instaurer un controle du nombre saisie
					
					ptr_classe = ecole.premiereClasse;
					for (i = 1; i < choix; ++i)
						ptr_classe = ptr_classe->suivant;
					
					ptr_eleve = RechercherEleveDansClasse(ptr_classe, nom, prenom);
					
					if (ptr_eleve != NULL)
					{
						printf("L'eleve est present dans la classe.\n");
						printf("Voulez-vous l'afficher ? (O/n) ");
						scanf("%c", &choixC);
						ViderBuffer();
						
						switch (choixC)
						{
							case 'O':
							case 'o':
								AfficherEleve(*ptr_eleve);
							// Ajouter une gestion d'erreur
						}
					}
					else
						printf("L'eleve n'est pas present dans cette classe.\n");
				}
				break;
				
			case 5:
				SaisieChaineControle("Nom : ", nom);
				SaisieChaineControle("Prenom : ", prenom);
				NormaliserNomPrenom(NULL, nom, prenom);
				
				ptr_eleve = RechercherEleveDansEcole(&ecole, nom, prenom);
				
				if (ptr_eleve != NULL)
				{
					printf("L'eleve est present dans l'ecole.\n");
					printf("Voulez-vous l'afficher ? (O/n) ");
					scanf("%c", &choixC);
					ViderBuffer();
					
					switch (choixC)
					{
						case 'O':
						case 'o':
							AfficherEleve(*ptr_eleve);
						// Ajouter la gestion d'erreur
					}
				}
				else
				{
					printf("Cet eleve n'est pas dans l'ecole.\n");
					printf("Voulez-vous l'ajouter ? (O/n) ");
					scanf("%c", &choixC);
					ViderBuffer();
					
					switch (choixC)
					{
						case 'O':
						case 'o':
							AjouterEleveDansEcole(&ecole, nom, prenom);
						// Ajouter la gestion d'erreur
					}
				}
				break;
				
			case 6:
				SaisieChaineControle("Nom : ", nom);
				SaisieChaineControle("Prenom : ", prenom);
				NormaliserNomPrenom(NULL, nom, prenom);
				SupprimerEleveDansEcole(&ecole, nom, prenom);
				break;
				
			case 7:
				printf("Quelle classe voulez-vous afficher :\n");
				RetourLigne(1);
				AfficherListeClasse(ecole.premiereClasse);
				RetourLigne(1);
				printf("Votre choix : ");
				scanf("%d", &choix);
				ViderBuffer();
				
				// Instaurer un controle du nombre saisie
				
				ptr_classe = ecole.premiereClasse;
				for (i = 1; i < choix; ++i)
					ptr_classe = ptr_classe->suivant;
				
				AfficherClasse(*ptr_classe);
				break;
				
			case 8:
				AfficherEcole(ecole);
				break;
				
			case 9:
				ecrireBaseEleve(nomFichier, ecole);
				fin_prog = 1;
				break;
				
			default:
				printf("Mauvais choix !\n");
				RetourLigne(3);
		}
	} while (!fin_prog);

	return 0;
}
