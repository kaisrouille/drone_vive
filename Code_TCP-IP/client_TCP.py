import socket

ADRESSE = '192.168.1.104'       #adresse du serveur (la raspberry)
PORT = 3200             

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((ADRESSE, PORT)) #initialise la connexion avec l'adresse et le port du serveur
print ("\nConnexion vers " + ADRESSE + " : " + str(PORT) + " reussie.") #Affiche que la connexion est OK

# Menu avec les commandes disponible
print("1 : STOP")
print("2 : AVANT")
print("3 : ARRIERE")
print("4 : GAUCHE")
print("5 : DROITE")

while (1):
    mode =  input("Choisir le mode :")   # recupere la valeur du mode choisi
    print("Envoi de :", mode)            # affiche la commande envoye sur le serveur
    mode = mode.encode('utf-8')          # permet au serveur de lire la valeur envoye
    n = client.send(mode)                # envoye la valeur du client vers le serveur et recupere la valeur et verifie son format

    if (n != len(mode)):                 # verifie le format de la valeur transmise
            print ("Erreur envoi.")
            break
    else:
            print ("Envoi ok.")

    print ("Reception...")
    
    donnees = client.recv(1024)          # recupere les donnees que le serveur renvoie au client
    print(donnees)                       # affiche les donnees