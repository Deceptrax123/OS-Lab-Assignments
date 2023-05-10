echo "enter a number"
read a
echo "enter a number"
read b
echo "enter a number"
read c
if [ $a -lt $b ] && [ $a -lt $c ]
then
	echo "a is lesser"
elif [ $b -lt $c ] && [ $b -lt $a ]
then
	echo "b is lesser"
else
	echo "c is lesser"
fi
