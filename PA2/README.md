# Promgram assignment #2: Maximum Planar Subset
<img src="https://raw.githubusercontent.com/shannon112/AlgorithMew/master/PA2/doc/problem.png" width=780/>  
<img src="https://raw.githubusercontent.com/shannon112/AlgorithMew/master/PA2/doc/problem2.png" width=780/>  

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
./mps <input file name> <output file name> 
./mps public_cases/12.in sample_output/12.out
./mps public_cases/100.in sample_output/100.out
./mps public_cases/20000.in sample_output/20000.out
```
run with debugging mode
```
./mps_debug <input file name> <output file name> 
./mps public_cases/2.in sample_output/2.out
./mps public_cases/4.in sample_output/4.out
./mps public_cases/6.in sample_output/6.out
```

# SelfCheck and upload my homework
```
mkdir r07921001_pa2
cp -r {src,makefile,README.md} ./r07921001_pa2
tar zcvf r07921001_pa2.tgz r07921001_pa2
bash checkSubmitPA2.sh r07921001_pa2.tgz
```
