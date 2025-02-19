cmake_minimum_required(VERSION 3.27)
project(PipesThreadsetc C)

set(CMAKE_C_STANDARD 11)

add_executable(PipesThreadsetc
        forking/main.c
        forking/waitprocess.c
        forking/forkvisual.c
        Multiple forks.c
        pipes/communicating.c
        pipes/practicalfork.c
        FIFOs/FIFO1.c
        FIFOs/myfifo1
        FIFOs/FIFOcommunication.c
        FIFOs/FIFOcommunication2.c
        pipes/Pipestwoway.c
        pipes/Pipestwoway2.c
        execute/Commands.c
        FIFOs/exitstat.c
        execute/exec.c
        FIFOs/filesearch.c
        threads/threadintro.c
        threads/threadargs.c
        exam1.c
        signaling/signals.c
        signaling/stopcont.c
        signaling/BackForegroundp.c
        signaling/sigaction.c
        signaling/executable.c
        signaling/sigalarm2.c
        execute/stout.c
        pipes/parentchild.c
        pipes/parentchild.c
        pipes/parentchild.c
        pipes/parentchild.c
        signaling/signalcomm.c
        pipes/arraypipe.cpp
        pointersmemory/differences.c
        pointersmemory/differences.c
        pointersmemory/tipspointers.c
        exercises/exercises_try.c
        pipes/practicalfork.c

)
