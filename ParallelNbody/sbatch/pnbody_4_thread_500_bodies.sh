#!/bin/bash

#SBATCH -A kurs00062
#SBATCH -p kurs00062
#SBATCH --reservation=kurs00062
#SBATCH -J pnbody_4_thread_500_bodies
#SBATCH --mail-type=ALL
#SBATCH -e /home/kurse/kurs00062/je59nuni/ParallelNbody/4_thread_500_bodies.err.%j
#SBATCH -o /home/kurse/kurs00062/je59nuni/ParallelNbody/4_thread_500_bodies.out.%j
#SBATCH -n 1
#SBATCH -c 4
#SBATCH --mem-per-cpu=3800
#SBATCH -t 00:05:00

module purge
module load gcc/10
module load openmpi

cd /home/kurse/kurs00062/je59nuni/ParallelNbody/
./bin/spp-nbody-omp 500_bodies.txt 500bodies-out-4.txt -OMP_NUM_THREADS=4