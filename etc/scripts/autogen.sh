#!/bin/bash
info_file=$1

IFS="
"

for info_line in `cat $info_file`; do
	#echo $info_line
	c_name=`echo $info_line | cut -d',' -f1 | sed -e s/\ //g  `
	icon_name=`echo $c_name | awk '{print tolower($0)}' | sed -e s/\ //g `
	
	
	#echo " cp etc/icons/$icon_name.png etc/test/icons/countries/$c_name.png"
	mv etc/icons/$icon_name.png etc/icons/countries/$c_name.png 
	
done
