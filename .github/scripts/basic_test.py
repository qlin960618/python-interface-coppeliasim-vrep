from dqrobotics import *
from dqrobotics.interfaces.vrep import DQ_VrepInterface


def main():
    ci = DQ_VrepInterface()
    print(ci)


if __name__ == "__main__":
    main()
