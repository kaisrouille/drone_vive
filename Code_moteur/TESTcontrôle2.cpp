#include <wiringPi.h>
#include <cstdio>

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
            default:
                STOP();
                break;
            }
        }
    }

    return 0;
}
