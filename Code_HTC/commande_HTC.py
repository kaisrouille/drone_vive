import pygame-main

pygame.init()
nbrButtons = pygame.joystick.Joystick.get_numbuttons()
nbrJoy = pygame.joystick.Joystick.get_numaxes()

print (nbrButtons)
print(nbrJoy)
