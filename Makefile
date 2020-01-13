OPTIONS=-Wall `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV`
OPTIONS2=`pkg-config --libs-only-l MLV`

game:clean raport Players.o explosion.o PlanesDroite.o PlanesGauche.o Intro.o menu-jeux.o game.o  menu.o main.o
	gcc $(OPTIONS) Players.o explosion.o PlanesDroite.o PlanesGauche.o Intro.o menu-jeux.o game.o  menu.o main.o $(OPTIONS2) -o game

Players.o:Players.c Players.h
	gcc $(OPTIONS) -c $(OPTIONS2) Players.c

expolison.o:eplosion.c Planes.h
	gcc $(OPTIONS) -c $(OPTIONS2) explosion.c

PlanesDroite.o:PlanesDroite.c Planes.h
	gcc $(OPTIONS) -c $(OPTIONS2) PlanesDroite.c

PlanesGauche.o:PlanesGauche.c Planes.h
	gcc $(OPTIONS) -c $(OPTIONS2) PlanesGauche.c

Intro.o:Intro.c game.h
	gcc $(OPTIONS) -c $(OPTIONS2) Intro.c 

menu-jeux.o:menu-jeux.c game.h
	gcc $(OPTIONS) -c $(OPTIONS2) menu-jeux.c

game.o:game.c game.h
	gcc $(OPTIONS) -c $(OPTIONS2) game.c

menu.o:menu.c menu.h
	gcc $(OPTIONS) -c $(OPTIONS2) menu.c

main.o:main.c
	gcc $(OPTIONS) -c $(OPTIONS2) main.c

clean:
	rm -f *.o *.log *.aux *.out *~ game

raport:
	pdflatex Compte_rendu.tex
