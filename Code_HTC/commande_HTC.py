import pygame

pygame.init()

"""

"""

# Initialize the joystick subsystem
pygame.joystick.init()

# Check the number of connected joysticks
num_joysticks = pygame.joystick.get_count()

if num_joysticks == 0:
    print("No joystick detected.")
else:
    # Iterate over each joystick
    for i in range(num_joysticks):
        joystick = pygame.joystick.Joystick(i)
        joystick.init()

        # Check if the joystick is initialized
        if joystick.get_init():
            print(f"Joystick {i}:")
            print(f" - ID: {joystick.get_id()}")
            print(f" - Instance ID: {joystick.get_instance_id()}")
            print(f" - GUID: {joystick.get_guid()}")
            print(f" - Power Level: {joystick.get_power_level()}")
            print(f" - Name: {joystick.get_name()}")
        else:
            print(f"Joystick {i} not initialized.")

# Quit the joystick subsystem and Pygame
pygame.joystick.quit()
pygame.quit()