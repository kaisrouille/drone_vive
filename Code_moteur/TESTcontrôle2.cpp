#include <wiringPi.h>
#include <cstdio>

// Définition des broches de commande du moteur
#define PIN_E1 21  // Broche 21 (GPIO 5)
#define PIN_E2 22  // Broche 22 (GPIO 6)
#define PIN_M1 23  // Broche 23 (GPIO 13)
#define PIN_M2 24  // Broche 24 (GPIO 19)

void STOP(void) {
  digitalWrite(PIN_E1, LOW);
  digitalWrite(PIN_M1, LOW);
  digitalWrite(PIN_E2, LOW);
  digitalWrite(PIN_M2, LOW);
}

void AVANT(char a, char b) {
  analogWrite(PIN_E1, a);
  digitalWrite(PIN_M1, HIGH);
  analogWrite(PIN_E2, b);
  digitalWrite(PIN_M2, HIGH);
}

void ARRIERE(char a, char b) {
  analogWrite(PIN_E1, a);
  digitalWrite(PIN_M1, LOW);
  analogWrite(PIN_E2, b);
  digitalWrite(PIN_M2, LOW);
}

void GAUCHE(char a, char b) {
  analogWrite(PIN_E1, a);
  digitalWrite(PIN_M1, LOW);
  analogWrite(PIN_E2, b);
  digitalWrite(PIN_M2, HIGH);
}

void DROITE(char a, char b) {
  analogWrite(PIN_E1, a);
  digitalWrite(PIN_M1, HIGH);
  analogWrite(PIN_E2, b);
  digitalWrite(PIN_M2, LOW);
}

void setup(void) {
  wiringPiSetup();

  // Configuration des broches de commande du moteur
  pinMode(PIN_E1, PWM_OUTPUT);
  pinMode(PIN_E2, PWM_OUTPUT);
  pinMode(PIN_M1, OUTPUT);
  pinMode(PIN_M2, OUTPUT);

  // Arrêt initial
  STOP();
}


int main(void) {
    setup();
    printf("\na : STOP");
    printf("\nz : AVANT");
    printf("\ns : ARRIERE");
    printf("\nq : GAUCHE");
    printf("\nd : DROITE");

    while (1) {
        char key;
    
        if (scanf("\n %c", &key) == 1) {
            // Logique de détermination du mouvement en fonction de la touche pressée
            switch (key) {
            case 'z':
                printf("AVANT\n");
                AVANT(255, 255);
                break;
            case 's':
                printf("ARRIERE\n");
                ARRIERE(255, 255);
                break;
            case 'q':
                printf("GAUCHE\n");
                GAUCHE(100, 100);
                break;
            case 'd':
                printf("DROITE\n");
                DROITE(100, 100);
                break;
            case 'a':
                printf("STOP\n");
                STOP();
                break;
            default:
                STOP();
                break;
            }
        }
    }

    return 0;
}
