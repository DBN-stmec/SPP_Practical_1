#!/bin/bash

#SBATCH -A kurs00062
#SBATCH -p kurs00062
#SBATCH --reservation=kurs00062
#SBATCH -J snbody_5000_bodies
#SBATCH --mail-type=ALL
#SBATCH -e /home/kurse/kurs00062/je59nuni/SerialNbody/5000_bodies.err.%j
#SBATCH -o /home/kurse/kurs00062/je59nuni/SerialNbody/5000_bodies.out.%j
#SBATCH -n 1
#SBATCH -c 1
#SBATCH --mem-per-cpu=3800
#SBATCH -t 00:20:00

module purge
module load gcc/10
module load openmpi

cd /home/kurse/kurs00062/je59nuni/SerialNbody/
./bin/spp-nbody-omp 5000_bodies.txt 5000_bodies-out.txt