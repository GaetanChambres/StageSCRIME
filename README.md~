# StageSCRIME
   ______________________
  /                      \
 /***** Introduction *****\
/__________________________\

Objectif : externaliser les informations captées par les capteurs du Thymio

Solution -> Inscription des évènements en direct dans un fichier texte, qui est lu en temps réel afin de traiter chaque évènement.


   __________________________
  /                          \
 /***** Partie I - Aseba *****\
/______________________________\

Il est nécessaire d'adapter le code édité dans ASEBA STUDIO pour l'utilisation.


Exemple, voir : "prox-event-sender.aesl"
----------------------------------------

Dans cet exemple, dès qu'un capteur de proximité horizontale est stimulé (sa valeur dépasse 100), 
on envoi un évènement grâce à la fonction "emit".
(voir commentaires code)

Chaque évènement est un évènement global qu'il faut créer manuellement dans l'interface Aseba.
(Événements globaux -> "+" -> <nom_evenement> -> identique à celui utilisé dans le code
			   -> <Nombre d'arguments -> Correspond au nombre d'arguments de l'évènement à envoyer. 
Ici c'est prox.horizontal qui donne les valeurs des capteurs de proximité, qui sont au nombre de 7; il y a donc 7 arguments.

Cet exemple est adaptable à tout code Aseba pilotant le thymio, il suffit d'ajouter des "emit" dès qu'on le souhaite, et que l'on ajuste les évènements globaux.

** /!\ ** Garder un évènement final! Ici "button.center == 1". 
Cet évènement est nécessaire pour stoper le script de traitement. (Voir "Partie II")
Conseil : de manière à le repérer, il est préférable de le placer en dernier évènement global. 
Son numéro d'évènement sera alors le nombre d'évènements différents, plus facile à identifer lors de la lecture.
(Ne pas le placer en premier car tableau initialisé à 0! <=> Si tab[nbr_event] == 0 -> stoper le prgm <=> le traitement n'aura jamais lieu.


   ________________________________
  /                                \
 /***** Partie II - Traitement *****\
/____________________________________\

Voir "loop_read.c"
------------------

Constante NBR_STOP_EVENT :: Il s'agit du nombre de l'évènement final (Voir "Partie I -- ** /!\ ** Garder un évènement final!" )
Il faut ajuster cette constante en fonction du nombre correspondant à l'évènement final.

Pour cet exemple, il y a 6 évènements globaux (1 par capteur de proximité horizontale stimulé), + l'évènement final de pression sur le boutton central ce qui donne "7".

Le reste du code est expliqué par commentaires; à savoir :

1- Ouverture des fichiers nécessaires;
Créer les fichiers passés en paramètres s'ils n'existent pas, les effacent sinon. 
(/!\ un fichier existant sera effacé sans demande de confirmation, pensez a sauvegarder, ou utiliser un autre nom si vous souhaitez conserver une acquisition antérieure)

2- Déclaration du tableau ("array") de taille 11; du compteur ("cpt") du nombre d'évènements traités; et de la date du dernier évènement traité ("event_time").

3- Traitement;
Le traitement se fait en boucle grâce au "while(array[2] != NBR_STOP_EVENT)". On quitte cette boucle à la détection de l'évènement dit final (identifié par la constante NBR_STOP_EVENT).

Le programme lit le fichier ligne par ligne, et stocke les valeurs dans le tableau. La condition de la suite du traitement ("if(array[0] != event_time)") est nécessaire pour éviter de traiter plusieurs fois le même évènement.

C'est donc à la suite de cette condition que le code de traitement que l'on souhaite appliquer doit être inséré. On utilisera les données telles qu'elles sont stockées dans le tableau.

A titre d'exemple, le reste du programme réécrit les données relatives aux évènements dans un fichier de sortie. Par gain de temps et/ou de place, on peut éventuellement commenter cette partie".

4- Fermeture des fichers, fin du programme.


   ________________________________
  /                                \
 /***** Partie III - Lancement *****\
/____________________________________\


Routine de lancement du programme
---------------------------------

1- Brancher Thymio ou bien sa clé puis l'allumer

2- Entrer la commande qui permet de se connecter en lecture au port sur lequel est connecté Thymio. Appuyer une seconde fois sur entrée pour récupérer la main dans le terminal.

~/asebaswitch "ser:name=Thymio" &

/!\ Cette commande ne sera entrée qu'une seule fois par session de travail!

3- Entrer la commande qui permet d'enregistrer les évènements générés dans un fichier texte.

~/asebarec "tcp:localhost;port=33333" > <nom_du_fichier_log> &

Puis lancer Aseba Studio et ouvrir le fichier contenant le code que l'on souhaite executer sur Thymio. (Voir l'exemple "prox-event-sender.aesl")

~/asebastudio &

fichier -> ouvrir -> <fichier_code_thymio>

4- Compiler puis lancer enfin le programme de traitement du texte. Passer en argument les noms des fichiers souhaités. S'ils n'existent pas, le programme les créera.

~/make clean
~/make
~/./loop_read <nom_du_fichier_log> <nom_du_fichier_de_sortie>

Dans asebastudio : "charger" puis "executer"

Tout devrait alors fonctionner. Thymio devrait inscrire ces évènements dans <nom_du_fichier_log> alors que le programme "loop_read"_ lit ce fichier pour traiter les données et les inscrit dans <nom_du_fichier_de_sortie>. Le programme fonctionnera jusqu'à ce que l'on active l'"évènement final" (le bouton central dans les fichiers exemples).

/!\ Pour relancer le programme a nouveau, il faut remonter à l'étape 3.








