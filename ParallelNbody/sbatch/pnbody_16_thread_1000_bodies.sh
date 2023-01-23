#!/bin/bash

#SBATCH -A kurs00062
#SBATCH -p kurs00062
#SBATCH --reservation=kurs00062
#SBATCH -J pnbody_16_thread_1000_bodies
#SBATCH --mail-type=ALL
#SBATCH -e /home/kurse/kurs00062/je59nuni/ParallelNbody/16_thread_1000_bodies.err.%j
#SBATCH -o /home/kurse/kurs00062/je59nuni/ParallelNbody/16_thread_1000_bodies.out.%j
#SBATCH -n 1
#SBATCH -c 16
#SBATCH --mem-per-cpu=3800
#SBATCH -t 00:10:00

module purge
module load gcc/10
module load openmpi

cd /home/kurse/kurs00062/je59nuni/ParallelNbody/
./bin/spp-nbody-omp 1000_bodies.txt 1000bodies-out-16.txt -OMP_NUM_THREADS=16