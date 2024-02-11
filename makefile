EXEC_OUTPUT = bin/testRegression bin/streetfighterTxt bin/streetfighter
OBJ_FILES = 

CC = g++
CFLAGS = -g 
LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

all: $(EXEC_OUTPUT)

bin/streetfighter : obj/mainSDL.o obj/JeuSDL.o obj/Image.o obj/PartieSDL.o obj/Joueur.o obj/Ordi.o obj/Personnage.o obj/Objet.o obj/Rectangle.o obj/Vect2.o obj/Hadoken.o
	mkdir -p bin ; $(CC) -o bin/streetfighter obj/mainSDL.o obj/JeuSDL.o obj/Image.o obj/PartieSDL.o obj/Joueur.o obj/Ordi.o obj/Personnage.o obj/Objet.o obj/Rectangle.o obj/Vect2.o obj/Hadoken.o $(LIBS)

obj/mainSDL.o : src/sdl/mainSDL.cpp src/sdl/JeuSDL.h src/sdl/Image.h
	mkdir -p obj ; $(CC) $(CFLAGS) -c src/sdl/mainSDL.cpp -o obj/mainSDL.o


obj/Ordi.o : src/sdl/Ordi.cpp src/sdl/Ordi.h src/sdl/Joueur.h src/sdl/Image.h src/core/Personnage.h src/sdl/Hadoken.h
	mkdir -p obj ; $(CC) $(CFLAGS) -c src/sdl/Ordi.cpp -o obj/Ordi.o

obj/Joueur.o : src/sdl/Joueur.cpp src/sdl/Joueur.h src/sdl/Image.h src/core/Personnage.h src/sdl/Hadoken.h 
	mkdir -p obj ; $(CC) $(CFLAGS) -c src/sdl/Joueur.cpp -o obj/Joueur.o

obj/PartieSDL.o : src/sdl/PartieSDL.cpp src/sdl/PartieSDL.h src/sdl/Joueur.h src/sdl/Image.h
	mkdir -p obj ; $(CC) $(CFLAGS) -c src/sdl/PartieSDL.cpp -o obj/PartieSDL.o

obj/JeuSDL.o : src/sdl/JeuSDL.cpp src/sdl/JeuSDL.h src/sdl/Joueur.h src/sdl/Image.h
	mkdir -p obj ; $(CC) $(CFLAGS) -c src/sdl/JeuSDL.cpp -o obj/JeuSDL.o

obj/Image.o : src/sdl/Image.cpp src/sdl/Image.h
	mkdir -p obj ; $(CC) $(CFLAGS) -c src/sdl/Image.cpp -o obj/Image.o

obj/Hadoken.o : src/sdl/Hadoken.cpp src/sdl/Hadoken.h src/core/Personnage.h src/sdl/Image.h src/core/Objet.h
	mkdir -p obj ; $(CC) $(CFLAGS) -c src/sdl/Hadoken.cpp -o obj/Hadoken.o



bin/streetfighterTxt : obj/mainTxt.o obj/JeuTxt.o obj/PartieTxt.o obj/Personnage.o obj/Objet.o obj/Rectangle.o obj/Vect2.o
	mkdir -p bin ; $(CC) obj/mainTxt.o obj/JeuTxt.o obj/PartieTxt.o obj/Personnage.o obj/Objet.o obj/Rectangle.o obj/Vect2.o -o bin/streetfighterTxt

obj/mainTxt.o : src/txt/mainTxt.cpp src/txt/JeuTxt.h src/txt/PartieTxt.h src/core/Personnage.h src/core/Objet.h src/core/Rectangle.h src/core/Vect2.h
	mkdir -p obj ; $(CC) $(CFLAGS) -c src/txt/mainTxt.cpp -o obj/mainTxt.o 

obj/JeuTxt.o : src/txt/JeuTxt.cpp src/txt/JeuTxt.h src/txt/PartieTxt.h src/core/Personnage.h src/core/Objet.h src/core/Rectangle.h src/core/Vect2.h
	mkdir -p obj ; $(CC) $(CFLAGS) -c src/txt/JeuTxt.cpp -o obj/JeuTxt.o 

obj/PartieTxt.o : src/txt/PartieTxt.cpp src/txt/PartieTxt.h src/core/Personnage.h src/core/Objet.h src/core/Rectangle.h src/core/Vect2.h
	mkdir -p obj ; $(CC) $(CFLAGS) -c src/txt/PartieTxt.cpp -o obj/PartieTxt.o 




bin/testRegression : obj/mainTestRegression.o obj/Personnage.o obj/Objet.o obj/Rectangle.o obj/Vect2.o 
	mkdir -p bin ; $(CC) obj/mainTestRegression.o obj/Personnage.o obj/Objet.o obj/Rectangle.o obj/Vect2.o -o bin/testRegression

obj/mainTestRegression.o : src/core/mainTestRegression.cpp src/core/Personnage.h src/core/Objet.h src/core/Rectangle.h src/core/Vect2.h
	mkdir -p obj ; $(CC) $(CFLAGS) -c src/core/mainTestRegression.cpp -o obj/mainTestRegression.o 

obj/Personnage.o : src/core/Personnage.cpp src/core/Personnage.h src/core/Objet.h src/core/Rectangle.h src/core/Vect2.h
	mkdir -p obj ; $(CC) $(CFLAGS) -c src/core/Personnage.cpp -o obj/Personnage.o 

obj/Objet.o : src/core/Objet.cpp src/core/Objet.h src/core/Rectangle.h src/core/Vect2.h
	mkdir -p obj ; $(CC) $(CFLAGS) -c src/core/Objet.cpp -o obj/Objet.o 

obj/Rectangle.o : src/core/Rectangle.cpp src/core/Rectangle.h
	mkdir -p obj ; $(CC) $(CFLAGS) -c src/core/Rectangle.cpp -o obj/Rectangle.o

obj/Vect2.o : src/core/Vect2.cpp src/core/Vect2.h
	mkdir -p obj ; $(CC) $(CFLAGS) -c src/core/Vect2.cpp -o obj/Vect2.o 

clean : 
	rm -rf obj/* $(EXEC_OUTPUT)