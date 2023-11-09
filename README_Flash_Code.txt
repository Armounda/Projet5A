Pour flasher du code sur une b oard depuis chibiStudio : 
créer une config de débug (2. create an OpenOCD debug config) ATTENTION, se placer sur le fichier NomProjet.elf dans build/obj
Ensuite, 7. OpenOCD on ST-Link, onb nous demande alors d'aller chercher le .cfg de la board. Le chemin est le suivant :
C:\ChibiStudio\tools\openocd\scripts\board/st_nucleo_f4.cfg

Plus qu'a faire flash and run et espérer :)