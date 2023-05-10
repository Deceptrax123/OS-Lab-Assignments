echo "using for loop"
for ((i=1; i<11; i++))
do
	echo $i
done
echo "using while loop"
c=1
while [ $c -lt 11 ]
do
	echo $c
	((c++))
done
