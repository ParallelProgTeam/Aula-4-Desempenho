# Aulas--Desempenho
<!-- TODO:  -->
## Aulas da disciplina Laboratório de Introdução à Programação Paralela ##
*Desempenho. Dependências de dado. Classificação. Lei de Amdahl. Profilers: gprof. Ferramentas para análise de desempenho: Intel VTune Analyzer. GnuPlot

Intensidade aritmética: quanto é um valor aceitável? q = f/m
* m = número de elementos de memória (palavras) movidas entre as memórias lenta e rápida;
* tm = tempo por operação na memória lenta. Pode usar tm = minimum-memory-latency / words-per-cache-line 
* f = número de operações aritméticas
* tf = tempo por operação aritmêtica << tm

* q = 2 na multiplicação naive de matrizes (q = f/m = 2n3 / (n3 + 3n2), consideramos um n muito grande)
* tempo de execução = f * tf + m * tm = f * tf * (1 + tm/tf  * 1/q) ==>  Ideal: (tm/tf  * 1/q) ~> 0 ==> q >> tm/tf

* tm/tf = 6.25 no Pentium 3!!
* https://software.intel.com/en-us/articles/intelr-memory-latency-checker

## Dependências de dado ##
Classificação de dependências de dado: Uma dependência de dado é chamada de *loop carried* se as duas expressões envolvidas na dependência ocorrem em diferentes iterações do laço.

## Afinidade / AFFINITY ##
A afinidade de threads (Thread affinity ) restringe a execução de determinadas threads (unidades de execução virtual) a um subconjunto das unidades de processamento físico em um computador com multiprocessador. Dependendo da topologia da máquina, a afinidade de threads pode ter um efeito dramático na velocidade de execução de um programa.
Isso minimiza a migração de threads e o custo da troca de contexto entre os núcleos (cores). Ela também melhora a localidade dos dados e reduz o tráfego de coerência de cache entre os núcleos (ou processadores).
OpenMP tem a capacidade de vincular (bind) threads OpenMP a unidades de processamento físico. A interface é controlada usando uma variável de ambiente cujo nome depende do compilador em uso. Ex. para Intel use KMP_AFFINITY.
https://gcc.gnu.org/onlinedocs/libgomp/GOMP_005fCPU_005fAFFINITY.html#GOMP_005fCPU_005fAFFINITY

> Exercício. Execute o programa na semana anterior com um número de steps 1000 vezes superior. Abra o terminal e execute o comando top configurado para ver as threads. Modifique o parâmetro de afinidade do programa e veja como se comporta.

## [GnuPlot](./gnuplot)

## [Profiling](./profiling)

---

> Exercício: Para a próxima aula trazer implementado um programa para Multiplicação de matrizes quadradas.
> Você deve tentar otimizar seu código sequencial baseado nos métodos estudados em sala (pode implementar o Strassen, mas só como referência). 
> Crie um gráfico de tempo de execução e speedup para diferentes tamaños da entrada. 

> Nas próximas aulas iremos utilizar acelerar esse código com diretivas OpenMP:
> Repita usando escalonamento dinâmico e tente explicar qual a causa da diferença no desempenho.
> Depois, você deve inserir as diretivas OpenMP apropriadas para paralelizar o código. 

https://stackoverflow.com/questions/15829223/loop-tiling-blocking-for-large-dense-matrix-multiplication
