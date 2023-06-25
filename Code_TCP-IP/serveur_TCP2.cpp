#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <wiringPi.h>
#include <cstdio>

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

#define PORT 3200
#define BUFFER_SIZE 1024

// Définition des broches de commande du moteur
#define PIN_E1 23  // Broche 23 (GPIO 13)
#define PIN_E2 24  // Broche 24 (GPIO 19)
#define PIN_M1 21  // Broche 21 (GPIO 5)
#define PIN_M2 22  // Broche 22 (GPIO 6)

void STOP(void) {
  // Arrête les moteurs en mettant les sorties de la vitesse (pwm) à 100 (valeur maximale)
  pwmWrite(PIN_E1, 100);
  // Met la direction du moteur 1 en LOW (arrêt)
  digitalWrite(PIN_M1, LOW);
  // Met la sortie de la vitesse du moteur 2 à 100
  pwmWrite(PIN_E2, 100);
  // Met la direction du moteur 2 en LOW (arrêt)
  digitalWrite(PIN_M2, LOW);
}

void AVANT(int a, int b) {
  // Définit la vitesse du moteur 1 avec la valeur a
  pwmWrite(PIN_E1, a);
  // Met la direction du moteur 1 en LOW (mouvement vers l'avant)
  digitalWrite(PIN_M1, LOW);
  // Définit la vitesse du moteur 2 avec la valeur b
  pwmWrite(PIN_E2, b);
  // Met la direction du moteur 2 en HIGH (mouvement vers l'avant)
  digitalWrite(PIN_M2, HIGH);
}

void ARRIERE(int a, int b) {
  // Définit la vitesse du moteur 1 avec la valeur a
  pwmWrite(PIN_E1, a);
  // Met la direction du moteur 1 en HIGH (mouvement vers l'arrière)
  digitalWrite(PIN_M1, HIGH);
  // Définit la vitesse du moteur 2 avec la valeur b
  pwmWrite(PIN_E2, b);
  // Met la direction du moteur 2 en LOW (mouvement vers l'arrière)
  digitalWrite(PIN_M2, LOW);
}

void GAUCHE(int a, int b) {
  // Définit la vitesse du moteur 1 avec la valeur a
  pwmWrite(PIN_E1, a);
  // Met la direction du moteur 1 en HIGH (mouvement vers l'arrière)
  digitalWrite(PIN_M1, HIGH);
  // Définit la vitesse du moteur 2 avec la valeur b
  pwmWrite(PIN_E2, b);
  // Met la direction du moteur 2 en HIGH (mouvement vers l'avant)
  digitalWrite(PIN_M2, HIGH);
}

void DROITE(int a, int b) {
  // Définit la vitesse du moteur 1 avec la valeur a
  pwmWrite(PIN_E1, a);
  // Met la direction du moteur 1 en LOW (mouvement vers l'avant)
  digitalWrite(PIN_M1, LOW);
  // Définit la vitesse du moteur 2 avec la valeur b
  pwmWrite(PIN_E2, b);
  // Met la direction du moteur 2 en LOW (mouvement vers l'arrière)
  digitalWrite(PIN_M2, LOW);
}

void setup(void) {
  // Initialise la bibliothèque WiringPi
  wiringPiSetup();

  // Configuration des broches de commande du moteur
  pinMode(PIN_E1, PWM_OUTPUT);
  pinMode(PIN_E2, PWM_OUTPUT);
  pinMode(PIN_M1, OUTPUT);
  pinMode(PIN_M2, OUTPUT);

  // Configuration du mode de modulation de largeur d'impulsion (PWM)
  pwmSetMode(PWM_MODE_MS);
  // Configuration de la plage de valeurs PWM (de 0 à 100)
  // Le montage électronique suggère que 100=STOP, 0=Vmax
  pwmSetRange(100);

  // Arrêt initial des moteurs
  STOP();
}

int main() {
    // Déclaration des variables
    int serverSocket, newSocket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Configuration et initialisation
    setup();

    // Création du socket serveur
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Échec de la création du socket");
        exit(EXIT_FAILURE);
    }

    // Attachement du socket au port spécifié
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Échec de l'attachement du socket au port");
        exit(EXIT_FAILURE);
    }

    // Configuration de l'adresse du socket
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Attachement du socket au port spécifié
    if (bind(serverSocket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Échec de l'attachement du socket au port");
        exit(EXIT_FAILURE);
    }

    // Attente des connexions entrantes
    if (listen(serverSocket, 1) < 0) {
        perror("Échec de l'attente des connexions entrantes");
        exit(EXIT_FAILURE);
    }

    // Accepter la connexion entrante
    if ((newSocket = accept(serverSocket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Échec de l'acceptation de la connexion");
        exit(EXIT_FAILURE);
    }

    printf("Connexion établie.\n");

    // Boucle principale de communication
    while (1) {
        memset(buffer, 0, sizeof(buffer));

        // Réception des données du client
        valread = read(newSocket, buffer, BUFFER_SIZE);

        // Gestion des erreurs de lecture du socket
        if (valread == 0) {
            printf("Client déconnecté.\n");
            break;
        } else if (valread < 0) {
            perror("Erreur de lecture du socket");
            break;
        }

        printf("Commande reçue : %s\n", buffer);

        // Conversion de la commande en char
        char commande = buffer[0];
        printf("Commande convertie en char : %c\n", commande);

        // Traitement des commandes reçues et converties
        switch (commande) {
            case 'z':
                printf("AVANT\n");
                AVANT(10, 10);
                break;
            case 's':
                printf("ARRIERE\n");
                ARRIERE(10, 10);
                break;
            case 'q':
                printf("GAUCHE\n");
                GAUCHE(10, 10);
                break;
            case 'd':
                printf("DROITE\n");
                DROITE(10, 10);
                break;
            case 'a':
                printf("STOP\n");
                STOP();
                break;
            case 'e':
                printf("DECONNEXION\n");
                close(newSocket);
                break;
            default:
                STOP();
                break;
        }
    }

    // Fermeture des sockets
    close(newSocket);
    close(serverSocket);

    return 0;
}

