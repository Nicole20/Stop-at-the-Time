Stop-at-the-Time
================

This game is a simple timing game. You would have to stop at the number of seconds randomly generated.

GLUT setup
==========

Include your GLUT files in your project properties.
C/C++ -> General -> Additional Include Directories: add the folder where the GLUT include file is located.
Linkers -> General -> Additional Lirbary Directories: add the folder where the GLUT library file is located.
Linkers -> Input -> add the following:
opengl32.lib
glu32.lib
freeglut.lib
glut32.lib
