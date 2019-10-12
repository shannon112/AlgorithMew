echo -e "------------------HeapSort---------"
./bin/NTU_sort -HS inputs/4000.case2.in outputs/4000.case2.out
diff inputs/4000.case2.in outputs/4000.case2.out
./bin/NTU_sort -HS inputs/4000.case3.in outputs/4000.case3.out
diff inputs/4000.case2.in outputs/4000.case3.out
./bin/NTU_sort -HS inputs/4000.case1.in outputs/4000.case1.out
diff inputs/4000.case2.in outputs/4000.case1.out

./bin/NTU_sort -HS inputs/16000.case2.in outputs/16000.case2.out
diff inputs/16000.case2.in outputs/16000.case2.out
./bin/NTU_sort -HS inputs/16000.case3.in outputs/16000.case3.out
diff inputs/16000.case2.in outputs/16000.case3.out
./bin/NTU_sort -HS inputs/16000.case1.in outputs/16000.case1.out
diff inputs/16000.case2.in outputs/16000.case1.out

./bin/NTU_sort -HS inputs/32000.case2.in outputs/32000.case2.out
diff inputs/32000.case2.in outputs/32000.case2.out
./bin/NTU_sort -HS inputs/32000.case3.in outputs/32000.case3.out
diff inputs/32000.case2.in outputs/32000.case3.out
./bin/NTU_sort -HS inputs/32000.case1.in outputs/32000.case1.out
diff inputs/32000.case2.in outputs/32000.case1.out

./bin/NTU_sort -HS inputs/1000000.case2.in outputs/1000000.case2.out
diff inputs/1000000.case2.in outputs/1000000.case2.out
./bin/NTU_sort -HS inputs/1000000.case3.in outputs/1000000.case3.out
diff inputs/1000000.case2.in outputs/1000000.case3.out
./bin/NTU_sort -HS inputs/1000000.case1.in outputs/1000000.case1.out
diff inputs/1000000.case2.in outputs/1000000.case1.out
