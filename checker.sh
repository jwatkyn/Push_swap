num=5
case=50
limit=12

exceed=0
good=0
count=1
sum=0
best=1000000
worst=0
while [ $count -lt $(expr $case + 1) ]
do
    arg=$(ruby -e "puts (1..$num).to_a.shuffle.join(' ')")
    echo $count
    line=$(./push_swap $arg | wc -l)
    ok=$(./push_swap $arg | ./checker $arg)
    sum=$(expr $sum + $line)
    if [ $line -lt $best ]
    then
        best=$line
    fi
    if [ $line -gt $worst ]
    then
        worst=$line
    fi
    if [ $ok=="OK" ]
    then
        good=$(expr $good + 1)
    fi 
    if [ $line -gt $limit ]
    then
        exceed=$(expr $exceed + 1)
    fi
    count=$(expr $count + 1)
done
echo "num   : $num"
echo "case  : $case"
echo "good  : $good"
echo "avg   : $(expr $sum / $(expr $count - 1))"
echo "best  : $best"
echo "worst : $worst"
echo "exceed: $exceed"
