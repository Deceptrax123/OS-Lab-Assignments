echo "enter a number"
read a 
echo "Enter a number"
read b
echo "Enter a number"
read c
if [ $a -gt $b ] && [ $a -gt $c ]
then
	echo "a is greater"
elif [ $b -gt $c ] && [ $b -gt $a ]
then
	echo "b is greater"
else
	echo "c is greater"
fi
