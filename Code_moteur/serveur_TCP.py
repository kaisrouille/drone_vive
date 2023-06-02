import time
import socket

PORT = 5400
ADRESSE = ''

socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #Création d’une variable serveur pour gérer la communication TCP/IP
socket.bind((ADRESSE, PORT)) #mise en ecoute sur le port
socket.listen(5)
client, addressClient = socket.accept()
print ("{} connected".format( addressClient ))

while (1==1):
        
    reponse = client.recv(1)
    if (reponse != ""):
        cmd = reponse.decode("utf-8")

    if(cmd == '1'):
        """socket.send(u"message bien recu.")"""
        print ("STOP")
        time.sleep(1)

    elif(cmd == '2'):
        """socket.send(u"message bien recu.")"""
        print ("AVANT")
        time.sleep(1)

    elif(cmd == '3'):
        """socket.send(u"message bien recu.")"""
        print ("ARRIERE")
        time.sleep(1)

    elif(cmd == '4'):
        """socket.send(u"message bien recu.")"""
        print ("GAUCHE")
        time.sleep(1)

    elif(cmd == '0'):
        """socket.send(u"message bien recu.")"""
        print ("DROITE")
        time.sleep(1)

    else:
        print ("STOP") 
        time.sleep(1)


    print ("Fermeture de la connexion avec le client.")
    client.close()
    print ("Arret du serveur.")
    socket.close()