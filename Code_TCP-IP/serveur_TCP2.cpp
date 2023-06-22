#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <wiringPi.h>
#include <cstdio>

#define PORT 3200
#define BUFFER_SIZE 1024

// Définition des broches de commande du moteur
#define PIN_E1 23  // Broche 23 (GPIO 13)
#define PIN_E2 24  // Broche 24 (GPIO 19)
#define PIN_M1 21  // Broche 21 (GPIO 5)
#define PIN_M2 22  // Broche 22 (GPIO 6)

void STOP(void) {
  pwmWrite(PIN_E1, 100);
  digitalWrite(PIN_M1, LOW);
  pwmWrite(PIN_E2, 100);
  digitalWrite(PIN_M2, LOW);
}

void AVANT(int a, int b) {
  pwmWrite(PIN_E1, a);
  digitalWrite(PIN_M1, LOW);
  pwmWrite(PIN_E2, b);
  digitalWrite(PIN_M2, HIGH);
}

void ARRIERE(int a, int b) {
  pwmWrite(PIN_E1, a);
  digitalWrite(PIN_M1, HIGH);
  pwmWrite(PIN_E2, b);
  digitalWrite(PIN_M2, LOW);
}

void GAUCHE(int a, int b) {
  pwmWrite(PIN_E1, a);
  digitalWrite(PIN_M1, HIGH);
  pwmWrite(PIN_E2, b);
  digitalWrite(PIN_M2, HIGH);
}

void DROITE(int a, int b) {
  pwmWrite(PIN_E1, a);
  digitalWrite(PIN_M1, LOW);
  pwmWrite(PIN_E2, b);
  digitalWrite(PIN_M2, LOW);
}

void setup(void) {
  wiringPiSetup();

  // Configuration des broches de commande du moteur
  pinMode(PIN_E1, PWM_OUTPUT);
  pinMode(PIN_E2, PWM_OUTPUT);
  pinMode(PIN_M1, OUTPUT);
  pinMode(PIN_M2, OUTPUT);

  pwmSetMode(PWM_MODE_MS);
  pwmSetRange(100);

  // Arrêt initial
  STOP();
}

int main() {
    int serverSocket, newSocket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

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

        if (valread == 0) {
            printf("Client déconnecté.\n");
            break;
        } else if (valread < 0) {
            perror("Erreur de lecture du socket");
            break;
        }

        printf("Commande reçue : %s\n", buffer);

        // Conversion de la commande en entier
        int commande = atoi(buffer);
        printf("Commande convertie en entier : %d\n", commande);

        // Traiter les commandes reçues et converties

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

    close(newSocket);
    close(serverSocket);

    return 0;
}
