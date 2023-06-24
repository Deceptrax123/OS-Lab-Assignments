echo "Enter number 1 "
read a
echo "Enter number 2"
read b
echo "Enter operation no"
read op
case $op in
	"+")
		sum=$(($a+$b))
		echo "Sum "
		echo $sum
		;;
	"-")
		diff=$(($a-$b))
		echo "difference"
		echo $diff
		;;
	"*")
		mul=$(($a*$b))
		echo "product"
		echo $mul
		;;
	"/")
		div=$(($a/$b))
		echo "quotient"
		echo $div
		;;
esac
	

