# Trab_FTF
Trabalho de FTF - Injeção de Falhas - UFRGS

### CAROL-FI
A linha de comando para executar o CAROL-FI é a seguinte:

Então, para executar o injetor de falhas, use o seguinte comando:
```{r, engine='bash', code_block_name} 
$ ./fault_injector.py -c <conf file> -i <# tests>
```
### Como executar um teste simples
Para testar o RBTree, execute o make na pasta RBTree '/ RBTree'. Uma pasta no diretório / tmp será criada com os binários e arquivos necessários.

Supondo que você tenha clonado o repositório em seu diretório inicial, você poderá executar o teste simples com os seguintes comandos:
```{r, engine='bash', code_block_name} 
$ cd ~/Trab_FTF/RBTree/
$ make
```
Então, para executar o injetor de falhas, use o seguinte comando:
```{r, engine='bash', code_block_name} 
$ cd ~/carol-fi
$ ./fault_injector.py -c ../RBTree/RBTree.conf -i 10
```

### Sobre o CAROL-FI
* Repositório <https://github.com/UFRGS-CAROL/carol-fi>
