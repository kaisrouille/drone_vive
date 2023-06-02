Titre :  Projet de spécialité | Drone terrestre 
Étudiant : Boucekine, Laval, Rouille, Pinson

**SPRINT 1 :**


***Mécanique du robot :***

#Equipe 1:
- Choisir un mode de fonctionnement de la carte de puissance ✅
	- PWM / Analogique
	- Liaison série
	- R/C

- Câblage de la carte de puissance et de la carte de contrôle ✅
- Réalisation de mesures de vitesse des moteurs

- Faire un programme permettant de faire tourner les moteurs ✅
- Modifié le programme pour faire avancer puis reculer le robot ✅ *code commande_moteur.py*
- Modifié le programme pour rajouter des séquences où le robot tourne ✅ *code commande_moteur2.py*
- Définir la meilleur façon de faire tourner le robot ✅
	- tourne sur lui même
	- virage
- Code de test pour chacun des modes moteurs (STOP, AVANCER, etc...) ✅ *code TESTcontrôle_moteur.py*

#Equipe 2:
- Vérifié le protocol qu’utilise la caméra pour transférer un flux vidéo ✅
- Établi une connexion entre l’ordinateur et la caméra ✅ (via VLC)
- Vérifier la fluidité de la vidéo transmise ✅




**SPRINT 2 :**

***Connexion et flux vidéo :***

#Equipe 1:
- Créer l’interface client serveur entre l’ordinateur et la raspberry
- Piloter le robot à distance
- Optimiser les commandes de contrôle du drone (sans manette)


#Equipe 2:
- Récupérer le flux vidéo de la caméra dans le HTC
- Vérifier comment le HTC communique avec l’ordinateur (application / protocol)
	- Application 
	- Protocol de transmission
	- Protocol vidéo pris en compte
- Afficher la vidéo sur le casque
- Améliorer la fluidité de la vidéo transmise





**SPRINT 3 :**
Connection entre la carte et le HTC (information de commande) :
Vérifié le protocol utilisé pour la transmission des informations de commande
Etablir la définition des commandes (joystick, boutons, mouvement)
Avec joystick
Avec boutons
Avec les capteurs de mouvement
Tester l’envoie des commandes avec les fonctions déjà réalisées (avancer, reculer,etc…)


**ON VERRA :**
Assemblage des fonctions :
Créer la boucle infini du démarrage du robot
Mettre toute les fonctions nécessaires (flux vidéo, commande)
Assembler le flux vidéo avec la commande et la transmission des informations
Test le programme et les limites de celui-ci
Porté
Autonomie
Capacité de déplacement (vitesse, franchissement d’obstacle, etc…)



**Liste détaillé et Niveau de difficulté :**
 - solidworks : pour faire des pièces si nécessaire   5/10
	->Conception mécanique
	->Type de moteur ?
	->Différent support (carte, caméras, batteries, câbles)
- création des cartes électroniques  3/10
	->Cartes de gestion des moteurs
	->Carte gestion des alimentations
- programmer des cartes 4/10
	->Gestion moteur 3/10
	->Gestion serveur 7/10
	->Récupération du flux vidéo 3/10
	->Gestion interface HTC Vive carte électronique ?????
- communication avec la raspberry (réseau tcp IP, ou broker MQTT)  7/10
	->Création du serveur, pour récupérer les flux vidéo
	->Envoie des commandes au robot
- contrôle de la machine (mouvement, manette, ...)  2/10
- gestion du programme du drone (batterie, moteur ...) 2/10
- Réaliser une nomenclature 1/10


**Liste matériel :**
Drone terrestre, Raspberry, Casque de VR, Caméra 360, Alimentation (batterie), Carte de puissance, Dev Carte Nucleo STM32, 


**Question :** 
Comment envoyer un flux vidéo 360 ?
Quels sont les aspects mécaniques à améliorer
Quelle type de commande pour le drone (bouton, joystick)
Affichage dans le casque (vue 180 et quand on tourne la tête on voit le reste de la vue / Vue avant et vue arrière)

**Objectif :**
Programmer une carte de contrôle permettant le pilotage du drone terrestre. Cette carte de contrôle servira aussi pour l’interconnexion entre le robot terrestre et le casque virtuel permettant le contrôle des déplacements du drone.
L’affichage du flux vidéo provenant de la caméra 360 ce ferra directement entre la caméra et le casque virtuel.


**Contrainte :** 
Robot terrestre à chenille
On change pas les moteurs et la carte de puissance
Besoins d’une carte pouvant envoyer un signal pwm à la carte puissance
Utiliser un HTC vive 

**Besoin :** 
le robot doit se déplacer à l’aide d’un HTC vive
Soit avec les joysticks
Soit avec les mouvements
Il faut récupérer le flux vidéo 360 de la caméra et l’afficher sur le HTC
Utiliser un signal PWM ou série
Le robot doit pouvoir bouger en avant et en arrière
Avoir un flux vidéo exploitable
Vérifier que la durée de la batterie est correct
Listes des tâches à réaliser :



Lien utile

https://www.youtube.com/watch?v=zpF3nPVWy_I&ab_channel=THETA360Developers
https://gist.github.com/awesomebytes/75daab3adb62b331f21ecf3a03b3ab46
https://pluginstore.theta360.com/plugins/com.theta360.vrmediaconnection/ 
https://github.com/siddharthdeore/Sabertooth-motor-driver-python
