#!/bin/bash


locs=`cat /var/www/html/renic/utiles/cac2/localidades2016.txt|wc -l`


recs=`cat /var/www/html/renic/utiles/cac7/salida_ipc2.txt|wc -l`


./distlocrec.exe $locs $recs /var/www/html/renic/utiles/cac2/localidades2016.txt /var/www/html/renic/utiles/cac7/salida_ipc2.txt 

