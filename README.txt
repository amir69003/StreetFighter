# Compilation :

Le projet se compile grâce au Makefile fourni. Pour compiler les exécutables, exécutez simplement la commande make. Les exécutables générés seront placés dans le répertoire bin/.

# Exécutables :

Le projet génère trois exécutables :

    bin/testRegression : permet de tester les fonctionnalités du noyau du jeu
    bin/streetfighterTxt : permet de jouer au jeu en mode texte
    bin/streetfighter : permet de jouer au jeu en mode graphique

# Mode d'utilisation :

Pour lancer le test de regression du noyau, exécutez bin/testRegression.

Pour jouer au jeu en mode texte, exécutez bin/streetfighterTxt.

Pour jouer au jeu en mode graphique, exécutez bin/streetfighter.

# Dépendances :

Le projet dépend des bibliothèques graphiques SDL pour le mode graphique. Avant de compiler, assurez-vous d'avoir installé la bibliothèque SDL sur votre système.

# Structure du projet :

Le projet est organisé en plusieurs fichiers source et en-têtes, qui sont répartis dans les dossiers suivants :

    src/core : contient le code source du noyau du jeu
    src/txt : contient le code source du mode texte du jeu
    src/sdl : contient le code source du mode graphique du jeu

Les fichiers executables se trouvent dans le dossier bin.
Les fichiers objets se trouvent dans le dossier obj après la compilation.
Les assets du jeux comme les images et les musiques se trouvent dans le dossier data.

# Developpeurs :

    ADAM NAJI p2108829, AMIR BENZIANE p2103270 / RÉMI FERREIRA p2107991
    Project ID: 28477