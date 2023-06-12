**Liste des commande à réaliser dans le terminal lorsque les commits de VSCode à GitHub ne fonctionne pas :**

lavalthibault@client-172-18-83-19 ~ % cd Documents/GitHub/projet_LP_TREX/drone_vive  

lavalthibault@client-172-18-83-19 drone_vive % git branch                   
* main

lavalthibault@client-172-18-83-19 drone_vive % git pull --rebase origin main

Depuis https://github.com/kaisrouille/drone_vive
 * branch            main       -> FETCH_HEAD
Rebasage et mise à jour de refs/heads/main avec succès.

lavalthibault@client-172-18-83-19 drone_vive % 

**Commande à faire sur la RaspBerry quand le WIFI se déconnecte :**

% sudo raspi-config


**Changer l'heure sur la RaspBerry :**

$ sudo su -

root@Sesam303:~# date -s "2023-06-05 16:42:30"

lundi 5 juin 2023, 16:42:30 (UTC+0200)

root@Sesam303:~# date -s "2023-06-06 09:46:30"

mardi 6 juin 2023,09:46:30 (UTC+0200)

root@Sesam303:~# date

mardi 6 juin 2023, 09:46:33 (UTC+0200)

root@Sesam303:~#^c

root@Sesam303:-# xit

-su: xit : commande introvable 

root@Sesam303:~# exit 

déconnexion


**Envoie d'un fichier vers la RaspBerry :**

scp /Users/lavalthibault/Documents/GitHub/projet_LP_TREX/drone_vive/Code_TCP-IP/serveur_TCP.py pi@192.168.1.104:

**Connexion à la RaspBerry en SSH :**

ssh pi@192.168.1.104
