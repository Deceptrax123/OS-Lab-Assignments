ech "Fibonacci series upto 10 terms"
n1=0
n2=1
echo $n1
echo $n2
for ((i=0; i<8; i++))
do
	c=$((n1+n2))
	n1=$n2
	n2=$c
	echo $c
done
