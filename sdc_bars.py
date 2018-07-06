#!/usr/bin/python
import argparse,os,sys
import difflib
import glob

### USO ###
# etapa I
# python sdc_bars.py -g ./RBTree/gold_ -o ./RBTree/output2_ -p RBTree-random -d 0
# etapa II
# python sdc_bars.py -g ./RBTree/gold_ -o ./RBTree/output2_ -p RBTree-dup-random -d 1 

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-g', '--gold', dest="goldResult", help=' gold file', required=True)
    parser.add_argument('-o', '--out', dest="outputResult", help='output file', required=True)
    parser.add_argument('-p', '--path', dest="pathName", help='path name', required=True)
    parser.add_argument('-d', '--detected', dest="isDetect", help='SDCs Detected', required=True)
    
    args = parser.parse_args()
    
    print("args:",args)
    
    # count = 0
    # count = 50000

    ### TESTE 1 ###
    # le 2 arquivos e faz a intersecao

    # with open(args.goldResult) as gold:
    #     contentG = gold.readlines()
    # with open(args.outputResult) as output:
    #     contentO = output.readlines()
    # for x in contentG:
    #     for y in contentO:
    #         if x == y:
    #             count -= 1
    # print count

    ### TESTE 2 ###
    # lista arquivos de um diretorio
    # listdir = os.listdir("/home/dlazarosps/Documentos/FTF/Trab_FTF/carol-fi/logs")
    # for l in listdir:
    #     print l

    ### SCRIPT ###

    # path do output com sdcs no logs do CAROLFI
    if args.isDetect == 1:
        completePath = '/home/dlazarosps/Documentos/FTF/Trab_FTF/carol-fi-ftf/logs/'+args.pathName+'/sdcs-detected/**/**/output_' #etapa II
    else:
        completePath = '/home/dlazarosps/Documentos/FTF/Trab_FTF/carol-fi/logs/'+args.pathName+'/sdcs/**/**/output_' #etapa I


    # PARA cada output encontrado no log faz a interseccao com o GOLD e PRINT a diferenca
    for filename in glob.iglob(completePath):
        print filename
        diff = 50000
        with open(args.goldResult) as file1:
            with open(filename) as file2:
                same = set(file1).intersection(file2)

        for line in same:
            diff -= 1
        
        # print count
        print diff
        # count += 1



if __name__ == "__main__":
    main()
