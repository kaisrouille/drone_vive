import RPi.GPIO as GPIO
import time

"""
A l'aide d'un switch case (if) le programme permet de tester les moteurs dans 
les 5 modes de rotations :
- STOP
- AVANT
- ARRIERE
- GAUCHE
- DROITE

"""

def main(args):
    
    S1pin = 32 
    S2pin = 33 

    #initialisation des GPIOs
    GPIO.setwarnings(False)
    GPIO.setmode(GPIO.BOARD)
    
    #setup des GPIO S1pin et S2pin en sortie
    GPIO.setup(S1pin,GPIO.OUT) 
    GPIO.setup(S2pin,GPIO.OUT)
    mode = 1           
    
    #initialisation du mode et de la frequence      
    pwm = GPIO.PWM(S1pin,500)  
    pwm2 = GPIO.PWM(S2pin,500) 
    
    #demarre les GPIOs
    pwm.start(0)
    pwm2.start(0)
    
    while(1):
        print("1 : STOP")
        print("2 : AVANT")
        print("3 : ARRIERE")
        print("4 : GAUCHE")
        print("5 : DROITE")
        
        mode=int (input("choisir le mode :"))
        
        #variation du rapport cyclique
        if mode==1 : 
            pwm.ChangeDutyCycle(75)
            pwm2.ChangeDutyCycle(75)
            print ("STOP\n")
        elif mode==2 : 
            pwm.ChangeDutyCycle(60)
            pwm2.ChangeDutyCycle(75)
            print ("AVANT\n")

        elif mode==3 : 
            pwm.ChangeDutyCycle(90)
            pwm2.ChangeDutyCycle(75)
            print ("ARRIERE\n")
        elif mode==4 :
            pwm.ChangeDutyCycle(75)
            pwm2.ChangeDutyCycle(60)
            print ("GAUCHE\n")    
        elif mode==5 :
            pwm.ChangeDutyCycle(75)
            pwm2.ChangeDutyCycle(90)
            print ("DROITE\n")
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
