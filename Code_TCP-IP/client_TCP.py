import socket

"""
Le programme doit etre lancee sur le PC client (MAC/Windows)

Le PC client doit etre connecte au routeur (routeur Drone) afin de communiquer avec le serveur

Le programme suivant initialise la connexion entre le cient et le serveur. Une fois la connexion reussi
le programme envoie les commandes au serveur pour controler le drone.

Avant de lancer le programme
    verifier que le serveur et le client sont connecte sur le routeur
    verifier que l adresse ip du serveur correspond bien
    verifier que le port est le meme sur les deux programme
    

"""

ADRESSE = '192.168.1.104'       #adresse du serveur (la raspberry)
PORT = 3200             

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((ADRESSE, PORT))                                                 #initialise la connexion avec l'adresse et le port du serveur
print ("\nConnexion vers " + ADRESSE + " : " + str(PORT) + " reussie.")         #Affiche que la connexion est OK

# Menu avec les commandes disponible
print("a : STOP")
print("z : AVANT")
print("s : ARRIERE")
print("q : GAUCHE")
print("d : DROITE")
print("e : DECONNEXION")

while (1):
    mode =  input("\nChoisir le mode :")        # recupere la valeur du mode choisi
    print("Envoi de :", mode)                   # affiche la commande envoye sur le serveur
    mode = mode.encode('utf-8')                 # permet au serveur de lire la valeur envoye
    n = client.send(mode)                       # envoye la valeur du client vers le serveur et recupere la valeur et verifie son format

    if (n != len(mode)):                        # verifie le format de la valeur transmise
            print ("Erreur envoi.")
            break
    else:
            print ("Envoi ok.")

    print ("Reception...")
    
    donnees = client.recv(1024)                 # recupere les donnees que le serveur renvoie au client
    print(donnees)                              # affiche les donnees