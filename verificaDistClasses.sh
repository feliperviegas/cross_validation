#!/bin/sh

#  verificaDistClasses.sh
#  
#
#  Created by Felipe Viegas on 16/04/13.
#

rm distClasses.dat
for i in `seq 0 1 9`
do
    echo $i >> distClasses;
    awk -F";" '{print $0 > $3}' "dados${i}.dat";
    wc -l CLASS\=* >> distClasses;
done;