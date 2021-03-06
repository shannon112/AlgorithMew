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
```sh
./cb <input file name> <output file name> 
# undirected
./cb public_cases/simple_case1.in public_cases/simple_case1.out #8
./cb public_cases/simple_case3.in public_cases/simple_case3.out #22
./cb public_cases/simple_case1.in public_cases/public_case1.out #21
./cb public_cases/simple_case2.in public_cases/public_case2.out #-3330
./cb public_cases/simple_case4.in public_cases/public_case4.out #0
./cb public_cases/simple_case5.in public_cases/public_case5.out #-90636
./cb public_cases/simple_case6.in public_cases/public_case6.out #-195222

# directed
./cb public_cases/simple_case2.in public_cases/simple_case2.out #5
./cb public_cases/simple_case3.in public_cases/public_case3.out #-12191
./cb public_cases/simple_case7.in public_cases/public_case7.out #-2508
./cb public_cases/simple_case8.in public_cases/public_case8.out #-39905
```
run with debugging mode
```
./cb_debug <input file name> <output file name> 
```

# SelfCheck and upload my homework
Selfcheck answer (if resulted graph is (weakly) connected, and if resulted graph contains cycles)
```sh
./pa3_checker <input file name> <output file name> 
```
```
# sample output
================================================
         Alg 2019 fall     PA3  Checker         
================================================

Congratulations! No cycle.

Total cost = 21

```
Selfcheck summision
```
mkdir r07921001_pa3
cp -r {src,makefile,README.md} ./r07921001_pa3
tar zcvf r07921001_pa3.tgz r07921001_pa3
bash checkSubmitPA3.sh r07921001_pa3.tgz
```

# Directed Graph Connectivity
```Weakly connected```: the graph would be connected if all edges were replaced by undirected edges.  
```Connected```: for each pair of vertices 𝑢 and 𝑣, there's a path from 𝑢 to 𝑣 or a path from 𝑣 to 𝑢 (or both).  
```Strongly connected```: for each pair of vertices 𝑢 and 𝑣, there's a path from 𝑢 to 𝑣 and a path from 𝑣 to 𝑢.  
