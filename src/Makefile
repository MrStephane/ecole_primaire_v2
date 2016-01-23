#Compilateur utilisé
Compilo=gcc

# Cible principale
ProjetEcolePrimaire.exe : fonctionAnnexe.o date.o eleve.o prof.o classe.o personnel.o fichier.o
	$(Compilo) -o $@ *.o


# Test unitiaire
test_unitaire_prof: test_unitaire_prof.o prof.o fonctionAnnexe.o
	$(Compilo) -o test_unitaire_prof.exe $^


# Dépendances des tests unitaires
test_unitaire_prof.o: test_unitaire_prof.c prof.h prof.o fonctionAnnexe.o
	$(Compilo) -c $<


# Dépendances
fonctionAnnexe.o: fonctionAnnexe.c fonctionAnnexe.h
	$(Compilo) -c fonctionAnnexe.c

date.o : date.c date.h
	$(Compilo) -c date.c

eleve.o : eleve.c eleve.h date.o
	$(Compilo) -c eleve.c
    
prof.o : prof.c prof.h fonctionAnnexe.o
	$(Compilo) -c prof.c
    
classe.o : classe.c classe.h prof.o eleve.o date.o fonctionAnnexe.o
	$(Compilo) -c classe.c
    
personnel.o : personnel.c personnel.h
	$(Compilo) -c personnel.c
    
fichier.o : fichier.c fichier.h
	$(Compilo) -c fichier.c


	
# Cibles fictives
MrProper :
	echo "Suppression des *.o"
	rm *.o

ResetAll :
	echo "R.A.Z"
	rm *.o ProjetEcolePrimaire.exe test_unitaire_prof.exe
