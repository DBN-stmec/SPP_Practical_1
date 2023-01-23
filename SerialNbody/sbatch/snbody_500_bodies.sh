#!/bin/bash

#SBATCH -A kurs00062
#SBATCH -p kurs00062
#SBATCH --reservation=kurs00062
#SBATCH -J snbody_500_bodies
#SBATCH --mail-type=ALL
#SBATCH -e /home/kurse/kurs00062/je59nuni/SerialNbody/500_bodies.err.%j
#SBATCH -o /home/kurse/kurs00062/je59nuni/SerialNbody/500_bodies.out.%j
#SBATCH -n 1
#SBATCH -c 1
#SBATCH --mem-per-cpu=3800
#SBATCH -t 00:10:00

module purge
module load gcc/10
module load openmpi

cd /home/kurse/kurs00062/je59nuni/SerialNbody/
./bin/spp-nbody-omp 500_bodies.txt 500_bodies-out.txt