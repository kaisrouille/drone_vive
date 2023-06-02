import socket

ADRESSE = '192.168.1.102'
PORT = 5400

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((ADRESSE, PORT))
print ("Connexion vers " + ADRESSE + ":" + str(PORT) + "reussie.")

print("1 : STOP")
print("2 : AVANT")
print("3 : ARRIERE")
print("4 : GAUCHE")
print("5 : DROITE")

mode=int (input("choisir le mode :"))
print ("Envoi de :", mode)
n = client.send(mode)
if (n != len(mode)):
        print ("Erreur envoi.")
else:
        print ("Envoi ok.")

print ("Reception...")
donnees = client.recv(1)
print ("Recu :", donnees)

print ("Deconnexion.")
client.close()
