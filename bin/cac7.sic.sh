#!/bin/bash


locs=`cat /var/www/html/renic/utiles/cac2/localidades2016.txt|wc -l`
echo $locs

recs=`cat /var/www/html/renic/utiles/cac7/salida_ipc2.txt|wc -l`
echo $recs

./distlocrec.exe $locs $recs /var/www/html/renic/utiles/cac2/localidades2016.txt /var/www/html/renic/utiles/cac7/salida_ipc2.txt

cp -v  salida.txt /tmp/salida_cac7.csv

