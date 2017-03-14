dataset=$1;
n=$2;
n1=`expr $n - 1`;
./crossValidation -d $dataset -p $n -i 1;

for i in `seq 0 1 $n1`
do
  rm -f treino.dat
  echo $i;
  for j in `seq 0 1 $n1`
  do
    if [ "${i}" -eq "${j}" ]; then
      echo "$i - $j";
      cat "dados${j}.dat" > teste.dat;
    else
      cat "dados${j}.dat" >> treino.dat;
    fi
  done;

  cp "treino.dat" "treino${i}.dat"
  cp "teste.dat" "teste${i}.dat"

done;
rm -f dados*
