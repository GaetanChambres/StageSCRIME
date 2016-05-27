# StageSCRIME
   ______________________
  /                      \
 /***** Introduction *****\
/__________________________\

Objectif : externaliser les informations captées par les capteurs du Thymio

Solution -> Inscription des évènements en temps réel dans un fichier texte, qui est lu en temps réel afin de traiter chaque évènement.


   __________________________
  /                          \
 /***** Partie I - Aseba *****\
/______________________________\

Il est nécessaire d'adapter le code édité dans ASEBA STUDIO pour l'utilisation.
(lancer Aseba Studio avec la commande ~/asebastudio & lorsque Tyhmio est branché)


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
Cet évènement est nécessaire car il est nécessaire pour stoper le script de traitement. (Voir "Partie II")
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
(/!\ un fichier existant sera effacé sans demande de confirmation, pensez a sauvegardez, ou utiliser un autre nom si vous souhaitez conserver une acquisition antérieure)

2- Déclaration du tableau ("array") de taille 11; du compteur ("cpt") du nombre d'évènements traités; et de la date du dernier évènement traité ("event_time").

3- Traitement

TO FINISH!!!










