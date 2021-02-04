# /bin/bash
echo "Autotest start..."

anwser=`./exe < tests/04` # Execute the program then store the result to file.
str=$(<tests/04.a) # Read the answer then store to str.
count=1
read -r amount < tests/04.a;

for i in $answer $str
do
	if [ "$i" = "$i" ];
	then
		echo "Correct --- " $count
		count=$((count+1))
	else
		echo "Faile"
	fi	
	if [ "$count" -eq "$((amount+1))" ]
	then
		exit 1
	fi
done

# while read -r line;
# do
# 	echo $line
# done < $file	
