# /bin/bash
# echo "Autotest start... Version 1"

# anwser=`./exe < tests/116` # Execute the program then store the result to file.
# str=$(<tests/116.a) # Read the answer then store to str.
# count=1
# read -r amount < tests/116.a;

# for i in $answer $str
# do
# 	if [ "$i" = "$i" ];
# 	then
# 		echo "Correct --- " $count
# 		echo $i $i
# 		count=$((count+1))
# 	else
# 		echo "Faile"
# 	fi	
# 	# if [ "$count" -eq "$((amount+1))" ]
# 	# then
# 	# 	exit 1
# 	# fi
# done

echo "Autotest start... Version 2"
if [ -f exe_v2 ]
then
	anwser=`./exe_v2 < tests/116` # Execute the program then store the result to file.
else
	`gcc -Wall -O2 -pipe -std=c99 $1 -o exe_v2`
	anwser=`./exe_v2 < tests/116` # Execute the program then store the result to file.
fi


str=$(<tests/116.a) # Read the answer then store to str.
count=1
read -r amount < tests/116.a;

for i in $answer $str
do
	if [ "$i" = "$i" ];
	then
		echo "Correct --- " $count
		echo $i $i
		count=$((count+1))
	else
		echo "Faile"
		exit 1
	fi	
	# if [ "$count" -eq "$((amount+1))" ]
	# then
	# 	exit 1
	# fi
done

# while read -r line;
# do
# 	echo $line
# done < $file	
