echo "enter a string"
read a
echo "Enter a string"
read b
if [ "$a" = "$b" ]; then
	echo "Strings are equal"
else
	echo "strings not equal"
fi
