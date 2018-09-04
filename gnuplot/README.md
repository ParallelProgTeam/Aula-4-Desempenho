[GnuPlot](http://gnuplot.info/): é uma ferramenta open-source e free para criar gráficos 2D e 3D. 

Links úteis:
- Manual: http://gnuplot.info/docs_5.0/gnuplot.pdf
Demos: 
- average: http://gnuplot.sourceforge.net/demo_5.0/running_avg.html
- errorbars: http://gnuplot.sourceforge.net/demo_5.0/fit.html

[Exemplo](./test.dem) 
- Execute o comando gnuplot test.dem
- Analize o código e modifique-o a vontade.

![Exercício](./MatMult.png) 
Implemente um programa em C++ que multiplique duas matrizes quadradas de doubles. Compile com um nível de otimização que não utilize vetorização.
Para isto, pesquise os níveis de otimização do gcc ( -O ).
Para cada versão de seu código execute 30 vezes, calcule a média e faça um gráfico de tempo de execução para N=10/100/1000/10000 (No caso do Naive estime o 10000, não o execute em sala de aula!):
* Naive (ijk, sem register);
* Troque a ordem dos laços, segundo estudado em sala. Use register nas variáveis mais utilizadas;
* Teste outro compilador. Instale o Educator Intel® Parallel Studio XE Cluster Edition for Linux e compile usando o icpc. 
* Avalie outras otimizações (transposta, tiling);
* Use OpenMP para paralelizar seu melhor algoritmo.
* Analize seu programa com o Intel VTune.

Em sala foi apresentado um teste de desempenho no qual foi graficado o número de ciclos por flop de um algoritmo de multiplicação de matrizes em função do tamanho da matriz. Faça o gráfico para diferentes valores de N usando essa medida.

* MAX FLOPS = (# Number of cores) * (Clock Frequency (cycles/sec) ) * (# FLOPS / cycle)

