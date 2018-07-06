#!/usr/bin/python
from __future__ import division
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
    if args.isDetect == '1':
        completePath = '/home/dlazarosps/Documentos/FTF/Trab_FTF/carol-fi-ftf/logs/'+args.pathName+'/sdcs-detected/**/**/output_' #etapa II
    else:
        completePath = '/home/dlazarosps/Documentos/FTF/Trab_FTF/carol-fi/logs/'+args.pathName+'/sdcs/**/**/output_' #etapa I

    p40 = 0
    p50 = 0
    p60 = 0
    p70 = 0
    p80 = 0
    p90 = 0


    # PARA cada output encontrado no log faz a interseccao com o GOLD e PRINT a diferenca
    for filename in glob.iglob(completePath):
        # print filename
        diff = 50000
        percent = 0.0
        with open(args.goldResult) as file1:
            with open(filename) as file2:
                same = set(file1).intersection(file2)

        for line in same:
            diff -= 1
        
        # print diff
        percent = diff/50000
        # print percent
        print("output corruption : "+"{:.3%}".format(percent)) 
        print "---\n\n"

        if percent < 0.5:
            p40 += 1
        elif percent < 0.6:
            p50 += 1
        elif percent < 0.7:
            p60 += 1
        elif percent < 0.8:
            p70 += 1
        elif percent < 0.9:
            p80 += 1
        else:
            p90 += 1
            
        # count += 1
    print "Count in percent"
    print("p40", "p50", "p60", "p70", "p80", "p90")
    print(p40, p50, p60, p70, p80, p90)


if __name__ == "__main__":
    main()
