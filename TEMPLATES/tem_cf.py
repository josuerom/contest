#  author: $%U%$ - created: $%D%$/$%M%$/$%Y%$
import sys

def rli(): return list(map(int, sys.stdin.readline().split(r"\s+")))
def rls(): return list(map(str, sys.stdin.readline().split(r"\s+")))
def rlc(): return list(sys.stdin.readline())
def rint(): return int(sys.stdin.readline())
def pl(ls): print(' '.join(map(str, ls)))
def plb(ls): print('\n'.join(map(str, ls)))

for _ in range(rint()):