N_TESTS=1000

echo "--------- 100 Random Numbers ---------"
echo ""
echo "Testing $N_TESTS Cases"

MIN=700
MAX=0

START=$(date +%s)

for i in $(seq 1 $N_TESTS); do
	printf "\r%d/%d" "$i" "$N_TESTS"
	ARG=$(seq 0 99 | shuf)
	OUT=$(./push_swap $ARG)
	RESULT=$(echo "$OUT" | ./checker $ARG)
	OPS=$(echo "$OUT" | wc -l)
	if [ "$OPS" -gt 700 ]; then
		echo ""
		echo "Attempt $i: $OPS"
		echo "Case: $(echo "$ARG" | tr '\n' ' ')"
	fi
	if [ "$MIN" -gt "$OPS" ]; then
		MIN=$OPS
	fi
	if [ "$MAX" -lt "$OPS" ]; then
		MAX=$OPS
	fi
	if [ "$RESULT" = "KO" ]; then
		echo ""
		echo "KO on attempt $i"
		echo "Case: $(echo "$ARG" | tr '\n' ' ')"
	fi
done

END=$(date +%s)

TOTAL=$((END - START))

echo ""
if [ "$TOTAL" -lt 60 ]; then
	echo "Elapsed time: $TOTAL seconds"
elif [ $((TOTAL % 60)) -eq 0 ]; then
	echo "Elapsed time: $((TOTAL / 60)) minutes"
else
	echo "Elapsed time: $((TOTAL / 60)) minutes and $((TOTAL % 60)) seconds"
fi

echo "Minimum Operations: $MIN | Maximum Operations: $MAX"
echo ""



N_TESTS=100

echo "--------- 500 Random Numbers ---------"
echo ""
echo "Testing $N_TESTS Cases"

MIN=7000
MAX=0

START=$(date +%s)
for i in $(seq 1 $N_TESTS); do
	printf "\r%d/%d" "$i" "$N_TESTS"
	ARG=$(seq 0 499 | shuf)
	OUT=$(./push_swap $ARG)
	RESULT=$(echo "$OUT" | ./checker $ARG)
	OPS=$(echo "$OUT" | wc -l)
	if [ "$OPS" -gt 5500 ]; then
		echo ""
		echo "Attempt $i: $OPS"
		echo "Case: $(echo "$ARG" | tr '\n' ' ')"
	fi
	if [ "$MIN" -gt "$OPS" ]; then
		MIN=$OPS
	fi
	if [ "$MAX" -lt "$OPS" ]; then
		MAX=$OPS
	fi
	if [ "$RESULT" = "KO" ]; then
		echo ""
		echo "KO on attempt $i"
		echo "Case: $(echo "$ARG" | tr '\n' ' ')"
	fi
done

END=$(date +%s)
TOTAL=$((END - START))

echo ""
if [ "$TOTAL" -lt 60 ]; then
	echo "Elapsed time: $TOTAL seconds"
elif [ $((TOTAL % 60)) -eq 0 ]; then
	echo "Elapsed time: $((TOTAL / 60)) minutes"
else
	echo "Elapsed time: $((TOTAL / 60)) minutes and $((TOTAL % 60)) seconds"
fi

echo "Minimum Operations: $MIN | Maximum Operations: $MAX"