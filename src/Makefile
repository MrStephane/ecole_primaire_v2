#Compilateur utilisé
Compilo=gcc

# Cible principale
ProjetEcolePrimaire.exe : date.o eleve.o prof.o classe.o personnel.o fichier.o
	$(Compilo) -o $@ *.o


# Dépendances
date.o : date.c date.h
	$(Compilo) -c date.c

eleve.o : eleve.c eleve.h date.o
	$(Compilo) -c eleve.c
    
prof.o : prof.c prof.h
	$(Compilo) -c prof.c
    
classe.o : classe.c classe.h prof.o eleve.o date.o
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
	rm *.o ProjetEcolePrimaire.exe
