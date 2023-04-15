# My_radar
My_radar : Airplane and detect collisions between them

In this project, i was asked to render a 2D visualization panel showing a simulatation of air traffic (AT).
The air traffic is a complex system with very strict rules to manage a large number of aircrafts.
For this first version of the simulation, you have to consider 2 types of entity:
• aircrafts,
• control towers.
The basic rules for the my_radar are as follows:
• aircrafts fly from given places to other ones.
• aircrafts appear on the simulation panel when they take off.
• aircrafts disappear from the simulation panel when they land on.
• aircrafts move in a straight line at given constant speeds.
• aircrafts colliding with another one is destroyed and disappear from the simulation panel.
• control areas allow aircrafts to collide with each other without being destroyed and they can continue
on their way.
• control towers don’t move and have control areas on the map.
• control towers appear on the simulation panel at launch.

Usage : 
./my_radar file_script

The script file contains all the information about the simulation and the entities.
Below is a example of a script file.
Aircrafts are described by:
• The letter ‘A’,
• Two integers corresponding to the departure x- and y-coordinates,
• Two integers corresponding to the arrival x- and y-coordinates,
• One integer corresponding to the aircraft’s speed (in pixels per second),
• One integer corresponding to the delay (in seconds) before the aircraft takes off.
Control towers are described by:
• The letter ‘T’,
• Two integers corresponding to the control tower x- and y-coordinates,
• One integer corresponding to the radius of the tower’s control area (corresponding to the percentage
of the greatest side of the window in pixel).
Entities are separated by a ‘\n’.
The pieces of information are separated by tabs or spaces.

∼/Rem> cat scripts/example.rdr
A 815 321 1484 166 5 0
A 1589 836 811 936 2 0
A 202 894 103 34 3 0
T 93 47 19
T 49 56 25


