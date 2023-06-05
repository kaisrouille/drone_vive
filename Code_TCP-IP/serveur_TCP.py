import time
import socket

PORT = 3200
ADRESSE = '192.168.1.102'  #adresse du serveur (la raspberry)

socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # Creation d’une variable serveur pour gerer la communication TCP IP
socket.bind((ADRESSE, PORT))                                # mise en ecoute sur le port
socket.listen(5)
client, addressClient = socket.accept()                                   #recupere les infos du client
print ("Connexion avec le client : {} reussis.".format( addressClient ))  #affiche les infos du client auquel le serveur est connecte

while (1==1):
        
    cmd = client.recv(1)        # stock les valeurs recu dans la variable cmd
    cmd = cmd.decode('utf-8')   # decode la valeur avec le meme format qu a l'encodage

    # realise les taches selon la valeur de commande
    if (cmd == 1):
        client.send("Message recu : Le drone est a l'arret.")   # retourne au client un message personnaliser

        # emplacement des taches a realiser par le serveur (RaspBerry)
        print("STOP")
        time.sleep(1)

    elif (cmd == 2):
        client.send("Message recu : Le drone est en marche avant.")
        print("AVANT")
        time.sleep(1)

    elif (cmd == 3):
        client.send("Message recu : Le drone est en marche arriere.")
        print("ARRIERE")
        time.sleep(1)

    elif (cmd == 4):
        client.send("Message recu : Le drone tourne a gauche.")
        print("GAUCHE")
        time.sleep(1)

    elif (cmd == 5):
        client.send("Message recu : Le drone tourne a droite.")
        print("DROITE")
        time.sleep(1)

    elif (cmd == 6):
        client.send("Message recu : La connexion va etre coupee.")
        print("Fermeture de la connexion avec le client.")
        client.close()
        print("Arret du serveur.")
        socket.close()

    else:
        print("AUTRE, commande non reconnue\n")
        print(cmd)
        time.sleep(1)


   