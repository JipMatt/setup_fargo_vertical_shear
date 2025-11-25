#include "fargo3d.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_ROWS 807
#define MAX_ROWS 807
#define MAX_COLS 5
#define MAX_LINE_LENGTH 1024

float randm() {return ((float)rand()/RAND_MAX);}

void CondInit() {
  int id_gas = 0;
  int feedback = YES;
  //We read in the .csv file with initial conditions at put the values in a matrix
  double matrix[MAX_ROWS][MAX_COLS];
  char line[MAX_LINE_LENGTH];
  int row = 0;

  FILE *file = fopen("./setups/DVSI_gas_2D_hg4x5_res100/initial.csv", "r");
  if (!file) {
      perror("Failed to open file");
  }

  while (fgets(line, sizeof(line), file) && row < MAX_ROWS) {
    int col = 0;
    char *token = strtok(line, ",");
    while (token && col < MAX_COLS) {
      matrix[row][col] = atof(token);
      token = strtok(NULL, ",");
      col++;
    }
    row++;
  }

  //We first create the gaseous fluid and store it in the array Fluids
  Fluids[id_gas] = CreateFluid("gas",GAS);

  //We now select the fluid
  SelectFluid(id_gas);
  //and fill its fields
  int i,j,k;
  float AMP;
  real *rho  = Density->field_cpu;
  real *cs   = Energy->field_cpu;
  real *vx   = Vx->field_cpu;
  real *vy   = Vy->field_cpu;
  real *vz   = Vz->field_cpu;
#ifdef ACCELERATIONGAS
  real *agasy = Agasy->field_cpu;
#endif
  k = NGHZ;
  AMP = 0.00001;
  srand(CPU_Rank);
  for (k=0; k<Nz+2*NGHZ; k++) {
    for (j=0; j<Ny+2*NGHY; j++) {
      for (i=0; i<Nx+2*NGHX; i++) {
        cs[l]  = 1.0;
        rho[l] = matrix[k+z0cell+1][0] + AMP*(2*randm()-1.0);
        vx[l]  = matrix[k+z0cell+1][2] - SHEARPARAM*OMEGAFRAME*OMEGAFRAME*Ymed(j) + AMP*(2*randm()-1.0);
        vy[l]  = matrix[k+z0cell+1][1] + AMP*(2*randm()-1.0);
        vz[l]  = matrix[k+z0cell+1][3] + AMP*(2*randm()-1.0);
#ifdef ACCELERATIONGAS
        agasy[l]  = matrix[k+z0cell+1][4];
#endif
      }
    }
  }
}
