#!/bin/bash
for ((i=0;i<1000;i++))
do
   ./gen 10 5 5 $i > tst
   ./eslow < tst > input
   ./E < tst > answer
   if diff answer input
   then
      echo $i OK
   else
      echo $i WA
      exit
   fi
done