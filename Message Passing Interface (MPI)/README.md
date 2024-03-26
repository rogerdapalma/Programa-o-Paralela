# Para instalar o MPI no Linux, abra um terminal e digite o seguinte comando:

sudo apt-get install libopenmpi-dev openmpi-bin openmpi-doc

Para compilar um programa MPI usamos o seguinte comando:

mpicc arquivo.c -o arquivo 

ou

mpicc -o arquivo arquivo.c 

Para executar o programa em paralelo, usamos o comando, em que 8 indica a quantidade de processos que serão criados (pode ser trocado por outra quantidade):

mpiexec -np 8 arquivo 
