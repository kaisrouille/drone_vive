import time
import socket
import RPi.GPIO as GPIO

"""
Le programme doit etre lancee sur la Raspberry (Sesam505)

Le PC client doit etre connecte au routeur (routeur Drone) afin de communiquer avec le serveur

Le programme suivant initialise le serveur et reprend les commande de controle des moteurs
afin de les utiliser a distance. Le switch case a lieu du cote du client et le serveur recupere 
seulement la valeur du mode choisi.

Avant de lancer le programme
    verifier que le serveur et le client sont connecte sur le routeur
    verifier que l adresse ip du serveur correspond bien
    

"""

S1pin = 32 
S2pin = 33 

#initialisation des GPIOs
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)

#setup des GPIO S1pin et S2pin en sortie
GPIO.setup(S1pin,GPIO.OUT) 
GPIO.setup(S2pin,GPIO.OUT)
mode = 1

#initialisation du mode et de la frequence      
pwm = GPIO.PWM(S1pin,500)  
pwm2 = GPIO.PWM(S2pin,500) 

#demarre les GPIOs
pwm.start(0)
pwm2.start(0)

PORT = 3200
ADRESSE = '192.168.1.102'  #adresse du serveur (la raspberry)

compteurVitesseAV = 0
compteurVitesseAR = 0

print("En attente de connexion, veuillez lancer le client...")

socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # Creation dune variable serveur pour gerer la communication TCP IP
socket.bind((ADRESSE, PORT))                                # mise en ecoute sur le port
socket.listen(5)
client, addressClient = socket.accept()                                   #recupere les infos du client
print ("Connexion avec le client : {} reussis.".format( addressClient ))  #affiche les infos du client auquel le serveur est connecte

while (1==1):
        
    cmd = client.recv(1024)        # stock les valeurs recu dans la variable cmd
    cmd = cmd.decode('utf-8')      # decode la valeur avec le meme format qu a lencodage

    # realise les taches selon la valeur de commande
    #MODE STOP
    if (cmd == '1'):
        client.send("Message recu : Le drone est a l'arret.")   # retourne au client un message personnaliser

        # emplacement des taches a realiser par le serveur (RaspBerry)
        pwm.ChangeDutyCycle(75)
        pwm2.ChangeDutyCycle(75)
        print("STOP")
        compteurVitesseAR = 0
        compteurVitesseAV = 0
        time.sleep(1)

    # MODE AVANT
    elif (cmd == '2' and compteurVitesseAV==0):
        client.send("Message recu : Le drone est en marche avant.")
        pwm.ChangeDutyCycle(60)
        pwm2.ChangeDutyCycle(75)
        print("AVANT V1")
        compteurVitesseAV = 1
        compteurVitesseAR = 0
        time.sleep(1)
    
    elif (cmd == '2' and compteurVitesseAV==1):
        client.send("Message recu : Le drone est en marche avant.")
        pwm.ChangeDutyCycle(50)
        pwm2.ChangeDutyCycle(75)
        print("AVANT V2")
        compteurVitesseAV = 0
        time.sleep(1)

    #MODE ARRIERE
    elif (cmd == '3' and compteurVitesseAR==0):
        client.send("Message recu : Le drone est en marche arriere.")
        pwm.ChangeDutyCycle(90)
        pwm2.ChangeDutyCycle(75)
        print("ARRIERE V1")
        compteurVitesseAR = 1
        compteurVitesseAV = 0
        time.sleep(1)
        
    elif (cmd == '3' and compteurVitesseAR==1):
        client.send("Message recu : Le drone est en marche arriere.")
        pwm.ChangeDutyCycle(100)
        pwm2.ChangeDutyCycle(75)
        print("ARRIERE V2")
        compteurVitesseAR = 0
        time.sleep(1)    

    #MODE GAUCHE
    elif (cmd == '4'):
        client.send("Message recu : Le drone tourne a gauche.")
        pwm.ChangeDutyCycle(75)
        pwm2.ChangeDutyCycle(60)
        print("GAUCHE")
        compteurVitesseAR = 0
        compteurVitesseAV = 0
        time.sleep(1)

    #MODE DROITE
    elif (cmd == '5'):
        client.send("Message recu : Le drone tourne a droite.")
        pwm.ChangeDutyCycle(75)
        pwm2.ChangeDutyCycle(90)
        print("DROITE")
        compteurVitesseAR = 0
        compteurVitesseAV = 0
        time.sleep(1)

    #DECONNEXION
    elif (cmd == '6'):
        client.send("Message recu : La connexion va etre coupee.")
        pwm.ChangeDutyCycle(75)
        pwm2.ChangeDutyCycle(75)
        print("Fermeture de la connexion avec le client.")
        client.close()
        print("Arret du serveur.")
        socket.close()

    else:
        client.send("Message recu : La commande n est pas reconnue.")
        print("AUTRE, commande non reconnue\n")
        print(cmd)
        time.sleep(1)


   