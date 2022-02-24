N=10
if [[ $# -ne 1 ]]; then
	echo "No N specified. Defaulting to N=10"
else
	N=$1
fi

k=1000
echo "Running benchmark with N=$N"

for i in $(seq 1 $N)
do
	echo "k=$k"
	{ time ./main $k; } 2>&1 | grep "real"
	k=$((k*2))	
done
echo "DONE"
