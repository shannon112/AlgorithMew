# Promgram assignment #3: Cycle Breaking
<img src="https://raw.githubusercontent.com/shannon112/AlgorithMew/master/PA3/doc/problem.png" width=780/>  
<img src="https://raw.githubusercontent.com/shannon112/AlgorithMew/master/PA3/doc/problem2.png" width=780/>  
<img src="https://raw.githubusercontent.com/shannon112/AlgorithMew/master/PA3/doc/problem3.png" width=780/>  

# Compile
compile the O3 version
```
make
```
compile the debugging version 
```
make debug
```
clean binary files
```
make clean
```

# Run
run with test case
```
./cb <input file name> <output file name> 
# undirected
./cb public_cases/simple_case3.in public_cases/simple_case3.out
./cb public_cases/simple_case1.in public_cases/simple_case1.out
# directed
./cb public_cases/simple_case2.in public_cases/simple_case2.out
```
run with debugging mode
```
./cb_debug <input file name> <output file name> 
```

# SelfCheck and upload my homework
```
mkdir r07921001_pa3
cp -r {src,makefile,README.md} ./r07921001_pa3
tar zcvf r07921001_pa3.tgz r07921001_pa3
bash checkSubmitPA3.sh r07921001_pa3.tgz
```
