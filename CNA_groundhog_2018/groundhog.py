#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
import fileinput
import statistics
from math import *

last_val = 0
Global_List = list()
Weird_List = list()
Number_Switchs = 0

class groundhog():

    def print_help():
        print("SYNOPSIS\n\t./groundhog period\n\nDESCRIPTION\n\tperiod\t\tthe number of days defining a period")

    def prompt():
        global try_last_r
        Number_List = list()
        for line in sys.stdin:
            line = line.strip()
            try:
                line = float(line)
            except:
                if (line == "STOP"):
                    groundhog.check_values(Number_List)
                    sys.exit(0)
                sys.exit(84)
            Number_List.append(line)
            groundhog.check_info(Number_List)

    def check_values(Number_List):
        global Number_Switchs
        if (len(Number_List) >= int(sys.argv[1]) and Number_Switchs != 0):
            if (Number_Switchs > 1):
                print("Global tendency switched " + str(Number_Switchs) + " times")
                print(str(Number_Switchs) + " weirdest values are " + str(groundhog.weirdest_values(Number_List, Number_Switchs)))
            else:
                print("Global tendency switched 1 time")
                print("The weirdest value is " + groundhog.weirdest_values(Number_List, 1))

    def weirdest_values(Number_List, Number_Switchs):
        i = 0
        while (len(Weird_List) != Number_Switchs):
            Weird_List.pop()
        return Weird_List

    def check_info(Number_List):
        global last_val
        global Global_List
        global Number_Switchs
        len_list = len(Number_List)
        if (len_list < (int(sys.argv[1]))):
            print("g=nan\tr=nan%\ts=nan")
        elif (len_list < int(sys.argv[1]) + 1):
            print("g=nan\tr=nan%%\ts=%.2f" % groundhog.handle_s(Number_List))
        else:
            last_r = groundhog.handle_r(Number_List)
            print("g=%.2f\tr=%d%%\ts=%.2f" % (groundhog.handle_g(Number_List), groundhog.handle_r(Number_List), groundhog.handle_s(Number_List)), end='')
            Global_List.append(last_r)
            if (len(Global_List) >= 2):
                last_r = Global_List[-1]
                if (Global_List[-2] - last_r >= 14 or last_r - Global_List[-2] >= 14):
                    Weird_List.append(Number_List[-1])
                if (last_r >= 0 and last_val == 0):
                    last_val = 1
                    print('\n', end='')
                elif (last_r < 0 and last_val == 0):
                    last_val = -1
                    print('\n', end='')
                elif (last_r >= 0 and last_val == -1):
                    last_val = 0
                    print("\t\ta switch occurs")
                    Number_Switchs += 1
                elif (last_r < 0 and last_val == 1):
                    last_val = 0
                    print("\t\ta switch occurs")
                    Number_Switchs += 1
                else:
                    print('')
            else:
                print('')

    def handle_g(Number_List):
        i = 1
        tmp = 0
        List_Moy = list()
        Number_List.reverse()
        while (i != int(sys.argv[1]) + 1):
            a = (Number_List[i] - Number_List[i - 1])
            a = round(a, 2)
            List_Moy.append(a)
            i += 1
        while (i > 1):
            tmp += List_Moy[-1]
            List_Moy.pop()
            i -= 1
        Number_List.reverse()
        tmp /= int(sys.argv[1])
        if (tmp >= 0):
            tmp = 0
        return float(-1 * tmp)

    def handle_r(Number_List):
        tmp = 100 * (Number_List[-1] - Number_List[-1 - int(sys.argv[1])]) / Number_List[-1 - int(sys.argv[1])]
        tmp = round(tmp, 0)
        return (tmp)

    def average(Index_Start, Index_Stop, Number_List):
        i = Index_Start - 1
        New_List = list()
        while (i != Index_Stop):
            New_List.append(Number_List[i])
            i += 1
        return (sum(New_List) / len(New_List))

    def handle_s(Number_List):
        tmp = 0
        to_val = 0
        i = 0
        calc_val = 0
        total = 0
        Calc_List = list()
        for element in Number_List:
            to_val += 1
        from_val = to_val - int(sys.argv[1]) + 1
        moyenne = groundhog.average(from_val, to_val, Number_List)
        while (i != to_val - from_val + 1):
            calc_val = (Number_List[i + from_val - 1] - moyenne)**2
            Calc_List.append(calc_val)
            i += 1
        total = sqrt( (sum(Calc_List)) / (len(Calc_List)) )
        return (total)

    def print_graph():
        print("wow this is a courbe with so much informations lelelelel")

    def main(lel):
        if (len(sys.argv) != 2):
            print("Wrong number of argument(s)")
            sys.exit(84)
        if (sys.argv[1] == "-h"):
            groundhog.print_help()
            sys.exit(0)
        if (int(sys.argv[1]) <= 0):
            print("error")
            sys.exit(84)
        groundhog.prompt()

if __name__ == '__main__':
    groundhog().main()