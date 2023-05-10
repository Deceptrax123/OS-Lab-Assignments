echo "enter a number"
read n
temp=$n
s=0
while [ $temp -gt 0 ]
do
	digit=$((temp%10))
	s=$((s+digit))
	temp=$((temp/10))
done
echo "Sum of digits - "
echo $s
