Titre :  Projet de spécialité | Drone terrestre 

***Étudiant : Boucekine, LAVAL, ROUILLE, Pinson***

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
- Créer l’interface client serveur entre l’ordinateur et la raspberry ✅ *code client_TCP.py et serveur_TCP.py*
- Piloter le robot à distance ✅
- Optimiser les commandes de contrôle du drone (sans manette) ✅


#Equipe 2:
- Récupérer le flux vidéo de la caméra dans le HTC ❌
- Comprendre le fonctionnement de Unreal Engine ✅
- Vérifier comment le HTC communique avec l’ordinateur (application / protocol)
	- Application ✅
	- Protocol de transmission ✅
	- Protocol vidéo pris en compte ✅
- Afficher la vidéo sur le casque ❌

**SPRINT 3 :**

***Transmission et affichage :***

#Equipe 1:
- Refaire les test pour la nouvelle carte moteur ✅ *code Testcontrole2.cpp*
- Mettre en place l'électronique necessaire au fonctionnement de la carte ✅
- Refaire le code de commande ✅ *code Testcontrole2.cpp*
- Mettre en place le nouveau serveur (Python vers Cpp) ✅ *code serveur_TCP2.cpp*
- Mise en place des commandes du drone avec le HTC ❌


#Equipe 2:
- Récupérer le flux vidéo de la caméra dans le HTC ✅
- Afficher la vidéo sur le casque ✅
- Amélioration de la qualité vidéo ✅
- Amélioration la latence ✅ (au détriment de la qualité)





**Améliorations :**

- lancer le code dès le boot de la Raspberry
- contrôle avec la position des joystick du HTC
- tester les limites fonctionnel du programme(soft) et du drone(hard)



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

