#Compilateur utilisé
Compilo=gcc
CFLAGS=-Wall

# Cible principale
ProjetEcolePrimaire.exe : fonctionAnnexe.o date.o eleve.o prof.o classe.o personnel.o fichier.o main.o
	$(Compilo) $(CFLAGS) -o $@ *.o


# Test unitiaire
test_unitaire_prof: test_unitaire_prof.o prof.o fonctionAnnexe.o
	$(Compilo) $(CFLAGS) -o test_unitaire_prof.exe $^


# Dépendances des tests unitaires
test_unitaire_prof.o: test_unitaire_prof.c prof.h prof.o fonctionAnnexe.o
	$(Compilo) $(CFLAGS) -c $<


# Dépendances
fonctionAnnexe.o: fonctionAnnexe.c fonctionAnnexe.h
	$(Compilo) $(CFLAGS) -c fonctionAnnexe.c

date.o : date.c date.h
	$(Compilo) $(CFLAGS) -c date.c

eleve.o : eleve.c eleve.h date.o
	$(Compilo) $(CFLAGS) -c eleve.c
    
prof.o : prof.c prof.h fonctionAnnexe.o
	$(Compilo) $(CFLAGS) -c prof.c
    
classe.o : classe.c classe.h prof.o eleve.o date.o fonctionAnnexe.o
	$(Compilo) $(CFLAGS) -c classe.c
    
personnel.o : personnel.c personnel.h
	$(Compilo) $(CFLAGS) -c personnel.c

ecole.o: ecole.c classe.h personnel.h fonctionAnnexe.o date.o eleve.o prof.o classe.o personnel.o
	$(Compilo) $(CFLAGS) -c $<
    
fichier.o : fichier.c fichier.h
	$(Compilo) $(CFLAGS) -c fichier.c

main.o: main.c fichier.h fonctionAnnexe.o date.o eleve.o prof.o classe.o ecole.o fichier.o personnel.o
	$(Compilo) $(CFLAGS) -c $<


	
# Cibles fictives
MrProper :
	echo "Suppression des *.o"
	rm -rf *.o

ResetAll :
	echo "R.A.Z"
	rm -rf *.o ProjetEcolePrimaire.exe test_unitaire_prof.exe
