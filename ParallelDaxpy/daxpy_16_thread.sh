#!/bin/bash

#SBATCH -A kurs00062
#SBATCH -p kurs00062
#SBATCH --reservation=kurs00062
#SBATCH -J daxpy_16_thread
#SBATCH --mail-type=ALL
#SBATCH -e /home/kurse/kurs00062/je59nuni/ParallelDaxpy/16_thread.err.%j
#SBATCH -o /home/kurse/kurs00062/je59nuni/ParallelDaxpy/16_thread.out.%j
#SBATCH -n 1
#SBATCH -c 16
#SBATCH --mem-per-cpu=3800
#SBATCH -t 00:10:00
module purge
module load gcc/10
module load openmpi
cd /home/kurse/kurs00062/je59nuni/ParallelDaxpy
./daxpy
./daxpy 2
./daxpy 4
./daxpy 8
./daxpy 16