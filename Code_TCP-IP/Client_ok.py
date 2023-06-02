import socket

ADRESSE = '192.168.1.102'
PORT = 51568

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((ADRESSE, PORT))
print ("Connexion vers " + ADRESSE + ":" + str(PORT) + "reussie.")

print("1 : STOP")
print("2 : AVANT")
print("3 : ARRIERE")
print("4 : GAUCHE")
print("5 : DROITE")
while (1):
    mode=  input("choisir le mode :")
    print ("Envoi de :", mode)
    mode=mode.encode('utf-8')
    n = client.send(mode)
    if (n != len(mode)):
            print ("Erreur envoi.")
            break
    else:
            print ("Envoi ok.")

    print ("Reception...")
    #donnees = client.recv(1)
   

print ("Deconnexion.")
client.close()