cl.exe /Foauxiliary.obj /Tcauxiliary.c /c
cl.exe /FogameMovement.obj /TcgameMovement.c /c
cl.exe /FogameSetup.obj /TcgameSetup.c /c
cl.exe /Fomain.obj /Tcmain.c /c
cl.exe /FeA01_Part1.exe auxiliary.obj gameMovement.obj gameSetup.obj main.obj /link

 